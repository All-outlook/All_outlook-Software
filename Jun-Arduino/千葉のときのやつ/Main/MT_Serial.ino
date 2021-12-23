#include <SoftwareSerial.h>

SoftwareSerial MT0_Serial =  SoftwareSerial(42, 53);//rx,tx
SoftwareSerial MT1_Serial =  SoftwareSerial(43, 54);//rx,tx
SoftwareSerial MT2_Serial =  SoftwareSerial(44, 59);//rx,tx
SoftwareSerial MT3_Serial =  SoftwareSerial(45, 58);//rx,tx


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
