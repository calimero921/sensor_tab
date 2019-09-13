# sensor_tab
ESP32 sensor tab

External libraries : 
* BLEDevice
* BLEServer
* BLEUtils
* BLE2902
* NDEF: utility class to translate NDEF format of rfid card data (updated and corrected)
* Adafruit_NeoPixel: utility class to manage WS2812 led

Internal libraries : 
* cardReader: wrapper for MFRC522 library mixed with HW-178 multiplexing componenent
* readerState: data and utility class to manage reader state based on rfidData class
* rfidData: data and utility class to manage rfid card information
* pixelManager: wrapper for Adafruit Neo Pixel library to manage the set on WS2812 led, based on readerState library

