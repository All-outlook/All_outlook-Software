void DISPLAY_LED_setup(){
  for (int id = 0; id <= 3; id++) {
    pinMode(LED_PIN[id], OUTPUT);
    digitalWrite(LED_PIN[id], HIGH);
  }
}

void LED_WRITE(int n){
  for (int i = 0; i <= 3; i++) {
    pinMode(LED_PIN[i], OUTPUT);
    digitalWrite(LED_PIN[i], LOW);
  }
  digitalWrite(LED_PIN[n], HIGH);
}
