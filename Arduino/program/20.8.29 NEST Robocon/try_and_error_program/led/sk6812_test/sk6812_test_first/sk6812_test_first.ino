/*ＬＥＤ制御
 *2021.05.09*/
 
#include <Adafruit_NeoPixel.h>
 
const int DIN_PIN = 14; // D10
const int LED_COUNT = 2; // LEDの数

Adafruit_NeoPixel pixels(LED_COUNT, DIN_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin();
}

void loop() {
  pixels.clear();
  pixels.setPixelColor(0, pixels.Color(128, 0, 0));
  pixels.show();
  }
