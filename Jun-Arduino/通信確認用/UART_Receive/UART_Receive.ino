//void setup() {
//  Serial.begin(115200);
//  Serial1.begin(115200);
//  //pinMode(8, INPUT);
//
//}
//
//void loop() {
//  if (Serial1.available()) {
//    Serial.write(Serial1.read());
//  }
//}


#include <SoftwareSerial.h>
SoftwareSerial mySerial(66, 69); // RX, TX

void setup() {
  Serial.begin(115200);
  mySerial.begin(38400);
  pinMode(8, INPUT);

}

void loop() {
  if (mySerial.available()) {
    Serial.println(mySerial.read());
  }
//  for (int i = 0; i <= 100; i++) {
//    mySerial.write(i);
//  }
}
