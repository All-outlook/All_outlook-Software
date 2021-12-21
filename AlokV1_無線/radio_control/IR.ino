int mawarikomi(int IR_angle) {

  // IR_angle もとのIRセンサから得た値
  // 回り込み処理掛けてリターンしてあげてね
  int decision_angle = -1;


  if (140 <= IR_angle & IR_angle <= 150) {
    decision_angle = 270;
  } else if (150 < IR_angle & IR_angle <= 190) {
    decision_angle = 90;

  } else if (80 <= IR_angle & IR_angle <  140) {
    decision_angle = 180;
  } else if (190 < IR_angle & IR_angle <= 250) {
    decision_angle = 180;

  } else if (60 <= IR_angle & IR_angle < 80) {
    decision_angle = 175;
  } else if (250 < IR_angle & IR_angle <= 270) {
    decision_angle = 185;

  } else if (340 <= IR_angle | IR_angle < 60) {
    decision_angle = 90;
  } else if (270 < IR_angle & IR_angle <= 310) {
    decision_angle = 270 ;

  } else if (310 > IR_angle | IR_angle > 340) {
    decision_angle = 0;
  }




  return decision_angle;
}














int mawarikomi_IRkanpeki(int IR_angle) {

  // IR_angle もとのIRセンサから得た値
  // 回り込み処理掛けてリターンしてあげてね
  int decision_angle = -1;


  if (160 <= IR_angle & IR_angle <= 180) {
    decision_angle = 90;
  } else if (180 < IR_angle & IR_angle <= 200) {
    decision_angle = 270;

  } else if (90 <= IR_angle & IR_angle < 160) {
    decision_angle = 180;
  } else if (200 < IR_angle & IR_angle <= 270) {
    decision_angle = 180;

  } else if (60 <= IR_angle & IR_angle < 90) {
    decision_angle = 175;
  } else if (270 < IR_angle & IR_angle <= 300) {
    decision_angle = 185;

  } else if (40 <= IR_angle & IR_angle < 60) {
    decision_angle = IR_angle + 70;
  } else if (320 < IR_angle & IR_angle <= 340) {
    decision_angle = IR_angle - 70 ;

  } else if (40 > IR_angle | IR_angle > 320) {
    decision_angle = 0;
  }




  return decision_angle;
}


int IR_read() {
  byte knob;
  int degree;

  knob = 'A';
  digitalWrite(SS, LOW); //送信
  SPI.transfer(knob);
  digitalWrite(SS, HIGH);
  delayMicroseconds(100);

  digitalWrite(SS, LOW); //受信
  degree = SPI.transfer(0);
  digitalWrite(SS, HIGH);

  // Serial.print("knob:"); Serial.purint(knob);

  //Serial.print(", degree:");

  degree = degree * 2;
  //degree -= 79;
  degree = adjust_angle(degree);

  //Serial.print(degree); Serial.println("°   ");

  return degree;
}
