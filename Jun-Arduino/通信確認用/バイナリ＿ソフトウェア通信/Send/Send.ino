#include <SoftwareSerialParity.h>

SoftwareSerialParity IR_Serial(23, 53);//rx,tx

void setup() {
  
  pinMode(23, INPUT);
  pinMode(53, OUTPUT);
  IR_Serial.begin(38400, ODD);
}

void loop() {
  int best = 50;
  IR_Serial.write(best);
  IR_Serial.flush();
}
