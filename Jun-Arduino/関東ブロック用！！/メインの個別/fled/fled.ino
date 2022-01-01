void setup() {
  F_fled_setup();
}

void loop() {
  for (int i = 0; i <= 360; i++) {
    F_fled_start();
    F_fled_RGB_show(5, 30, 17);
    F_fled_angle_show(i, 50, 10, 3);
    F_fled_finish();
  }
}
