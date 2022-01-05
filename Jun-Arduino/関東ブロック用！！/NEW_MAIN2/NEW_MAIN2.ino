void setup() {
  all_reset();
  //↑リセットします！！！！
  Serial.begin(115200);


  F_MD_setup();
  F_ESP_setup();
  F_GYRO_setup();
  F_KICCER_SETUP();
  delay(1000);
}

int tilt = 0;

void loop() {
  F_ESP_read();
  F_time_read();
  F_KICCER_loop();
  F_GYRO_loop();



  if (F_ESP_switch() == 3) {
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

  int GYRO_DEGDEG = F_360_correct(F_GYRO_read() - tilt);
  int GO_DEGDEG;
  
  if (F_ESP_angle() != 0) {
    GO_DEGDEG = F_360_correct(F_ESP_angle()  - F_GYRO_read());
  }else{
    GO_DEGDEG = 0;
  }
  
  F_MD_rotate(GO_DEGDEG, GYRO_DEGDEG, map(F_ESP_speed(), 0, 100, 40, 254));

  Serial.println(GYRO_DEGDEG);

}
