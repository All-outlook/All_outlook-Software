const int motor_right[] = {2, 4, 6, 8};
const int motor_left[] = {3, 5, 7, 9};

void setup() {
  for (int i = 0; i <= 3; i++) {
    pinMode(motor_right[i], OUTPUT);
  }
  for (int i = 0; i <= 3; i++) {
    pinMode(motor_left[i], OUTPUT);
  }
}

void loop() {
  int MT_id = 0;
  int MT_speed = -120;
  motor_speed(MT_id, MT_speed);
}
