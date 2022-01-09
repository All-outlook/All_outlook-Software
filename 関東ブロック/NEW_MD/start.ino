void start() {
  digitalWrite(LED[0], HIGH);
  delay(150);
  digitalWrite(LED[1], HIGH);
  delay(150);
  digitalWrite(LED[2], HIGH);
  delay(150);
  for (int i = 0; i < 3; i++) {
    digitalWrite(LED[i], LOW);
  }
  delay(150);

  digitalWrite(LED[2], HIGH);
  delay(150);
  digitalWrite(LED[1], HIGH);
  delay(150);
  digitalWrite(LED[0], HIGH);
  delay(150);

  for (int n = 0; n < 5; n++) {
    for (int i = 0; i < 3; i++) {
      digitalWrite(LED[i], HIGH);
      digitalWrite(M_LED_A[i], HIGH);
      digitalWrite(M_LED_B[i], HIGH);
    }
    delay(100);
    for (int i = 0; i < 3; i++) {
      digitalWrite(LED[i], LOW);
      digitalWrite(M_LED_A[i], LOW);
      digitalWrite(M_LED_B[i], LOW);
    }
    delay(100);
  }
}
