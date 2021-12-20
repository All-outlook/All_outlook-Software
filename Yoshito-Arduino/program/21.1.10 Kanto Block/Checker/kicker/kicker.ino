#include <Adafruit_NeoPixel.h>
const int KICKER = 22;                  //kicker ancestry
const int KICKER_SWITCH = 24;           //kicker ancestry
const int CAPTURE[] = {A4, A5};         //kicker ancestry
const int CAPTURE_LED = 14;             //kicker ancestry
int LED_count = 2;
Adafruit_NeoPixel pixels(LED_count, CAPTURE_LED, NEO_GRB + NEO_KHZ800);
unsigned long previousMicros = 0;
unsigned long kickerMicros = 0;

void setup() {
  Serial.begin(115200);
  pinMode(KICKER, OUTPUT);
  pinMode(KICKER_SWITCH, OUTPUT);
  pixels.begin();
  for (int id = 0; id <= 1; id++) {
    pinMode(CAPTURE[id], INPUT);
    pixels.setPixelColor(id, pixels.Color(128, 128, 128));
    pixels.show();
  }
}

void loop() {
  time_read();
  Serial.print('t');
  Serial.print(F_time_get());
  Serial.print(",");

  char capture_number[] = {'A', 'B'};
  int capture_value[2];
  int capture_threshold[] = {20, 10};
  int capture_digits[2];
  int kicker_shoot = 0;

  for (int id = 0; id <= 1; id++) {
    capture_value[id] = analogRead(CAPTURE[id]);
    if (capture_threshold[id] < capture_value[id]) {
      capture_digits[id] =  1;
    } else {
      capture_digits[id] = 0;
    }
    Serial.print('d');
    Serial.print(capture_number[id]);
    Serial.print(capture_digits[id]);
    Serial.print(",");
  }


  if (capture_digits[0] == 0 /*& capture_digits[1] == 0 */& F_time_get() - previousMicros >= 1000000) {
    previousMicros = F_time_get();
    kickerMicros = time_goal(10);
    kicker_shoot = 1;
  } else {
    if (kickerMicros >= F_time_get()) { //This is point!
      kicker_shoot = 1;
    } else {
      kicker_shoot = 0;
    }
  }

  if (kicker_shoot == 1) {
    digitalWrite(KICKER_SWITCH, HIGH);
    digitalWrite(KICKER, HIGH);
  } else if (kicker_shoot == 0) {
    digitalWrite(KICKER, LOW);
    digitalWrite(KICKER_SWITCH, LOW);
  }

  Serial.print('k');
  Serial.print(kickerMicros);
  Serial.print('p');
  Serial.print(previousMicros);
  Serial.println();
}
