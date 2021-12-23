#include <Adafruit_NeoPixel.h>

const int FULL_LED = 40;
const int FULL_LED_NUM = 31;
Adafruit_NeoPixel FRAME(FULL_LED_NUM, FULL_LED, NEO_GRB + NEO_KHZ800);

void F_full_led_setup(int r, int g, int b) {
  FRAME.begin();

  FRAME.clear();
  for (int i = 0; i < FULL_LED_NUM; i++) {
    FRAME.setPixelColor(i, FRAME.Color(r, g, b));
  }
  FRAME.show();
}
