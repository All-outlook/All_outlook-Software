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

int GyroS;
//ジェゥイロ(MPU6050)

int line[15]={960,580,  0,900,850,850,860,950,  0,900,850,700,880,970,800};
//line pin  = 0   1   2   3   4   5   6   7   8   9   10  11  12  13  14
//line      = 1   2   3   4   5   6   7   8   9c  10  11  12  13  14  15
////////////////////////////////////////////////////////////////////////////////////////////////////

void setup() {
  Serial.begin(9600);
  Serial3.begin(9600);
  Wire.begin();
  Gyro_Start();

  pinMode(52,INPUT_PULLUP);while(digitalRead(52)==HIGH);
}

#define spin 30 //gyro sentor set speed

void loop() {
  GyroGet();
  int ir = Serial3.read();
  GyroS = GyroS -20;//場所によって変更する
  if(GyroS < 0) GyroS = 360 - abs(GyroS);

  int i;
  for(i=3;i<8;i++){
    if(analogRead(i)<line[i]){
      motorAngle(i*24);
      break;
    }
  }
  
  if(GyroS < 10 or GyroS > 350){
    if(ir != -1){
      if(ir < 3 || GyroS > 9){
        motorAngle(ir * 30);
      }else if(ir < 6){
        motorAngle((ir * 30)+ 60);
      }else{
        motorAngle((ir * 30)- 60);
      }
    }
  }else{
    if(GyroS < 180){
      motor(-spin,-spin,-spin);
    }else{
      motor(spin,spin,spin);
    }
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////

void motorAngle(int theta){ //モーター角度
  int sita = theta;
  int power = 150;
  int M1;
  int M2;
  int M3;
  M1 = sin((sita - 60) * 3.14 / 180) * power;
  M2 = sin((sita - 180) * 3.14 / 180) * power;
  M3 = sin((sita - 300) * 3.14 / 180) * power;

  int SFlist[3] = {M1 , M2 , M3};

//  Serial.println(M1);
//  Serial.println(M2);
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

void motor(int MpinIN0 , int MpinIN1 , int MpinIN2){ //モーター(pololu)
  int Mpin[3] = {MpinIN0 , MpinIN1 , MpinIN2};
  int motor_all_list[3] = {49, 51, 53};
  int motor_pin_list[3] = {46, 48, 50};
  int motor_pwm_list[3] = {2, 3, 4};
  for (int MOTF = 0; MOTF <= 2; MOTF++) {
    int HL;
    digitalWrite(motor_all_list[MOTF] , HIGH);
    if (Mpin[MOTF] >= 0) {
      HL = HIGH;
    } else {
      HL = LOW;
    }
    digitalWrite(motor_pin_list[MOTF] , HL);
    analogWrite(motor_pwm_list[MOTF] , abs(Mpin[MOTF]));
  }
}

void GyroGet(){ //ジャイロ(MPU6050)
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

  if(Gyro >= 180) GyroS = Gyro - 180;
  if(Gyro < 180) GyroS = Gyro + 180;
}

void Gyro_Start(){ //ジャイロ(MPU6050)
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
