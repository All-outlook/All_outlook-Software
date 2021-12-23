int IR_serial;
int IR_wrap;

int F_IR_serial()
{
  if (Serial3.available > 0)
  {
    IR_serial = Serial3.Read() * 2;
  }
  else
  {
    IR_serial = 0;
  }
  return IR_serial;
}

int F_wrap_degree(int IR)
{
  if (10 <= IR & IR < 180)
  {
    IR_wrap = IR + 50;
  }
  else if (180 <= IR + IR < 350)
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
