const int MT_PIN[] = {5, 6};
int speed;
void setup() {
  Serial.begin(38400);
  for (int id = 0; id <= 1; id++) {
    pinMode(MT_PIN[id], OUTPUT);
  }
}

void loop() {
 analogWrite(MT_PIN[0], 255);
 digitalWrite(MT_PIN[1], LOW);
 delay(1000);

 digitalWrite(MT_PIN[0], LOW);
 digitalWrite(MT_PIN[1], LOW);
 delay(500);

 digitalWrite(MT_PIN[0], LOW);
 analogWrite(MT_PIN[1], 255);
 delay(1000);

 digitalWrite(MT_PIN[0], LOW);
 digitalWrite(MT_PIN[1], LOW);
 delay(500);
}
