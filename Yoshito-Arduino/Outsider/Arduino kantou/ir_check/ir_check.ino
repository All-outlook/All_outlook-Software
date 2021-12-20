void setup(){
  Serial.begin(9600);
  Serial3.begin(9600);
}

void loop() {
  int ir = Serial.read();
  int ir1 = Serial3.read();
   //Serial.println(ir1);
  if(ir1 != -1){
    Serial.print(ir);
    Serial.print("--");
    Serial.println(ir1);
  }
}
