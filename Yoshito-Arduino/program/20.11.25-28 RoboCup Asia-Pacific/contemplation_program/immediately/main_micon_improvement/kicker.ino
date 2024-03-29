#include <Adafruit_NeoPixel.h>
const int CAPTURE_LED = 14;             //kicker ancestry
const int KICKER = 22;                  //kicker ancestry
const int KICKER_SWITCH = 24;           //kicker ancestry
const int CAPTURE[] = {A4, A5};         //kicker ancestry
const int C_capture_threshold[] = {20, 10};
int LED_count = 2;
Adafruit_NeoPixel pixels(LED_count, CAPTURE_LED, NEO_GRB + NEO_KHZ800);
unsigned long previousMicros = 0;
unsigned long kicker_time = 0;

void F_kicker_setup() {
  pinMode(KICKER, OUTPUT);
  pinMode(KICKER_SWITCH, OUTPUT);
  pixels.begin();
  for (int id = 0; id <= 1; id++) {
    pinMode(CAPTURE[id], INPUT);
    pixels.setPixelColor(id, pixels.Color(0, 0, 0));
//      pixels.setPixelColor(id, pixels.Color(128, 128, 128));
    pixels.show();
  }
}

int F_kicker() {
    for (int id = 0; id <= 1; id++) {
    pinMode(CAPTURE[id], INPUT);
    pixels.setPixelColor(id, pixels.Color(0, 0, 0));
    pixels.show();
  }
  
  char capture_number[] = {'A', 'B'};
  int capture_value[2];
  int capture_digits[2];
  int kicker_shoot = 0;
  int kicker_digits;

  for (int id = 0; id <= 1; id++) {
    capture_value[id] = analogRead(CAPTURE[id]);
    if (C_capture_threshold[id] < capture_value[id]) {
      capture_digits[id] =  1;
    } else {
      capture_digits[id] = 0;
    }
    /*Serial.print('d');
    Serial.print(capture_number[id]);
    Serial.print(capture_digits[id]);
    Serial.print(",");*/
  }

  if (/*capture_digits[0] == 0 & capture_digits[1] == 0 & */F_time_get() - previousMicros >= 10000000) {
    previousMicros = F_time_get();
    kicker_time = F_time_goal(10);
    kicker_shoot = 1;
  } else {
    if (kicker_time >= F_time_get()) { //This is point!
      kicker_shoot = 1;
    } else {
      kicker_shoot = 0;
    }
  }

  if (kicker_shoot == 1) {
    digitalWrite(KICKER_SWITCH, HIGH);
    digitalWrite(KICKER, HIGH);
    kicker_digits = 1;
  } else if (kicker_shoot == 0) {
    digitalWrite(KICKER, LOW);
    digitalWrite(KICKER_SWITCH, LOW);
    kicker_digits = 0;
  }
  return kicker_digits;
}
