void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("「slot」put switch");
  pinMode(52,INPUT_PULLUP);while(digitalRead(52)==HIGH);
  for(int i=0;i<=5;i++){
    Serial.print("-");
    delay(500);
    Serial.print(random(10));
    delay(500);
  }
  Serial.println("");
}
