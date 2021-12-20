int attitude(int gyro) {
  int gyro_attitude;
  if (0 <= gyro & gyro <= 10 | 350 <= gyro & gyro <= 360) {
    gyro_attitude = 0;
  } else if (5 < gyro & gyro <= 180) {
    gyro_attitude = map(gyro, 5, 180, 100, 200);
  } else if (180 < gyro & gyro <= 355) {
    gyro_attitude = map(gyro, 180, 355, -200, -100);
  } else {
    gyro_attitude = 0;
  }
  return gyro_attitude;
}
