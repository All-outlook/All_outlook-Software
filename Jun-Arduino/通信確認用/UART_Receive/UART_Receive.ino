/**********************************************
  Arduino UART Receive (Master)
**********************************************/

//#include <SoftwareSerialParity.h>
//SoftwareSerialParity mySerial(68, 49); // RX, TX

void setup() {
  Serial.begin(38400);
  Serial3.begin(38400);
  //pinMode(68, INPUT);

}

void loop() {
  if (Serial3.available()) {
    Serial.println(Serial3.read());
  }
}
