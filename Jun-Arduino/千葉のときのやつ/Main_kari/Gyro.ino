int pre_Gyro_recive;

int UART_gyro_degree() {
  int Gyro_recive;
  if ( Serial2.available() ) {       // 受信データがあるか？
    String str = Serial2.readStringUntil('&');
    Gyro_recive = str.toInt() <= 360 ? str.toInt() : pre_Gyro_recive;
//    if (Gyro_recive > 350 || Gyro_recive < 20) {
//      //なんもしない
//    } else if (pre_Gyro_recive + 20 <= Gyro_recive || pre_Gyro_recive - 20 >= Gyro_recive ) {
//      Gyro_recive = pre_Gyro_recive;
//    }

    //while(Serial2.available() > 0){
    //char t = Serial2.read();
    //}
  }

  pre_Gyro_recive = Gyro_recive;
  return Gyro_recive;
}

int Gyro_attitude(int gyro) {
  //角度に応じて0,100-200のパワーに変換
  int gyro_attitude;
  if (0 <= gyro & gyro <= 20 | 340 <= gyro & gyro <= 360) {
    gyro_attitude = 0;
  } else if (20 < gyro & gyro <= 180) {
    gyro_attitude = map(gyro, 20, 180, 100, 200);
  } else if (180 < gyro & gyro <= 340) {
    gyro_attitude = map(gyro, 180, 340, -200, -100);
  } else {
    gyro_attitude = 0;
  }
  return gyro_attitude;
}
