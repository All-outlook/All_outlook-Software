void setup() {
  F_KICCER_setup();
  Serial.begin(38400);
}

void loop() {
  Serial.println(F_KICCER_check());

  F_KICCR_KICC();

  delay(2000);
}
