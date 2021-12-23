void LED_shine() {
  for (int id = 0; id <= 3; id++) {
    digitalWrite(LED_PIN[id], LOW);
  }
  if (rotation == 10) {
    digitalWrite(LED_PIN[2], HIGH);
    
  } else if (rotation == 20) {
    digitalWrite(LED_PIN[0], HIGH);
    
  } else if (rotation == 30) {
    digitalWrite(LED_PIN[0], HIGH);
    digitalWrite(LED_PIN[2], HIGH);
    
  } else if (rotation == 0 | rotation == 40) {
    digitalWrite(LED_PIN[0], HIGH);
    digitalWrite(LED_PIN[1], HIGH);
    digitalWrite(LED_PIN[2], HIGH);
  } else {
  }
}
