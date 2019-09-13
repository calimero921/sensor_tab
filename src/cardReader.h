
#ifndef CardReader_H
#define CardReader_H

#include "Arduino.h"
#include <MFRC522.h>
#include <ArduinoJson.h>
#include "rfidData.h"

// configuration multiplexeur
#define MULTIPLEXADR0 12
#define MULTIPLEXADR1 13
#define MULTIPLEXADR2 14
#define MULTIPLEXADR3 15

// configuration MFRC522
#define MFRC522SDAPIN 21
#define MFRC522RESETPIN 22
#define MFRC522MISOPIN 19
#define MFRC522MOSIPIN 23
#define MFRC522SCKPIN 18

#define PAYLOAD_SIZE 1024

//#define DEBUG

class CardReader
{
public:
  CardReader(int nbCardReader);
  ~CardReader();
  void init();
  RfidData readRFIDCard(int reader);
  void shutdownAllReaders();
  void shutdownReader(int reader);

private:
  uint16_t countCardReader;
  MFRC522 board;

  void selectReader(int reader);
  void readBlock(byte index, byte *buffer);
  RfidData convertMessage(char *message);

  // long convertHtmlColorToLong(const char* color);
  byte *longToByteArray(long inLong);

  void printHex(byte *buffer, byte bufferSize);
  void printChar(byte *buffer, byte bufferSize);
  void printDec(byte *buffer, byte bufferSize);
};
#endif
