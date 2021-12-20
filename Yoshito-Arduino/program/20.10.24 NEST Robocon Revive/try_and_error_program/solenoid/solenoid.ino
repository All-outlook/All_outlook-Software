#include <Adafruit_NeoPixel.h>
const int capture_LED_pin = 14;
const int kicker_pin = 23;
const int capture_pin[] = {A4, A5};

unsigned int period_count = 0;
int LED_count = 2;
int capture_read[2];
int capture_value[2];
int kicker_count;
int kicker_reaction;
Adafruit_NeoPixel pixels(LED_count, capture_LED_pin, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin();
  for (int id = 0; id <= 1; id++) {
    pinMode(capture_pin[id], INPUT);
    pixels.setPixelColor(id, pixels.Color(128, 128, 128));
    //pixels.setPixelColor(id, pixels.Color(0, 128, 32));
    pixels.show();
  }
  pinMode(kicker_pin, OUTPUT);
}

void loop() {
  for (int id = 0; id <= 1; id++) {
    capture_read[id] = analogRead(capture_pin[id]);
    if (capture_read[id] >= 300) {
      capture_value[id] = 1;
    } else {
      capture_value[id] = 0;
    }
  }
  if (capture_value[0] == 1 & capture_value[1] == 1) {
    digitalWrite(kicker_pin, HIGH);
  } else {
    digitalWrite(kicker_pin, LOW);
  }

  Serial.print("kicker:");
  if (kicker_pin == HIGH) {
    Serial.print("on");
  } else {
    Serial.print("off");
  }
  Serial.println();

  if (kicker_pin == HIGH) {
    kicker_count = goal_count(10000);
    kicker_reaction = 1;
  }
  if (kicker_reaction == 1) {
    digitalWrite(kicker_pin, LOW);
  } else if (kicker_reaction == 0) {
  }
  if (period_count == kicker_count) {
    kicker_count = -1;
    kicker_reaction = -1;
  }
}
