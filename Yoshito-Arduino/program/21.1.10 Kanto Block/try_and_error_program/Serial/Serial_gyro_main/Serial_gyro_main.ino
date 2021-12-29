int gyro_serial;

void setup() {
  Serial.begin(115200);
  Serial2.begin(38400, SERIAL_8E1);
}

void loop() {
  int i;
  while (Serial2.available() > 1) {
    int g = Serial2.read();
  }
  if (Serial2.available()) {
    gyro_serial = Serial2.read() * 2;
  }
  Serial.println(gyro_serial);
}
