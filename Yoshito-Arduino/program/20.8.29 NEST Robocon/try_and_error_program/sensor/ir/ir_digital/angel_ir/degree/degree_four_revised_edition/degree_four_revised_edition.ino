#include <SPI.h>

const int IRpin[] = {2, 6, A0, A4};
const char IRprint[] = {'A', 'B', 'C', 'D'};
long duration[4];
int mytimeout = 1725;

#define PI 3.141592653589793
int x_axis;
int y_axis;
int degree;
long distance;
int alpha_distance;

void setup() {
  SPCR |= bit(SPE);
  pinMode(MISO, OUTPUT);
  SPI.attachInterrupt();
  Serial.begin(38400);
  for (int i = 0; i <= 3; i++) {
    pinMode(IRpin[i], INPUT);
  }
}

void loop() {
  for (int i = 0; i <= 3; i++) {
    duration[i] = pulseIn(IRpin[i], LOW, mytimeout);
  }

  //感度補正(450)
  /*duration[0] *= 1.05;
    duration[1] *= 1.07;
    duration[2] *= 1.02;
    duration[3] *= 0.96;
    duration[4] *= 1.00;
    duration[5] *= 1.00;
    duration[6] *= 1.01;
    duration[7] *= 1.00;*/

  for (int i = 0; i <= 3; i++) {
    if (duration[i] > 0) {
      for (int j = 0; j <= 3; j++) {
        if (duration[j] == 0) {
          duration[j] = 80;
        }
      }
    }
  }

  y_axis = duration[0] - duration[2];
  x_axis = duration[3] - duration[1];

  degree = (atan2((y_axis), (x_axis)) * 180 / PI);

  degree += 270; //正面が0°になるようにする
  if (degree >= 360) {
    degree -= 360;
  }

  degree -= 11; //傾き(11°)をなくす
  if (degree < 0) {
    degree += 360;
  }

  if (x_axis == 0 & y_axis == 0) { //ボール読み取れないとき259°と出るの腹立つため
    degree = 0;
  }

  distance = sqrt(pow(x_axis, 2) + pow(y_axis, 2)), 2;

  /*if (0 <= distance & distance < 10) {
    alpha_distance = 'A';
    } else if (10 <= distance & distance <= 20) {
    alpha_distance = 'B';
    } else if (20 <= distance & distance <= 30) {
    alpha_distance = 'C';
    } else if (30 <= distance & distance <= 40) {
    alpha_distance = 'D';
    } else if (40 <= distance & distance <= 50) {
    alpha_distance = 'E';
    } else if (50 <= distance & distance <= 60) {
    alpha_distance = 'F';
    } else if (60 <= distance & distance <= 70) {
    alpha_distance = 'G';
    } else if (70 <= distance & distance <= 80) {
    alpha_distance = 'H';
    } else if (80 <= distance & distance <= 90) {
    alpha_distance = 'I';
    } else if (90 <= distance) {
    alpha_distance = 'J';*/

  Serial.print("degree:"); Serial.print(degree); Serial.print("° / ");
  Serial.print("distance:"); Serial.print(distance); Serial.print("cm / ");
  Serial.print("x_axis:"); Serial.print(x_axis); Serial.print(", ");
  Serial.print("y_axis:"); Serial.println(y_axis);

  for (int i = 0; i <= 3; i++) {
    Serial.print(IRprint[i]);
    Serial.print(":");
    Serial.print(duration[i]);
    Serial.print(", ");
  }
  Serial.println();
  Serial.println();
}

int  knob;
ISR(SPI_STC_vect) {
  knob = SPDR; //konbからきた値をSPDRに入れる
  SPDR = degree / 2; //角度を送り返す(SPI通信上、255までしか送れないため、半分にして送る。
}
