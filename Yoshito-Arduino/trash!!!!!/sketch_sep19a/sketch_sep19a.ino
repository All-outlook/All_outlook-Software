int myspeed = 230;
int pin1 = 8;
int pin2 = 9;
void setup() {
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
}

void loop() {
  analogWrite(pin1, myspeed);
  analogWrite(pin2, 0);
  delay(2500);
  
  analogWrite(pin1,0);
  analogWrite(pin2, 0);
  delay(2500);

  analogWrite(pin1, 0);
  analogWrite(pin2, myspeed);
  delay(2500);
  
  analogWrite(pin1, 0);
  analogWrite(pin2, 0);
  delay(2500);
}
