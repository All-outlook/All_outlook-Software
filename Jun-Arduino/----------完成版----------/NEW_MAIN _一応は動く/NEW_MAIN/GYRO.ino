void F_GYRO_setup(){
  Serial2.begin(38400, SERIAL_8E1);
}

int F_GYRO_read(){
  int i;
  while (Serial2.available() > 1) {
    int g = Serial2.read();
  }
  if (Serial2.available()) {
    i = Serial2.read() * 2;
  }
  return i;
}
