//#include <SoftwareSerial.h>
//
//SoftwareSerial LINE_Serial(67, 69); //rx,tx

void F_LINE_setup() {
  Serial1.begin(38400);
}



int line_result;
int LINE_recive;

int F_LINE_get() {
  return line_result;
}


void F_LINE_read() {
//  Serial1.listen();
  while (Serial1.available() > 5) {
    int g = Serial1.read();
  }
  if (Serial1.available()) {
    LINE_recive = Serial1.read();
  }
//  if(LINE_recive > 180 || LINE_recive == 133 || LINE_recive == 148 || LINE_recive == 138 || LINE_recive == 128 || LINE_recive == 158 || LINE_recive == 153 || LINE_recive == 143 || LINE_recive == 168 || LINE_recive == 163 || LINE_recive == 173 || LINE_recive == 178){
//    Serial.print("*****");
//  }
  Serial.print("*****");
  Serial.print(LINE_recive);
  Serial.println("*****");


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
