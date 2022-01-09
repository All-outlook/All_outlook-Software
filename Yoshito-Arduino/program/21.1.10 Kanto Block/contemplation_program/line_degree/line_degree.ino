#include <SoftwareSerial.h>
#include <Adafruit_NeoPixel.h>
const int A_PIN = 2;
const int B_PIN = 3;
const int C_PIN = 4;
const int AMP_PIN[] = {A0, A1, A2, A3}; //AMP = Analog Multi Plexor
SoftwareSerial LINESerial(10, 11); //rx,tx

const int LED_PIN = 5;
const int C_LED_count = 32;
Adafruit_NeoPixel pixels(C_LED_count, LED_PIN, NEO_GRB + NEO_KHZ800);

int id;
int line_value[32];
const int C_line_threshold = 500;
int line_digits[32];
int line_min[32];
int line_max[32];
float smallest = 0.0;
float biggest = 0.0;
int line_degree;

void setup() {
  Serial.begin(115200);
  LINESerial.begin(115200);
  pinMode(10, OUTPUT);
  F_AMP_setup();
  F_LED_setup(60, 60, 60);
}

void loop() {

  F_LED_loop(128, 1, 1);
  for (int id = 0; id <= 7; id++) {
    F_line_choice(id);
    line_value[id] = analogRead(AMP_PIN[0]); //0-7
    line_value[id + 8] = analogRead(AMP_PIN[1]); //8-15
    line_value[id + 16] = analogRead(AMP_PIN[2]); //15-23
    line_value[id + 24] = analogRead(AMP_PIN[3]); //24-31
  }
  line_value[28] = 0; //This is incompetence!!!!

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
  //    Serial.print(smallest);
  //    Serial.print(",");
  //    Serial.print(biggest);
  //    Serial.print(",");

  float line_value;
  if (biggest - smallest > 16) {
    line_value = (biggest + smallest) / 2 + 16;
    if (line_value <= 32) {
      line_value -= 32;
    }
  } else if (0 < biggest - smallest & biggest - smallest <= 16) {
    line_value = (biggest + smallest) / 2;
  } else if (biggest == 0 & smallest == 31) {
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

  LINESerial.write(line_degree / 2);
  LINESerial.flush();
  Serial.print(line_degree);
  line_degree = 0; //line_degree reset
  Serial.println();
}
