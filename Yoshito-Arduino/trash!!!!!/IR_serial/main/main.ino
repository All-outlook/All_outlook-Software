#include <SoftwareSerialParity.h>
const int RESET_PIN[] = {2, 3, 4, 5, 6, 7, 8, 10};

void setup() {
    for (int id = 0; id <= 7; id++) {
    pinMode(RESET_PIN[id], OUTPUT);
    digitalWrite(RESET_PIN[id], HIGH);
    digitalWrite(RESET_PIN[id], LOW);
    digitalWrite(RESET_PIN[id], HIGH);
  }
  
  Serial.begin(38400);
  Serial3.begin(38400);
  pinMode(66, INPUT);
}

int IR_receive;
void loop() {
  IR_receive = Serial3.read() * 2;
  Serial.println(IR_receive);
  delay(15);
}
