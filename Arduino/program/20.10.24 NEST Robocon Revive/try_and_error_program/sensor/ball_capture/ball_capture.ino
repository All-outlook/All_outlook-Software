#include <Adafruit_NeoPixel.h>

int capture_pin[] = {A4, A5};
int LED_pin = 14;
const int LED_count = 2;
int capture_read[2];
int capture_value[2];
Adafruit_NeoPixel pixels(LED_count, LED_pin, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(38400);
  pixels.begin();
  for (int id = 0; id <= 1; id++) {
    pinMode(capture_pin[id], INPUT);

    pixels.setPixelColor(id, pixels.Color(0, 128, 0));
    pixels.show();
  }
}

void loop() {
  for (int id = 0; id <= 1; id++) {
    capture_read[id] = analogRead(capture_pin[id]);

    if (capture_read[id] >= 100) {
      capture_value[id] = 0;

    } else {
      capture_value[id] = 1;
    }

    Serial.print(id);
    Serial.print(":");
    Serial.print(capture_read[id]);
    Serial.print(", ");
  }
  Serial.println();
}
