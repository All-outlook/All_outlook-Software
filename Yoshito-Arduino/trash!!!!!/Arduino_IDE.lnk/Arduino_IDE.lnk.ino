#include <Arduino.h>
#include <Wire.h>

// 1 second = 1,000 millis = 1,000,000 micros
// goal_time(n), n = millis
const int LED_PIN[] = {30, 31, 32, 33};
const int TOGGLE_PIN = 41;
int id;
int toggle_value;
int gyro_degree;
int gyro_speed;
int IR_degree;
int wrap_degree;
int line_digits;
int line_degree;
int either_degree;
int either_speed[4];
char MT_number[] = {'A', 'B', 'C', 'D'};
int MT_speed[4];
int MT_rotate[4];
int pre_MT_rotate[4];
int MT_rest[4];
unsigned long MT_rest_time[4];
unsigned long MT_stop_time[4];
int kicker_value;

void setup() {
  pinMode(TOGGLE_PIN, INPUT);
  for (id = 0; id <= 3; id++) {
    pinMode(LED_PIN[id], OUTPUT);
  }
}

void loop() {
  F_time_read();

  toggle_value = digitalRead(TOGGLE_PIN);
  if (toggle_value == 0)
  {
    for (id = 0; id <= 3; id++)
    {
      digitalWrite(LED_PIN[id], LOW);
    }
  }

    gyro_degree = 0;
    Serial.print('g');
    Serial.print(gyro_degree);
    Serial.print(",");
    gyro_speed = 0;
    Serial.print('a');
    Serial.print(gyro_speed);
    Serial.print(",");

    IR_degree = 0;
    Serial.print('i');
    Serial.print(IR_degree);
    Serial.print(",");
    wrap_degree = 0;
    Serial.print('w');
    Serial.print(wrap_degree);
    Serial.print(",");

    line_digits = 0;
    Serial.print('l');
    Serial.print(line_digits);
    Serial.print(",");
    line_degree = 0;
    Serial.print('s');
    Serial.print(line_degree);
    Serial.print(",");

    if (line_degree != 0 & IR_degree != 0 | line_degree != 0 & IR_degree == 0)
    {
    either_degree = line_degree;
    }
    else if (line_degree == 0 & IR_degree != 0)
    {
    either_degree = IR_degree;
    }
    else if (line_degree == 0 & IR_degree == 0)
    {
    either_degree = 0;
    }
    Serial.print("e");
    Serial.print(either_degree);
    Serial.print(",");
}
