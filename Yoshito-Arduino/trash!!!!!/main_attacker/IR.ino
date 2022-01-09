const int IR_RX = 66;

int IR_serial;
int IR_wrap;

int F_IR_serial()
{
  if (Serial3.available() > 0) {
    IR_serial = Serial3.read() * 2;
  }
  if (IR_serial == 0 | IR_serial == -2) {
    IR_serial = 0;
  }
  return IR_serial;
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
