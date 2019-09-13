#ifndef RfidData_H
#define RfidData_H

#include "Arduino.h"
#include <ArduinoJson.h>

//#define DEBUG

class RfidData
{
public:
  RfidData();
  ~RfidData();
  void set(RfidData *data);
  String color();
  void setColor(String colorHtml);
  String format();
  void setFormat(String format);
  String error();
  void setError(String error);
  boolean equals(RfidData *data);

private:
  String strColor;
  String strFormat;
  String strError;
};
#endif
