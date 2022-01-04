#include <SoftwareSerialParity.h>
const int RESET_PIN[] = {2, 3, 4, 5, 6, 7, 8, 10};
SoftwareSerialParity LINE_Serial(68, 49); //rx,tx
void setup() {
  for (int id = 0; id <= 7; id++) {
    pinMode(RESET_PIN[id], OUTPUT);
    digitalWrite(RESET_PIN[id], HIGH);
    digitalWrite(RESET_PIN[id], LOW);
    digitalWrite(RESET_PIN[id], HIGH);
  }

  Serial.begin(38400);
  LINE_Serial.begin(38400, ODD);
  pinMode(68, INPUT);
}

int LINE_receive;
void loop() {
  LINE_receive = LINE_Serial.read() * 2;
  Serial.println(LINE_receive);
  delay(7);
}
