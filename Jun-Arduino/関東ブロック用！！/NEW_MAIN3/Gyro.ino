void F_GYRO_setup(){
  Serial2.begin(38400, SERIAL_8E1);
}

int Gyro_value;

void F_GYRO_read(){
  while (Serial2.available() > 1) {
    int g = Serial2.read();
  }
  if (Serial2.available()) {
    Gyro_value = Serial2.read() * 2;
  }
}

int F_GYRO_get(){
  return Gyro_value;
}
