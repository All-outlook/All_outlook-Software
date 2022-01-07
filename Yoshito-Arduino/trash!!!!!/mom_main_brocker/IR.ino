const int IR_RX = 66;

int IR_serial;
int IR_shed;
int IR_count;
int cur_IR_degree;
int pre_IR_degree;
unsigned long forward_time = 0;
unsigned long wrap_time = 0;
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

int F_shed_degree(int IR)
{
  if (350 <= IR & IR <= 360 | 0 < IR & IR < 10) {
    IR_shed = 360;
  } else if (10 <= IR & IR < 170) {
    IR_shed = 85;
  } else if (170 <= IR & IR < 190) {
    IR_shed = 0;
  } else if (190 <= IR & IR < 350) {
    IR_shed = 270;
  }
  return IR_shed;
}

int F_go_forward(int IR) {
  cur_IR_degree = IR;
  if (0 <= abs(cur_IR_degree - pre_IR_degree) & abs(cur_IR_degree - pre_IR_degree) <= 15) {
    IR_count ++;
  } else if (cur_IR_degree == 0 | pre_IR_degree == 0) {
  } else {
    IR_count = 0;
  }

  if (IR_count >= 3000) {
    IR_digits = 1;
    forward_time = F_time_goal(1000);
    IR_count = 0;
  }

  if (F_time_get() >= forward_time & IR_digits == 1) {
    forward_time = 0;
    IR_digits = 2;
    IR_count = 0;
    wrap_time = F_time_goal(20000);
  }

  if (F_time_get() >= wrap_time & IR_digits == 2) {
    IR_digits = 0;
    wrap_time = 0;
    IR_count = 0;
  }

  if (IR_digits == 1) {
    if (0 < cur_IR_degree & cur_IR_degree < 90 | 270 <= cur_IR_degree & cur_IR_degree <= 360) {
      IR_wrap = cur_IR_degree;
    } else {
      IR_wrap = 0;
    }
  } else if (IR_digits == 2) {
    if (350 <= IR & IR <= 360 | 0 < IR & IR < 10) {
      IR_wrap = 360;
    } else if (10 <= IR & IR < 180) {
      IR_wrap = IR + 35;
    } else if (180 <= IR & IR < 350) {
      IR_wrap = IR - 35;
    }
  }
  Serial.print("count");
  Serial.print(IR_digits);
  Serial.print(",");

  pre_IR_degree = cur_IR_degree;
  return IR_wrap;
}
