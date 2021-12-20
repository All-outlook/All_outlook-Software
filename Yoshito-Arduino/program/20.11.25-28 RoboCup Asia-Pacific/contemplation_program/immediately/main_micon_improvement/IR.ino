//const int C_IR_length = 16.25; //When the distance is 500mm, 16.25°. If the distance is "d", arcsin(140 / d)°.
const int C_IR_length = 45; //300mm

const int C_IR_tilt = 11.25; //Because the IR sensors are't front.

int F_wrap_around(int IR) {
  int IR_wrap_degree;
  if (IR == 0 | IR == 15) {
    IR_wrap_degree = 360;
  } else if (1 <= IR & IR <= 2) {
    IR_wrap_degree = (IR * 22.5) + C_IR_length + C_IR_tilt;
  } else if (3 <= IR & IR <= 4) {
    IR_wrap_degree = 135;
  } else if (5 <= IR & IR <= 7) {
    IR_wrap_degree = (IR * 22.5) + 30 + C_IR_tilt;
  } else if (8 <= IR & IR <= 10) {
    IR_wrap_degree = (IR * 22.5) - 30 + C_IR_tilt;
  } else if (11 <= IR & IR <= 12) {
    IR_wrap_degree = 225;
  } else if (13 <= IR & IR <= 14) {
    IR_wrap_degree = (IR * 22.5) - C_IR_length + C_IR_tilt;
  } else if (IR == 20 | IR == 73 | IR == 255) { //error_value
    IR_wrap_degree = 0;
  }
  return IR_wrap_degree;
}
