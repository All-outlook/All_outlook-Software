#include <SPI.h>
const int motor_right[] = {2, 4, 6, 8};
const int motor_left[] = {3, 5, 7, 9};

int MT_speed[4];

#define PI 3.141592653589793
int MT_degree[] = {45, 135, 225, 315};
int MT_degree_speed[4];
int go_degree;

void setup() {
  Serial.begin(38400);
  digitalWrite(SS, HIGH);
  SPI.begin();
  for (int i = 0; i <= 3; i++) {
    pinMode(motor_right[i], OUTPUT);
    pinMode(motor_left[i], OUTPUT);
  }
}

void loop() {
  go_degree = spi();

  for (int id = 0; id <= 3; id += 1) {
    MT_degree_speed[id] = MT_last_speed(MT_degree[id], go_degree);
  }

  for (int id = 0; id <= 3; id += 1) {
    MT_speed[id] = MT_degree_speed[id];
    motor_speed(id, MT_speed[id]);
  }
  Serial.println(go_degree);

}
