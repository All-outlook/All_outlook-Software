const int motor_right[] = {2, 4, 6, 8};
const int motor_left[] = {3, 5, 7, 9};

int myspeed = 200;
int MT_move_times = 1000;
int MT_stop_times = 1000;

void setup() {
  for (int i = 0; i <= 3; i++) {
    pinMode(motor_right[i], OUTPUT);
    pinMode(motor_left[i], OUTPUT);
  }
}

void loop() {
  motor_right_func();
  motor_left_func();
}

void motor_right_func() {
  for (int i = 0; i <= 3; i++) {
    analogWrite(motor_right[i], myspeed);
    analogWrite(motor_left[i], 0);
  }
  delay(MT_move_times);
  for (int i = 0; i <= 3; i++) {
    digitalWrite(motor_right[i], HIGH);
    digitalWrite(motor_right[i], HIGH);
  }
  delay(MT_stop_times);
}

void motor_left_func() {
  for (int i = 0; i <= 3; i++) {
    analogWrite(motor_right[i], 0);
    analogWrite(motor_left[i], myspeed);
  }
  delay(MT_move_times);
  for (int i = 0; i <= 3; i++) {
    digitalWrite(motor_right[i], HIGH);
    digitalWrite(motor_left[i], HIGH);
  }
  delay(MT_stop_times);
}
