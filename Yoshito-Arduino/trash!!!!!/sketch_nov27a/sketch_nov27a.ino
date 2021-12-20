//const int C_IR_length = 16.25; //When the distance is 500mm, 16.25°. If the distance is "d", arcsin(140 / d)°.
const int C_IR_length = 45;

int F_wrap_around(int IR) {
  int IR_wrap_degree;
  if (IR == 0) {
    IR_wrap_degree = 360;
  } else if (1 <= IR & IR <= 8) {
    IR_wrap_degree = (IR * 22.5) + C_IR_length;
  } else if (9 <= IR & IR <= 14) {
    IR_wrap_degree = (IR * 22.5) - C_IR_length;
  } else if (IR == 20 | IR == 73 | IR == 255) { //error_value
    IR_wrap_degree = 0;
  }
  return IR_wrap_degree;
}
