void setup() {
  F_fled_setup();
  F_ESP_setup();
  F_BUZ_setup();
  Serial.begin(38400);
}

void loop() {
  F_ESP_read();

  
//  F_fled_start();
  F_fled_RGB_show(5, 30, 17);
  F_fled_angle_show(F_ESP_angle(), 50, 10, 3);
  F_fled_finish();

  Serial.println(F_ESP_angle());

  if(F_ESP_switch() == 1){
    F_BUZ_doremi();
  }else if(F_ESP_switch() == 2){
    F_BUZ_koinobori();
  }else if(F_ESP_switch() == 3){
    F_BUZ_DarthVader();
  }else if(F_ESP_switch() == 4){
    F_BUZ_ElectricalParade();
  }
}
