void setup() {
  // put your setup code here, to run once:

}

void loop() {
    tone(35, 880);
    delay(500);
    tone(35, 698);
    delay(500);
    tone(35, 784);
    delay(500);
    tone(35, 523);
    delay(500);
    noTone(35);
    delay(500);

    tone(35, 523);
    delay(500);
    tone(35, 784);
    delay(500);
    tone(35, 880);
    delay(500);
    tone(35, 698);
    delay(1200);
    noTone(35);
    delay(400);
}
