int IR_go_after() {
  if (345 <= IR_value & IR_value < 360 | 0 <= IR_value & IR_value < 15) {
    IR_degree = -1;
  } else if (15 <= IR_value & IR_value < 165) {
    IR_degree = 90;
  } else if (165 <= IR_value & IR_value <195) {
    IR_degree = -1;
  } else if (195 <= IR_value & IR_value < 345) {
    IR_degree = 270;
  } else if(IR_value == -1){
    IR_degree = -1;
  }
  return IR_degree;
}
