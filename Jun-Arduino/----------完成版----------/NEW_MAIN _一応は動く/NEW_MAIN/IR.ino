#include <SPI.h>

const int IR_SS_PIN = 56;

unsigned long IR_Filte_time = 0;
int pre_IR_recive;

int AVE_NUM = 10;
int IR_average[10];

//SoftwareSerialParity IRSerial(56, 28); //rx,tx


void F_IR_setup() {
  pinMode(IR_SS_PIN, OUTPUT);
  digitalWrite(IR_SS_PIN, HIGH);
  SPI.begin();

  //  pinMode(56, INPUT);
  //  pinMode(28, OUTPUT);
  //  IRSerial.begin(38400, ODD);

//  SPISettings mySPISettings = SPISettings(400000, MSBFIRST, SPI_MODE0);
//  SPI.beginTransaction(mySPISettings);
}

int F_IR_read() {
  byte IR_transmission;
  int IR_recive;

  IR_transmission = 'I';
  digitalWrite(IR_SS_PIN, LOW);
  SPI.transfer(IR_transmission);
  digitalWrite(IR_SS_PIN, HIGH);

  digitalWrite(IR_SS_PIN, LOW);
  IR_recive = SPI.transfer(0);
  digitalWrite(IR_SS_PIN, HIGH);

  //  while (IRSerial.available() > 1) {
  //    int g = IRSerial.read();
  //  }
  //  if (IRSerial.available()) {
  //    i = IRSerial.read();
  //  }
  //

  if (0 < IR_recive && IR_recive < 16) {
    IR_Filte_time = F_time_goal(10);
  }

  if (IR_Filte_time > 0 && (0 > IR_recive && IR_recive > 16)) {
    IR_recive = pre_IR_recive;
  }

  if (IR_Filte_time <= F_time_get()) {
    IR_Filte_time = 0;
  }

  pre_IR_recive = IR_recive;
  return IR_recive;
}


int F_IR_wrap_around(int IR) {//1-16の値だよ
  IR -= 1;
  const int C_IR_length = 16.25; //距離が500時、16.25°。距離がxの時、arcsin(140 / x)°
  int IR_wrap_degree;
  if (IR == 0) {
    IR_wrap_degree = 360;
  } else if (1 <= IR & IR <= 8) {
    IR_wrap_degree = (IR * 22.5) + C_IR_length;
  } else if (9 <= IR & IR <= 15) {
    IR_wrap_degree = (IR * 22.5) - C_IR_length;
  } else if (IR == 20 | IR == 73 | IR == 255) { //error_value
    IR_wrap_degree = 0;
  }



  //平均値フィルター
  for (int i = 0; i < AVE_NUM - 1; i++) {
    IR_average[i] = IR_average[i + 1];
  }
  IR_average[AVE_NUM - 1] = IR_wrap_degree;
  Serial.println(' ');
  Serial.print("IR:");

  int more = 0;
  int worse = 360;
  int ir_ave_num = 0;//平均値計算結果
  for (int i = 0; i < AVE_NUM; i++) {
    more = max(more, IR_average[i]);
    worse = min(worse, IR_average[i]);
    ir_ave_num += IR_average[i];
    Serial.print(IR_average[i]);
    Serial.print(':');
  }
  Serial.print(',');
  Serial.print(more);
  Serial.print(':');
  Serial.print(worse);
  ir_ave_num = ir_ave_num / AVE_NUM;
  int difference = more - worse;
  //dofferense(差)が180未満だったら平均値そのまま 180以上だったら平均値足す180
  if (difference > 270) {
    ir_ave_num + 180;
    ir_ave_num %= 360;
  }
  if(IR_wrap_degree == 360){
    ir_ave_num = 360;
  }
  Serial.print(',');
  Serial.println(ir_ave_num);

  return ir_ave_num;
}
