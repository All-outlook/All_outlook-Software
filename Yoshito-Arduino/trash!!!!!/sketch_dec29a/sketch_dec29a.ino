#include <Arduino.h>
const int IR_RX = 66;

int IR_serial;

void setup() {
  Serial.begin(115200);
  Serial3.begin(38400);
  pinMode(IR_RX, INPUT);
}

void loop() {
IR_serial = Serial3.read();
Serial.println(IR_serial);
}
