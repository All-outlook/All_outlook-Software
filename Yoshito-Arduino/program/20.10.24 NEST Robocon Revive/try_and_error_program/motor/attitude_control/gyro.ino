#include "I2Cdev.h"
#include "MPU6050.h"
#include "Wire.h"
MPU6050 accelgyro;

int16_t ax, ay, az;
int16_t gx, gy, gz;

void gyro_configuration() {
  Wire.begin();

  // 初期化
  accelgyro.initialize();
  delay(10);

  // 計測範囲を2000 deg/secに設定、16.4 LSB/deg/s
  accelgyro.setFullScaleGyroRange(MPU6050_GYRO_FS_2000);
  delay(10);

  accelgyro.CalibrateGyro();
  accelgyro.CalibrateAccel();
}

float gyro_loop() {
  // 時間を計っとく
  static float timer = 0;

  // 各軸加速度と角速度を取得
  accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  //X、Y軸まわりの角度を計算
  int degY = atan2(ax, az) * RAD_TO_DEG;
  int degX = atan2(ay, az) * RAD_TO_DEG;

  // Z軸まわりの角度を計算
  static float degZ = 0;
  static int last_time = micros();
  float omega = float(gz) / 16.4; //omega[deg/s] = gz[LSB] / 16.4[LSB/deg/s]
  int current_time = micros();  //time[us]
  float dt = current_time - last_time;
  // 角度は角速度の積分
  degZ += omega * dt / 1000000.0; //degZ[deg] = omega[deg/s] * dt[us] / 1000000[us/s]
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
}

int turning(int gyro) {
  int gyro_turning;
  if (0 <= gyro & gyro <= 10 | 350 <= gyro & gyro <= 360) {
    gyro_turning = 0;
  } else if (10 < gyro & gyro <= 180) {
    gyro_turning = map(gyro, 10, 180, 100, 200);
  } else if (180 < gyro_value & gyro_value <= 350) {
    gyro_turning = map(gyro, 180, 350, -200, -100);
  }
  return gyro_turning;
}
