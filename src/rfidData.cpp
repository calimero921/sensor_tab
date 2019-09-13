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
  //Serial.println("RfidData::equals:");
  boolean result = true;

  //Serial.print("RfidData::equals:compare >");
  //Serial.print(strColor);
  //Serial.print("< to >");
  //Serial.print(data.color());
  //Serial.print("< => ");
  if (!strColor.equalsIgnoreCase(data->color()))
  {
    result = false;
  }
  //Serial.println(result);

  //Serial.print("RfidData::equals:compare >");
  //Serial.print(strFormat);
  //Serial.print("< to >");
  //Serial.print(data.format());
  //Serial.print("< => ");
  if (!strFormat.equalsIgnoreCase(data->format()))
  {
    result = false;
  }
  //Serial.println(result);

  //Serial.print("RfidData::equals:return ");
  //Serial.println(result);
  return result;
}
