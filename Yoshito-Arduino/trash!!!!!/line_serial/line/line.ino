#include <SoftwareSerialParity.h>
SoftwareSerialParity LINESerial(7, 10); //rx,tx

void setup() {
  Serial.begin(115200);
  LINESerial.begin(38400, ODD);
  pinMode(10, OUTPUT);
}

int degree = 0;
void loop() {
  if(degree >= 256){
    degree -= 256;
  }
  LINESerial.write(degree / 2);
  LINESerial.flush();
  Serial.println(degree);
  //delay(100);
  degree += 8;
}
