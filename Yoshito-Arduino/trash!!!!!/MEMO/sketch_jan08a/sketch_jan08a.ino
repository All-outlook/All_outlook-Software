unsigned long IR_[5];

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}

int F_go_forward(int IR) {
  IR_count ++;

  if (IR_count == 1) {
    IR_value[0] = IR;
  } else if (IR_count == 250) {
    IR_count[1] = IR;
    if (15 < abs(IR_value[0] - IR_value[1]) {
    IR_count = 0;
  }
} else if (IR_count == 500) {
    IR_count[2] = IR;
    if (15 < abs(IR_value[1] - IR_value[2]) {
    IR_count = 0;
  }
} else if (IR_count == 750) {
    IR_count[3] = IR;
    if (15 < abs(IR_value[2] - IR_value[3]) {
    IR_count = 0;
  }
} else if (IR_count == 1000) {
    IR_count[4] = IR;
    if (15 < abs(IR_value[3] - IR_value[4]) {
    IR_count = 0;
  } else {
    IR_digits = 1;
    forward_time = F_time_goal(1000);
    }
  }
}
