/*
*/

//#define DEBUG

#ifndef PixelManage_H
#define PixelManager_H

#include "Arduino.h"
#include "readerState.h"

#define PIXELDATAPIN 17

class PixelManager
{
public:
  PixelManager(uint16_t pixelNb);
  ~PixelManager();
  void init();
  void switchOffAllPixels();
  void switchOffPixel(uint16_t pixelNum);
  void setPixelState(ReaderState *readerState);
  void setPixelColor(uint16_t pixelNum, uint32_t pixelColor);
  void setPixelRGB(uint16_t pixelNum, uint16_t pixelRed, uint16_t pixelGreen, uint16_t pixelBlue);
  void setPixelText(uint16_t pixelNum, String pixelColorHtml);

private:
  uint16_t pixelCount;
  uint32_t convertHtmlColorToLong(String color);
};
#endif
