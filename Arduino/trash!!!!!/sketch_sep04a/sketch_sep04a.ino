#include <Adafruit_NeoPixel.h>
const int DIN_PIN = 10; // D10
const int LED_COUNT = 20; // LEDの数
Adafruit_NeoPixel pixels(LED_COUNT, DIN_PIN, NEO_GRB + NEO_KHZ800);

#include "I2Cdev.h"
#include "MPU6050.h"
#include "Wire.h"

MPU6050 accelgyro;

int16_t ax, ay, az;
int16_t gx, gy, gz;

void setup() {
  Wire.begin();
  pixels.begin();
  Serial.begin(38400);

  // 初期化
  accelgyro.initialize();
  delay(10);

  // 計測範囲を2000 deg/secに設定、16.4 LSB/deg/s
  accelgyro.setFullScaleGyroRange(MPU6050_GYRO_FS_2000);
  delay(10);

  accelgyro.CalibrateGyro();
  accelgyro.CalibrateAccel();
}

void loop() {

  // 時間を計っとく
  static float timer = 0;

  // 各軸加速度と角速度を取得
  accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  //X、Y軸まわりの角度を計算
  float degY = atan2(ax, az) * RAD_TO_DEG;
  float degX = atan2(ay, az) * RAD_TO_DEG;

  // Z軸まわりの角度を計算
  static float degZ = 0;
  static int last_time = micros();
  float omega = float(gz) / 16.4; //omega[deg/s] = gz[LSB] / 16.4[LSB/deg/s]
  int current_time = micros();  //time[us]
  float dt = current_time - last_time;
  // 角度は角速度の積分
  degZ += omega * dt / 1000000.0; //degZ[deg] = omega[deg/s] * dt[us] / 1000000[us/s]
  last_time = current_time;

  Serial.print(timer += dt / 1000000); Serial.print(", ");
  Serial.print(degX); Serial.print(", ");
  Serial.print(degY); Serial.print(", ");
  Serial.println(degZ);


  while (degZ > 360) {
    degZ = degZ - 360;
  }

  while (degZ < 0) {
    degZ = degZ + 360;
  }

  if (degZ >= 0 && degZ < 60) {
    for (int i = 0; i < LED_COUNT; i++)
      pixels.setPixelColor(i, pixels.Color(20, 0, 0));
    pixels.show();

  } else if (degZ >= 60 && degZ < 120) {
    for (int i = 0; i < LED_COUNT; i++)
      pixels.setPixelColor(i, pixels.Color(0, 0, 20));
    pixels.show();

  } else if (degZ >= 120 && degZ < 180) {
    for (int i = 0; i < LED_COUNT; i++)
      pixels.setPixelColor(i, pixels.Color(20, 10, 0));
    pixels.show();

  }  else if (degZ >= 180 && degZ < 240) {
    for (int i = 0; i < LED_COUNT; i++)
      pixels.setPixelColor(i, pixels.Color(0, 20, 0));
    pixels.show();

  }  else if (degZ >= 240 && degZ < 300) {
    for (int i = 0; i < LED_COUNT; i++)
      pixels.setPixelColor(i, pixels.Color(20, 0, 20));
    pixels.show();

  }  else if (degZ >= 300 && degZ < 360) {
    for (int i = 0; i < LED_COUNT; i++)
      pixels.setPixelColor(i, pixels.Color(20, 20, 20));
    pixels.show();

  } else {
    for (int i = 0; i < LED_COUNT; i++)
      pixels.setPixelColor(i, pixels.Color(0, 0, 0));
    pixels.show();
  }
}
