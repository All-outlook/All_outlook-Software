#include <Wire.h>
#include <MPU6050_6Axis_MotionApps20.h>

#define Gyro_X 65
#define Gyro_Y 26
#define Gyro_Z -123
#define Accel_Z 1051
//Your offsets:  683 4025  1051  65  26  -123


MPU6050 mpu;
static uint8_t mpuIntStatus;
static bool dmpReady = false;  // set true if DMP init was successful
static uint16_t packetSize;    // expected DMP packet size (default is 42 bytes)

int16_t  Gyro_Now = 0, Gyro = 0, Gyro_Offset = 0;
uint16_t fifoCount;
uint8_t fifoBuffer[64]; // FIFO storage buffer                 // orientation/motion vars
Quaternion q;           // [w, x, y, z]         quaternion container
VectorFloat gravity;    // [x, y, z]            gravity vector
float ypr[3];           // [yaw, pitch, roll]   yaw/pitch/roll container and gravity vector

void F_gyro_configuration() {
  mpu.initialize();
  if (mpu.testConnection() != true) {
    Serial.println("MPU disconection");
    while (true) {}
  }
  if (mpu.dmpInitialize() != 0) {
    Serial.println("MPU break");
    while (true) {}
  }
  mpu.setXGyroOffset(Gyro_X);
  mpu.setYGyroOffset(Gyro_Y);
  mpu.setZGyroOffset(Gyro_Z);
  mpu.setZAccelOffset(Accel_Z);
  mpu.setDMPEnabled(true);
  mpuIntStatus = mpu.getIntStatus();
  dmpReady = true;
  packetSize = mpu.dmpGetFIFOPacketSize();
}

int  F_gyro_loop() {
   mpuIntStatus = false;
  mpuIntStatus = mpu.getIntStatus();
  fifoCount = mpu.getFIFOCount();
  if ((mpuIntStatus & 0x10) || fifoCount == 1024) {
    mpu.resetFIFO();
  }
  else if (mpuIntStatus & 0x02) {
    while (fifoCount < packetSize) fifoCount = mpu.getFIFOCount();
    mpu.getFIFOBytes(fifoBuffer, packetSize);
    fifoCount -= packetSize;
    mpu.dmpGetQuaternion(&q, fifoBuffer);
    mpu.dmpGetGravity(&gravity, &q);
    mpu.dmpGetYawPitchRoll(ypr, &q, &gravity);
    Gyro_Now = degrees(ypr[0]) + 180;
    Gyro = Gyro_Now + Gyro_Offset;
    if (Gyro < 0) Gyro += 360;
    if (Gyro > 359) Gyro -= 360;
  }
  
  int new_Gyro = Gyro - 180;
  if (new_Gyro <= 0) {
    new_Gyro += 360;
  }
    if (new_Gyro == 0) {
    new_Gyro = 360;
  }
  return new_Gyro;
}

int F_attitude(int gyro) {
  int gyro_attitude;
  if (0 <= gyro & gyro <= 10 | 350 < gyro & gyro <= 360) {
    gyro_attitude = 0;
  } else if (10 < gyro & gyro <= 180) {
    gyro_attitude = map(gyro, 10, 180, 100, 200);
  } else if (180 < gyro_value & gyro_value <= 350) {
    gyro_attitude = map(gyro, 180, 350, -200, -100);
  }
  return gyro_attitude;
}
