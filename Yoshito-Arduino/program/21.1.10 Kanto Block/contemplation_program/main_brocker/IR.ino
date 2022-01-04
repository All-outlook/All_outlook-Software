const int IR_RX = 66;

int IR_serial;
int IR_wrap;
int IR_shed;

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

int F_shed_degree(int IR)
{
  if (350 <= IR & IR <= 360 | 0 < IR & IR < 10) {
    IR_shed = 0;
  } else if (10 <= IR & IR < 170) {
    IR_shed = 90;
  } else if (170 <= IR & IR < 190) {
    IR_shed = 0;
  } else if (190 <= IR & IR < 350) {
    IR_shed = 270;
  }
  return IR_shed;
}

int F_wrap_degree(int IR)
{
  if (10 <= IR & IR < 180)
  {
    IR_wrap = IR + 50;
  }
  else if (180 <= IR & IR < 350)
  {
    IR_wrap = IR - 50;
  }
  else if (0 < IR & IR < 10 | 350 <= IR & IR <= 360)
  {
    IR_wrap = 360;
  }
  else
  {
    IR_wrap = 0;
  }
  return IR_wrap;
}
