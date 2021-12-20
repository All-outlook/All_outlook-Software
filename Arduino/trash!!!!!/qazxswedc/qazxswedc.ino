void setup() {
  // put your setup code here, to run once:
Serial.begin(38400);
pinMode(A0, INPUT);
}

void loop() {
  analogRead(A0);
  Serial.println(A0);

}
