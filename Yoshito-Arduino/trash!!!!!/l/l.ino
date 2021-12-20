const int motor_right[] = {2, 4, 6, 8};
const int motor_left[] = {3, 5, 7, 9};

void setup() {
  for (int i = 0; i <= 3; i++) {
    pinMode(motor_right[i], OUTPUT);
  }
}

void loop() {
  for (int i  = 0; i <= 3; i++) {
  motor_right;
}
  analogWrite(motor_right[i], 170);
}
