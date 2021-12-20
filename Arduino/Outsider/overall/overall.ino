// jyro_start();にエラーが来たらloopの}が消えちゃってる可能性大


//----------オルタスイッチ----------
int switch_led = 10;//LED
int button     = 11;//タクトスイッチ

unsigned int period_count = 0;

//----------ライン----------

int line_threshold[] = {500, 450, 600, 500};//しきい値指定
int line_pin[] = {A0, A1, A2, A3};
int RED_LED_pin[] = {40, 41, 42, 43};
int line_analog_value[] = {400, 400, 400, 400}; // ライン読み取り値 関数内用


int li_val[] = {0, 0, 0, 0}; // ライン読み取り値 制御用

int Air_rest = 0; // 強制的に回んないでって叩き込む 0:回る 1:回んない
int Air_rest_goal = 0; // いつまで回らない周期かメモっとこ

//----------モーター----------
#define PI 3.141592653589793

#include <SPI.h>

int MT_pin1[] = {2, 4, 6, 8};
int MT_pin2[] = {3, 5, 7, 9};

int MT_angle[] = {45, 135, 225, 315}; // モーター配置角度

int MT_direction[] = { -1, -1, 1, 1}; // モーター回転方向メモ  1:正転 -1:後転
int pre_MT_direction[] = { -1, -1, 1, 1}; // 前回のメーモ

int MT_rest[] = {0, 0, 0, 0}; // 強制的に回んないでって叩き込む 0:回る 1:回んない
int MT_rest_goal[] = {0, 0, 0, 0}; // いつまで回らない周期かメモっとこ

int MT_force[] = {0, 0, 0, 0}; // 強制的に回れって叩き込む 0:普通 1:強制的に回る
int MT_force_boot[] = {0, 0, 0, 0}; // いつまで強制するかメモっとこ
int MT_force_goal[] = {0, 0, 0, 0}; // いつまで次の強制しないかメモっとこ

//モータースピードの調整用
int MT_gyro_speed[] = {0, 0, 0, 0};
int MT_angle_speed[] = {0, 0, 0, 0};

int MT_speed[] = {0, 0, 0, 0}; // モーター回転速度合計値


int go_angle = 0; //進む角度


//----------緑と白のLED----------

int GN_WT_LED_pin[] = {44, 45, 46, 47};

//----------ジャイロスイッチ----------
int gyro_switch = 12;

float gyro_reference = 0;  //


void setup() {
  // オルタスイッチ
  pinMode(switch_led, OUTPUT);
  pinMode(button, INPUT);

  // ライン
  for (int id = 0; id <= 3; id += 1) {
    pinMode(line_pin[id], INPUT);
    pinMode(RED_LED_pin[id], OUTPUT);
  }


  // モーター
  for (int id = 0; id <= 3; id += 1) {
    pinMode(MT_pin1[id], OUTPUT);
    pinMode(MT_pin2[id], OUTPUT);
  }

  //緑と白のLED
  for (int id = 0; id <= 3; id += 1) {
    pinMode(GN_WT_LED_pin[id], OUTPUT);
    digitalWrite(GN_WT_LED_pin[0], LOW);
  }

  pinMode(gyro_switch, INPUT);

  Serial.begin(38400);
  gyro_start();
  digitalWrite(GN_WT_LED_pin[3], HIGH);
  Serial.println();
  Serial.println("Let's Go!!");



}

unsigned long gauge = 0;
int gyro_switch_count = 0;
int switch_count = 0;

void loop() {
  //------------------------------まずはジャイロ初期化しよ------------------------------
  if (gyro_switch_count == 0) {
    gauge = 0;
    while (!digitalRead(gyro_switch)) {
      gauge++;
    }
    if (gauge > 10000) {
      gyro_reference = gyro();
    }
    digitalWrite(GN_WT_LED_pin[2], HIGH);
    Serial.println("gyro_reset");
    gyro_switch_count = 1;
  }

  //------------------------------んじゃスタートスイッチ待ちます------------------------------
  if (switch_count == 0) {
    gauge = 0;
    while (!digitalRead(button)) {
      gauge++;
      gyro(); // ジャイロ計算されないのを防ぐため
    }
    if (gauge > 10000) {
    }
    digitalWrite(switch_led, HIGH);
    Serial.println("robot_start");
    switch_count = 1;
  }

  //------------------------------今の周期確認します!!------------------------------
  if (period_count == 1000) {
    period_count = 0;
  }
  period_count += 1;


  if (period_count >= 950 | 500 >= period_count & period_count >= 450) {
    digitalWrite(GN_WT_LED_pin[0], HIGH);
  } else {
    digitalWrite(GN_WT_LED_pin[0], LOW);
  }

  //------------------------------ライン読んどこっかな------------------------------
  for (int id = 0; id <= 3; id += 1) {
    li_val[id] = line_read(id);
  }

  //------------------------------よし。ジャイロ読んどこ------------------------------
  int gyro_value = gyro();



  //------------------------------よし。IR読んどこ------------------------------
  int IR_value_angle = 0;     //ボールの角度
  int IR_value_distance = 0;  //ボールの距離
  //↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑ここほんとはSPIの値いれるんだよ。わかる？？？？？？？？？？？？？？？？？？


  //こっからメインプログラムかいていいよおおおおおおおおおおおおおおおおおおおおおおおおおおおおおお

  //-------------------------------------------------------------------------------------------------------------------------------


  //A_じゃあまずはモーターのスピードを決めていくよ
  //A-1 てことで角度補正

  for (int id = 0; id <= 3; id += 1) {
    MT_gyro_speed[id] = MT_turning(gyro_value);
  }



  //A-2 ラインさけます
  int line_last_angle = 0; //-1だったら動かない

  int line_4 = li_val[0] * 1000 + li_val[1] * 100 + li_val[2] * 10 + li_val[3];


  if (line_4 == 0) {
    line_last_angle = -1;
  } else if (line_4 == 1) {
    line_last_angle = 90;
  } else if (line_4 == 10) {
    line_last_angle = 0;
  } else if (line_4 == 11) {
    line_last_angle = 45;
  } else if (line_4 == 100) {
    line_last_angle = 270;
  } else if (line_4 == 101) {
    line_last_angle = -1;
  } else if (line_4 == 110) {
    line_last_angle = 315;
  } else if (line_4 == 111) {
    line_last_angle = 0;
  } else if (line_4 == 1000) {
    line_last_angle = 180;
  } else if (line_4 == 1001) {
    line_last_angle = 135;
  } else if (line_4 == 1010) {
    line_last_angle = -1;
  } else if (line_4 == 1011) {
    line_last_angle = 90;
  } else if (line_4 == 1100) {
    line_last_angle = 225;
  } else if (line_4 == 1101) {
    line_last_angle = 180;
  } else if (line_4 == 1110) {
    line_last_angle = 270;
  } else if (line_4 == 1111) {
    line_last_angle = -1;
  }
  Serial.print(" line:");
  Serial.print(line_last_angle);


  //A-3 ボール追います
  IR_value_angle = 60; //入力値 実験用だよおおおおおおおおおおおおおおおおおおおおおおおおおおおおおおおおおおおおおおおお


  //ここに回り込み
  IR_value_angle = 60 ;//mawarikomi(IR_value_angle);
  //ここまで（回り込み）


  int IR_last_angle = adjust_angle(IR_value_angle); //最終的な進行方向代

  Serial.print(" IR:");
  Serial.print(IR_last_angle);

  //A-4
  //ラインとボールで出てきた値足して進行方向決めるよ
  if (line_last_angle == -1) {
    go_angle = IR_last_angle;
  } else {
    go_angle = adjust_angle(add_angle(IR_last_angle, line_last_angle, 10));
  }

  Serial.print(" goukei_kakudo:");
  Serial.print(go_angle);


  for (int id = 0; id <= 3; id += 1) {
    MT_angle_speed[id] = MT_straight(MT_angle[id], go_angle);
  }


  //A-5 全部足そ
  for (int id = 0; id <= 3; id += 1) {
    MT_speed[id] = (MT_angle_speed[id] * 0.7) + (MT_gyro_speed[id] * 0.3);
    //MT_speed[id] = MT_angle_speed[id];
  }

  //------------------------------------------------------------------------------------------------------

  //B_モーター回転方向メモっとこかな
  //  ついでに回転方向変わったか確認してあげよう!
  for (int id = 0; id <= 3; id += 1) {
    if (MT_speed[id] > 0) {
      MT_direction[id] = 1;
    } else if (MT_speed[id] < 0) {
      MT_direction[id] = -1;
    } else if (MT_speed[id] == 0) {
      MT_direction[id] = 0;
    }

    if (MT_direction[id] == 0) {

    } else if (pre_MT_direction[id] == 0) {

    } else if (MT_direction[id] != pre_MT_direction[id]) {
      // 前回と違う値が来たとき！！
      // 20回は止まるように
      MT_rest[id] = 1;
      MT_rest_goal[id] = goal_count(20);
    }

    if (period_count == MT_rest_goal[id]) {
      // んじゃ30回やったか確認
      MT_rest[id] = 0;
      MT_rest_goal[id] = -1;
    }

  }

  //C_ロボットが空にないか確認しとこう
  //  ついでに降りてからもちょっと待とう
  if ( line_air() == 1) {
    // 1(空中)が来たとき！！
    // 以後300回は止まるように
    Air_rest = 1;
    Air_rest_goal = goal_count(300);

    digitalWrite(GN_WT_LED_pin[1], HIGH);
  } else {
    digitalWrite(GN_WT_LED_pin[1], LOW);
  }

  if (period_count == Air_rest_goal) {
    // んじゃ300回やったか確認
    Air_rest = 0;
    Air_rest_goal = -1;
  }


  //D_モーター送る前最後の工程
  //  な、なんと130以下のspeedはモーター加速(200)します！
  for (int id = 0; id <= 3; id += 1) {
    bool zettai = ( 0 < MT_speed[id] & MT_speed[id] <= 130 ) | ( -130 <= MT_speed[id] & MT_speed[id] < 0 ) ;
    bool nanashi = MT_force[id] == 0;

    if (zettai & nanashi) {
      MT_force[id] = 1;
      MT_force_boot[id] = goal_count(4);
      MT_force_goal[id] = goal_count(500);
    }
    if (period_count == MT_force_boot[id] ) {
      // んじゃ4回やったか確認
      MT_force[id] = 2;
      MT_force_boot[id] = -1;
    }
    if (period_count == MT_force_goal[id]) {
      // んじゃ500回やったか確認
      MT_force_goal[id] = 0;
      MT_force[id] = 0;
    }
  }


  //    //E_次はモーター回すよ(シリアル有り)
  //    Serial.print("  sora_stop:");
  //    Serial.print(Air_rest);
  //
  Serial.print("  gyro:");
  Serial.print(gyro_value);

  for (int id = 0; id <= 3; id += 1) {
    Serial.print("  ");
    Serial.print(id);
    Serial.print(":");
    Serial.print(MT_force[id]);
    Serial.print(":");
    if (MT_speed[id] == 0 | MT_rest[id] == 1 | Air_rest == 1) {
      // まずはモーター止めるとき
      MT_stop(id);
      Serial.print("stop");
      MT_force[id] = 0; // ここで強制動作切ります！！
    } else if (MT_force[id] == 1) {
      // 強制200で回すとき
      if (MT_direction[id] == 1) {
        // 正転
        MT_rotate(id, 200);
        Serial.print("seiten");
      } else if (MT_direction[id] == -1) {
        // 後転
        MT_rotate(id, -200);
        Serial.print("kouten");
      }

    } else if (MT_rest[id] == 0) {
      MT_rotate(id, MT_speed[id]);
      Serial.print(MT_speed[id]);
    }
  }
  Serial.println();


  //  //E_次はモーター回すよ(シリアルなし)
  //  for (int id = 0; id <= 3; id += 1) {
  //    if (MT_speed[id] == 0 | MT_rest[id] == 1 | Air_rest == 1) {
  //      // まずはモーター止めるとき
  //      MT_stop(id);
  //      MT_force[id] = 0; // ここで強制動作切ります！！
  //    } else if (MT_force[id] == 1) {
  //      // 強制200で回すとき
  //      if (MT_direction[id] == 1) {
  //        // 正転
  //        MT_rotate(id, 200);
  //      } else if (MT_direction[id] == -1) {
  //        // 後転
  //        MT_rotate(id, -200);
  //      }
  //
  //    } else if (MT_rest[id] == 0) {
  //      MT_rotate(id, MT_speed[id]);
  //    }
  //  }

  //Z_んじゃ最後に今回の値を次の参考に
  for (int id = 0; id <= 3; id += 1) {
    pre_MT_direction[id] = MT_direction[id];
  }

}