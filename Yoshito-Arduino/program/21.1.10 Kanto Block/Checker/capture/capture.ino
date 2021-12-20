#include <Adafruit_NeoPixel.h>
const int CAPTURE_LED = 14;             //kicker ancestry
const int CAPTURE[] = {A4, A5};         //kicker ancestry
int LED_count = 2;
Adafruit_NeoPixel pixels(LED_count, CAPTURE_LED, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(115200);
  pixels.begin();
  for (int id = 0; id <= 1; id++) {
    pinMode(CAPTURE[id], INPUT);
    pixels.setPixelColor(id, pixels.Color(128, 128, 128));
    pixels.show();
  }

}

void loop() {
  int capture_value[2];
  int capture_digits[2];
  int kicker_shoot = 0;
  int kicker_digits;

  for (int id = 0; id <= 1; id++) {
    capture_value[id] = analogRead(CAPTURE[id]);
    Serial.print(id);
    Serial.print(":");
    Serial.print(capture_value[id]);
    Serial.print(",");
  }
Serial.println();
}
