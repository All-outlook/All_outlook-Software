#include "I2Cdev.h"
#include "MPU6050.h"
#include "Wire.h"
MPU6050 accelgyro;

int16_t ax, ay, az;
int16_t gx, gy, gz;

void gyro_configuration() {
  Wire.begin();
  accelgyro.initialize();
  delay(10);
  accelgyro.setFullScaleGyroRange(MPU6050_GYRO_FS_2000);
  delay(10);
  accelgyro.CalibrateGyro();
  accelgyro.CalibrateAccel();
}

static float gyro_loop() {
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

  while (degZ >= 360) {
    degZ -= 360;
  }
  while (degZ < 0) {
    degZ += 360;
  }
  float new_degZ = 360 - degZ;
  if (new_degZ == 360) {
    new_degZ = 0;
  }
  Serial.print("gyro:");
  Serial.print(new_degZ);
  Serial.print(",  ");
  return new_degZ; 
  //return new_degZ;  //逆回しになちゃった時
}

int attitude(int gyro) {
  int gyro_attitude;
  if (0 <= gyro & gyro <= 10 | 350 <= gyro & gyro <= 360) {
    gyro_attitude = 0;
  } else if (5 < gyro & gyro <= 180) {
    gyro_attitude = map(gyro, 5, 180, 100, 200);
  } else if (180 < gyro_value & gyro_value <= 355) {
    gyro_attitude = map(gyro, 180, 355, -200, -100);
  }
  /*Serial.print("gyro_attitude:");
    Serial.print(gyro_attitude);
    Serial.print(", ");*/
  return gyro_attitude;
}
