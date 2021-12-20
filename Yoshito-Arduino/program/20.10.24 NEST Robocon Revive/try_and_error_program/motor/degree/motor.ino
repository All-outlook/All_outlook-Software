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



int MT_last_speed(int MT_new_degree, int MT_go_degree) {
  float MT_speed;
  int power = 230;
  //int theta = MT_go_degree - MT_new_degree;
  int theta = MT_new_degree - MT_go_degree;

  MT_speed = sin(theta * PI / 180) * power;

  if (1 <= MT_speed && MT_speed <= 120) {
    MT_speed = 120;
  } else if (-120 <= MT_speed && MT_speed <= -1) {
    MT_speed = -120;
  }
  return MT_speed;
}



void MT_stop (int id) {
  digitalWrite(motor_right[id], 0);
  digitalWrite(motor_left[id], 0);
}
