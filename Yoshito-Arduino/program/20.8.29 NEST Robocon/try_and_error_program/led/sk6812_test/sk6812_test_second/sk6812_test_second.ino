/*虹色ＬＥＤ制御
 *2021.05.09*/

#include <Adafruit_NeoPixel.h>

const int DIN_PIN = 10; // D10
const int LED_COUNT = 4; // Number of LEDs

Adafruit_NeoPixel pixels(LED_COUNT, DIN_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin();
}

uint32_t red = pixels.Color(128, 0, 0);
uint32_t orange = pixels.Color(128, 82, 0);
uint32_t yellow = pixels.Color(128, 128, 0);
uint32_t green = pixels.Color(0, 128, 0);
uint32_t cyan = pixels.Color(0, 128, 128);
uint32_t blue = pixels.Color(0, 0, 128);
uint32_t purple = pixels.Color(128, 0, 128);
uint32_t rainbow_color[] = {red, orange, yellow, green, cyan, blue, purple};
int rainbow_index[]={6, 5, 4, 3, 2, 1, 0,};

void loop() {
  for(int i = 0; i < LED_COUNT; i++){
    
    pixels.clear();
    for(int j=0; j<7; j++){
      rainbow_index[j] = i + 6 - j;
      if(rainbow_index[j] >= LED_COUNT)
rainbow_index[j] -= LED_COUNT;

     pixels.setPixelColor(rainbow_index[j], rainbow_color[j]);
    }
    pixels.show();
    delay(200); 
 }
}
