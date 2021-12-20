void F_buzzer_3 () {
    for (int i = 0; i < 32; i++) {
    tone(35, star[i], 100);
    delay(100);
  }
}
