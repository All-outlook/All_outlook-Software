//#include <SPI.h>
#include <SoftwareSerial.h>

#define C_BORDER_WHITE_LINE 700
//スーパーチーム70
//練習コート 250
//試合コート 300
//パドックコート 500

const int A_PIN = 2;
const int B_PIN = 3;const int C_PIN = 4;
const int LED_PIN = 5;
const int LED_NUM = 32;
const int READ_PIN[] = {A0, A1, A2, A3};



int line_value[32];

SoftwareSerial LINESerial(10, 11); //rx,tx


void setup() {
//  Serial.begin(115200);
  LINESerial.begin(115200);
//  Serial.println("hello);
  pinMode(10, OUTPUT);
  F_line_setup();

}


int go_angle;
float angle_time;

void loop() {
  F_time_read();
  F_pixle_setup(250, 1, 1);

  for (int id = 0; id <= 7; id++) {
    F_line_choice(id);
    line_value[id] = analogRead(READ_PIN[0]);
    line_value[id + 8] = analogRead(READ_PIN[1]);
    line_value[id + 16] = analogRead(READ_PIN[2]);
    line_value[id + 24] = analogRead(READ_PIN[3]);
  }
    line_value[28] = 0;

  //もとの値
  int best_value = 0;
  int best_id = 0;
  //  Serial.print("Moto_value       : ");
  for (int id = 0; id <= 31; id++) {
    best_value = max(best_value, line_value[id]);
    if (best_value == line_value[id]) {
      best_id = id;
    }
  }
  

  if (angle_time == 0) {
    if (best_value >= C_BORDER_WHITE_LINE) {
      go_angle = (best_id * 11.25);
      angle_time = F_time_goal(200);
    } else {
      go_angle = 0;
    }
  }

  if (angle_time <= F_time_get()) {
    angle_time = 0;
  }



  LINESerial.write(go_angle /2 );
  LINESerial.flush();
  Serial.println(go_angle);
}
