//#include <SPI.h>
#include <SoftwareSerialParity.h>

const int A_PIN = 2;
const int B_PIN = 3;
const int C_PIN = 4;
const int LED_PIN = 5;
const int LED_NUM = 32;
const int READ_PIN[] = {A0, A1, A2, A3};

const int C_BORDER_WHITE_LINE = 250;


int line_value[32];

SoftwareSerialParity LINESerial(7, 10); //rx,tx


void setup() {
  Serial.begin(38400);
  LINESerial.begin(38400, ODD);
  pinMode(10,OUTPUT);
  F_line_setup();
}


int go_angle;

void loop() {
  F_pixle_setup(250, 1, 1);
  
//  SPCR |= bit(SPE);
//  pinMode(MISO, OUTPUT);
//  SPI.attachInterrupt();
  for (int id = 0; id <= 7; id++) {
    F_line_choice(id);
    line_value[id] = analogRead(READ_PIN[0]);
    line_value[id + 8] = analogRead(READ_PIN[1]);
    line_value[id + 16] = analogRead(READ_PIN[2]);
    line_value[id + 24] = analogRead(READ_PIN[3]);
  }

  Serial.print("Moto_value       : ");
  for (int id = 0; id <= 31; id++) {
    Serial.print(line_value[id]);
    Serial.print(":");
  }
  Serial.println();

  // 値の判定 0か１か
  Serial.print("Get_value       : ");
  for (int id = 0; id <= 31; id++) {
    line_value[id] = line_value[id] >= C_BORDER_WHITE_LINE ? 1 : 0;
    Serial.print(line_value[id]);
    Serial.print(", ");
  }
  Serial.println();

  // 配列の一番前を位置にする
  // ラインがないときは31になる
  int angle_calibration = 0;
  while (line_value[0] == 0 && angle_calibration <= 30) {
    for (int id = 0; id <= 30; id++) {
      line_value[id] = line_value[id + 1];
    }
    line_value[31] = 0;
    angle_calibration += 1;
  }

  Serial.print("Get_hosei_value : ");
  for (int id = 0; id <= 31; id++) {
    Serial.print(line_value[id]);
    Serial.print(", ");
  }
  Serial.println(angle_calibration);

  //連続している0を観測する
  int continue_num[16][32];
  int dummy_data = -5;
  for (int i = 0; i <= 15; i++) {
    for (int j = 0; j <= 31; j++) {
      continue_num[i][j] = dummy_data;
    }
  }

  // ーーーー１番大きい範囲調べるーーーー
  int num_count[16];
  int max_id;
  int max_count = 0;

  if (angle_calibration < 31) {
    int line_lump_count = 0;
    int line_private_count = 0;
    //ライン上にいた場合
    for (int id = 0; id <= 31; id++) {
      if (line_value[id] == 0) {
        continue_num[line_lump_count][line_private_count] = id;
        line_private_count += 1;
      } else if (continue_num[line_lump_count][line_private_count - 1] + 1 == id) {
        line_lump_count += 1;
      }
      if (line_value[id] == 1) {
        line_private_count = 0;
      }
    }

    //データ量カウント
    for (int i = 0; i <= 15; i++) {
      if (continue_num[i][0] != dummy_data) {
        //idが入ってた場合
        int count = 0;
        int j = 0;
        while (continue_num[i][j] != dummy_data) {
          j += 1;
          count += 1;
        }
        num_count[i] = count;
      } else {
        //idが入ってなかった場合
        num_count[i] = 0;
      }
    }

    //最大量出してる塊見つける
    for (int i = 0; i <= 15; i++) {
      max_count = max(max_count, num_count[i]);
      if (max_count == num_count[i]) {
        max_id = i;
      }
    }


    //最大量出してる塊の平均出して角度情報に！！
    int sum = 0;
    int average;
    int line_angle;
    Serial.print("line_keisanti");
    Serial.print(" : ");
    Serial.print(max_id);
    Serial.print(":");
    for (int j = 0; j <= 31; j++) {
      if (continue_num[max_id][j] != dummy_data) {
        sum += continue_num[max_id][j];
        Serial.print(continue_num[max_id][j] + angle_calibration);
        Serial.print(", ");
      }
    }
    Serial.println("");
    average = (sum / max_count) * 100;

    line_angle = (average / 100) * 11.25;


    line_angle = line_angle - (angle_calibration * 11.25);
    Serial.print("line_value : ");
    Serial.println(line_angle);
    line_angle = 180 + line_angle;

    go_angle = line_angle > 0 ? line_angle : line_angle + 360 ;
    go_angle = line_angle > 360 ? line_angle - 360 : line_angle ;

    // ライン上にいた場合 終わり
  } else {
    go_angle = 0;
  }

  Serial.print("Final_value : ");
  Serial.println(go_angle);
  Serial.println();

  //  Serial.println(max_id);
  //  Serial.println(max_count);
  //  for (int i = 0; i <= 15; i++) {
  //    //delay(10);
  //    Serial.print(i);
  //    Serial.print(":");
  //    Serial.print(num_count[i]);
  //    Serial.print(" : ");
  //    for (int j = 0; j <= 31; j++) {
  //      //Serial.print(j);
  //      //Serial.print(":");
  //      Serial.print(continue_num[i][j]);
  //      Serial.print(", ");
  //    }
  //    Serial.println(" ");
  //}

  LINESerial.write(go_angle);
  LINESerial.flush();
}
