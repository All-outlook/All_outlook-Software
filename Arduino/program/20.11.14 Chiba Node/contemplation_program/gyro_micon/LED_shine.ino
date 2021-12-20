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
