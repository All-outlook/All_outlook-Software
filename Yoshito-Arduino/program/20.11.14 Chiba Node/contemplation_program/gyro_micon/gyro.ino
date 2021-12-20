void gyro_configuration() {
  Wire.begin();
  accelgyro.initialize();
  delay(10);
  accelgyro.setFullScaleGyroRange(MPU6050_GYRO_FS_2000);
  delay(10);
  accelgyro.CalibrateGyro();
  accelgyro.CalibrateAccel();
}

int gyro_loop() {
  static float timer = 0;
  accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  int degY = atan2(ax, az) * RAD_TO_DEG;
  int degX = atan2(ay, az) * RAD_TO_DEG;

  static float degZ = 0;
  static int last_time = micros();
  float omega = float(gz) / 16.4;
  int current_time = micros();
  float dt = current_time - last_time;
  degZ += omega * dt / 1000000.0;
  last_time = current_time;

  while (degZ > 360) {
    degZ -= 360;
  }
  while (degZ <= 0) {
    degZ += 360;
  }
  /*float new_degZ = 360 - degZ;
  if (new_degZ == 0) {
    new_degZ = 360;
  }
return new_degZ;*/
return degZ;
}
