unsigned long mytime;
void setup() {
  Serial.begin(115200);
}

void loop() {
  mytime = micros();
  Serial.println(mytime);
}
