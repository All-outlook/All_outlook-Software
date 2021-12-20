#include <SPI.h>
const int RESET_PIN[] = {2, 3, 4, 5, 6, 7, 8, 9};
const int SS_PIN[] = {53, 54, 59, 58};
void setup() {
  SPI.begin();
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
  for (int id = 0; id <= 3; id++) {
    byte IR_transmission;
    int IR_recive;

    IR_transmission = 10;
    digitalWrite(SS_PIN[id], LOW);
    SPI.transfer(IR_transmission);
    digitalWrite(SS_PIN[id], HIGH);

    IR_transmission = 100;
    digitalWrite(SS_PIN[id], LOW);
    SPI.transfer(IR_transmission);
    digitalWrite(SS_PIN[id], HIGH);
  }
}
