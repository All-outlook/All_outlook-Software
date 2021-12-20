int MT_PIN1[] = {2, 4, 6, 8};
int MT_PIN2[] = {3, 5, 7, 8};
int power = 100;
int continue_time = 2000;
int stop_time = 2000;
void setup() {
  for(int id = 0; id <= 3; id++){
    pinMode(MT_PIN1[id], OUTPUT);
    pinMode(MT_PIN2[id], OUTPUT);
  }

}

void loop() {
  for(int id = 0; id <= 3; id++){
analogWrite(MT_PIN1[id], power);
digitalWrite(MT_PIN2[id], LOW);
}
delay(continue_time);

  for(int id = 0; id <= 3; id++){
digitalWrite(MT_PIN1[id], HIGH);
digitalWrite(MT_PIN2[id], HIGH);
}
delay(stop_time);

  for(int id = 0; id <= 3; id++){
digitalWrite(MT_PIN1[id], LOW);
analogWrite(MT_PIN2[id], power);
}
delay(continue_time);

  for(int id = 0; id <= 3; id++){
digitalWrite(MT_PIN1[id], HIGH);
digitalWrite(MT_PIN2[id], HIGH);
}
delay(stop_time);
}
