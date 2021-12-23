void setup(){
  Serial.begin(38400,SERIAL_8E1);
}



void loop(){
  Serial.write(255);//0d255
  
  Serial.write(10);//0d10
  
  Serial.write(160);//0d160
  
  delay(100);
}
