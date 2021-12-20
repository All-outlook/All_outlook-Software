void motor_speed(int id, int myspeed) {
  if (myspeed >= 0) {
    analogWrite(motor_right[id], 0);
    analogWrite(motor_left[id], myspeed);

  } else if (myspeed < 0) {
    myspeed = abs(myspeed);
    analogWrite(motor_right[id], myspeed);
    analogWrite(motor_left[id], 0);
  }
}

void MT_stop (int id) {
  digitalWrite(motor_right[id], 0);
  digitalWrite(motor_left[id], 0);
}
