#include <Adafruit_NeoPixel.h>

const int A_PIN = 2;
const int B_PIN = 3;
const int C_PIN = 4;
const int LED_PIN = 5;
const int LED_NUM = 32;
const int READ_PIN[] = {A0, A1, A2, A3};

const int C_BORDER_WHITE_LINE = 500;


int line_value[32];
Adafruit_NeoPixel LINE_PIXLES(LED_NUM, LED_PIN, NEO_GRB + NEO_KHZ800);


void setup() {
  Serial.begin(38400);
  F_line_setup();
  F_pixle_setup(10, 10, 130);
}

void loop() {
  for (int id = 0; id <= 7; id++) {
    F_line_choice(id);
    line_value[id] = analogRead(READ_PIN[0]);
    line_value[id + 8] = analogRead(READ_PIN[1]);
    line_value[id + 16] = analogRead(READ_PIN[2]);
    line_value[id + 24] = analogRead(READ_PIN[3]);
  }

  // 値の判定 0か１か
  int white_line[32];
  int black_line[32];
  
  //  Serial.print("moto__");
  for (int id = 0; id <= 31; id++) {
    line_value[id] = line_value[id] >= C_BORDER_WHITE_LINE ? 1 : 0;
    //    Serial.print(line_value[id]);
    //    Serial.print(", ");

    if (line_value[id] == 1){
      //もしラインがあったら
      white_line[id] = id;
      black_line[id] = 0;
    }else{
      //もしラインがなかったら
    }
  }
  //  Serial.println();



}
