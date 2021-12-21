int MT_turning(float MT_turn_angle) {
  // 回転角度からモーター出力値計算
  // turn 今ロボットが向いてる角度

  int MT_speed = 0; // モーター出力値

  if (5.0 <= MT_turn_angle && MT_turn_angle <= 180.0) {
    //左回り
    MT_speed = map(MT_turn_angle, 0, 180, -40, -150);

  } else if (180.0 <= MT_turn_angle && MT_turn_angle <= 355.0) {
    //右回り
    MT_speed = map(MT_turn_angle, 360, 180, 40, 150);

  } else {
    MT_speed = 0;
  }

  return MT_speed;
}



int MT_straight(int MT_angle, int MT_straight_angle) {
  // 進行角度からモーター出力値計算
  // angle       モーター角度
  // straight   進行角度

  float MT_speed_flo = 0.00; // モーター出力値小数
  int MT_speed = 0; // モーター出力値

  // 進行方向を分解
  int sine_angle = MT_straight_angle - MT_angle;
  MT_speed_flo = sin(sine_angle * PI / 180);

  //出力値調整
  MT_speed = 200 * MT_speed_flo;


  if (MT_speed < 110 && MT_speed > 1) {
    MT_speed = 40;
  } else if (MT_speed < -1 && MT_speed > -110) {
    MT_speed = -40;
  }

  // モーター出力値返します。
  return MT_speed;

}



void  MT_rotate (int id , int myspeed) {
  // モーター１つ回します
  // idでモーター番号指定0~3
  // speedで速度指定
  //  マイナスは90以上
  //  プラスは110以上
  //  id1が怪しい…


  if (myspeed > 0) {
    analogWrite(MT_pin1[id], myspeed);
    analogWrite(MT_pin2[id], 0);

  } else if (myspeed < 0) {
    myspeed = abs(myspeed);
    analogWrite(MT_pin1[id], 0);
    analogWrite(MT_pin2[id], myspeed);
  }

}



void MT_stop (int id) {
  // モーター停止します

  digitalWrite(MT_pin1[id], 1);
  digitalWrite(MT_pin2[id], 1);
}
