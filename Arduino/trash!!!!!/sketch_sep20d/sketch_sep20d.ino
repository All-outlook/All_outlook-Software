void setup() {
 pinMode(8, OUTPUT);
 pinMode(9, OUTPUT);

}

void loop() {
 analogWrite(8, 240);
 analogWrite(9, 0);
 delay(500);
 
 digitalWrite(8, 0);
 digitalWrite(9, 0);
 delay(1000);
 
 analogWrite(8, 0);
 analogWrite(9, 240);
 delay(500);

 digitalWrite(8, 0);
 digitalWrite(9, 0);
 delay(500);

}
