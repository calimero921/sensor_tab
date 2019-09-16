/*
*/

#include "cardReader.h"
#include <SPI.h>
#include <NDEF.h>

// Prepare the key (used both as key A and as key B)
// using FFFFFFFFFFFFh which is the default at chip delivery from the factory
byte keyGArray[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
byte keyAArray[] = {0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5};
byte keyBArray[] = {0xD3, 0xF7, 0xD3, 0xF7, 0xD3, 0xF7};

StaticJsonDocument<1024> jsonDocument;

CardReader::CardReader(int nbCardReader)
{
  countCardReader = nbCardReader;
  board = MFRC522(MFRC522SDAPIN, MFRC522RESETPIN);
}

CardReader::~CardReader()
{
}

void CardReader::init()
{
#ifdef DEBUG
  Serial.println("CardReader::Card reader initialisation...");
  Serial.println("CardReader::Card reader selector initialisation...");
#endif
  pinMode(MULTIPLEXADR0, OUTPUT);
  pinMode(MULTIPLEXADR1, OUTPUT);
  pinMode(MULTIPLEXADR2, OUTPUT);
  pinMode(MULTIPLEXADR3, OUTPUT);

#ifdef DEBUG
  //Serial.println("CardReader::Starting SPI...");
#endif
  SPI.begin();

#ifdef DEBUG
  //Serial.println("CardReader::Card reader reset...");
#endif
  for (int i = 0; i < countCardReader; i++)
  {
    // selection du Lecteur
    selectReader(i);

    // MFRC522
#ifdef DEBUG
    Serial.println("CardReader::Init...");
#endif
    board.PCD_Init();
#ifdef DEBUG
    Serial.println("CardReader::Version...");
#endif
    board.PCD_DumpVersionToSerial();
#ifdef DEBUG
    Serial.println("CardReader::Power off...");
#endif
    board.PCD_SoftPowerDown();
  }
}

RfidData CardReader::readRFIDCard(uint16_t reader)
{
  RfidData result = RfidData();

  char payload[PAYLOAD_SIZE] = {};
  memset(payload, 0, PAYLOAD_SIZE);

#ifdef DEBUG
  Serial.print("CardReader::readRFIDCard:Reader ");
  Serial.print(reader);
  Serial.println(" ...");
#endif
  selectReader(reader);
  // MFRC522
#ifdef DEBUG
  Serial.println("CardReader::readRFIDCard:Crad reader initialization...");
#endif
  board.PCD_Init();
  // Look for new cards
#ifdef DEBUG
  Serial.println("CardReader::readRFIDCard:Check card available");
#endif
  if (!board.PICC_IsNewCardPresent())
  {
#ifdef DEBUG
    Serial.println("CardReader::readRFIDCard:No new card to read");
#endif
    result.setError("Error no new card to read");
    return result;
  }

  // Select one of the cards
#ifdef DEBUG
  Serial.println("CardReader::readRFIDCard:Check card serial");
#endif
  if (!board.PICC_ReadCardSerial())
  {
#ifdef DEBUG
    Serial.println("CardReader::readRFIDCard:Your tag has no serial number");
#endif
    result.setError("Error Your tag has no serial number");
    return result;
  }

  MFRC522::PICC_Type piccType = board.PICC_GetType(board.uid.sak);
  Serial.print(F("CardReader::readRFIDCard:PICC type: "));
  Serial.println(board.PICC_GetTypeName(piccType));

  // Check is the PICC of Classic MIFARE type
  if (piccType != MFRC522::PICC_TYPE_MIFARE_MINI &&
      piccType != MFRC522::PICC_TYPE_MIFARE_1K &&
      piccType != MFRC522::PICC_TYPE_MIFARE_4K)
  {
    Serial.println(F("CardReader::readRFIDCard:Your tag is not of type MIFARE Classic."));
    result.setError("Error your tag is not of type MIFARE Classic");
    return result;
  }

  Serial.print(F("CardReader::readRFIDCard:The NUID tag is:"));
  printHex(board.uid.uidByte, board.uid.size);
  Serial.println();

  uint16_t count = 0;
  for (byte sector = 0; sector < SECTORCOUNT; sector++)
  {
#ifdef INFO
    Serial.println("");
    Serial.print("CardReader::readRFIDCard:----------------------------- Sector");
    printHex(&sector, 1);
    Serial.println(" ------------------------------");
#endif
    for (byte line = 0; line < BLOCKPERSECTOR; line++)
    {
      byte buffer[BLOCKSIZE];
      memset(buffer, 0, BLOCKSIZE * sizeof(byte));
#ifdef DEBUG
      Serial.print("CardReader::readRFIDCard:buffer:               ");
      printHex(buffer, BLOCKSIZE);
      Serial.println();
#endif
      byte numBlock = BLOCKPERSECTOR * sector + line;
      readBlock(numBlock, buffer);
#ifdef INFO
      Serial.print("CardReader::readRFIDCard:line : ");
      Serial.print(line);
      Serial.print(" Block : ");
      printHex(&numBlock, 1);
      Serial.print("  ");
      printHex(buffer, BLOCKSIZE);
      Serial.print("  ");
#endif
      for (uint8_t i = 0; i < BLOCKSIZE; i++)
      {
        if (sector > 0)
        {
          if (line != 3)
          {
            payload[count] = buffer[i];
            count++;
          }
        }
#ifdef INFO
        Serial.print(" ");
        Serial.write(buffer[i]);
#endif
      }
#ifdef INFO
      Serial.println();
#endif
    }
#ifdef INFO
    Serial.print("count : ");
    Serial.println(count);
#endif
  }
#ifdef INFO
  Serial.println();
#endif

  char message[PAYLOAD_SIZE] = {};
  for (int i = 0; i < count; i++)
  {
    if (i > 1)
    {
      message[i - 2] = payload[i];
    }
  }

  result = convertMessage(message);
  if (result.error().length() == 0)
  {
    Serial.print(F("CardReader::readRFIDCard:color : "));
    Serial.println(result.color());

    Serial.print(F("CardReader::readRFIDCard:format: "));
    Serial.println(result.format());
  }
  else
  {
    Serial.println(F("CardReader::readRFIDCard:Sending error"));
    result.setError("Error reading card");
  }
  Serial.println();

#ifdef DEBUG
  Serial.println("CardReader::readRFIDCard:Stoping card reader");
#endif
  shutdownReader(reader);
  return result;
}

void CardReader::shutdownAllReaders()
{
  for (uint16_t reader = 0; reader < countCardReader; reader++)
  {
    shutdownReader(reader);
  }
}

void CardReader::shutdownReader(uint16_t reader)
{
  selectReader(reader);
  // Halt PICC
  board.PICC_HaltA();
  // Stop encryption on PCD
  board.PCD_StopCrypto1();
  board.PCD_SoftPowerDown();
}

void CardReader::selectReader(uint16_t reader)
{
  // selection du lecteur par le multiplexeur
#ifdef DEBUG
  Serial.print("CardReader::Select reader to call : ");
  Serial.print(reader);
  Serial.print(" -> 0x");
  Serial.print(bitRead(reader, 3) == 0 ? LOW : HIGH);
#endif
  digitalWrite(MULTIPLEXADR2, bitRead(reader, 3) == 0 ? LOW : HIGH);

#ifdef DEBUG
  Serial.print(bitRead(reader, 2) == 0 ? LOW : HIGH);
#endif
  digitalWrite(MULTIPLEXADR2, bitRead(reader, 2) == 0 ? LOW : HIGH);

#ifdef DEBUG
  Serial.print(bitRead(reader, 1) == 0 ? LOW : HIGH);
#endif
  digitalWrite(MULTIPLEXADR1, bitRead(reader, 1) == 0 ? LOW : HIGH);

#ifdef DEBUG
  Serial.print(bitRead(reader, 0) == 0 ? LOW : HIGH);
#endif
  digitalWrite(MULTIPLEXADR0, bitRead(reader, 0) == 0 ? LOW : HIGH);
#ifdef DEBUG
  Serial.println();
#endif
}

void CardReader::readBlock(byte index, byte *buffer)
{
  MFRC522::MIFARE_Key key;
  MFRC522::StatusCode status;

  switch (index)
  {
  case 0:
  case 1:
  case 2:
  case 3:
    memcpy(key.keyByte, keyAArray, MFRC522::MF_KEY_SIZE);
    break;
  default:
    memcpy(key.keyByte, keyBArray, MFRC522::MF_KEY_SIZE);
    break;
  }
#ifdef DEBUG
  Serial.print("CardReader::readBlock:Using the following key:");
  printHex(key.keyByte, MFRC522::MF_KEY_SIZE);
  Serial.println();
#endif

  status = board.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, index, &key, &board.uid); //line 834 of MFRC522.cpp file
  if (status != MFRC522::STATUS_OK)
  {
#ifdef INFO
    Serial.print(F("CardReader::readBlock:Authentication failed: "));
    Serial.println(F(board.GetStatusCodeName(status)));
#endif
  }
  else
  {
    //initialisation du buffer de block
    byte blockSize = BLOCKSIZE + 2;
    byte blockBuffer[blockSize];
    memset(blockBuffer, 0, blockSize * sizeof(byte));

    status = board.MIFARE_Read(index, blockBuffer, &blockSize);
    if (status != MFRC522::STATUS_OK)
    {
#ifdef INFO
      Serial.print(F("CardReader::readBlock:Reading failed: "));
      Serial.println(F(board.GetStatusCodeName(status)));
#endif
    }
    else 
    {
#ifdef INFO
      Serial.print("CardReader::readBlock:blockBuffer:             ");
      printHex(blockBuffer, BLOCKSIZE);
      Serial.println();
#endif
    }
    memcpy(buffer, blockBuffer, BLOCKSIZE);
  }
#ifdef DEBUG
  Serial.print("CardReader::readBlock:finalBuffer:             ");
  printHex(buffer, BLOCKSIZE);
  Serial.println();
#endif
}

RfidData CardReader::convertMessage(char *message)
{
  RfidData result = RfidData();
  jsonDocument.clear();

#ifdef DEBUG
  Serial.println("CardReader::convertMessage:");
#endif
  FOUND_MESSAGE decodedMessage = NDEF().decode_message((uint8_t *)message);

  if (!decodedMessage.error)
  {
    Serial.print(F("CardReader::convertMessage:type : "));
    Serial.println(decodedMessage.type);
    Serial.print(F("CardReader::convertMessage:format : "));
    Serial.println(decodedMessage.format);
    Serial.print(F("CardReader::convertMessage:payload : "));
    Serial.println((char *)decodedMessage.payload);

#ifdef DEBUG
    Serial.println("CardReader::convertMessage:deserialization:");
#endif
    // Deserialize the JSON document
    DeserializationError error = deserializeJson(jsonDocument, (char *)decodedMessage.payload);

    // Test if parsing succeeds.
    if (error)
    {
      Serial.print(F("CardReader::convertMessage:deserialization failed: "));
      Serial.println(error.c_str());
      result.setError(error.c_str());
    }
    else
    {
      Serial.println(F("CardReader::convertMessage:formating content:"));
      result.setColor(jsonDocument["color"]);
      result.setFormat(jsonDocument["format"]);
    }
  }
  else
  {
    Serial.println(F("CardReader::Sending error reading tag:"));
    result.setError("error reading tag");
  }
  return result;
}

byte *CardReader::longToByteArray(long inLong)
{
#ifdef DEBUG
  Serial.println("CardReader::longToByteArray");
#endif
  byte *outArray = {};
  outArray[0] = inLong;
  outArray[1] = (inLong >> 8);
  outArray[2] = (inLong >> 16);
  outArray[3] = (inLong >> 24);
  return outArray;
}

/**
* Helper routine to dump a byte array as hex values to Serial.
*/
void CardReader::printHex(byte *buffer, byte bufferSize)
{
  for (byte i = 0; i < bufferSize; i++)
  {
    Serial.print(F(buffer[i] < 0x10 ? " 0" : " "));
    Serial.print(buffer[i], HEX);
  }
}

/**
* Helper routine to dump a byte array as char values to Serial.
*/
void CardReader::printChar(byte *buffer, byte bufferSize)
{
  for (byte i = 0; i < bufferSize; i++)
  {
    Serial.write(buffer[i]);
  }
}

/**
* Helper routine to dump a byte array as dec values to Serial.
*/
void CardReader::printDec(byte *buffer, byte bufferSize)
{
  for (byte i = 0; i < bufferSize; i++)
  {
    Serial.print(F(buffer[i] < 0x10 ? " 0" : " "));
    Serial.print(buffer[i], DEC);
  }
}