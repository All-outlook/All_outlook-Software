void F_buzzer_4 () {
    for (int i = 0; i < 13; i++) {
    tone(35, mario[i], 50);
    delay(140);
  }
}
