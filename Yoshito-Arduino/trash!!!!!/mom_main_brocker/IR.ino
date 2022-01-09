const int IR_RX = 66;

unsigned long forward_time = 0;
unsigned long wrap_time = 0;

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
  unsigned long IR_count;
  int IR_value[5];
  int IR_wrap;

  if (0 < IR) {
    IR_count++;
  }

  if (IR_count == 1) {
    IR_value[0] = IR;
  } else if (IR_count == 500) {
    IR_value[1] = IR;
    if (15 < abs(IR_value[0] - IR_value[1])) {
      IR_count = 0;
      for (id = 0; id <= 1; id++) {
        IR_value[id] = 0;
      }
    }
  } else if (IR_count == 1000) {
    IR_value[2] = IR;
    if (15 < abs(IR_value[1] - IR_value[2])) {
      IR_count = 0;
      for (id = 0; id <= 2; id++) {
        IR_value[id] = 0;
      }
    }
  } else if (IR_count == 1500) {
    IR_value[3] = IR;
    if (15 < abs(IR_value[2] - IR_value[3])) {
      IR_count = 0;
      for (id = 0; id <= 3; id++) {
        IR_value[id] = 0;
      }
    }
  } else if (IR_count == 2000) {
    IR_value[4] = IR;
    if (15 < abs(IR_value[3] - IR_value[4])) {
      IR_count = 0;
      for (id = 0; id <= 4; id++) {
        IR_value[id] = 0;
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
  Serial.print("count");
  Serial.print(IR_digits);
  Serial.print(",");
  return IR_wrap;
}
