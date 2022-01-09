int GYRO_receive = 0;

void F_GYRO_setup() {
  Serial2.begin(115200);
//  Serial2.begin(38400, SERIAL_8E1);
}

void F_GYRO_read() {
  while (Serial2.available() > 1) {
    int g = Serial2.read();
  }
  if (Serial2.available() > 0) {
    GYRO_receive = Serial2.read() * 2;
  }
}

int F_GYRO_get() {
  return GYRO_receive;
}

void F_GYRO_debug(){
  Serial.print(" GYRO:");
  Serial.print(GYRO_receive);
}
