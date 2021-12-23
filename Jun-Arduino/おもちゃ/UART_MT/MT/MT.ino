
#include <SoftwareSerial.h>
SoftwareSerial mySerial =  SoftwareSerial(10, 7);//rx,tx
int data = 0;
int led = 13;
 
void setup() {
  pinMode(10, INPUT);
  pinMode(7, OUTPUT);
  pinMode(led, OUTPUT);
  mySerial.begin(9600);
  Serial.begin(38400);
  delay(200);
}
 
void loop() {
  if ( mySerial.available() ) {       // 受信データがあるか？

    String str = mySerial.readStringUntil('&');

    int control_value = str.toInt();

    Serial.println(control_value);
  }else{
    Serial.println("kitenai");
  }
}
