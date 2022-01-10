int IR_receive = 0;

void F_IR_setup() {
  Serial3.begin(115200);
}

void F_IR_read() {
  while (Serial3.available() > 5) {
    int g = Serial3.read();
  }
  if (Serial3.available() > 0) {
    IR_receive = Serial3.read() * 2;
  }
}

int F_IR_get() {
  return IR_receive;
}

void F_IR_debug() {
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
  const int C_IR_length = 65; //300mm

  int result;
  //回り込み
  if (IR == 0) {
    result = 0;
  } else if ((20 >= IR || IR >= 340) ) {
    result = 360;
  } else if ((20 <= IR && IR <= 25) ) {
    result = 45;
  } else if ((25 <= IR && IR <= 70) ) {
    result = IR + 80;

  } else if (70 <= IR && IR <= 180) {
    result = IR + C_IR_length ;

  } else if ( 180 <= IR && IR <= 290 ) {
    result = IR - C_IR_length;

  } else if ((290 <= IR && IR <= 335) ) {
    result = IR - 80;
  
  } else if ( 335 <= IR && IR <= 340 ) {
    result = 315;
  }
  return result;
}
