
//Jun
//#define Gyro_X 74
//#define Gyro_Y 63
//#define Gyro_Z 27
//#define Accel_Z 4732

// Yoshito
#define Gyro_X 29
#define Gyro_Y 9
#define Gyro_Z -93
#define Accel_Z 4940


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



int GyroGet() {
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
    Gyro_Now = 360 - degrees(ypr[0]);// + 180;
    Gyro = Gyro_Now + Gyro_Offset;
    if (Gyro < 0) Gyro += 360;
    if (Gyro > 359) Gyro -= 360;
  }
  return Gyro;
}

void Gryo_Start() {
  mpu.initialize();
  if (mpu.testConnection() != true) {
//    Serial.println("MPU disconection");
    while (true) {}
  }
  if (mpu.dmpInitialize() != 0) {
//    Serial.println("MPU break");
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

void LED_shine(float gyro) {
  if (337.5 <=  gyro & gyro <= 360 | 0 <= gyro & gyro < 22.5) {
    digitalWrite(LED_CIRCLE[0], HIGH);
  } else {
    digitalWrite(LED_CIRCLE[0], LOW);
  }

  if (22.5 <= gyro & gyro < 67.5) {
    digitalWrite(LED_CIRCLE[7], HIGH);
  } else {
    digitalWrite(LED_CIRCLE[7], LOW);
  }

  if (67.5 <= gyro & gyro < 112.5) {
    digitalWrite(LED_CIRCLE[6], HIGH);
  } else {
    digitalWrite(LED_CIRCLE[6], LOW);
  }

  if (112.5 <= gyro & gyro < 157.5) {
    digitalWrite(LED_CIRCLE[5], HIGH);
  } else {
    digitalWrite(LED_CIRCLE[5], LOW);
  }

  if (157.5 <= gyro & gyro < 202.5) {
    digitalWrite(LED_CIRCLE[4], HIGH);
  } else {
    digitalWrite(LED_CIRCLE[4], LOW);
  }

  if (202.5 <= gyro & gyro < 247.5) {
    digitalWrite(LED_CIRCLE[3], HIGH);
  } else {
    digitalWrite(LED_CIRCLE[3], LOW) ;
  }

  if (247.5 <= gyro & gyro < 292.5) {
    digitalWrite(LED_CIRCLE[2], HIGH);
  } else {
    digitalWrite(LED_CIRCLE[2], LOW);
  }

  if (292.5 <= gyro & gyro < 337.5) {
    digitalWrite(LED_CIRCLE[1], HIGH);
  } else {
    digitalWrite(LED_CIRCLE[1], LOW) ;
  }
}

void pinSetup() {
  pinMode(DONE_LED, OUTPUT);
  pinMode(SWITCH_LED, OUTPUT);
  pinMode(GYRO_SWITCH, INPUT);
  for (int id = 0; id <= 7; id++) {
    pinMode(LED_CIRCLE[id], OUTPUT);
    digitalWrite(LED_CIRCLE[id], HIGH);
  }
  for (int id = 0; id <= 7; id++) {
    digitalWrite(LED_CIRCLE[id], LOW);
  }
}
