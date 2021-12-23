int gyro_serial;
void setup() {
  Serial.begin(115200);
  Serial2.begin(38400);
}

void loop() {
  if (Serial2.available() > 0)
  {
    gyro_serial = Serial2.read() * 2;
  }
  else
  {
    gyro_serial = 0;
  }
  Serial.println(gyro_serial);
}
