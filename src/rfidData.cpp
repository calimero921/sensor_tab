
#include "rfidData.h"

RfidData::RfidData() {
  strColor = "";
  strFormat = "";
  strError = "";
}

RfidData::~RfidData() {

}

String RfidData::color() {
  return strColor;
}

void RfidData::setColor(String colorHtml) {
  strColor = colorHtml;
  return;
}

String RfidData::format() {
  return strFormat;
}

void RfidData::setFormat(String format) {
  strFormat = format;
  return;
}

String RfidData::error() {
  return strError;
}

void RfidData::setError(String error) {
  strError = error;
  return;
}

String RfidData::toJson() {
  return "";
}

void RfidData::fromJson(String jsonString) {
  return;
}
