void LED_shine() {
  for (int id = 0; id <= 7; id++) {
    digitalWrite(LED_CIRCLE1[id], LOW);
  }

  if (326 <= degree & degree <= 360 | 0 < degree & degree < 11) {
    digitalWrite(LED_CIRCLE1[0], HIGH);
  } else if (11 <= degree & degree < 56) {
    digitalWrite(LED_CIRCLE1[1], HIGH);
  } else if (56 <= degree & degree < 101) {
    digitalWrite(LED_CIRCLE1[2], HIGH);
  } else if (101 <= degree & degree < 146) {
    digitalWrite(LED_CIRCLE1[3], HIGH);
  } else if (146 <= degree & degree < 191) {
    digitalWrite(LED_CIRCLE1[4], HIGH);
  } else if (191 <= degree & degree < 236) {
    digitalWrite(LED_CIRCLE1[5], HIGH);
  } else if (236 <= degree & degree < 281) {
    digitalWrite(LED_CIRCLE1[6], HIGH);
  } else if (281 <= degree & degree < 326) {
    digitalWrite(LED_CIRCLE1[7], HIGH);
  } else if (degree == 0) {
    for (int id = 0; id <= 7; id++) {
      digitalWrite(LED_CIRCLE1[id], HIGH);
    }
  }
}
