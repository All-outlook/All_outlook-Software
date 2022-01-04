const int RESET_PIN[] = {2, 3, 4, 5, 6, 7, 8, 10};

void F_reset_setup(){
  for (id = 0; id <= 7; id++) {
    pinMode(RESET_PIN[id], OUTPUT);
    digitalWrite(RESET_PIN[id], HIGH);
    digitalWrite(RESET_PIN[id], LOW);
    digitalWrite(RESET_PIN[id], HIGH);
  }
}
