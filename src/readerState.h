

#ifndef ReaderState_H
#define ReaderState_H

#include "Arduino.h"
#include <ArduinoJson.h>
#include "rfidData.h"

//#define DEBUG

class ReaderState
{
public:
  ReaderState(int nbCardReader);
  ~ReaderState();
  boolean setState(uint16_t reader, RfidData *data);
  RfidData getState(uint16_t reader);
  uint16_t count();
  String toJsonString(boolean colorSelector, boolean formatSelector);

private:
  uint16_t countCardReader;
  RfidData *readerState;
};
#endif
