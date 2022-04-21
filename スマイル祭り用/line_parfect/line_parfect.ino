#include <SoftwareSerial.h>
#include <Adafruit_NeoPixel.h>

const int C_line_threshold = 600;


const int A_PIN = 2;
const int B_PIN = 3;
const int C_PIN = 4;
const int AMP_PIN[] = {A0, A1, A2, A3}; //AMP = Analog Multi Plexor
SoftwareSerial LINESerial(10, 11); //rx,tx

const int LED_PIN = 5;
const int C_LED_count = 32;
Adafruit_NeoPixel pixels(C_LED_count, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(115200);
  LINESerial.begin(115200);
  pinMode(10, OUTPUT);
  F_AMP_setup();
  for (int r = 0; r < 150; r++) {
    F_LED_setup(r, 150 - r, 0);
    delay(5);
  }
}


int read_value = 0;
int pre_read_value = 0;

bool line_turn = 0;

unsigned long line_time;

void loop() {
  F_time_read();
  F_LED_loop(128, 1, 1);
  //よみとり
  read_value = line_degree_read();
  Serial.print(read_value);
  Serial.print(":");

  // ラインが見えなくなっても一定時間は進もう！！
  if (read_value != 0 && line_turn == 0) {
    //ラインがあって内側にいるとき
    line_time = F_time_goal(300);
  }
  if (read_value == 0 && line_time > F_time_get()) {
    read_value = pre_read_value;
  }
  //------------------------


  if (pre_read_value != 0 && read_value != 0) {
    //前回ラインがあって今回もあるよ
    //前回から+-90の範囲にあるか判定する。
    bool a =  1 <= pre_read_value && pre_read_value <= 90;//1-90
    bool aa = pre_read_value + 270 <= read_value || read_value <= pre_read_value + 90;
    bool b =  90 < pre_read_value && pre_read_value <= 270;//91-270
    bool bb = pre_read_value - 90 <= read_value && read_value <= pre_read_value + 90;
    bool c =  270 < pre_read_value && pre_read_value <= 360;//271-360
    bool cc = pre_read_value - 90 <= read_value || read_value <= pre_read_value - 270;
    bool abc = (a && aa) || (b && bb) || (c && cc);
    if (abc == false) {
      line_turn = 1;
    } else {
      line_turn = 0;
    }

    if (line_turn == 1) {
      read_value += 180;
    }
  }


  if (read_value > 360) {
    read_value = read_value - 360;
  }






  LINESerial.write(read_value / 2);
  LINESerial.flush();
  Serial.print(read_value);

  pre_read_value = read_value;
}


bool judge_degree(int judge_num,int range_down,int range_up){//1<=num<=360
  //範囲内にあるかどうか判定する
  //範囲内:1 範囲外:0
  bool result;
  if(range_down < range_up){
    if(range_down <= judge_num && judge_num <= range_up){
      result = 1;
    }else{
      result = 0;
    }
  }else if(range_down < range_up){
    if(range_down <= judge_num || judge_num <= range_up){
      result = 1;
    }else{
      result = 0;
    }
  }
  return result;
}

int adjust_degree(int num){
  while(num > 360){
    num -= 360;
  }
  while(num < 0){
    num += 360;
  }
  return num;
}
