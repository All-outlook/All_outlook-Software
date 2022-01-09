int GYRO_receive = 0;

void F_GYRO_setup() {
  Serial2.begin(115200);
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

int F_attitude_control(int gyro)
{
  int gyro_attitude;
  if (0 <= gyro & gyro <= 10 | 350 <= gyro & gyro <= 360)
  {
    gyro_attitude = 0;
  }
  else if (5 < gyro & gyro <= 180)
  {
    gyro_attitude = map(gyro, 5, 180, 40, 254);
  }
  else if (180 < gyro & gyro <= 355)
  {
    gyro_attitude = map(gyro, 180, 355, -254, -40);
  }
  else
  {
    gyro_attitude = 0;
  }
  return gyro_attitude;
}
