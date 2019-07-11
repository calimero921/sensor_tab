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
#include <NDEF.h>
#include <ArduinoJson.h>

#include "main.h"

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

// configuration Adafruit_NeoPixel
Adafruit_NeoPixel pixels(PIXELNUMBER, PIXELDATAPIN, NEO_GRB + NEO_KHZ800);
void switchOffPixels();

// configuration MFRC522
MFRC522 board = MFRC522(MFRC522SDAPIN, MFRC522RESETPIN);

#define PAYLOAD_SIZE 1024
char payload[PAYLOAD_SIZE] = {};

// Prepare the key (used both as key A and as key B)
// using FFFFFFFFFFFFh which is the default at chip delivery from the factory
byte keyGArray[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
byte keyAArray[] = {0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5};
byte keyBArray[] = {0xD3, 0xF7, 0xD3, 0xF7, 0xD3, 0xF7};

StaticJsonDocument<1024> jsonDoc;

void setup() {
  Serial.begin(115200);

  // Adafruit_NeoPixel
  pixels.begin();
  switchOffPixels();

  // multiplexeur
  pinMode(MULTIPLEXADR0, OUTPUT);
  pinMode(MULTIPLEXADR1, OUTPUT);
  pinMode(MULTIPLEXADR2, OUTPUT);
  pinMode(MULTIPLEXADR3, OUTPUT);

  // initialisation des lecteurs;
  SPI.begin();
  for(int i = 0 ; i < MFRC522COUNT ; i++) {
    // selection du Lecteur
    selectReader(i);

    // MFRC522
    board.PCD_Init();
    board.PCD_DumpVersionToSerial();
    board.PCD_SoftPowerDown();
  }

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
}

void loop() {
  memset(payload, 0, PAYLOAD_SIZE);

  // notify changed value
  if (deviceConnected) {
    for(int reader = 0; reader < MFRC522COUNT; reader++) {
      readRFIDCard(reader);
      // delay(100);
    }
  }

  // disconnecting
  if (!deviceConnected && oldDeviceConnected) {
    delay(500); // give the bluetooth stack the chance to get things ready

    // shutting down readers
    for(int reader=0; reader < MFRC522COUNT; reader++) {
      selectReader(reader);
      board.PCD_SoftPowerDown();
    }

    pixels.clear();
    pixels.setPixelColor(PIXELNUMBER-1, 0, 0, 0);
    pixels.show();

    pAdvertising->start();
    Serial.println("start advertising");
    oldDeviceConnected = deviceConnected;
  }
  // connecting
  if (deviceConnected && !oldDeviceConnected) {
    pixels.clear();
    pixels.setPixelColor(PIXELNUMBER-1, 0, 32, 0);
    pixels.show();
    // do stuff here on connecting
    oldDeviceConnected = deviceConnected;
  }
}

void switchOffPixels() {
  for(int i=0; i<PIXELNUMBER; i++) {
    pixels.clear();
    pixels.setPixelColor(i, 0, 0, 0);
    pixels.show();
  }
}

void selectReader(int reader) {
  Serial.print("Reader to call : ");
  Serial.print(reader);

  // arret du lecteur en cours
  // board.PCD_SoftPowerDown();

  Serial.print(" -> 0x");
  // selection du lecteur par le multiplexeur
  Serial.print(bitRead(reader, 3) == 0 ? LOW : HIGH);
  digitalWrite(MULTIPLEXADR2, bitRead(reader, 3) == 0 ? LOW : HIGH);

  Serial.print(bitRead(reader, 2) == 0 ? LOW : HIGH);
  digitalWrite(MULTIPLEXADR2, bitRead(reader, 2) == 0 ? LOW : HIGH);

  Serial.print(bitRead(reader, 1) == 0 ? LOW : HIGH);
  digitalWrite(MULTIPLEXADR1, bitRead(reader, 1) == 0 ? LOW : HIGH);

  Serial.print(bitRead(reader, 0) == 0 ? LOW : HIGH);
  digitalWrite(MULTIPLEXADR0, bitRead(reader, 0) == 0 ? LOW : HIGH);
  Serial.println();

  // attente d'établissement du multiplexeur
  // delay(40);

  // activation du lecteur selectionné
  // board.PCD_SoftPowerUp();
}

void readRFIDCard(int reader) {
  Serial.print("Lecteur ");
  Serial.print(reader);
  Serial.println(" ...");
  selectReader(reader);

  // Look for new cards
  if ( ! board.PICC_IsNewCardPresent()) {
    Serial.print("pas de nouvelle carte");
    Serial.println();
    return;
  }

  // Select one of the cards
  if ( ! board.PICC_ReadCardSerial()) {
    Serial.print("pas de numero de serie");
    Serial.println();
    return;
  }

  // Dump debug info about the card; PICC_HaltA() is automatically called
  Serial.print("trouve");
  Serial.println();
  Serial.print(F("PICC type: "));
  MFRC522::PICC_Type piccType = board.PICC_GetType(board.uid.sak);
  Serial.println(board.PICC_GetTypeName(piccType));

  // Check is the PICC of Classic MIFARE type
  if (piccType != MFRC522::PICC_TYPE_MIFARE_MINI &&
    piccType != MFRC522::PICC_TYPE_MIFARE_1K &&
    piccType != MFRC522::PICC_TYPE_MIFARE_4K) {
    Serial.println(F("Your tag is not of type MIFARE Classic."));
    return;
  }

  Serial.println(F("The NUID tag is:"));
  Serial.print(F("In hex: "));
  printHex(board.uid.uidByte, board.uid.size);
  Serial.println();
  Serial.print(F("In dec: "));
  printDec(board.uid.uidByte, board.uid.size);
  Serial.println();

  byte buffer[18];
  byte numBlock[1] = {0};
  byte sector[1] = {0};
  uint16_t count;

  count = 0;
  for (sector[0] = 0; sector[0] < 16; sector[0]++) {
    Serial.println("");
    Serial.print("----------------------------- Sector");
    printHex(sector, 1);
    Serial.print(" ------------------------------");
    for (byte line = 0; line < 4; line++) {
      numBlock[0] = 4 * sector[0] + line;
      readBlock(numBlock[0], buffer);
      Serial.print("line : ");
      Serial.print(line);
      Serial.print(" Block : ");
      printHex(numBlock, 1);
      Serial.print("  ");
      printHex(buffer, 16);
      Serial.print("  ");
      for (uint8_t i = 0; i < 16; i++) {
        if ((int)sector[0] > 0) {
          if ((int)line != 3) {
            payload[count] = buffer[i];
            count++;
          }
        }
        Serial.print(" ");
        Serial.write(buffer[i]);
      }
    }
    Serial.print("count : ");
    Serial.print(count);
  }
  Serial.println();
  // Serial.print("Payload : ");
  // printHex((byte*)payload, count);
  // Serial.println();
  // Serial.print("Payload : ");
  // printChar((byte*)payload, count);
  // Serial.println();

  char message[PAYLOAD_SIZE] = {};
  for (int i = 0; i < count; i++) {
    if (i > 1) {
      message[i-2] = payload[i];
    }
  }

  // Serial.println();
  Serial.println("conversion message:");
  FOUND_MESSAGE result = NDEF().decode_message((uint8_t*)message);

  Serial.print("type : ");
  Serial.print(result.type);
  Serial.println();
  Serial.print("format : ");
  Serial.print(result.format);
  Serial.println();
  Serial.print("payload : ");
  Serial.print((char*)result.payload);
  Serial.println();

  // Deserialize the JSON document
  DeserializationError error = deserializeJson(jsonDoc, (char*)result.payload);

  // Test if parsing succeeds.
  if (error) {
    Serial.print(F("deserializeJson() failed: "));
    Serial.println(error.c_str());
    return;
  }

  const char* color = jsonDoc["color"];
  Serial.print("color : ");
  Serial.print(color);
  Serial.println();

  long pixelColor = convertHtmlColorToLong(color);
  pixels.clear();
  pixels.setPixelColor(reader, pixelColor);
  pixels.show();
  const char* format = jsonDoc["format"];
  Serial.print("format : ");
  Serial.print(format);
  Serial.println();

  // Halt PICC
  board.PICC_HaltA();
  // Stop encryption on PCD
  board.PCD_StopCrypto1();
  board.PCD_SoftPowerDown();
}

long convertHtmlColorToLong(const char* color) {
  char hexStr[9] = {'0','x','0','0','0','0','0','0','\0'};
  hexStr[2] = color[1];
  hexStr[3] = color[2];
  hexStr[4] = color[3];
  hexStr[5] = color[4];
  hexStr[6] = color[5];
  hexStr[7] = color[6];
  long result = strtoul(hexStr, NULL, 16);
  Serial.print("convertHtmlColorToLong : ");
  Serial.print(result, HEX);
  Serial.println();
  return result;
}
/**
* Helper routine to dump a byte array as hex values to Serial.
*/
void printHex(byte *buffer, byte bufferSize) {
  for (byte i = 0; i < bufferSize; i++) {
    Serial.print(buffer[i] < 0x10 ? " 0" : " ");
    Serial.print(buffer[i], HEX);
  }
}

/**
* Helper routine to dump a byte array as char values to Serial.
*/
void printChar(byte *buffer, byte bufferSize) {
  for (byte i = 0; i < bufferSize; i++) {
    Serial.write(buffer[i]);
  }
}

/**
* Helper routine to dump a byte array as dec values to Serial.
*/
void printDec(byte *buffer, byte bufferSize) {
   for (byte i = 0; i < bufferSize; i++) {
     Serial.print(buffer[i] < 0x10 ? " 0" : " ");
     Serial.print(buffer[i], DEC);
   }
}

void longToByteArray(long inLong, byte* outArray) {
  outArray[0] = inLong;
  outArray[1] = (inLong >> 8);
  outArray[2] = (inLong >> 16);
  outArray[3] = (inLong >> 24);
}

void readBlock(byte index, byte *buffer) {
  MFRC522::MIFARE_Key key;
  MFRC522::StatusCode status;
  byte len = 18;
  byte buffer1[len];

  switch(index) {
    case 0:
    case 1:
    case 2:
    case 3:
      for (byte i = 0; i < MFRC522::MF_KEY_SIZE; i++) {key.keyByte[i] = keyAArray[i];}
      break;
    default:
      for (byte i = 0; i < MFRC522::MF_KEY_SIZE; i++) {key.keyByte[i] = keyBArray[i];}
      break;
  }
  // Serial.print(F("Using the following key:"));
  // printHex(key.keyByte, MFRC522::MF_KEY_SIZE);
  Serial.println();

  status = board.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, index, &key, &(board.uid)); //line 834 of MFRC522.cpp file
  if (status != MFRC522::STATUS_OK) {
    Serial.print(F("Authentication failed: "));
    Serial.println(board.GetStatusCodeName(status));
  } else {
    status = board.MIFARE_Read(index, buffer1, &len);
    if (status != MFRC522::STATUS_OK) {
      Serial.print(F("Reading failed: "));
      Serial.println(board.GetStatusCodeName(status));
    } else {
      for (byte i = 0; i < len; i++) {
        buffer[i] = buffer1[i];
      }
    }
  }
}
