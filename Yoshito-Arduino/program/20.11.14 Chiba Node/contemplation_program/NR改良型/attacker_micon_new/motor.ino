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
  int power = 255;
  //int theta = MT_go_degree - MT_degree;
  int theta = MT_degree - MT_go_degree;

  MT_speeeed = sin(theta * PI / 180) * power;

  if (1 <= MT_speeeed && MT_speeeed <= 100) {
    MT_speeeed = 100;
  } else if (-100 <= MT_speeeed && MT_speeeed <= -1) {
    MT_speeeed = -100;
  }
  return MT_speeeed;
}

void MT_stop (int id) {
  digitalWrite(motor_right_pin[id], LOW);
  digitalWrite(motor_left_pin[id], LOW);
}

void MT_brake (int id) {
  digitalWrite(motor_right_pin[id], HIGH);
  digitalWrite(motor_left_pin[id], HIGH);
}
