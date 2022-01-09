const int IR_RX = 66;

unsigned long IR_count = 0;
unsigned long forward_time = 0;
unsigned long wrap_time = 0;
int IR_keep[] = {0, 0, 0, 0, 0};

int F_IR_serial()
{
  int IR_serial;
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
  int IR_shed = 0;
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

int F_go_forward(int IR) {
  int IR_wrap;
  int IR_subtract;

  if (0 < IR) {
    IR_count++;
  } else {
    IR_count = 0;
  }

  if (IR_count == 1) {
    IR_keep[0] = IR;
  } else if (IR_count == 750) {
    IR_keep[1] = IR;
    IR_subtract = abs(IR_keep[1] - IR_keep[0]);
    if (10 < IR_subtract) {
      IR_count = 0;
      IR_subtract = 0;
      for (id = 0; id <= 4; id++) {
        IR_keep[id] = 0;
      }
    }
  } else if (IR_count == 1500) {
    IR_keep[2] = IR;
    IR_subtract = abs(IR_keep[2] - IR_keep[1]);
    if (10 < IR_subtract) {
      IR_count = 0;
      IR_subtract = 0;
      for (id = 0; id <= 4; id++) {
        IR_keep[id] = 0;
      }
    }
  } else if (IR_count == 2250) {
    IR_keep[3] = IR;
    IR_subtract = abs(IR_keep[3] - IR_keep[2]);
    if (10 < IR_subtract) {
      IR_count = 0;
      IR_subtract = 0;
      for (id = 0; id <= 4; id++) {
        IR_keep[id] = 0;
      }
    }
  } else if (IR_count == 3000) {
    IR_keep[4] = IR;
    IR_subtract = 0;
    IR_subtract = abs(IR_keep[4] - IR_keep[3]);
    if (10 < IR_subtract) {
      IR_count = 0;
      IR_subtract = 0;
      for (id = 0; id <= 4; id++) {
        IR_keep[id] = 0;
      }
    } else {
      IR_digits = 1;
      forward_time = F_time_goal(1000);
    }
  }

  if (F_time_get() >= forward_time & IR_digits == 1) {
    forward_time = 0;
    IR_digits = 2;
    wrap_time = F_time_goal(20000);
  }

  if (F_time_get() >= wrap_time & IR_digits == 2) {
    IR_subtract = 0;
    IR_digits = 0;
    wrap_time = 0;
    IR_count = 0;
  }

  if (IR_digits == 1) {
    if (0 < IR & IR < 90 | 270 <= IR & IR <= 360) {
      IR_wrap = IR;
    } else {
      IR_wrap = 360;
    }
  } else if (IR_digits == 2) {
    if (350 <= IR & IR <= 360 | 0 < IR & IR < 10) {
      IR_wrap = 360;
    } else if (10 <= IR & IR < 180) {
      IR_wrap = IR + 35;
    } else if (180 <= IR & IR < 350) {
      IR_wrap = IR - 35;
    }
  } else {
    IR_wrap = 0;
  }
  return IR_wrap;
}
