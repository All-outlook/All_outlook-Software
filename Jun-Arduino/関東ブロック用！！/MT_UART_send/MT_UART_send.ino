void setup() {
  F_MD_setup();
  all_reset();
}


void loop() {


  test();
  //  int in = 0;
  //  for (int i = 0; i < 5000; i++) {
  //    kurukuru(220, 250, 250, 220);
  //  }
  //
  //  for (int i = 0; i < 150; i++) {
  //    kurukuru(in, in, in, in);
  //  }
  //
  //  for (int i = 0; i < 5000; i++) {
  //    kurukuru(-250, -250, -250, -250);
  //  }
  //
  //  for (int i = 0; i < 150; i++) {
  //    kurukuru(in, in, in, in);
  //  }

}


void kurukuru(int a, int b, int c, int d) {
  F_speed_send(0, a);
  F_speed_send(1, b);
  F_speed_send(2, c);
  F_speed_send(3, d);
}
