#ifndef RfidData_H
#define RfidData_H

#include "Arduino.h"
#include <ArduinoJson.h>

class RfidData {
  public:
    RfidData();
    ~RfidData();
    String color();
    void setColor(String colorHtml);
    String format();
    void setFormat(String format);
    String error();
    void setError(String error);
    String toJson();
    void fromJson(String jsonString);

  private:
    String strColor;
    String strFormat;
    String strError;
};
#endif
