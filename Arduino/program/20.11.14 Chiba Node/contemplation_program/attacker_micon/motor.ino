int MT_last_speed(int MT_degree, int MT_go_degree) {
  float MT_speeeed;
  int power = 255;
  int theta = MT_degree - MT_go_degree;

  MT_speeeed = sin(theta * PI / 180) * power;

  if (1 <= MT_speeeed && MT_speeeed <= 100) {
    MT_speeeed = 100;
  } else if (-100 <= MT_speeeed && MT_speeeed <= -1) {
    MT_speeeed = -100;
  }
  return MT_speeeed;
}
