/*
*/

#include "pixelManager.h"
#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel pixels = Adafruit_NeoPixel();

PixelManager::PixelManager(uint16_t pixelNb)
{
  pixelCount = pixelNb;
}

PixelManager::~PixelManager()
{
}

void PixelManager::init()
{
#ifdef DEBUG
  Serial.println("PixelManager::Pixel manager initialisation...");
#endif
  // configuration Adafruit_NeoPixel
  pixels.updateLength(pixelCount);
  pixels.setPin(PIXELDATAPIN);
  pixels.updateType(NEO_GRB + NEO_KHZ800);
#ifdef DEBUG
  Serial.println("PixelManager::Pixel manager starting...");
#endif
  pixels.begin();
}

void PixelManager::switchOffAllPixels()
{
#ifdef DEBUG
 Serial.println("PixelManager::Shuttingdown all pixels...");
#endif
 for (int i = 0; i < pixelCount; i++)
 {
   switchOffPixel(i);
 }
}

void PixelManager::switchOffPixel(uint16_t pixelNum)
{
#ifdef DEBUG
  Serial.print("PixelManager::shuttingdown pixel:");
  Serial.println(pixelNum);
#endif
  pixels.clear();
  pixels.setPixelColor(pixelNum, 0, 0, 0);
  pixels.show();
}

void PixelManager::setPixelState(ReaderState *readerState)
{
#ifdef DEBUG
  Serial.println("PixelManager::setPixelState:started");
#endif
  pixels.clear();
#ifdef DEBUG
  Serial.print("PixelManager::setPixelState:readerState.count():");
  Serial.println(readerState->count());
#endif
  for (uint16_t pixel = 0; pixel < readerState->count(); pixel++)
  {
#ifdef DEBUG
    Serial.print("PixelManager::setPixelState:pixel:");
    Serial.println(pixel);
#endif
    String pixelColorHtml = readerState->getState(pixel).color();
#ifdef DEBUG
    Serial.print("PixelManager::setPixelState:pixelColorHtml:");
    Serial.println(pixelColorHtml);
#endif
    uint32_t pixelColor = convertHtmlColorToLong(pixelColorHtml);
#ifdef DEBUG
    Serial.print("PixelManager::setPixelState:pixelColor:");
    Serial.println(pixelColor);
#endif
    pixels.setPixelColor(pixel, pixelColor);
  }
  pixels.show();
#ifdef DEBUG
  Serial.println("PixelManager::setPixelState:finished");
#endif
}

void PixelManager::setPixelColor(uint16_t pixelNum, uint32_t pixelColor)
{
#ifdef DEBUG
  Serial.print("PixelManager::Starting pixel:");
  Serial.print(pixelNum);
  Serial.print(" with color:");
  Serial.println(pixelColor);
#endif
  pixels.clear();
  pixels.setPixelColor(pixelNum, pixelColor);
  pixels.show();
}

void PixelManager::setPixelRGB(uint16_t pixelNum, uint16_t pixelRed, uint16_t pixelGreen, uint16_t pixelBlue)
{
  pixels.clear();
  pixels.setPixelColor(pixelNum, pixelRed, pixelGreen, pixelBlue);
  pixels.show();
}

void PixelManager::setPixelText(uint16_t pixelNum, String pixelColorHtml)
{
#ifdef DEBUG
  Serial.print("PixelManager::Starting pixel:");
  Serial.print(pixelNum);
  Serial.print(" with HTML color:");
  Serial.println(pixelColorHtml);
#endif
  uint32_t pixelColor = convertHtmlColorToLong(pixelColorHtml);
  setPixelColor(pixelNum, pixelColor);
}

uint32_t PixelManager::convertHtmlColorToLong(String pixelColorHtml)
{
#ifdef DEBUG
  Serial.print("PixelManager::convertHtmlColorToLong:");
  Serial.println(pixelColorHtml);
#endif
  char buffer[pixelColorHtml.length() + 1];
  pixelColorHtml.toCharArray(buffer, pixelColorHtml.length() + 1);
  char hexStr[9] = {'0', 'x', '0', '0', '0', '0', '0', '0', '\0'};
  hexStr[2] = buffer[1];
  hexStr[3] = buffer[2];
  hexStr[4] = buffer[3];
  hexStr[5] = buffer[4];
  hexStr[6] = buffer[5];
  hexStr[7] = buffer[6];
#ifdef DEBUG
  Serial.print("PixelManager::convertHtmlColorToLong:");
  Serial.println(hexStr);
#endif
  uint32_t result = strtoul(hexStr, NULL, 16);
#ifdef DEBUG
  Serial.print("PixelManager::convertHtmlColorToLong:");
  Serial.println(result, HEX);
#endif
  return result;
}
