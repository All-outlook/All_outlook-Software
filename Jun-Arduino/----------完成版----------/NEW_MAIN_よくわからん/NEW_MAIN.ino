void setup() {
  F_all_reset();
  F_BUZ_setup();
  F_BUZ_frog();

  Serial.begin(38400);

  F_MD_setup();
  F_SWITCH_setup();
  F_fled_setup();
  F_GYRO_setup();
  F_IR_setup();

}

int i = 1;

void loop() {
  F_time_read(); //今回の時間取得！！
  F_fled_start();// フレームのLEDスタート

  if (F_SWITCH_VALUE() == 0) {
    /*
       対戦用プログラムスタート！！！！！
    */
    F_fled_RGB_show(0, 0, 0/*8, 8, 0*/); //動いていることを示す


    int GYRO_DEGDEG = F_GYRO_read();

    int IR_DEGDEG = F_IR_wrap_around(F_IR_read());

    //回転させるよ*************************************
    F_MD_rotate(IR_DEGDEG , GYRO_DEGDEG, 5);
    //    Serial.print(IR_DEGDEG);
    //    Serial.print(':');
    //    Serial.print(GYRO_DEGDEG);
    //    Serial.print(',');


    //    //F_fled_angle_show(i, 0, 0, 100);
    //    i ++;
    //    if (i >= 360) {
    //      i = 1;
    //    }
    //    //*******************************************ここまで

  } else {
    /*
       まだだ、まだ始まらない
    */
    F_fled_RGB_show(0, 0, 0 /* 3, 10, 0 */ ); //動いていないことを示す
    F_MD_rotate(0 , 0, 0);//モーターは止まっとけ

  }
  F_fled_finish();
}











































void mawarudake() {
  int kyuukei = 10;
  for (int i = 0; i < 150; i++) {
    kurukuru(80, 80, -80, -80);
    delay(1);
  }
  for (int i = 0; i < kyuukei; i++) {
    kurukuru(0, 0, 0, 0);
    delay(1);
  }

  for (int i = 0; i < 150; i++) {
    kurukuru(-200, 200, 200, -200);
    delay(1);
  }
  for (int i = 0; i < kyuukei; i++) {
    kurukuru(0, 0, 0, 0);
    delay(1);
  }

  for (int i = 0; i < 150; i++) {
    kurukuru(-200, -200, 200, 200);
    delay(1);
  }
  for (int i = 0; i < kyuukei; i++) {
    kurukuru(0, 0, 0, 0);
    delay(1);
  }

  for (int i = 0; i < 150; i++) {
    kurukuru(200, -200, -200, 200);
    delay(1);
  }
  for (int i = 0; i < kyuukei; i++) {
    kurukuru(0, 0, 0, 0);
    delay(1);
  }

}


void kurukuru(int a, int b, int c, int d) {
  F_speed_send(0, a);
  F_speed_send(1, b);
  F_speed_send(2, c);
  F_speed_send(3, d);
}
