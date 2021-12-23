void setup() {
  Serial.begin( 115200 );     // シリアル通信を初期化する。通信速度は9600bps
  Serial.println( "Mega Arduino!" );   // 最初に1回だけメッセージを表示する

  F_ESP_setup();
}



void loop () {
  F_ESP_read();

  Serial.print(F_ESP_angle());
  Serial.print(" : ");
  Serial.print(F_ESP_speed());
  Serial.print(" : ");
  Serial.println(F_ESP_switch());
  
}
