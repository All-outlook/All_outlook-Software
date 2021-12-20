//ジャイロ(MPU6050)
#include <Wire.h>
#include <MPU6050_6Axis_MotionApps20.h>

#define Gyro_X 58
#define Gyro_Y 19
#define Gyro_Z -1
#define Accel_Z 640

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
//ジャイロ(MPU6050)

////////////////////////////////////////////////////////////////////////////////////////////////////
void setup() {
  Serial.begin(9600);
  //Wire.begin();
  //Gryo_Start();
}

//now
//   ↑/  \↓
//      ＿
//      ←
//think
//   ↑/  \↓
//      ＿
//      ←

void loop() {
  int irSensor = Serial.read();
  //Serial.println(irSensor);
  if(irSensor != -1){
    Serial.println(irSensor);
    //irSensor = irSensor;
    motorAngle(irSensor * 30);
  }
  
//  motorAngle(0);
//  delay(1000);
//  motorAngle(90);
//  delay(1000);
//  motorAngle(180);
//  delay(1000);
//  motorAngle(270);
//  delay(1000);
}

////////////////////////////////////////////////////////////////////////////////////////////////////

void motorAngle(int theta){
  int sita = theta;
  int power = 100;
  int M1;
  int M2;
  int M3;
  M1 = sin((sita - 60) * 3.14 / 180) * power;
  M2 = sin((sita - 180) * 3.14 / 180) * power;
  M3 = sin((sita - 300) * 3.14 / 180) * power;

  int SFlist[3] = {M1 , M2 , M3};

  //  M1 = abs(M1);
  //  M2 = abs(M2);
  //  M3 = abs(M3);

//  Serial.print(M1);
//  Serial.print("**");
//  Serial.print(M2);
//  Serial.print("**");
//  Serial.println(M3);

  int motor_all_list[3] = {49, 51, 53};
  int motor_pin_list[3] = {46, 48, 50};
  int motor_pwm_list[3] = {2, 3, 4};
  
  for (int MOTF = 0; MOTF <= 2; MOTF++) {
    int HL;
    digitalWrite(motor_all_list[MOTF] , HIGH);
    if (SFlist[MOTF] >= 0) {HL = LOW;} else {HL = HIGH;}
    digitalWrite(motor_pin_list[MOTF] , HL);
    analogWrite(motor_pwm_list[MOTF] , abs(SFlist[MOTF]));
  }
}

//ジャイロ(MPU6050)
void GyroGet() {
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
}

void Gryo_Start() {
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
//ジャイロ(MPU6050)
