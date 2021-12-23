/**********************************************
  Arduino UART Receive (Master)
**********************************************/

#include <SoftwareSerial.h>
SoftwareSerial MT0_Serial =  SoftwareSerial(42, 58);//rx,tx


void setup() {
  MT0_Serial.begin(9600);
}

void loop() {
  for (int n = 0; n <= 100; n++) {
    MT0_Serial.print(n);
    MT0_Serial.print('&');
    MT0_Serial.flush();
  }
}
