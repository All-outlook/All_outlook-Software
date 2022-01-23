const int IR_RX = 66;

int IR_receive = 0;

int IR_serial;
int IR_wrap;

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

int F_IR_get(){
  return IR_receive;
}

int F_wrap_degree(int IR)
{
  if (350 <= IR & IR <= 360 | 0 < IR & IR < 10) {
    IR_wrap = 360;
  } else if (10 <= IR & IR < 180) {
    IR_wrap = IR + 35;
  } else if (180 <= IR & IR < 350) {
    IR_wrap = IR - 35;
  }
  return IR_wrap;
}
