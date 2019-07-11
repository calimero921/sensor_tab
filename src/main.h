// #include <avr/pgmspace.h>

#include "Arduino.h"

// See the following for generating UUIDs:
// https://www.uuidgenerator.net/
#define SERVICE_UUID        "4fafc201-1fb5-459e-8fcc-c5c9c331914b"
#define LED_CHARACTERISTIC_UUID "beb5483e-36e1-4688-b7f5-ea07361b26a8"
#define RFID_CHARACTERISTIC_UUID "bb23e586-ce7c-4bc7-b3fb-b5f88a0f3277"

// configuration Adafruit_NeoPixel
#define PIXELNUMBER 3
#define PIXELDATAPIN 17

// configuration multiplexeur
#define MULTIPLEXADR0 12
#define MULTIPLEXADR1 13
#define MULTIPLEXADR2 14
#define MULTIPLEXADR3 15

// configuration MFRC522
#define MFRC522COUNT 3
#define MFRC522SDAPIN 21
#define MFRC522RESETPIN 22
#define MFRC522MISOPIN 19
#define MFRC522MOSIPIN 23
#define MFRC522SCKPIN 18

void switchOffPixels();
void selectReader(int reader);
void readRFIDCard(int reader);
// string *readRFIDCard(int reader);
void readBlock(byte index, byte *buffer);

long convertHtmlColorToLong(const char* color);
void printHex(byte *buffer, byte bufferSize);
void printChar(byte *buffer, byte bufferSize);
void printDec(byte *buffer, byte bufferSize);
void longToByteArray(long inLong, byte* outArray);
