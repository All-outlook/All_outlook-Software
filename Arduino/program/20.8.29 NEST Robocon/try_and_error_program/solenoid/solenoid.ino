#include <Adafruit_NeoPixel.h>
const int capture_LED_pin = 14;
const int kicker_pin = 23;
const int capture_pin[] = {A4, A5};
int LED_count = 2;
int capture_read[2];
int capture_value[2];
int kicker_count;
int kicker_reaction;
Adafruit_NeoPixel pixels(LED_count, capture_LED_pin, NEO_GRB + NEO_KHZ800);

int state = 0;
unsigned long currentMillis = millis();
unsigned long previousMillis = 0;

void setup() {
  Serial.begin(115200);
  pixels.begin();
  for (int id = 0; id <= 1; id++) {
    pinMode(capture_pin[id], INPUT);
    //pixels.setPixelColor(id, pixels.Color(0, 255, 64));
    pixels.setPixelColor(id, pixels.Color(0, 255, 255));
    pixels.show();
  }
  pinMode(kicker_pin, OUTPUT);
}

void loop() {
  for (int id = 0; id <= 1; id++) {
    capture_read[id] = analogRead(capture_pin[id]);
    if (capture_read[id] >= 10) {
      capture_value[id] = 0;
    } else {
      capture_value[id] = 1;
    }
  }
  Serial.print("kicker:");
  
  if (currentMillis - previousMillis >= 1000) {
    if (capture_value[0] == 1 /*& capture_value[1] == 1*/) {
      if (state == 0) {
        digitalWrite(kicker_pin, HIGH);
        Serial.print("on");
        state = 1;
      } else {
        digitalWrite(kicker_pin, LOW);
        Serial.print("off");
        state = 0;
      }
      previousMillis = currentMillis;

    } else {
      if (state == 1) {
        digitalWrite(kicker_pin, LOW);
        state = 0;
        Serial.print("off");
      }
    }
  }
  Serial.println();
}
