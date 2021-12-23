/**********************************************
  Arduino UART Send (Gyro)
**********************************************/

#include <SoftwareSerialParity.h>
SoftwareSerialParity mySerial(23, 53); // RX, TX

void setup() {
  mySerial.begin(38400,ODD);
}

void loop() {
  for (int i = 0; i <= 100; i++) {
    mySerial.write(i);
  }
}
