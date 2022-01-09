SoftwareSerial MT_R_Serial(42, 53); // rx,tx
SoftwareSerial MT_L_Serial(45, 58); // rx,tx

#define PI 3.14
const int MT_angle[] = {45, 135, 225, 315};
int IL_speed;
int theta;

int F_MT_Il_speed(int id, int either) {
  theta = MT_angle[id] - either;
  IL_speed = sin(theta * PI / 180) * power;
  return IL_speed;
}

int F_max_speed(float ratio, int MT_value) {
  MT_value *= ratio;

  if (MT_value > 254) {
    MT_value = 254;
  } else if (MT_value < -254) {
    MT_value = -254;
  } else if (-20 < MT_value & MT_speed < 20) {
    MT_value = 0;
  } else if (20 <= MT_value & MT_value < 40) {
    MT_value = 40;
  } else if (-40 <= MT_value & MT_value < -20) {
    MT_value = -40;
  }
  return MT_value;
}
