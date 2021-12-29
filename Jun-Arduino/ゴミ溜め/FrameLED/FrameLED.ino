#include <Adafruit_NeoPixel.h>
#define PIN       40 // 信号用のピンを指定
#define FRAMELED 31 // LEDの数を指定

Adafruit_NeoPixel frameLED(FRAMELED, PIN, NEO_GRB + NEO_KHZ800);



void setup() {
  frameLED.begin();
}

void loop() {
  full_led(100, 100, 100);
  delay(100);

  int LEDid = 0;
  while (true) {
    frameLED.clear();
    full_led(2,2,1);
    frameLED.setPixelColor(LEDid, frameLED.Color(250, 0, 10));
    //frameLED.setPixelColor(id+1, frameLED.Color(50, 50, 0));
    LEDid += 1;
    frameLED.show();

    id = id == FRAMELED ? 0 : id;
  }

}




void full_led(int red, int green, int blue) {
  frameLED.clear();
  for (int id = 0; id <= FRAMELED - 1; id += 1) {
    frameLED.setPixelColor(id, frameLED.Color(red, green, blue));
  }
  frameLED.show();
}
