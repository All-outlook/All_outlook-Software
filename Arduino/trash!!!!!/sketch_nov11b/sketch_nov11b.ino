#include <SPI.h>
const int RESET_PIN[] = {2, 3, 4, 5, 6, 7, 8, 9};
//const int SS_MT[] = {53, 54, 59, 58};
int SS_PIN = 58;
void setup() {
  SPI.begin();
  pinMode(SS_PIN, OUTPUT);
  digitalWrite(SS_PIN, HIGH);
  for (int id = 0; id <= 7; id++) {
    pinMode(RESET_PIN[id], OUTPUT);
    digitalWrite(RESET_PIN[id], HIGH);
    digitalWrite(RESET_PIN[id], LOW);
    digitalWrite(RESET_PIN[id], HIGH);
  }
}

void loop() {
  byte IR_transmission;
  int IR_recive;

  IR_transmission = 10;
  digitalWrite(SS_PIN, LOW);
  SPI.transfer(IR_transmission);
  digitalWrite(SS_PIN, HIGH);

  IR_transmission = 200;
  digitalWrite(SS_PIN, LOW);
  SPI.transfer(IR_transmission);
  digitalWrite(SS_PIN, HIGH);
}
