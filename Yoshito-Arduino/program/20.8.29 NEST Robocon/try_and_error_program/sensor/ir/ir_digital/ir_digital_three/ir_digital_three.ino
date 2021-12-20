int IRpin1 = 11;
int IRpin2 = 12;
int IRpin3 = 13;
unsigned long duration1;
unsigned long duration2;
unsigned long duration3;

void setup(){
  pinMode(IRpin1,INPUT);
  pinMode(IRpin2,INPUT);
  pinMode(IRpin3,INPUT);
  Serial.begin(9600);
}

void loop(){
  duration1 = pulseIn(IRpin1,HIGH);
  duration2 = pulseIn(IRpin2,HIGH);
  duration3 = pulseIn(IRpin3,HIGH);  

  Serial.print("IRpin1:"); Serial.print(duration1); 
  Serial.print(",  IRpin2:"); Serial.print(duration2); 
  Serial.print(",  IRpin3:"); Serial.println(duration3); 
}
