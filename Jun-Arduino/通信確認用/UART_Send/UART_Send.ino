/**********************************************
  Arduino UART Send (Gyro)
**********************************************/

#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 11); // RX, TX

void setup() {
  mySerial.begin(38400);
  Serial.begin(115200);
}

void loop() {
//  for (int i = 0; i <= 100; i++) {
//    mySerial.write(i);
//  }
  if (mySerial.available()) {
    Serial.println(mySerial.read());
  }
}
