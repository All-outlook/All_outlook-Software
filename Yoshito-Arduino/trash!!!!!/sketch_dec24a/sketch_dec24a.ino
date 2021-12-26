#include <Arduino.h>
#include <Wire.h>

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
  F_serial_setup();
  F_flame_setup();
  F_kicker_setup();
  F_reset_setup();
  F_buzzer_setup();
}

void loop() {
  // put your main code here, to run repeatedly:

}
