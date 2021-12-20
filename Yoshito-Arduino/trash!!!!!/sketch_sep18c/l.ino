void motor_speed(int id ,int myspeed) {
  if (myspeed >= 0) {
    analogWrite(motor_right[id], myspeed);
    analogWrite(motor_left[id], 0);

  } else if (myspeed < 0) {
    abs(myspeed);
    analogWrite(motor_right[id], 0);
    analogWrite(motor_left[id], myspeed);
  }
}
