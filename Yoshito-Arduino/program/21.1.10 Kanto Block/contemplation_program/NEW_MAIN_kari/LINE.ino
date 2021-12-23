

#include <SoftwareSerialParity.h>
//const int LINE_SS_PIN = 57;

SoftwareSerialParity LINE_Serial(68, 49); //rx,tx

void F_LINE_setup() {
  LINE_Serial.begin(38400, ODD);
  pinMode(68, INPUT);

}


int LINE_recive = 0;



int F_LINE_read() {
  float LINE_recive;

Serial_error:
  while (LINE_Serial.available() > 5) {
    int g = LINE_Serial.read();
  }
  if (LINE_Serial.available()) {
    LINE_recive = LINE_Serial.read();
  }

  if (LINE_recive > 50) {
    goto Serial_error;
  }
//
//  Serial.print("****");
//  Serial.print(LINE_recive);
//  Serial.print("****");

  //値処理
  int line_result;
  

  if (LINE_recive == 40) {
    line_result = 0;
  } else {
    LINE_recive = LINE_recive * 11.25;

    line_result = LINE_recive + 180;
    line_result %= 360;
  }
  if((line_result == 45 || line_result == 315) || line_result == 225){
    goto Serial_error;
  }

  return line_result;
}
