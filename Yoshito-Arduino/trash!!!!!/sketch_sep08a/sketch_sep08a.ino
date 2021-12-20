unsigned long time;

void setup() {
  Serial.begin(38400);
}

void loop() {
  time = millis();
  if (time >= 10000){
    time -= 10000;
  }
    Serial.println(time);
}
