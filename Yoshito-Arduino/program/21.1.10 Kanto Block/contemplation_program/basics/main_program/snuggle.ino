const int UI_Y = 22;
const int UI_B = 23;
const int UI_X = 24;
const int UI_A = 25;
const int UI_NO = 26;
const int UI_OK = 27;
const int LED_PIN[] = {30, 31, 32, 33};
const int TOGGLE_PIN = 41;

int value;

void F_snuggle_setup() {
  for (id = 0; id <= 3; id++) {
    pinMode(LED_PIN[id], OUTPUT);
  }
  pinMode(TOGGLE_PIN, INPUT);
  pinMode(UI_Y, INPUT);
  pinMode(UI_B, INPUT);
  pinMode(UI_X, INPUT);
  pinMode(UI_A, INPUT);
  pinMode(UI_NO, INPUT);
  pinMode(UI_OK, INPUT);
}

int F_switch_value() {
  value = digitalRead(TOGGLE_PIN);
  return value;
}


void F_LED_turnon() {
  for (id = 0; id <= 3; id++) {
    pinMode(LED_PIN[id], HIGH);
  }
}

void F_LED_turnoff() {
  for (id = 0; id <= 3; id++) {
    pinMode(LED_PIN[id], LOW);
  }
}
