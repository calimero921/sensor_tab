/*
*/

#include "rfidData.h"

// public
RfidData::RfidData()
{
  strColor = "#000000";
  strFormat = "none";
  strError = "";
}

RfidData::~RfidData()
{
}

void RfidData::set(RfidData *data)
{
  strColor = data->color();
  strFormat = data->format();
  strError = data->error();
}

String RfidData::color()
{
  return strColor;
}

void RfidData::setColor(String colorHtml)
{
  strColor = colorHtml;
  return;
}

String RfidData::format()
{
  return strFormat;
}

void RfidData::setFormat(String format)
{
  strFormat = format;
  return;
}

String RfidData::error()
{
  return strError;
}

void RfidData::setError(String error)
{
  strError = error;
  return;
}

boolean RfidData::equals(RfidData *data)
{
#ifdef DEBUG
  Serial.println("RfidData::equals:");
#endif
  boolean result = true;
#ifdef DEBUG
  Serial.print("RfidData::equals:compare >");
  Serial.print(strColor);
  Serial.print("< to >");
  Serial.print(data.color());
  Serial.print("< => ");
#endif
  if (!strColor.equalsIgnoreCase(data->color()))
  {
    result = false;
  }
#ifdef DEBUG
  Serial.println(result);
  Serial.print("RfidData::equals:compare >");
  Serial.print(strFormat);
  Serial.print("< to >");
  Serial.print(data.format());
  Serial.print("< => ");
#endif
  if (!strFormat.equalsIgnoreCase(data->format()))
  {
    result = false;
  }
#ifdef DEBUG
  Serial.println(result);
  Serial.print("RfidData::equals:return ");
  Serial.println(result);
#endif
  return result;
}
