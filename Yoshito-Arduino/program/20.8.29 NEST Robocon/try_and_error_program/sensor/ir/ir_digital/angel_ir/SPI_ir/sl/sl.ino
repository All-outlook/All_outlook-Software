#include <SPI.h>

#define IR1 2
#define IR3 4
#define IR5 6
#define IR7 8
#define IR9 A0
#define IR11 A2
#define IR13 A4
#define IR15 A6
long duration1; //unsigned アンサインド
long duration3;
long duration5;
long duration7;
long duration9;
long duration11;
long duration13;
long duration15;
long duration1of15;
long duration13of15;
long duration1of3;
long duration5of3;
long duration9of7;
long duration5of7;
long duration9of11;
long duration13of11;
int mytimeout = 1725;

int x_axis;
int y_axis;
int knob;
#define PI 3.141592653589793
int degree;

void setup() {
  SPCR |= bit(SPE);
  pinMode(MISO, OUTPUT);
  SPI.attachInterrupt();
  Serial.begin(9600);
  pinMode(IR1, INPUT);
  pinMode(IR3, INPUT);
  pinMode(IR5, INPUT);
  pinMode(IR7, INPUT);
  pinMode(IR9, INPUT);
  pinMode(IR11, INPUT);
  pinMode(IR13, INPUT);
  pinMode(IR15, INPUT);
}

void loop() {
  duration1 = pulseIn(IR1, LOW, mytimeout);
  duration3 = pulseIn(IR3, LOW, mytimeout);
  duration5 = pulseIn(IR5, LOW, mytimeout);
  duration7 = pulseIn(IR7, LOW, mytimeout);
  duration9 = pulseIn(IR9, LOW, mytimeout);
  duration11 = pulseIn(IR11, LOW, mytimeout);
  duration13 = pulseIn(IR13, LOW, mytimeout);
  duration15 = pulseIn(IR15, LOW, mytimeout);

  duration1of15 = sin(PI / 4) * duration15; //45°
  duration13of15 = cos(PI / 4) * duration15;
  duration1of3 = sin(PI * 3 / 4) * duration3; //135°
  duration5of3 = cos(PI * 3 / 4) * duration3 * -1;
  duration9of7 = sin(PI * 5 / 4) * duration7 * -1; //225°
  duration5of7 = cos(PI * 5 / 4) * duration7 * -1;
  duration9of11 = sin(PI * 7 / 4 ) * duration11 * -1; //315°
  duration13of11 = cos(PI * 7 / 4) * duration11;

  long update_duration1 = duration1 * 2 + duration1of15 + duration1of3; //duration15が生きていないため、duration1を*2する
  long update_duration5 = duration5 + duration5of3 + duration5of7;
  long update_duration9 = duration9 + duration9of7 + duration9of11;
  long update_duration13 = duration13 * 2 + duration13of11 + duration13of15; //duration15が生きていないため、duration13を*2する

  y_axis = update_duration1 - update_duration9;
  x_axis = update_duration13 - update_duration5;

  degree = (atan2((y_axis), (x_axis)) * 180 / PI);

  if (degree < 0) {
    degree = degree + 360;
  }

  //long pre_distance = pow(x_axis, 2) + pow(y_axis, 2);
  //Serial.println(pre_distance);
  //long distance = (sqrt(pre_distance)); 　
  long distance = sqrt(pow(x_axis, 2) + pow(y_axis, 2));

  /*Serial.print("degree:"); Serial.print(degree); Serial.print("° / ");
    //Serial.print("distance:"); Serial.print(distance); Serial.print("cm / ");
    Serial.print("x_axis:"); Serial.print(x_axis); Serial.print(", ");
    Serial.print("y_axis:"); Serial.println(y_axis);*/

  /*Serial.print("1of15:"); Serial.print(duration1of15); Serial.print(", ");
    Serial.print("13of15:"); Serial.print(duration13of15); Serial.print(", ");
    Serial.print("1of3:"); Serial.print(duration1of3); Serial.print(", ");
    Serial.print("5of3:"); Serial.print(duration5of3); Serial.print(", ");
    Serial.print("9of7:"); Serial.print(duration9of7); Serial.print(", ");
    Serial.print("5of7:"); Serial.print(duration5of7); Serial.print(", ");
    Serial.print("9of11:"); Serial.print(duration9of11); Serial.print(", ");
    Serial.print("13of11:"); Serial.print(duration13of11); Serial.println(", ");

    Serial.print("A:"); Serial.print(duration1); Serial.print(", ");
    Serial.print("C:"); Serial.print(duration3); Serial.print(", ");
    Serial.print("E:"); Serial.print(duration5); Serial.print(", ");
    Serial.print("G:"); Serial.print(duration7); Serial.print(", ");
    Serial.print("I:"); Serial.print(duration9); Serial.print(", ");
    Serial.print("K:"); Serial.print(duration11); Serial.print(", ");
    Serial.print("M:"); Serial.print(duration13); Serial.print(", ");
    Serial.print("O:"); Serial.println(duration15);*/
  // delay(750);
  Serial.println(knob);
}

ISR(SPI_STC_vect) {
  knob = SPDR; //konbからきた値をrxdataに入れる
  SPDR = 45; //knobからきた値(P)を送り返す
}
