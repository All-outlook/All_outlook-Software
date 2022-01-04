#define SERIAL_8E1 0x26

int F_gyro_serial()
{
  int i;
  while (Serial2.available() > 1) {
    int g = Serial2.read();
  }
  if (Serial2.available()) {
    i = Serial2.read() * 2;
  }
  return i;
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
    gyro_attitude = map(gyro, 5, 180, 100, 200);
  }
  else if (180 < gyro & gyro <= 355)
  {
    gyro_attitude = map(gyro, 180, 355, -200, -100);
  }
  else
  {
    gyro_attitude = 0;
  }
  return gyro_attitude;
}
