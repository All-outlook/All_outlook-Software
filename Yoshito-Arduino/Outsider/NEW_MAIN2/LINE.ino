#include <SoftwareSerial.h>

SoftwareSerial LINE_Serial(66, 69); //rx,tx

void F_LINE_setup() {
  LINE_Serial.begin(38400);
  pinMode(66, INPUT);
}



int line_result;
int LINE_recive;

int F_LINE_get() {
  return line_result;
}


void F_LINE_read() {

  while (LINE_Serial.available() > 5) {
    int g = LINE_Serial.read();
  }
  if (LINE_Serial.available()) {
    LINE_recive = LINE_Serial.read();
  }

  Serial.println(LINE_recive);


  //値処理


  if (LINE_recive == 40) {
    line_result = 0;
  } else {
    //    LINE_recive = LINE_recive * 11.25;
    //
    //    line_result = LINE_recive + 180;
    //    line_result %= 360;
    line_result = LINE_recive;
  }

}
