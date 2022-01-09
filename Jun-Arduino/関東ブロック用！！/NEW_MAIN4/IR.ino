int IR_receive = 0;

void F_IR_setup() {
  Serial3.begin(38400);
}

void F_IR_read() {
  while (Serial3.available() > 5) {
    int g = Serial3.read();
  }
  if (Serial3.available() > 0) {
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


int F_IR_wrap_around(int IR) {
  //IR -= 1;
  //const int C_IR_length = 16.25; //距離が500時、16.25°。距離がxの時、arcsin(140 / x)°

  int IR_wrap_degree = F_IR_mawarikomi(IR);
  
  return IR_wrap_degree;
}


int F_IR_mawarikomi(int IR) {
  const int C_IR_length = 35; //300mm
  
  int result;
  //回り込み
  if (IR == 0) {
    result = 0;
  } else if ((15 >= IR || IR >= 345) ) {
    result = 360;
  } else if ((15 <= IR && IR <= 45) ) {
    result = 20;

  } else if (45 <= IR && IR <= 180) {
    result = IR+C_IR_length ;

  } else if ( 180 <= IR && IR <= 315 ) {
    result = IR-C_IR_length;

  } else if ((315 <= IR && IR <= 345) ) {
    result = 340;
  }
  return result;
}
