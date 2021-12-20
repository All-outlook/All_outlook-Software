#include <Adafruit_NeoPixel.h>
const int KICKER = 22;                  //kicker ancestry
const int KICKER_SWITCH = 24;           //kicker ancestry
const int CAPTURE[] = {A4, A5};         //kicker ancestry
const int CAPTURE_LED = 14;             //kicker ancestry
int LED_count = 2;
Adafruit_NeoPixel pixels(LED_count, CAPTURE_LED, NEO_GRB + NEO_KHZ800);
unsigned long period_count;

void setup() {
  Serial.begin(115200);
  pinMode(KICKER, OUTPUT);
  pinMode(KICKER_SWITCH, INPUT);
  pixels.begin();
  for (int id = 0; id <= 1; id++) {
    pinMode(CAPTURE[id], INPUT);
    pixels.setPixelColor(id, pixels.Color(128, 128, 128));
    pixels.show();
  }
}

void loop() {
  if (period_count == 1000) {
    period_count = 0;
  }
  period_count++;

  char capture_number[] = {'A', 'B'};
  int capture_value[2];
  int capture_threshold[] = {20, 5};
  int capture_digits[2];
  int kicker_shoot;
  int kicker_shoot_count;
  int kicker_rest;
  int kicker_rest_count;

  /*for (int id = 0; id <= 1; id++) {
    capture_value[id] = analogRead(CAPTURE[id]);
    if (capture_threshold[id] < capture_value[id]) {
      capture_digits[id] =  1;
    } else {
      capture_digits[id] = 0;
    }
    Serial.print('d');
    Serial.print(capture_number[id]);
    Serial.print(capture_value[id]);
    Serial.print(",");
  }*/
capture_digits[0] = 0;
capture_digits[1] = 0;
 if(capture_digits[0] == 0 & capture_digits[1] == 0){
  kicker_shoot = 1;
  kicker_shoot_count = goal_count(10);
  digitalWrite(KICKER_SWITCH, HIGH);
 }

Serial.print('k');
 if(kicker_shoot == 1){
  kicker_shoot = 0;
  digitalWrite(KICKER, HIGH);
  Serial.print("on");
 } else {
  digitalWrite(KICKER, LOW);
  Serial.print(KICKER_SWITCH, LOW);
  Serial.print("off");
 }

if(period_count == kicker_shoot_count){
  kicker_shoot = 0;
  kicker_shoot_count = 0;
  kicker_rest = 1;
  kicker_rest_count = goal_count(500);
}

if(kicker_rest == 1){
  digitalWrite(KICKER, LOW);
} 

if(period_count == kicker_rest_count){
  kicker_rest = 0;
  kicker_rest_count = 0;
}
  Serial.println();
}
