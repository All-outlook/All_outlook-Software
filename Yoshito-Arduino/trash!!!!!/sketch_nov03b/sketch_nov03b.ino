const int MT_PIN[] = {5, 6};
int speed;
void setup() {
  Serial.begin(38400);
  for (int id = 0; id <= 1; id++) {
    pinMode(MT_PIN[id], OUTPUT);
  }
}

void loop() {
  speed = 0; //前進
  while (speed <= 220) {
    analogWrite(MT_PIN[0], speed);
    analogWrite(MT_PIN[1], 0);
    delay(150);
    speed = speed + 45;
    Serial.println(speed);
  }
  delay(1000);

  speed = 220;
  while (speed >= 0) {
    Serial.println(speed);
    analogWrite(MT_PIN[0], 0);
    analogWrite(MT_PIN[1], speed);
    delay(150);
    speed = speed - 45;
  }
  delay(1000);
}
