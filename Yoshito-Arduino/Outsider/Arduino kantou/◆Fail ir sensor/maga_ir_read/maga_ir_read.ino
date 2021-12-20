void setup() {
  Serial.begin(9600);
}

void loop(){
  int irSensor = Serial.read();
  //Serial.println(irSensor);
  if(irSensor != -1){
    Serial.println(irSensor);
  }
}
