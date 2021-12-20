const int motor_right[] = {2, 4, 6, 8};
const int motor_left[] = {3, 5, 7, 9};

int motor_degree[] = {45, 135, 225, 315};
int motor_speed;
int mytime = millis();

float gyro_degree;

void setup() {
  gyro_configuration();
  Serial.begin(38400);
  for (int i = 0; i <= 3; i++) {
    pinMode(motor_right[i], OUTPUT);
  }
  for (int i = 0; i <= 3; i++) {
    pinMode(motor_left[i], OUTPUT);
  }
}

void loop() {
  gyro_degree = gyro_loop();

  if (gyro_degree > 5.00 & gyro_degree <= 180.00) {
    motor_speed = gyro_degree * 1 + 35;
    for (int i = 0; i <= 3; i++) {
      mytime = 0;
      if (mytime <= 2000) {
        analogWrite(motor_right[i], 120);
      }
      mytime = 0;
      if (mytime <= 250) {
        analogWrite(motor_right[i], motor_speed);
      }
      mytime = 0;
      if (mytime <= 20) {
        digitalWrite(motor_right[i], LOW);
      }

    }/* else if (gyro_degree > 180.00 & gyro_degree <= 355.00) {
      motor_speed = gyro_degree * -1 + 395;
      for (int i = 0; i <= 3; i++) {
        analogWrite(motor_right[i], 120);

        analogWrite(motor_left[i], motor_speed);
      }
      delay(250);
      digitalWrite(motor_left[i], LOW);
    }
    delay(250); */

  } else if (gyro_degree > 355.00 & gyro_degree < 360.00 | gyro_degree <= 0 &  gyro_degree <= 5.00) {
    motor_speed = 0;
  }
  Serial.print("gyro_degree:"); Serial.print(gyro_degree); Serial.print(",  ");
  Serial.print("motor_speed:"); Serial.println(motor_speed);
}
