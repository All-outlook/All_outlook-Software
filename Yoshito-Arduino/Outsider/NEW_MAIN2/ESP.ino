/*
ESPを介してスマホと無線通信用関数セット！！

F_ESP_setup()  ESPと通信するのに必要なことやるよ

F_ESP_read()   値を取得するよ

F_ESP_angle()  スティックの角度を返すよ
F_ESP_speed()  スティックの傾き度を返すよ
F_ESP_switch() スイッチの状況を返すよ
*/

int controller_angle;
int controller_speed;
int controller_switch;



void F_ESP_setup() {
  Serial1.begin( 115200 );
}

int F_ESP_angle(){
  return controller_angle;
}

int F_ESP_speed(){
  return controller_speed;
}

int F_ESP_switch(){
  return controller_switch;
}



int pre_controller_switch = 0;
void F_ESP_read() {
  if ( Serial1.available() ) {
    String str = Serial1.readStringUntil('#');
//    Serial.println(str);
    long value = str.toInt();

    if ((value / 10000) == 0) {
      controller_angle = 0;
    } else {
      controller_angle = 450 - (value / 10000);
    }

    if (controller_angle > 360) {
      controller_angle -= 360;
    }

    controller_speed = value % 10000 / 10;
    controller_switch = value % 10;
  }

  //Switch補正
  if (pre_controller_switch != 0) {
    controller_switch = 0;
  }
  pre_controller_switch = controller_switch;
}
