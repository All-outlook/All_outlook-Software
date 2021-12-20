#define PI 3.1415
int MT_angle[] = {45, 135, 225, 315};

void F_MT_setup(){
  for(int id = 0; id <= 3; id++){
    pinMode(MT_FORWARD[id], OUTPUT);
    pinMode(MT_REVERSAL[id], OUTPUT);
  }
}

void F_motor_speed(int id, int myspeed) {
  if (myspeed >= 0) {
    analogWrite(MT_FORWARD[id], 0);
    analogWrite(MT_REVERSAL[id], myspeed);

  } else if (myspeed < 0) {
    myspeed = abs(myspeed);
    analogWrite(MT_FORWARD[id], myspeed);
    analogWrite(MT_REVERSAL[id], 0);
  }
}

int F_MT_Il_speed(int id, int either_degree) {
  int MT_speed;
  int power = 230;
  int theta = MT_angle[id] - either_degree;

  MT_speed = sin(theta * PI / 180) * power;

  if (1 <= MT_speed && MT_speed <= 120) {
    MT_speed = 120;
  } else if (-120 <= MT_speed && MT_speed <= -1) {
    MT_speed = -120;
  }
  return MT_speed;
}

void F_MT_stop (int id) {
  digitalWrite(MT_FORWARD[id], LOW);
  digitalWrite(MT_REVERSAL[id], LOW);
}

void F_MT_brake (int id) {
  digitalWrite(MT_FORWARD[id], HIGH);
  digitalWrite(MT_REVERSAL[id], HIGH);
}
