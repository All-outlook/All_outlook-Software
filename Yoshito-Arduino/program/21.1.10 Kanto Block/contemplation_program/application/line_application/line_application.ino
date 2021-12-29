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
const int C_line_threshold = 600;
int line_digits[32];
int line_min[32];
int line_max[32];
int smallest;
int biggest;
int line_degree;
int point;
int return_degree;
int current_degree;
int previous_degree;
int cur_re_degree;
int pre_re_degree;
int false_degree;
int return_digits;
unsigned long line_time;
int degree;


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
  line_value[20] = 0; //This is incompetence!!!!

  //  for (id = 0; id <= 31; id++) { //Please comment here as well.
  //        Serial.print(line_value[id]);
  //        Serial.print(",");
  //  } //Please comment here as well.

  for (id = 0; id <= 31; id++) {
    if (line_value[id] >= C_line_threshold) {
      line_digits[id] = 1;
    } else {
      line_digits[id] = 0;
    }
    //    Serial.print(line_digits[id]);
    //    Serial.print(",");
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
    line_value = (biggest + smallest) / 2;
  } else if (biggest - smallest <= 16 ) {
    line_value = (biggest + smallest) / 2 + 16;
    if (line_value <= 32) {
      line_value -= 32;
    }
  } else if (biggest == 0 & smallest == 31) {
    line_value = -1;
  }
  line_degree = abs(round(line_value * 11.25));

  if (line_degree == 0) {
    line_degree = 360;
  } else if (line_degree == 11) {
    line_degree = 0;
  }
  // Serial.print(line_degree);
  current_degree = line_degree;

  if (abs(current_degree - previous_degree) >= 165 & current_degree != 0 & previous_degree != 0) {
    point = 1;
  } else {
    point = 0;
  }

  if (point == 1) {
    return_degree = previous_degree;
    cur_re_degree = previous_degree;
    if (cur_re_degree != pre_re_degree & cur_re_degree != 0 & pre_re_degree != 0) {
      return_digits = 1;
      false_degree = pre_re_degree;
      line_time = F_time_goal(300);
    }
    pre_re_degree = cur_re_degree;
  }

  if (F_time_get() > line_time & line_time != 0) {
    return_digits = 0;
    return_degree = 0;
    false_degree = 0;
    current_degree = 0;
    previous_degree = 0;
    pre_re_degree = 0;
    cur_re_degree = 0;
    line_time = 0;
  }


  if (line_degree == 0 & return_degree > 0) {
    degree = return_degree;
  } else if (return_digits == 1) {
    degree = false_degree;
  } else {
    degree = 0;
  }

  //Serial.print(pre_re_degree);
  Serial.print(degree);

  LINESerial.write(degree / 2);
  LINESerial.flush();

  previous_degree = current_degree;
  Serial.println();
}
