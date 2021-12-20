const int motor_forward[] = {2, 4, 6, 8};
const int motor_reversal[] = {3, 5, 7, 9};

void setup() {
  Serial.begin(38400);
  for (int i = 0; i <= 3; i++) {
    pinMode(motor_forward[i], OUTPUT);
  }
  for (int i = 0; i <= 3; i++) {
    pinMode(motor_reversal[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i <= 3; i++) {
    analogWrite(motor_forward[i], 0);
  }
  for (int i = 0; i <= 3; i++) {
    analogWrite(motor_reversal[i], 0);
  }
  motor_forward_func();
  motor_reversal_func();
}

void motor_forward_func() {
  for (int i = 0; i <= 3; i++) {
    analogWrite(motor_forward[i], 150);
  }
  delay(500);
  for (int i = 0; i <= 3; i++) {
    digitalWrite(motor_forward[i], LOW);
  }
  delay(250);
}

void motor_reversal_func() {
  for (int i = 0; i <= 3; i++) {
    analogWrite(motor_reversal[i], 150);
  }
  delay(500);
  for (int i = 0; i <= 3; i++) {
    digitalWrite(motor_reversal[i], LOW);
  }
  delay(250);
}
