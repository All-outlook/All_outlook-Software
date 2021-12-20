int wrap_around(int IR_degree) {
  int IR_wrap_degree;
  if (345 <= IR_degree & IR_degree < 360 | 0 <= IR_degree & IR_degree < 15) {
    IR_wrap_degree = 0;
  } else if (15 <= IR_degree & IR_degree < 90) {
    IR_wrap_degree = 135;
  } else if (90 <= IR_degree & IR_degree < 170) {
    IR_wrap_degree = IR_degree + 90;
  } else if (170 <= IR_degree & IR_degree < 180) {
    IR_wrap_degree = 135;
  } else if (180 <= IR_degree & IR_degree < 190) {
    IR_wrap_degree = 225;
  } else if (190 <= IR_degree & IR_degree < 270) {
    IR_wrap_degree = IR_degree - 90;
  } else if (270 <= IR_degree & IR_degree < 345) {
    IR_wrap_degree = 315;
  } else if (IR_degree == -1) {
    IR_wrap_degree = -1;
  }
  Serial.print("IR_wrap_degree:");
  Serial.print(IR_wrap_degree);
  Serial.print(", ");
  return IR_wrap_degree;
}
