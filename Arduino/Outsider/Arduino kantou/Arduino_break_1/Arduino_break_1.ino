void setup() {
}

void loop() {
  analogWrite(13,255);
  delay(500);
  analogWrite(13,0);
  delay(500);
}
