const int LED_PIN[] = {30, 31, 32, 33};

void F_LED_setuo(){
   for (id = 0; id <= 3; id++) {
    pinMode(LED_PIN[id], OUTPUT);
  } 
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
