#include <SoftwareSerialParity.h>
#include <Adafruit_NeoPixel.h>
const int A_PIN = 2;
const int B_PIN = 3;
const int C_PIN = 4;
const int AMP_PIN[] = {A0, A1, A2, A3}; //AMP = Analog Multi Plexor
SoftwareSerialParity LINESerial(7, 10); //rx,tx

const int LED_PIN = 5;
const int C_LED_count = 32;
Adafruit_NeoPixel pixels(C_LED_count, LED_PIN, NEO_GRB + NEO_KHZ800);

int id;
int line_value[32];
const int C_line_threshold = 500;
int line_digits[32];
int line_min[32];
int line_max[32];
int smallest;
int biggest;
int line_degree;
unsigned long line_time = 0;
const unsigned long diagonal_time = 1000; //1000
const unsigned long width_time = 300; //300
int false_digits = 0;
int degree;
int false_degree;
int go_degree;

void setup() {
  F_time_read();
  Serial.begin(115200);
  LINESerial.begin(38400, ODD);
  pinMode(10, OUTPUT);
  F_AMP_setup();
  F_LED_setup(60, 60, 60);
}

void loop() {
  F_time_read();
  //  Serial.print('t');
  //  Serial.print(F_time_get());
  //  Serial.print(",");

  F_LED_loop(128, 1, 1);
  for (int id = 0; id <= 7; id++) {
    F_line_choice(id);
    line_value[id] = analogRead(AMP_PIN[0]); //0-7
    line_value[id + 8] = analogRead(AMP_PIN[1]); //8-15
    line_value[id + 16] = analogRead(AMP_PIN[2]); //15-23
    line_value[id + 24] = analogRead(AMP_PIN[3]); //24-31
  }
  line_value[28] = 0; //This is incompetence!!!!n

  //  for (id = 0; id <= 31; id++) { //Please comment here as well.
  //    Serial.print(line_value[id]);
  //    Serial.print(",");
  //  } //Please comment here as well.

  for (id = 0; id <= 31; id++) {
    if (line_value[id] >= C_line_threshold) {
      line_digits[id] = 1;
    } else {
      line_digits[id] = 0;
    }
    //        Serial.print(line_digits[id]);
    //        Serial.print(",");
  }
  for (id = 0; id <= 31; id++) {
    if (line_digits[id] == 1) {
      line_min[id] = id;
      line_max[id] = id;
    } else {
      line_min[id] = 31;
      line_max[id] = 0;
    }
  }

  smallest = 31;
  biggest = 0;
  for (id = 0; id <= 31; id++) {
    smallest = min(smallest, line_min[id]);
    biggest = max(biggest, line_max[id]);
  }
  Serial.print(smallest);
  Serial.print(",");
  Serial.print(biggest);
  Serial.print(",");

  float line_value;
  if (biggest - smallest > 16) {
    line_value = (biggest + smallest) / 2 + 16;
    if (line_value <= 32) {
      line_value -= 32;
    }
  } else if (0 < biggest - smallest & biggest - smallest <= 16 ) {
    line_value = (biggest + smallest) / 2;
  } else if (smallest == 31 & biggest == 0) {
    line_value = -1;
  }
  line_degree = round(line_value * 11.25);

  if (line_degree == 0) {
    line_degree = 360;
  } else if (line_degree > 360) {
    line_degree -= 360;
  } else if (line_degree < 0 & line_degree != -11) {
    line_degree += 360;
  } else if (line_degree == -11) {
    line_degree = 0;
  }

  if (line_degree == 0) { //in the court
    degree = 180;
  } else if (23 <= line_degree & line_degree < 58) { //The white line is in the higher right corner.
    false_degree = 203;
    false_digits = 1;
    line_time = F_time_goal(1000);
  } else if (58 <= line_degree & line_degree < 113) { //The white line is near 90 degrees.
    false_degree = 270;
    false_digits = 1;
    line_time = F_time_goal(300);
  }  else if (113 <= line_degree & line_degree < 158) { //The white line is in the lower right corner.
    false_degree = 338;
    false_digits = 1;
    line_time = F_time_goal(1000);
  } else if (158 <= line_degree & line_degree < 203) { //The white line is near 180 degrees.
    degree = 0;
  } else if (203 <= line_degree & line_degree < 258) { //The white line is in the lower left corner.
    false_degree = 23;
    false_digits = 1;
    line_time = F_time_goal(1000);
  }  else if (258 <= line_degree & line_degree < 303) { //The white line is near 270 degrees.
    false_degree = 90;
    false_digits = 1;
    line_time = F_time_goal(300);
  } else if (303 <= line_degree & line_degree < 338) { //The white line is in the higher left corner.
    false_degree = 158;
    false_digits = 1;
    line_time = F_time_goal(1000);
  } else if (338 <= line_degree & line_degree <= 360 | 0 < line_degree & line_degree < 23) {
    if (line_digits[3] == 1 | line_digits[4] == 1 | line_digits[28] == 1 | line_digits[29] == 1) {
      degree = 0;
    } else if (line_digits[3] == 0 | line_digits[4] == 0 | line_digits[28] == 0 | line_digits[29] == 0) {
      degree = 360;
    } else if (line_digits[30] == 1 | line_digits[31] == 1 | line_digits[0] == 1 | line_digits[1] == 1 | line_digits[2] == 1) {
      degree = 360;
    }
  }

  if (F_time_get() >= line_time & line_time != 0)
  {
    line_time = 0;
    false_digits = 0;
  }

  if (false_digits == 1) {
    go_degree = false_degree;
  } else {
    go_degree = degree;
  }
  Serial.print(line_degree);
  Serial.print(",");
  Serial.print(degree);

  LINESerial.write(go_degree / 2);
  LINESerial.flush();

  go_degree = 0; //degree reset
  Serial.println();
}
