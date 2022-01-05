const int MT_PIN1[] = {2, 4, 6, 8};
const int MT_PIN2[] = {3, 5, 7, 9};
int speed;
void setup() {
  Serial.begin(38400);
  for (int id = 0; id <= 3; id++) {
    pinMode(MT_PIN1[id], OUTPUT);
    pinMode(MT_PIN2[id], OUTPUT);
  }
}

void loop() {
  for (int id = 0; id <= 3; id++) {
    analogWrite(MT_PIN1[id], 255);
    digitalWrite(MT_PIN2[id], LOW);
  }
  delay(1000);

  for (int id = 0; id <= 3; id++) {
    
    digitalWrite(MT_PIN1[id], HIGH);
    digitalWrite(MT_PIN2[id], HIGH);
  }
  delay(500);

  for (int id = 0; id <= 3; id++) {
    digitalWrite(MT_PIN1[id], LOW);
    analogWrite(MT_PIN2[id], 255);
  }
  delay(1000);

  for (int id = 0; id <= 3; id++) {
    digitalWrite(MT_PIN1[id], HIGH);
    digitalWrite(MT_PIN2[id], HIGH);
  }
  delay(500);
}
