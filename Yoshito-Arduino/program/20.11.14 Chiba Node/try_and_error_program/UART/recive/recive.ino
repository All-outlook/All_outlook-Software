void setup() {
  Serial.begin(38400);
  Serial2.begin(9600);
  Serial.println("start");
}

int kazu;
void loop() {
  String recive_value = Serial2.readStringUntil('&');
  // recive_value = Serial1.read();
  //Serial.println(Serial1.read());
  kazu = recive_value.toInt() + 1;
  Serial.println(kazu);
}
