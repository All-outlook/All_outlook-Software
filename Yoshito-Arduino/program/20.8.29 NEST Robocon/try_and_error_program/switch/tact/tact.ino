int tact = 8;
void setup() {
  Serial.begin(9600);
  pinMode(tact,INPUT); 
}
 
void loop() {  
  int val = digitalRead(tact);
  Serial.println(val);
}
