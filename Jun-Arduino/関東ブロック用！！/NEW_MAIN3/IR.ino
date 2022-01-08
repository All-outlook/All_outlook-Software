int IR_receive = 0;

void F_IR_setup() {
  Serial3.begin(38400);
}

void F_IR_read() {
  while (Serial3.available() > 5) {
    int g = Serial3.read();
  }
  if (Serial3.available()) {
    IR_receive = Serial3.read() * 2;
  }
}

int F_IR_get(){
  return IR_receive;
}

void F_IR_debug(){
  Serial.print(" IR:");
  Serial.print(IR_receive);
}


int F_IR_wrap_around(float IR) {
  //IR -= 1;
  //const int C_IR_length = 16.25; //距離が500時、16.25°。距離がxの時、arcsin(140 / x)°

  int IR_wrap_degree = F_IR_mawarikomi(IR);
  
  return IR_wrap_degree;
}


int F_IR_mawarikomi(float IR) {
  const int C_IR_length = 65; //300mm
  
  int result;
  //回り込み
  if (IR == 20.00) {
    result = 2000;
  } else if ((0.4 >= IR || IR >= 15.6) ) {
    result = 360;
  } else if ((0.4 <= IR && IR <= 1.9) ) {
    result = 20;

  } else if (1.9 <= IR && IR <= 8) {
    result = (IR * 22.5) + C_IR_length ;

  } else if ( 8 <= IR && IR <= 14.1 ) {
    result = (IR * 22.5) - C_IR_length;

  } else if ((14.1 <= IR && IR <= 15.6) ) {
    result = 320;
  }
  return result;
}
