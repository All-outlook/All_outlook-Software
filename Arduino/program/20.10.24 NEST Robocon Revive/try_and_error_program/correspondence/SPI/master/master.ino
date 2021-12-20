#include<tinySPI.h>
int knob = 0;

void setup() {
  SPI.begin();
  digitalWrite(SS, HIGH);
}

void loop() {
  knob = analogRead(0);
  digitalWrite(SS, LOW);
  SPI.transfer(knob);
  digitalWrite(SS, HIGH);
}
