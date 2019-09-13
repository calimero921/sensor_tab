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

  //Serial.println("CardReader::Starting SPI...");
  SPI.begin();

  //Serial.println("CardReader::Card reader reset...");
  for (int i = 0; i < countCardReader; i++)
  {
    // selection du Lecteur
    selectReader(i);

    // MFRC522
    //Serial.println("CardReader::Init...");
    board.PCD_Init();
    //Serial.println("CardReader::Version...");
    board.PCD_DumpVersionToSerial();
    //Serial.println("CardReader::Power off...");
    board.PCD_SoftPowerDown();
  }
}

RfidData CardReader::readRFIDCard(int reader)
{
  RfidData result = RfidData();

  char payload[PAYLOAD_SIZE] = {};
  memset(payload, 0, PAYLOAD_SIZE);

  //Serial.print("CardReader::Reader ");
  //Serial.print(reader);
  //Serial.println(" ...");
  selectReader(reader);

  // Look for new cards
  //Serial.println("CardReader::Check card available");
  if (!board.PICC_IsNewCardPresent())
  {
    //Serial.println("CardReader::No new card to read");
    result.setError("Error no new card to read");
    return result;
  }

  // Select one of the cards
  //Serial.println("CardReader::Check card serial");
  if (!board.PICC_ReadCardSerial())
  {
    //Serial.println("CardReader::Your tag has no serial number");
    result.setError("Error Your tag has no serial number");
    return result;
  }

  MFRC522::PICC_Type piccType = board.PICC_GetType(board.uid.sak);
  Serial.print("CardReader::PICC type: ");
  Serial.println(board.PICC_GetTypeName(piccType));

  // Check is the PICC of Classic MIFARE type
  if (piccType != MFRC522::PICC_TYPE_MIFARE_MINI &&
      piccType != MFRC522::PICC_TYPE_MIFARE_1K &&
      piccType != MFRC522::PICC_TYPE_MIFARE_4K)
  {
    Serial.println("CardReader::Your tag is not of type MIFARE Classic.");
    result.setError("Error your tag is not of type MIFARE Classic");
    return result;
  }

  Serial.print("CardReader::The NUID tag is:");
  printHex(board.uid.uidByte, board.uid.size);
  Serial.println();

  byte buffer[18];
  byte numBlock[1] = {0};
  byte sector[1] = {0};
  uint16_t count;

  count = 0;
  for (sector[0] = 0; sector[0] < 16; sector[0]++)
  {
    Serial.println("");
    Serial.print("CardReader::----------------------------- Sector");
    printHex(sector, 1);
    Serial.println(" ------------------------------");
    for (byte line = 0; line < 4; line++)
    {
      numBlock[0] = 4 * sector[0] + line;
      readBlock(numBlock[0], buffer);
      Serial.print("CardReader::line : ");
      Serial.print(line);
      Serial.print(" Block : ");
      printHex(numBlock, 1);
      Serial.print("  ");
      printHex(buffer, 16);
      Serial.print("  ");
      for (uint8_t i = 0; i < 16; i++)
      {
        if ((int)sector[0] > 0)
        {
          if ((int)line != 3)
          {
            payload[count] = buffer[i];
            count++;
          }
        }
        Serial.print(" ");
        Serial.write(buffer[i]);
      }
      Serial.println();
    }
    Serial.print("count : ");
    Serial.println(count);
  }
  Serial.println();

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
    Serial.print("CardReader::color : ");
    Serial.println(result.color());

    Serial.print("CardReader::format : ");
    Serial.println(result.format());
  }
  else
  {
    Serial.println("CardReader::Sending error");
    result.setError("Error reading card");
  }
  Serial.println();

  //Serial.println("CardReader::Stoping card reader");
  // Halt PICC
  board.PICC_HaltA();
  // Stop encryption on PCD
  board.PCD_StopCrypto1();
  board.PCD_SoftPowerDown();
  return result;
}

RfidData CardReader::convertMessage(char *message)
{
  RfidData result = RfidData();
  jsonDocument.clear();

  Serial.println("CardReader::convertMessage:");
  FOUND_MESSAGE decodedMessage = NDEF().decode_message((uint8_t *)message);

  if (!decodedMessage.error)
  {
    Serial.print("CardReader::convertMessage:type : ");
    Serial.println(decodedMessage.type);
    Serial.print("CardReader::convertMessage:format : ");
    Serial.println(decodedMessage.format);
    Serial.print("CardReader::convertMessage:payload : ");
    Serial.println((char *)decodedMessage.payload);

    Serial.println("CardReader::convertMessage:deserialization:");
    // Deserialize the JSON document
    DeserializationError error = deserializeJson(jsonDocument, (char *)decodedMessage.payload);

    // Test if parsing succeeds.
    if (error)
    {
      Serial.print("CardReader::convertMessage:deserialization failed: ");
      Serial.println(error.c_str());
      result.setError(error.c_str());
    }
    else
    {
      Serial.println("CardReader::convertMessage:formating content:");
      result.setColor(jsonDocument["color"]);
      result.setFormat(jsonDocument["format"]);
    }
  }
  else
  {
    Serial.println("CardReader::Sending error reading tag:");
    result.setError("error reading tag");
  }
  return result;
}

void CardReader::shutdownAllReaders()
{
  for (int reader = 0; reader < countCardReader; reader++)
  {
    shutdownReader(reader);
  }
}

void CardReader::shutdownReader(int reader)
{
  selectReader(reader);
  // Halt PICC
  board.PICC_HaltA();
  // Stop encryption on PCD
  board.PCD_StopCrypto1();
  board.PCD_SoftPowerDown();
}

void CardReader::selectReader(int reader)
{
  //Serial.print("CardReader::Select reader to call : ");
  //Serial.print(reader);

  //Serial.print(" -> 0x");
  // selection du lecteur par le multiplexeur
  //Serial.print(bitRead(reader, 3) == 0 ? LOW : HIGH);
  digitalWrite(MULTIPLEXADR2, bitRead(reader, 3) == 0 ? LOW : HIGH);

  //Serial.print(bitRead(reader, 2) == 0 ? LOW : HIGH);
  digitalWrite(MULTIPLEXADR2, bitRead(reader, 2) == 0 ? LOW : HIGH);

  //Serial.print(bitRead(reader, 1) == 0 ? LOW : HIGH);
  digitalWrite(MULTIPLEXADR1, bitRead(reader, 1) == 0 ? LOW : HIGH);

  //Serial.print(bitRead(reader, 0) == 0 ? LOW : HIGH);
  digitalWrite(MULTIPLEXADR0, bitRead(reader, 0) == 0 ? LOW : HIGH);
  //Serial.println();
}

void CardReader::readBlock(byte index, byte *buffer)
{
  MFRC522::MIFARE_Key key;
  MFRC522::StatusCode status;
  byte len = 18;
  byte buffer1[len];

  switch (index)
  {
  case 0:
  case 1:
  case 2:
  case 3:
    for (byte i = 0; i < MFRC522::MF_KEY_SIZE; i++)
    {
      key.keyByte[i] = keyAArray[i];
    }
    break;
  default:
    for (byte i = 0; i < MFRC522::MF_KEY_SIZE; i++)
    {
      key.keyByte[i] = keyBArray[i];
    }
    break;
  }
  // Serial.print(F("Using the following key:"));
  // printHex(key.keyByte, MFRC522::MF_KEY_SIZE);
  //Serial.println();

  status = board.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, index, &key, &(board.uid)); //line 834 of MFRC522.cpp file
  if (status != MFRC522::STATUS_OK)
  {
    Serial.print("CardReader::Authentication failed: ");
    Serial.println(board.GetStatusCodeName(status));
  }
  else
  {
    status = board.MIFARE_Read(index, buffer1, &len);
    if (status != MFRC522::STATUS_OK)
    {
      Serial.print("CardReader::Reading failed: ");
      Serial.println(board.GetStatusCodeName(status));
    }
    else
    {
      for (byte i = 0; i < len; i++)
      {
        buffer[i] = buffer1[i];
      }
    }
  }
}

byte *CardReader::longToByteArray(long inLong)
{
  //Serial.println("CardReader::longToByteArray");
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
    Serial.print(buffer[i] < 0x10 ? " 0" : " ");
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
    Serial.print(buffer[i] < 0x10 ? " 0" : " ");
    Serial.print(buffer[i], DEC);
  }
}
