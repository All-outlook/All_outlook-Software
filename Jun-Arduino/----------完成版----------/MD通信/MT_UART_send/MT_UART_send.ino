void setup() {
  F_MD_setup();
  all_reset();
}


void loop() {
  int in = -1;
  for (int i = 0; i < 5000; i++) {
    kurukuru(220, 250, 250, 220);
    //delay(1);
  }

  for (int i = 0; i < 150; i++) {
    kurukuru(in, in, in, in);
  }
  kurukuru(0, 0, 0, 0);
  kurukuru(0, 0, 0, 0);

  for (int i = 0; i < 5000; i++) {
    kurukuru(-250, -250, -250, -250);
    //delay(1);
  }

  for (int i = 0; i < 150; i++) {
    kurukuru(in, in, in, in);
  }
  kurukuru(0, 0, 0, 0);
  kurukuru(0, 0, 0, 0);

  //  int kyuukei = 5;
  //  for (int i = 0; i < 150; i++) {
  //    kurukuru(200, 200, -200, -200);
  //    delay(1);
  //  }
  //  for (int i = 0; i < kyuukei; i++) {
  //    kurukuru(0, 0, 0, 0);
  //    delay(1);
  //  }
  //
  //  for (int i = 0; i < 150; i++) {
  //    kurukuru(-200, 200, 200, -200);
  //    delay(1);
  //  }
  //  for (int i = 0; i < kyuukei; i++) {
  //    kurukuru(0, 0, 0, 0);
  //    delay(1);
  //  }
  //
  //  for (int i = 0; i < 150; i++) {
  //    kurukuru(-200, -200, 200, 200);
  //    delay(1);
  //  }
  //  for (int i = 0; i < kyuukei; i++) {
  //    kurukuru(0, 0, 0, 0);
  //    delay(1);
  //  }
  //
  //  for (int i = 0; i < 150; i++) {
  //    kurukuru(200, -200, -200, 200);
  //    delay(1);
  //  }
  //  for (int i = 0; i < kyuukei; i++) {
  //    kurukuru(0, 0, 0, 0);
  //    delay(1);
  //  }



  //  for (int i = 0; i < 100; i++) {
  //    for (int i = 0; i < 4; i++) {
  //      speed_send(i, 0);
  //    }
  //    delay(1);
  //  }
  //
  //  for (int i = 0; i < 100; i++) {
  //    for (int i = 0; i < 2; i++) {
  //      speed_send(i, 200);
  //      speed_send(i + 2, -200);
  //    }
  //    delay(1 );
  //  }
  //
  //  for (int i = 0; i < 100; i++) {
  //    for (int i = 0; i < 4; i++) {
  //      speed_send(i, 0);
  //    }
  //    delay(1);
  //  }
  //  for (int i = 0; i < 100; i++) {
  //    for (int i = 0; i < 2; i++) {
  //      speed_send(i, -200);
  //      speed_send(i + 2, 200);
  //    }
  //    delay(1);
  //  }
}


void kurukuru(int a, int b, int c, int d) {
  F_speed_send(0, a);
  F_speed_send(1, b);
  F_speed_send(2, c);
  F_speed_send(3, d);
}
