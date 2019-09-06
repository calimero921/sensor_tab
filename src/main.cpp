/*
    Video: https://www.youtube.com/watch?v=oCMOYS71NIU
    Based on Neil Kolban example for IDF: https://github.com/nkolban/esp32-snippets/blob/master/cpp_utils/tests/BLE%20Tests/SampleNotify.cpp
    Ported to Arduino ESP32 by Evandro Copercini
    updated by chegewara

   Create a BLE server that, once we receive a connection, will send periodic notifications.
   The service advertises itself as: 4fafc201-1fb5-459e-8fcc-c5c9c331914b
   And has a characteristic of: beb5483e-36e1-4688-b7f5-ea07361b26a8

   The design of creating the BLE server is:
   1. Create a BLE Server
   2. Create a BLE Service
   3. Create a BLE Characteristic on the Service
   4. Create a BLE Descriptor on the characteristic
   5. Start the service.
   6. Start advertising.

   A connect hander associated with the server starts a background task that performs notification
   every couple of seconds.
*/
#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>
#include <ArduinoJson.h>

#include "main.h"
#include "cardReader.h"
#include "pixelManager.h"

BLEServer* pServer = NULL;
BLECharacteristic* pLedCharacteristic = NULL;
BLECharacteristic* pRfidCharacteristic = NULL;
bool deviceConnected = false;
bool oldDeviceConnected = false;
uint32_t value = 0;

int manufacturer_code = 0xFFFF;
char manufacturer_name[] = "DIPONGO";
char device_name[] = "DIPONGO-TAB-ESP32";

BLEAdvertisementData advertisement;
BLEAdvertising *pAdvertising;

class MyServerCallbacks: public BLEServerCallbacks {
    void onConnect(BLEServer* pServer) {
      deviceConnected = true;
      BLEDevice::startAdvertising();
    };

    void onDisconnect(BLEServer* pServer) {
      deviceConnected = false;
    }
};

class LedCharacteristicCallbacks: public BLECharacteristicCallbacks {
    void onRead(BLECharacteristic* pCharacteristic) {
      pCharacteristic->setValue("lecture tableau de led");
    }

    void onWrite(BLECharacteristic* pCharacteristic) {
      std::string value = pCharacteristic->getValue();
      Serial.print("Received Value: ");
      for (int i = 0; i < value.length(); i++)
        Serial.print(value[i]);
      Serial.println();    }
};

class RfidCharacteristicCallbacks: public BLECharacteristicCallbacks {
    void onRead(BLECharacteristic* pCharacteristic) {
      pCharacteristic->setValue("lecture tableau rfid");
    }
};

// // configuration Adafruit_NeoPixel
// Adafruit_NeoPixel pixels(PIXELNUMBER, PIXELDATAPIN, NEO_GRB + NEO_KHZ800);
PixelManager pixelStrip = PixelManager(PIXELCOUNT);

// configuration MFRC522
CardReader cardReader = CardReader(MFRC522COUNT);

void setup() {
  Serial.begin(115200);
  Serial.println("Main::Setup");
  pixelStrip.init();
  cardReader.init();

  pixelStrip.switchOffAllPixels();

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
                      BLECharacteristic::PROPERTY_READ   |
                      BLECharacteristic::PROPERTY_WRITE  |
                      BLECharacteristic::PROPERTY_NOTIFY |
                      BLECharacteristic::PROPERTY_INDICATE
                    );
  // https://www.bluetooth.com/specifications/gatt/viewer?attributeXmlFile=org.bluetooth.descriptor.gatt.client_characteristic_configuration.xml
  // Create a BLE Descriptor
  pLedCharacteristic->addDescriptor(new BLE2902());
  pLedCharacteristic->setCallbacks(new LedCharacteristicCallbacks());

  // Create a BLE led Characteristic
  pRfidCharacteristic = pService->createCharacteristic(
                      RFID_CHARACTERISTIC_UUID,
                      BLECharacteristic::PROPERTY_READ   |
                      BLECharacteristic::PROPERTY_NOTIFY |
                      BLECharacteristic::PROPERTY_INDICATE
                    );
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
  pAdvertising->setMinPreferred(0x0);  // set value to 0x00 to not advertise this parameter
  BLEDevice::startAdvertising();
  Serial.println("Main::Waiting a client connection to notify...");
}

void loop() {
  // memset(payload, 0, PAYLOAD_SIZE);

  // notify changed value
  if (deviceConnected) {
    Serial.println("Main::Device connected...");
    StaticJsonDocument<1024> jsonArray;
    for(int reader = 0; reader < MFRC522COUNT; reader++) {
      Serial.print("Main::Using reader ");
      Serial.print(reader);
      Serial.println(" ...");
      RfidData cardContent = cardReader.readRFIDCard(reader);
      if (cardContent.error().length() == 0) {
        pixelStrip.setPixelText(reader, cardContent.color());
        StaticJsonDocument<256> jsonObject;
        jsonObject["reader"] = reader;
        jsonObject["color"] = cardContent.color();
        jsonObject["format"] = cardContent.format();
        Serial.print("Main::jsonObject -> ");
        serializeJson(jsonObject, Serial);
        Serial.println();
        jsonArray.add(jsonObject);
      }
      // delay(100);
    }
    uint16_t arraySize = jsonArray.memoryUsage();
    Serial.print("Main::arraySize -> ");
    Serial.println(arraySize);
    if(arraySize > 0) {
      char results[arraySize];
      serializeJson(jsonArray, results, arraySize);
      Serial.print("Main::Result Array -> ");
      Serial.println(results);
      Serial.println("Main::Notifying bluetooth master...");
      pRfidCharacteristic->setValue((uint8_t*)&results, arraySize);
      pRfidCharacteristic->notify();
    } else {
      Serial.println("Main::Nothing to notify...");
    }
  }

  // disconnecting
  if (!deviceConnected && oldDeviceConnected) {
    Serial.println("Main::Device disconnecting...");
    delay(500); // give the bluetooth stack the chance to get things ready

    cardReader.shutdownAllReaders();
    pixelStrip.switchOffPixel(PIXELCOUNT-1);

    pAdvertising->start();
    Serial.println("Main::Start advertising");
    oldDeviceConnected = deviceConnected;
  }
  // connecting
  if (deviceConnected && !oldDeviceConnected) {
    Serial.println("Main::Device connecting...");
    pixelStrip.setPixelRGB(PIXELCOUNT-1, 0, 32, 0);
    // do stuff here on connecting
    oldDeviceConnected = deviceConnected;
  }
}
