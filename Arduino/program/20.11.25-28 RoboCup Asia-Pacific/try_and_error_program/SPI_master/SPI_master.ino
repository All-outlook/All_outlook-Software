#include <SPI.h>
const int RESET_PIN[] = {2, 3, 4, 5, 6, 7, 8, 10};
const int SS_PIN[] = {53, 54, 59, 58};
void setup() {
  SPI.begin();
  Serial.begin(115200);
  for (int id = 0; id <= 7; id++) {
    pinMode(RESET_PIN[id], OUTPUT);
    digitalWrite(RESET_PIN[id], HIGH);
    digitalWrite(RESET_PIN[id], LOW);
    digitalWrite(RESET_PIN[id], HIGH);
  }
  for (int id = 0; id <= 3; id++) {
    pinMode(SS_PIN[id], OUTPUT);
    digitalWrite(SS_PIN [id], HIGH);
  }
}

void loop() {
  //int id = 3;
  int rotate1 = 10;
  int rotate2 = 20;
  int rotate_stop = 30;
  int my_speed = 200;
  int delay_count = 1000;

  for (int id = 0; id <= 3; id++) {
    SPI_rotate_speed(id, rotate1, my_speed);
  }
  delay(delay_count);

  for (int id = 0; id <= 3; id++) {
    SPI_rotate_speed(id, rotate_stop, my_speed);
  }
  delay(delay_count);

  for (int id = 0; id <= 3; id++) {
    SPI_rotate_speed(id, rotate2, my_speed);
  }
  delay(delay_count);

  for (int id = 0; id <= 3; id++) {
    SPI_rotate_speed(id, rotate_stop, my_speed);
  }
  delay(delay_count);
}
