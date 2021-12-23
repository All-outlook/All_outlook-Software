void LED_shine() {
  for (int id = 0; id <= 7; id++) {
    digitalWrite(LED_CIRCLE1[id], LOW);
  }
  
  if (best == 0 | best == 1) {
    digitalWrite(LED_CIRCLE1[0], HIGH);
  } else if (best == 2 | best == 3) {
    digitalWrite(LED_CIRCLE1[1], HIGH);
  } else if (best == 4 | best == 5) {
    digitalWrite(LED_CIRCLE1[2], HIGH);
  } else if (best == 6 | best == 7) {
    digitalWrite(LED_CIRCLE1[3], HIGH);
  } else if (best == 8 | best == 9) {
    digitalWrite(LED_CIRCLE1[4], HIGH);
  } else if (best == 10 | best == 11) {
    digitalWrite(LED_CIRCLE1[5], HIGH);
  } else if (best == 12 | best == 13) {
    digitalWrite(LED_CIRCLE1[6], HIGH);
  } else if (best == 14 | best == 15) {
    digitalWrite(LED_CIRCLE1[7], HIGH);
  } else if (best == 20) {
    for (int id = 0; id <= 7; id++) {
      digitalWrite(LED_CIRCLE1[id], HIGH);
    }
  } else {

  }
}
