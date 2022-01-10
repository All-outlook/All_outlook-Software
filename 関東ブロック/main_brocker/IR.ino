const int IR_RX = 66;

int IR_receive = 0;

unsigned long IR_count = 0;
unsigned long forward_time = 0;
int IR_keep[] = {0, 0, 0, 0, 0};

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
      forward_time = F_time_goal(1600);
    }
  }

  if ((F_time_get() >= forward_time & IR_digits == 1) | kicker_value == 1) {
    forward_time = 0;
    IR_subtract = 0;
    IR_digits = 0;
    IR_count = 0;
  }
  
  if (IR_digits == 1) {
    if (270 <= IR & IR <= 360 | 0 < IR & IR < 90) {
      IR_wrap = IR;
    } else {
      IR_wrap = 0;
    }
  }
    return IR_wrap;
  }
