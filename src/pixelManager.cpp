#include "pixelManager.h"
#include <Adafruit_NeoPixel.h>

int pixelNumber = 0;
Adafruit_NeoPixel pixels = Adafruit_NeoPixel();

PixelManager::PixelManager(uint16_t pixelNb) {
  pixelNumber = pixelNb;
}

PixelManager::~PixelManager() {
}

void PixelManager::init() {
  Serial.println("PixelManager::Pixel manager initialisation...");

  // configuration Adafruit_NeoPixel
  Serial.println("PixelManager::Pixel manager setting parameters...");
  pixels.updateLength(pixelNumber);
  pixels.setPin(PIXELDATAPIN);
  pixels.updateType(NEO_GRB + NEO_KHZ800);

  Serial.println("PixelManager::Pixel manager starting...");
  pixels.begin();
}

void PixelManager::switchOffAllPixels() {
  Serial.println("PixelManager::Shuttingdown all pixels...");
  for(int i=0; i<pixelNumber; i++) {
    switchOffPixel(i);
  }
}

void PixelManager::switchOffPixel(uint16_t pixelNum) {
  Serial.print("PixelManager::shuttingdown pixel:");
  Serial.println(pixelNum);
  pixels.clear();
  pixels.setPixelColor(pixelNum, 0, 0, 0);
  pixels.show();
}

void PixelManager::setPixelColor(uint16_t pixelNum, uint32_t pixelColor) {
  Serial.print("PixelManager::Starting pixel:");
  Serial.print(pixelNum);
  Serial.print(" with color:");
  Serial.println(pixelColor);
  pixels.clear();
  // pixels.setPixelColor(pixelNum, pixelColor);
  pixels.fill(pixelColor);
  pixels.show();
}

void PixelManager::setPixelRGB(uint16_t pixelNum, uint16_t pixelRed, uint16_t pixelGreen, uint16_t pixelBlue) {
  pixels.clear();
  pixels.setPixelColor(pixelNum, pixelRed, pixelGreen, pixelBlue);
  pixels.show();
}

void PixelManager::setPixelText(uint16_t pixelNum, String pixelColorHtml) {
  Serial.print("PixelManager::Starting pixel:");
  Serial.print(pixelNum);
  Serial.print(" with HTML color:");
  Serial.println(pixelColorHtml);
  uint32_t pixelColor = convertHtmlColorToLong(pixelColorHtml);
  setPixelColor(pixelNum, pixelColor);
}

uint32_t PixelManager::convertHtmlColorToLong(String pixelColorHtml) {
  Serial.print("PixelManager::convertHtmlColorToLong:");
  Serial.println(pixelColorHtml);
  char buffer[pixelColorHtml.length() + 1];
  pixelColorHtml.toCharArray(buffer, pixelColorHtml.length() + 1);
  char hexStr[9] = {'0','x','0','0','0','0','0','0','\0'};
  hexStr[2] = buffer[1];
  hexStr[3] = buffer[2];
  hexStr[4] = buffer[3];
  hexStr[5] = buffer[4];
  hexStr[6] = buffer[5];
  hexStr[7] = buffer[6];
  Serial.print("PixelManager::convertHtmlColorToLong:");
  Serial.println(hexStr);
  uint32_t result = strtoul(hexStr, NULL, 16);
  Serial.print("PixelManager::convertHtmlColorToLong:");
  Serial.println(result, HEX);
  return result;
}
