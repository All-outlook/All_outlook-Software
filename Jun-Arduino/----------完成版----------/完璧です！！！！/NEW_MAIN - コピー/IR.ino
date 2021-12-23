
//const int IR_SS_PIN = 56;

unsigned long IR_Filte_time = 0;
int pre_IR_recive;

int AVE_NUM = 10;
int IR_average[10];

//SoftwareSerialParity IR_Serial(66, 48); //rx,tx

//SPISettings mySPISettings = SPISettings(400000, MSBFIRST, SPI_MODE0);

void F_IR_setup() {
  //  pinMode(IR_SS_PIN, OUTPUT);
  //  digitalWrite(IR_SS_PIN, HIGH);
  Serial3.begin(38400);
  pinMode(66, INPUT);
  //  SPI.begin();
  //SPI.beginTransaction(mySPISettings);

}


int IR_recive = 0;

float F_IR_read() {
Serial_error:
  while (Serial3.available() > 10) {
    int g = Serial3.read();
  }
  // while (IR_recive > 200/*(IR_recive < 0 || IR_recive > 15) && IR_recive != 20*/) {
  if (Serial3.available()) {
    IR_recive = Serial3.read();
  }

  if (IR_recive > 30) {
    goto Serial_error;
  }

  /*
    //SPI受信*******************************************************
    byte IR_transmision;
    while ((IR_recive < 0 || IR_recive > 15) && IR_recive != 20) {
    IR_transmission = 'I';
    digitalWrite(IR_SS_PIN, LOW);
    SPI.transfer(IR_transmission);
    digitalWrite(IR_SS_PIN, HIGH);

    delayMicroseconds(5);

    digitalWrite(IR_SS_PIN, LOW);
    IR_recive = SPI.transfer(0) - 130;
    digitalWrite(IR_SS_PIN, HIGH);
    }
  */
  //SPI受信**終わり***************************************

  //平均値フィルター***************************************************

  for (int i = 0; i < AVE_NUM - 1; i++) {
    IR_average[i] = IR_average[i + 1];
  }
  IR_average[AVE_NUM - 1] = IR_recive;

  int more = 0;
  int worse = 15;
  float ir_ave_num = 0;//平均値計算結果
  for (int i = 0; i < AVE_NUM; i++) {
    ir_ave_num = ir_ave_num + IR_average[i];
    more = max(more, IR_average[i]);
    worse = min(worse, IR_average[i]);
    //    Serial.print(IR_average[i]);
    //    Serial.print(':');
  }

  ir_ave_num = ir_ave_num / AVE_NUM;


  if ((more == 15 || more == 14) && (worse == 0 || worse == 1 || worse == 2)) {
    //    Serial.print("kitaaa");

    int IR_average_kari[10];
    for (int i = 0; i < AVE_NUM; i++) {
      if (IR_average[i] == 0) {
        IR_average_kari[i] = 16;
      } else if (IR_average[i] == 1) {
        IR_average_kari[i] = 17;
      } else if (IR_average[i] == 2) {
        IR_average_kari[i] = 18;
      } else {
        IR_average_kari[i] = IR_average[i];
      }
    }
    for (int i = 0; i < AVE_NUM; i++) {
      ir_ave_num = ir_ave_num + IR_average_kari[i];
    }
    ir_ave_num = ir_ave_num / AVE_NUM;

    if (ir_ave_num > 15) {
      ir_ave_num -= 15;
    }
  }


//  Serial.print(ir_ave_num);
//  Serial.print(',');
  return ir_ave_num;


  //  //旧フィルタ
  //  if (0 < IR_recive && IR_recive < 16) {
  //    IR_Filte_time = F_time_goal(10);
  //  }
  //
  //  if (IR_Filte_time > 0 && (0 > IR_recive && IR_recive > 16)) {
  //    IR_recive = pre_IR_recive;
  //  }
  //
  //  if (IR_Filte_time <= F_time_get()) {
  //    IR_Filte_time = 0;
  //  }
  //
  //  pre_IR_recive = IR_recive;
  //float IR_recive;
  //  //旧IR用平均値フィルタおわりいいいい
}
int F_IR_mawarikomi(float IR) {
  const int C_IR_length = 45; //300mm
  int result;
  //回り込み
  if (IR == 20.00) {
    result = 0;
  } else if ((1.5 >= IR || IR >= 14.5) ) {
    result = 360;
  } else if (1.5 <= IR && IR <= 3) {
    result = (IR * 22.5) + C_IR_length ;
  } else if (3 <= IR && IR <= 4) {
    result = 150;
  } else if ( 4 <= IR && IR <= 8) {
    result = (IR * 22.5) + C_IR_length;
  } else if ( 8 <= IR && IR <= 12) {
    result = (IR * 22.5) - C_IR_length ;
  }  else if ( 12 <= IR && IR <= 13) {
    result = 210;
  } else if ( 13 <= IR && IR <= 14.5 ) {
    result = (IR * 22.5) - C_IR_length;
  }

  return result;
}





int F_IR_wrap_around(float IR) {
  //IR -= 1;
  //const int C_IR_length = 16.25; //距離が500時、16.25°。距離がxの時、arcsin(140 / x)°
  int IR_wrap_degree;
//  Serial.print(IR);
//  Serial.print(',');
  IR_wrap_degree = F_IR_mawarikomi(IR);
//  Serial.print(IR_wrap_degree);
//  Serial.print(',');

  //平均値フィルター
  //    for (int i = 0; i < AVE_NUM - 1; i++) {
  //      IR_average[i] = IR_average[i + 1];
  //    }
  //    IR_average[AVE_NUM - 1] = IR_wrap_degree;
  //    //  Serial.println(' ');
  //    //  Serial.print("IR:");
  //
  //    int more = 0;
  //    int worse = 360;
  //    int ir_ave_num = 0;//平均値計算結果
  //    for (int i = 0; i < AVE_NUM; i++) {
  //      more = max(more, IR_average[i]);
  //      worse = min(worse, IR_average[i]);
  //      ir_ave_num += IR_average[i];
  //      //    Serial.print(IR_average[i]);
  //      //    Serial.print(':');
  //    }
  //    //  Serial.print(',');
  //    //  Serial.print(more);
  //    //  Serial.print(':');
  //    //  Serial.print(worse);
  //    ir_ave_num = ir_ave_num / AVE_NUM;
  //    int difference = more - worse;
  //    //dofferense(差)が180未満だったら平均値そのまま 180以上だったら平均値足す180
  //    if (difference > 270) {
  //      ir_ave_num + 180;
  //      ir_ave_num %= 360;
  //    }
  //
  //    if (IR == 20) {
  //      ir_ave_num = 0;
  //    }
  //    if (IR_wrap_degree == 360) {
  //      ir_ave_num = 360;
  //    }
  //    Serial.print(',');
  //    Serial.println(ir_ave_num);
  //    return ir_ave_num;
  //  平均値フィルタここまで

//  Serial.println(IR_wrap_degree);
  return IR_wrap_degree;
}
