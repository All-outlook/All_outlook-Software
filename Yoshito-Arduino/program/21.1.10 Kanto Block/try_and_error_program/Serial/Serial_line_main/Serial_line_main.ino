#include <SoftwareSerialParity.h>

SoftwareSerialParity LINE_Serial(68, 49); //rx,tx
void setup() {
  Serial.begin(115200);
  LINE_Serial.begin(38400, ODD);
  pinMode(68, INPUT);
}

int LINE_recive = 0;

void loop() {
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

  Serial.println(line_result);
}
