/*
*/

#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>

#include "main.h"
#include "cardReader.h"
#include "rfidData.h"
#include "pixelManager.h"
#include "readerState.h"

BLEServer *pServer = NULL;
BLECharacteristic *pLedCharacteristic = NULL;
BLECharacteristic *pRfidCharacteristic = NULL;
bool deviceConnected = false;
bool oldDeviceConnected = false;
uint32_t value = 0;

int manufacturer_code = 0xFFFF;
char manufacturer_name[] = "DIPONGO";
char device_name[] = "DIPONGO-TAB-ESP32";

// Configuration readerState
ReaderState readerState = ReaderState(MFRC522COUNT);

// Configuration Adafruit_NeoPixel
// Adafruit_NeoPixel pixels(PIXELNUMBER, PIXELDATAPIN, NEO_GRB + NEO_KHZ800);
PixelManager pixelStrip = PixelManager(PIXELCOUNT);

// Configuration MFRC522
CardReader cardReader = CardReader(MFRC522COUNT);

BLEAdvertisementData advertisement;
BLEAdvertising *pAdvertising;

class MyServerCallbacks : public BLEServerCallbacks
{
  void onConnect(BLEServer *pServer)
  {
    deviceConnected = true;
    BLEDevice::startAdvertising();
  };

  void onDisconnect(BLEServer *pServer)
  {
    deviceConnected = false;
  }
};

class LedCharacteristicCallbacks : public BLECharacteristicCallbacks
{
  void onRead(BLECharacteristic *pCharacteristic)
  {
    String jsonString = readerState.toJsonString(true, false);
    uint16_t arraySize = jsonString.length();
    char results[arraySize];
    jsonString.toCharArray(results, arraySize);
    pCharacteristic->setValue(results);
  }

  void onWrite(BLECharacteristic *pCharacteristic)
  {
    std::string value = pCharacteristic->getValue();
    Serial.print("Received Value: ");
    for (int i = 0; i < value.length(); i++)
      Serial.print(value[i]);
    Serial.println();
  }
};

class RfidCharacteristicCallbacks : public BLECharacteristicCallbacks
{
  void onRead(BLECharacteristic *pCharacteristic)
  {
    String jsonString = readerState.toJsonString(true, true);
    uint16_t arraySize = jsonString.length();
    char results[arraySize];
    jsonString.toCharArray(results, arraySize);
    pCharacteristic->setValue(results);
  }
};

void setup()
{
  Serial.begin(115200);
  Serial.println("Main::Setup");

  pixelStrip.init();
  pixelStrip.switchOffAllPixels();

  cardReader.init();

  // Create the BLE Device
  BLEDevice::init(device_name);

  // Create the BLE Server
  pServer = BLEDevice::createServer();
  pAdvertising = pServer->getAdvertising();

  String s;
  char b2 = (char)(manufacturer_code >> 8);
  manufacturer_code <<= 8;
  char b1 = (char)(manufacturer_code >> 8);
  s.concat(b1);
  s.concat(b2);
  s.concat(manufacturer_name);
  advertisement.setManufacturerData(s.c_str());
  advertisement.setName(device_name);
  pAdvertising->setAdvertisementData(advertisement);
  pServer->setCallbacks(new MyServerCallbacks());

  // Create the BLE Service
  BLEService *pService = pServer->createService(SERVICE_UUID);

  // Create a BLE led Characteristic
  pLedCharacteristic = pService->createCharacteristic(
      LED_CHARACTERISTIC_UUID,
      BLECharacteristic::PROPERTY_READ |
          BLECharacteristic::PROPERTY_WRITE |
          BLECharacteristic::PROPERTY_NOTIFY |
          BLECharacteristic::PROPERTY_INDICATE);
  // https://www.bluetooth.com/specifications/gatt/viewer?attributeXmlFile=org.bluetooth.descriptor.gatt.client_characteristic_configuration.xml
  // Create a BLE Descriptor
  pLedCharacteristic->addDescriptor(new BLE2902());
  pLedCharacteristic->setCallbacks(new LedCharacteristicCallbacks());

  // Create a BLE led Characteristic
  pRfidCharacteristic = pService->createCharacteristic(
      RFID_CHARACTERISTIC_UUID,
      BLECharacteristic::PROPERTY_READ |
          BLECharacteristic::PROPERTY_NOTIFY |
          BLECharacteristic::PROPERTY_INDICATE);
  // https://www.bluetooth.com/specifications/gatt/viewer?attributeXmlFile=org.bluetooth.descriptor.gatt.client_characteristic_configuration.xml
  // Create a BLE Descriptor
  pRfidCharacteristic->addDescriptor(new BLE2902());
  pRfidCharacteristic->setCallbacks(new RfidCharacteristicCallbacks());

  // Start the service
  pService->start();

  // Start advertising
  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->addServiceUUID(SERVICE_UUID);
  pAdvertising->setScanResponse(false);
  pAdvertising->setMinPreferred(0x0); // set value to 0x00 to not advertise this parameter
  BLEDevice::startAdvertising();
  Serial.println("Main::Waiting a client connection to notify...");
}

void loop()
{
  // notify changed value
  if (deviceConnected)
  {
#ifdef DEBUG
    Serial.println("Main::Device connected...");
#endif
    boolean hasChanged = false;
    for (int reader = 0; reader < MFRC522COUNT; reader++)
    {
#ifdef DEBUG
      Serial.print("Main::Using reader ");
      Serial.print(reader);
      Serial.println(" ...");
#endif
      RfidData cardContent = cardReader.readRFIDCard(reader);
      // test if reader has content
      if (cardContent.error().length() == 0)
      {
        if (readerState.setState(reader, &cardContent))
        {
          hasChanged = true;
        }
      }
    }
    pixelStrip.setPixelState(&readerState);

    if (hasChanged)
    {
      String jsonString = readerState.toJsonString(true, true);
      uint16_t arraySize = jsonString.length();
      char results[arraySize];
      jsonString.toCharArray(results, arraySize);

      Serial.print("Main::Notifying bluetooth master:");
      Serial.println(results);
      pRfidCharacteristic->setValue(results);
      pRfidCharacteristic->notify();
    }
    else
    {
#ifdef DEBUG
      Serial.println("Main::Nothing to notify...");
#endif
    }
    // delay(1000);
  }

  // disconnecting
  if (!deviceConnected && oldDeviceConnected)
  {
    Serial.println("Main::Device disconnecting...");
    delay(500); // give the bluetooth stack the chance to get things ready

    cardReader.shutdownAllReaders();
    pixelStrip.switchOffPixel(PIXELCOUNT - 1);

    pAdvertising->start();
    Serial.println("Main::Start advertising");
    oldDeviceConnected = deviceConnected;
  }
  // connecting
  if (deviceConnected && !oldDeviceConnected)
  {
    Serial.println("Main::Device connecting...");
    pixelStrip.setPixelRGB(PIXELCOUNT - 1, 0, 32, 0);
    // do stuff here on connecting
    oldDeviceConnected = deviceConnected;
  }
}