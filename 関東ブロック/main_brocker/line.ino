int LINE_receive;

unsigned long line_time = 0;

void F_LINE_setup() {
  Serial1.begin(115200);
}

void F_LINE_read() {

  while (Serial1.available() > 5) {
    int g = Serial1.read();
  }
  if (Serial1.available() > 0) {
    LINE_receive = Serial1.read() * 2;
  }
}

int F_LINE_get() {
  return LINE_receive;
}

int F_line_avoid(int line)
{
  int false_degree;
  int false_digits;
  int line_degree;
  int previous_degree;
  int degree;

  if (line == 0) { //in the court
    line_degree = 180;
  } else if (23 <= line & line < 58) { //The white line is in the higher right corner.
    false_degree = 203;
    false_digits = 1;
    line_time = F_time_goal(1000);
  } else if (58 <= line & line < 113) { //The white line is near 90 line.
    false_degree = 270;
    false_digits = 1;
    line_time = F_time_goal(300);
  }  else if (113 <= line & line < 158) { //The white line is in the lower right corner.
    false_degree = 338;
    false_digits = 1;
    line_time = F_time_goal(1000);
  } else if (158 <= line & line < 203) { //The white line is near 180 line.
    line_degree = 0;
  } else if (203 <= line & line < 258) { //The white line is in the lower left corner.
    false_degree = 23;
    false_digits = 1;
    line_time = F_time_goal(1000);
  }  else if (258 <= line & line < 303) { //The white line is near 270 line.
    false_degree = 90;
    false_digits = 1;
    line_time = F_time_goal(300);
  } else if (303 <= line & line < 338) { //The white line is in the higher left corner.
    false_degree = 158;
    false_digits = 1;
    line_time = F_time_goal(1000);
  } else if (338 <= line & line <= 360 | 0 < line & line < 23) {
    line_degree = 360;
  }

  if (line_degree == 0 & previous_degree == 360) {
    false_degree = 360;
    false_digits = 1;
    line_time = F_time_goal(100);
  }

  if (F_time_get() >= line_time & line_time != 0)
  {
    line_time = 0;
    false_digits = 0;
  }

  if (false_degree == 1) {
    degree = false_degree;
  } else {
    degree = line_degree;
  }

  previous_degree = line_degree;
  return degree;
}

int F_just_pulled(int line) {
  int line_value;
  line_value = line + 180; //in the court
  if (line == 0) {
    line_value = 0;
  } else if (line_value > 360) {
    line_value -= 360;
  }
  return line_value;
}
