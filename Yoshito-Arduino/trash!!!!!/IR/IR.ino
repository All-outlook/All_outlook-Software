#include <SoftwareSerial.h>
SoftwareSerial IRSerial(23, 53); // RX, TX
void setup() {
  IRSerial.begin(38400);
  pinMode(10, OUTPUT);
}

int degree = 200;
void loop() {
  IRSerial.write(degree / 2);
  IRSerial.flush();
}
