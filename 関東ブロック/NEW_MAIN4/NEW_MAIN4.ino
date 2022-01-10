void setup() {
  all_reset();
  //↑リセットします！！！！
  Serial.begin(115200);


  F_MD_setup();
  F_ESP_setup();
  F_GYRO_setup();
  F_KICCER_SETUP();
  F_LINE_setup();
  F_IR_setup();

  pinMode(41, INPUT);
  delay(1000);
}

int tilt = 0;

void loop() {
  F_ESP_read();
  F_KICCER_loop();
  F_time_read();
  F_GYRO_read();
  F_LINE_read();
  F_IR_read();

  if (digitalRead(41) == 0) {
    if (F_KICCER_judge_V2() == 1) {
      F_KICCER_kick();
    }

    int GYRO_DEGDEG = F_360_correct(F_GYRO_get() - tilt);
    int GO_DEGDEG;
    int SPEED_PEDPED;
    if (F_LINE_get() > 0) {
      Serial.print('_');
      GO_DEGDEG = F_360_correct(F_LINE_get() + F_GYRO_get());
      SPEED_PEDPED = 130;
    } else {
      Serial.print('*');
      GO_DEGDEG = F_IR_wrap_around(F_360_correct(F_IR_get() + F_GYRO_get()));
      SPEED_PEDPED = 150;
    }

    Serial.print(' ');
    Serial.print(GO_DEGDEG);
    
    if (GO_DEGDEG != 0) {
      GO_DEGDEG = F_360_correct(GO_DEGDEG  - F_GYRO_get());
    } else {
      GO_DEGDEG = 0;
    }

    
    F_MD_rotate(GO_DEGDEG, GYRO_DEGDEG, SPEED_PEDPED);



  } else {

    if (F_KICCER_judge_V2() == 1 || F_ESP_switch() == 3) {
      F_KICCER_kick();
    }
    if (F_ESP_switch() == 4) {
      tilt = 45;
    }
    if (F_ESP_switch() == 1) {
      tilt = 0;
    }
    if (F_ESP_switch() == 2) {
      tilt = -45;
    }

    int GYRO_DEGDEG = F_360_correct(F_GYRO_get() - tilt);
    int GO_DEGDEG;

    if (F_ESP_angle() != 0) {
      GO_DEGDEG = F_360_correct(F_ESP_angle()  - F_GYRO_get());
    } else {
      GO_DEGDEG = 0;
    }

    F_MD_rotate(GO_DEGDEG, GYRO_DEGDEG, map(F_ESP_speed(), 0, 100, 40, 254));
  }


  F_GYRO_debug();
  F_LINE_debug();
  F_IR_debug();
  F_KICCER_debug();
  F_MD_debug();

  Serial.println();
}
