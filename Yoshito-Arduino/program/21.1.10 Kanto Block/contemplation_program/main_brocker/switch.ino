const int TOGGLE_PIN = 41;

int value;

void F_switch_setup() {
  pinMode(TOGGLE_PIN, INPUT);
}

int F_switch_value() {
  value = digitalRead(TOGGLE_PIN);
  return value;
}
