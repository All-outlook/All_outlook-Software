void motor_speed(int id, int myspeed) {
  if (myspeed >= 0) {
    analogWrite(motor_right_pin[id], 0);
    analogWrite(motor_left_pin[id], myspeed);

  } else if (myspeed < 0) {
    myspeed = abs(myspeed);
    analogWrite(motor_right_pin[id], myspeed);
    analogWrite(motor_left_pin[id], 0);
  }
}

int MT_last_speed(int MT_degree, int MT_go_degree) {
  float MT_speeeed;
  int power = 220;
  //int theta = MT_go_degree - MT_degree;
  int theta = MT_degree - MT_go_degree;

  MT_speeeed = sin(theta * PI / 180) * power;

  if (1 <= MT_speed && MT_speed <= 120) {
    MT_speeeed = 120;
  } else if (-120 <= MT_speed && MT_speed <= -1) {
    MT_speeeed = -120;
  }
  return MT_speeeed;
}



void MT_stop (int id) {
  digitalWrite(motor_right_pin[id], 0);
  digitalWrite(motor_left_pin[id], 0);
}
