int LINESerial;
int previous_value;
int false_current_degree;
int current_value;
int false_digits;
unsigned long line_time;
int current_degree;
int previous_degree;
int degree;
int line_value;

int F_line_serial()
{
  if (Serial1.available() > 0) {
    current_value = Serial1.read() * 2;
  }
  if (current_value > 360) {
    current_value = 0;
  }
  if (current_value == 0 & previous_value != 0) {
    LINESerial = previous_value;
  } else {
    LINESerial = current_value;
  }
  previous_value = current_value;
  return LINESerial;
}

int F_line_avoid(int line)
{
  if (line == 0) { //in the court
    current_degree = 180;
  } else if (23 <= line & line < 58) { //The white line is in the higher right corner.
    false_current_degree = 203;
    false_digits = 1;
    line_time = F_time_goal(1000);
  } else if (58 <= line & line < 113) { //The white line is near 90 current_degrees.
    false_current_degree = 270;
    false_digits = 1;
    line_time = F_time_goal(300);
  }  else if (113 <= line & line < 158) { //The white line is in the lower right corner.
    false_current_degree = 338;
    false_digits = 1;
    line_time = F_time_goal(1000);
  } else if (158 <= line & line < 203) { //The white line is near 180 current_degrees.
    current_degree = 0;
  } else if (203 <= line & line < 258) { //The white line is in the lower left corner.
    false_current_degree = 23;
    false_digits = 1;
    line_time = F_time_goal(1000);
  }  else if (258 <= line & line < 303) { //The white line is near 270 current_degrees.
    false_current_degree = 90;
    false_digits = 1;
    line_time = F_time_goal(300);
  } else if (303 <= line & line < 338) { //The white line is in the higher left corner.
    false_current_degree = 158;
    false_digits = 1;
    line_time = F_time_goal(1000);
  } else if (338 <= line & line <= 360 | 0 < line & line < 23) {
    current_degree = 360;
  }

  if (F_time_get() >= line_time & line_time != 0)
  {
    line_time = 0;
    false_digits = 0;
  }

  if (current_degree == 0 & previous_degree == 360) {
    degree = current_degree;
  } else {
    degree = previous_degree;
  }

  previous_degree = current_degree;
  return degree;
}

int F_just_pulled(int line) {
  line_value = line + 180; //in the court
  if (line == 0) {
    line_value = 0;
  } else if (line_value > 360) {
    line_value -= 360;
  }
  return line_value;
}
