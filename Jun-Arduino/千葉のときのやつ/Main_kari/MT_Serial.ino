#include <SoftwareSerial.h>

SoftwareSerial MT0_Serial =  SoftwareSerial(42, 53);//rx,tx
SoftwareSerial MT1_Serial =  SoftwareSerial(43, 54);//rx,tx
SoftwareSerial MT2_Serial =  SoftwareSerial(44, 59);//rx,tx
SoftwareSerial MT3_Serial =  SoftwareSerial(45, 58);//rx,tx

int num_judg(int num) {
  int result;
  if (num > 0) {
    result = 1;
  } else if (num < 0) {
    result = -1;
  } else if (num == 0) {
    result = 0;
  }
  return result;
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



void Serial_setup() {
  pinMode(42, INPUT);
  pinMode(53, OUTPUT);
  pinMode(43, INPUT);
  pinMode(54, OUTPUT);
  pinMode(44, INPUT);
  pinMode(59, OUTPUT);
  pinMode(45, INPUT);
  pinMode(58, OUTPUT);
  MT0_Serial.begin(9600);
  MT1_Serial.begin(9600);
  MT2_Serial.begin(9600);
  MT3_Serial.begin(9600);
}


//void ALL_UART(int value) {
//  for (int i = 0; i <= 3; i++) {
//    MT_UART(i, value);
//  }
//}

void MT_UART(int id, int knob) { //knob == 送信値
  if (id == 0) {
    MT0_Serial.print(knob);
    MT0_Serial.print('&');
    MT0_Serial.flush();
  } else if (id == 1) {
    MT1_Serial.print(knob);
    MT1_Serial.print('&');
    MT1_Serial.flush();
  } else if (id == 2) {
    MT2_Serial.print(knob);
    MT2_Serial.print('&');
    MT2_Serial.flush();
  } else if (id == 3) {
    MT3_Serial.print(knob);
    MT3_Serial.print('&');
    MT3_Serial.flush();
  } else {
    //なし
  }
}

void speed_send(int id , int mySpeed) {
  if (mySpeed > 0) {
    //正転 10
    MT_UART(id, 10);
    MT_UART(id, mySpeed);

  } else if (mySpeed < 0) {
    //後転 20
    MT_UART(id, 20);
    MT_UART(id, abs(mySpeed));

  } else if (mySpeed == 0) {
    //ブレーキ 40
    MT_UART(id, 40);
  }
}
