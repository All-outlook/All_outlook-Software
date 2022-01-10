#include <SoftwareSerial.h>
SoftwareSerial IRSerial(23, 53); // RX, TX
const int IR_PIN[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17};
const int LED_PIN[] = {20, 21};
const int LED_CIRCLE1[] = {30, 31, 32, 33, 34, 35, 36, 37};
const int LED_CIRCLE2[] = {40, 41, 42, 43, 44, 45, 46, 47};
long duration[16];
int mytimeout = 1725;
int more;
int best_duration;
int best;
int degree;
int knob;

void setup() {
  Serial.begin(115200);
  IRSerial.begin(115200);
  pinMode(10, OUTPUT);
  for (int id = 0; id <= 2; id++)
  {
    pinMode(LED_PIN[id], OUTPUT);
    digitalWrite(LED_PIN[id], HIGH);
  }
  for (int id = 0; id <= 7; id++)
  {
    pinMode(LED_CIRCLE1[id], OUTPUT);
    pinMode(LED_CIRCLE2[id], OUTPUT);
    digitalWrite(LED_CIRCLE2[id], HIGH);
  }
  for (int id = 0; id <= 15; id++)
  {
    pinMode(IR_PIN[id], INPUT);
  }
}

void loop() {
  for (int id = 0; id <= 15; id++) {
    duration[id] = pulseIn(IR_PIN[id], LOW, mytimeout);
  }

  /*for (int id = 0; id <= 15; id++) {
    Serial.print(id);
    Serial.print(":");
    Serial.print(duration[id]);
    Serial.print(", ");
    }
    Serial.println();*/

  more = 0;
  best_duration = 0;
  for (int id = 0; id <= 15; id++) {
    more = max(more, duration[id]);

    if (more == duration[id]) {
      best = id;
      best_duration = duration[id];
    }
  }

  if (best_duration == 0) {
    best = 20;
  }
  
  degree = best * 22.5;
  if(best == 20){
    degree = 0;
  } else if(best == 0){
    degree = 360;
  }
  
  LED_shine();
  IRSerial.write(degree / 2);
  IRSerial.flush();
  Serial.println();
}
