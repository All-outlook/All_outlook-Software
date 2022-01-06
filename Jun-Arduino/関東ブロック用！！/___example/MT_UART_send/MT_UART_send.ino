void setup() {
  F_MD_setup();
  all_reset();
}


void loop() {


  //  test();
  int in = 0;
  for (int id = 0; id < 800; id++) {
    int i = 40;
    kurukuru(-i, -i, i, i);
    delay(10);
  }

  for (int id = 0; id < 80; id++) {
    int i = 254;
    kurukuru(i, i, -i, -i);
    delay(10);
  }


}


void kurukuru(int a, int b, int c, int d) {
  F_speed_send(0, a);
  F_speed_send(1, b);
  F_speed_send(2, c);
  F_speed_send(3, d);
}
