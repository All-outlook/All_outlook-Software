const int GYRO_RESET = 9;
const int TOGGLE_PIN = 41;
const int LED_PIN[] = {30, 31, 32, 33};

int toggle_value;
void setup() {
  pinMode(GYRO_RESET, OUTPUT);
  pinMode(TOGGLE_PIN, INPUT);
  for (int id = 0; id <= 3; id++) {
    pinMode(LED_PIN[id], OUTPUT);
  }

  digitalWrite(GYRO_RESET, HIGH);
  digitalWrite(GYRO_RESET, LOW);
  digitalWrite(GYRO_RESET, HIGH);
}

void loop() {
  toggle_value = digitalRead(TOGGLE_PIN);
  if (toggle_value == 0) {
    for (int id = 0; id <= 3; id++) {
      digitalWrite(LED_PIN[id], HIGH);
    }
  } else {
    for (int id = 0; id <= 3; id++) {
      digitalWrite(LED_PIN[id], LOW);
    }
  }
}
