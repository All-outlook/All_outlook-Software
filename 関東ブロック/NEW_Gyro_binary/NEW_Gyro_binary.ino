#include <Wire.h>
#include <MPU6050_6Axis_MotionApps20.h>

const int DONE_LED = 2;
const int SWITCH_LED = 3;
const int GYRO_SWITCH = 4;
const int LED_CIRCLE[] = {5, 6, 7, 8, 9, 10, 11, 12};

void setup() {
  Serial.begin(115200);
//  Serial.begin(38400 ,SERIAL_8E1);
  Wire.begin();

  pinSetup();
  
  Gryo_Start();

  //Serial.print("Gyro_OK");
}



int Gyro_hosei = 0;
int Gyro_degree = 0;
int gauge = 0;
int switch_count = 0;


void loop() {
  if (switch_count == 0) {
    gauge = 0;
    while (!digitalRead(GYRO_SWITCH)) {
      gauge++;
    }
    if (gauge > 10000) {
      Gyro_hosei = Gyro_degree;
      digitalWrite(SWITCH_LED, HIGH);
      switch_count = 1;
    }
  }
  
  digitalWrite(DONE_LED, HIGH);


  Gyro_degree = GyroGet() - Gyro_hosei;

  if (Gyro_degree < 0) Gyro_degree += 360;
  if (Gyro_degree > 359) Gyro_degree -= 360;


  LED_shine(Gyro_degree);
  Serial.write(Gyro_degree / 2);
//  Serial.flush();
}
