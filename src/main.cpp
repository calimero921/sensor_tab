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
#include <Adafruit_NeoPixel.h>
#include <SPI.h>
#include <MFRC522.h>

BLEServer* pServer = NULL;
BLECharacteristic* pLedCharacteristic = NULL;
BLECharacteristic* pRfidCharacteristic = NULL;
bool deviceConnected = false;
bool oldDeviceConnected = false;
uint32_t value = 0;

int manufacturer_code = 0xFFFF;
char* manufacturer_name = "DIPONGO";
char* device_name = "DIPONGO-TAB-ESP32";

BLEAdvertisementData advertisement;
BLEAdvertising *pAdvertising;

// See the following for generating UUIDs:
// https://www.uuidgenerator.net/
#define SERVICE_UUID        "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
#define LED_CHARACTERISTIC_UUID "beb5483e-36e1-4688-b7f5-ea07361b26a8"
#define RFID_CHARACTERISTIC_UUID "bb23e586-ce7c-4bc7-b3fb-b5f88a0f3277"

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

// configuration Adafruit_NeoPixel
#define PINPIXELS 14
#define NUMPIXELS 8
Adafruit_NeoPixel pixels(NUMPIXELS, PINPIXELS, NEO_GRB + NEO_KHZ800);
void switchOffPixels();

// configuration MFRC522
#define MFRC522RESETPIN 22
#define MFRC522SELECTPIN 21

MFRC522 mfrc522 = MFRC522(MFRC522SELECTPIN, MFRC522RESETPIN);
void ShowReaderDetails();

void setup() {
  Serial.begin(115200);
  SPI.begin();

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
  Serial.println("Waiting a client connection to notify...");

  // Adafruit_NeoPixel
  pixels.begin();
  switchOffPixels();

  // MFRC522
  mfrc522.PCD_Init();
  mfrc522.PCD_DumpVersionToSerial();
}

void loop() {
    // notify changed value
    if (deviceConnected) {
      pixels.clear();
      for(int i=0; i<NUMPIXELS; i++) {
        pixels.setPixelColor(i, pixels.Color(0, 150, 0));
        pixels.show();
        delay(50);
      }
      for(int i=0; i<NUMPIXELS; i++) {
        pixels.setPixelColor(i, pixels.Color(0, 0, 0));
        pixels.show();
        delay(50);
      }
      // Look for new cards
      if ( ! mfrc522.PICC_IsNewCardPresent()) {
      	return;
      }
      // Select one of the cards
      if ( ! mfrc522.PICC_ReadCardSerial()) {
      	return;
      }
      // Dump debug info about the card; PICC_HaltA() is automatically called
      mfrc522.PICC_DumpToSerial(&(mfrc522.uid));
    }
    // disconnecting
    if (!deviceConnected && oldDeviceConnected) {
        delay(500); // give the bluetooth stack the chance to get things ready
        pAdvertising->start();
        // pServer->startAdvertising(); // restart advertising
        switchOffPixels();
        Serial.println("start advertising");
        oldDeviceConnected = deviceConnected;
    }
    // connecting
    if (deviceConnected && !oldDeviceConnected) {
        // do stuff here on connecting
        oldDeviceConnected = deviceConnected;
    }
}

void switchOffPixels() {
  pixels.clear();
  for(int i=0; i<NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 0, 0));
  }
  pixels.show();
}

void ShowReaderDetails() {
	// Get the MFRC522 software version
	byte v = mfrc522.PCD_ReadRegister(mfrc522.VersionReg);
	Serial.print(F("MFRC522 Software Version: 0x"));
	Serial.print(v, HEX);
	if (v == 0x91)
		Serial.print(F(" = v1.0"));
	else if (v == 0x92)
		Serial.print(F(" = v2.0"));
	else
		Serial.print(F(" (unknown)"));
	Serial.println("");
	// When 0x00 or 0xFF is returned, communication probably failed
	if ((v == 0x00) || (v == 0xFF)) {
		Serial.println(F("WARNING: Communication failure, is the MFRC522 properly connected?"));
	}
}
