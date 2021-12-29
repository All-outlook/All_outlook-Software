
//const int IR_SS_PIN = 56;

unsigned long IR_Filte_time = 0;
int pre_IR_recive;

int AVE_NUM = 10;
int IR_average[10];
int IR_recive = 0;

void setup() {
  Serial.begin(115200);
  Serial3.begin(38400);
  pinMode(66, INPUT);
}

void loop() {
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

    if (ir_ave_num >= 16) {
      ir_ave_num -= 16;
    }
  }

  Serial.print(ir_ave_num);
  Serial.print(',');
}
