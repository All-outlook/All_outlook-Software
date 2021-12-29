void setup() {
   Serial.begin(38400, SERIAL_8E1);
}

void loop() {
  int gyro = 168;
  Serial.write(gyro / 2);
  Serial.flush();
  
 // Serial.println(gyro);
}
