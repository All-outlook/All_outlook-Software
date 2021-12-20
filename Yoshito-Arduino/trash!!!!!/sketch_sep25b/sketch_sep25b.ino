const int led[] = {40, 41, 42, 43, 44, 45, 46, 47};
void setup() {
  for (int i = 0; i <= 7; i++) {
    pinMode(led[i], OUTPUT);
  }

}

void loop() {
  for (int i = 0; i <= 7; i++) {
    digitalWrite(led[i], HIGH);
    delay(250);
    digitalWrite(led[i], LOW);
    delay(250);
  }
}
