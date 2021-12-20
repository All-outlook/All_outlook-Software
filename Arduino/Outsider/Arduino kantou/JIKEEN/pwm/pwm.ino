void setup() {
pinMode(11, OUTPUT);
pinMode(12, OUTPUT);

}

void loop() {
  analogWrite(11,100);
  analogWrite(12,200);
}
