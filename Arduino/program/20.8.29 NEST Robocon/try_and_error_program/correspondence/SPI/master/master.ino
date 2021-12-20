#include<tinySPI.h>
int knob = 0;

void setup() {
  SPI.begin();
  pinMode(53, OUTPUT);
  digitalWrite(53, HIGH);
}

void loop() {
  int IR_recive;
  byte knob = 'i';
  digitalWrite(53, LOW);
  SPI.transfer(knob);
  digitalWrite(53, HIGH);


  delayMicroseconds(100);

  digitalWrite(53, LOW);
  IR_recive = SPI.transfer(0);
  digitalWrite(53, HIGH);

  Serial.println(IR_recive);
}
