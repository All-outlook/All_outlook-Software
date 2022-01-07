#include <SoftwareSerialParity.h>
SoftwareSerialParity mySerial(10, 11); // RX, TX

void setup() {
  mySerial.begin(9600,ODD);
  Serial.begin(115200);
}
int i = 0;
void loop() {
  for (int in = 0; in < 10; in++) {
    mySerial.write(i);
    delay(5);
  }

  i += 5;
  if (i > 180) {
    i = 0;
  }
}


//#include <SoftwareSerial.h>
//SoftwareSerial mySerial(10, 11); // RX, TX
//
//void setup() {
//  mySerial.begin(9600);
//  Serial.begin(115200);
//}
//int i= 0;
//void loop() {
//  for (int in = 0; in < 10; in++) {
//    mySerial.write(i);
//    delay(5);
//  }
//
//  i += 5;
//  if(i > 180){
//    i = 0;
//  }
//
//
//  //  if (mySerial.available()) {
//  //    Serial.println(mySerial.read());
//  //  }
//}
