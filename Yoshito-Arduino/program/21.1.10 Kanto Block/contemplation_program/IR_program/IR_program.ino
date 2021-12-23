#include <SPI.h>
const int IR_PIN[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17};
const int LED_PIN[] = {20, 21};
const int LED_CIRCLE1[] = {30, 31, 32, 33, 34, 35, 36, 37};
const int LED_CIRCLE2[] = {40, 41, 42, 43, 44, 45, 46, 47};
long duration[16];
int mytimeout = 1725;
float sine[] = {0, 0.38, 0.71, 0.92, 1, 0.92, 0.71, 0.38, 0, -0.38, -0.71, -0.92, -1, -0.92, -0.71, 0.38};
float cosine[] = {1, 0.92, 0.71, 0.38, 0, -0.38, -0.71, -0.92, -1, -0.92, -0.71, -0.38, 0, 0.38, 0.71, 0.92};
int range[5];
int x_component[16];
int y_component[16];
int x_axis;
int y_axis;
int degree;
int more;
int best_duration;
int best;

void setup() {
  SPCR |= bit(SPE);
  pinMode(MISO, OUTPUT);
  SPI.attachInterrupt();
  Serial.begin(115200);
  for (int id = 0; id <= 2; id++) {
    pinMode(LED_PIN[id], OUTPUT);
    digitalWrite(LED_PIN[id], HIGH);
  }
  for (int id = 0; id <= 7; id++) {
    pinMode(LED_CIRCLE1[id], OUTPUT);
    pinMode(LED_CIRCLE2[id], OUTPUT);
    digitalWrite(LED_CIRCLE2[id], HIGH);
  }
  for (int id = 0; id <= 15; id++) {
    pinMode(IR_PIN[id], INPUT);
  }
}

void loop() {
  for (int id = 0; id <= 15; id++) {
    duration[id] = pulseIn(IR_PIN[id], LOW, mytimeout);
  }

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
  } else if (best_duration > 0) {
    range[0] = best - 2;
    range[1] = best - 1;
    range[2] = best;
    range[3] = best + 1;
    range[4] = best + 2;
  }

  for (int id = 0; id <= 4; id++) {
    if (range[id] > 15) {
      range[id] -= 16;
    } else if (range[id] < 0) {
      range[id] += 16;
    }
  }

  for (int id = 0; id <= 15; id++) {
    if (id == range[0] | range[1] | range[2] | range[3] | range[4]) {
      x_component[id] = duration[id] * cosine[id];
      y_component[id] = duration[id] * sine[id];
    } else if (id != range[0] | range[1] | range[2] | range[3] | range[4]) {
      x_component[id] = 0;
      y_component[id] = 0;
    }
  }

  x_axis = x_component[0] + x_component[1] + x_component[2] + x_component[3] + x_component[4] + x_component[5] + x_component[6] + x_component[7] +
           x_component[8] + x_component[9] + x_component[10] + x_component[11] + x_component[12] + x_component[13] + x_component[14] + x_component[15];
  y_axis = y_component[0] + y_component[1] + y_component[2] + y_component[3] + y_component[4] + y_component[5] + y_component[6] + y_component[7] +
           y_component[8] + y_component[9] + y_component[10] + y_component[11] + y_component[12] + y_component[13] + y_component[14] + y_component[15];

  degree = (atan2((y_axis), (x_axis)) * 180 / PI);

  if (degree < 0) {
    degree += 360;
  }
  if (x_axis == 0 & y_axis == 0) {
    degree = 0;
  }
  
  LED_shine();
  
  for (int id = 0; id <= 4; id++) {
    Serial.print(range[id]);
    Serial.print(",");
  }
  Serial.print(degree);
  Serial.print("°");
  Serial.println();
  
  for(int id = 0; id <= 4; id++){
    range[id] = 0;
  }
  int half_degree = degree / 2;
  Serial.print(half_degree);
  Serial.print('&');
}
