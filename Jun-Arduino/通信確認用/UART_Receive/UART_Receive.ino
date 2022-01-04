/**********************************************
  Arduino UART Receive (Master)
**********************************************/

#include <SoftwareSerial.h>
SoftwareSerial mySerial(8, 18); // RX, TX

void setup() {
  Serial.begin(38400);
  mySerial.begin(38400);
  pinMode(8, INPUT);

}

void loop() {
  if (mySerial.available()) {
    Serial.println(mySerial.read());
  }
}
