void setup() {
}

int Apin = 46;
int Bpin = 48;
int Cpin = 50;

void loop() {
  digitalWrite(53,HIGH);
  digitalWrite(51,HIGH);
  digitalWrite(49,HIGH);

  analogWrite(2,100);
  analogWrite(3,100);
  analogWrite(4,100);
  
  digitalWrite(Apin,HIGH);
  digitalWrite(Bpin,HIGH);
  digitalWrite(Cpin,HIGH);

  analogWrite(13,255);
  delay(2000);
  digitalWrite(Apin,LOW);
  digitalWrite(Bpin,LOW);
  digitalWrite(Cpin,LOW);

  analogWrite(13,0);
  delay(2000);
}
