const int LINE_RX = 68;
const int LINE_TX = 49;
SoftwareSerialParity line_Serial(LINE_RX, LINE_TX);  // rx,tx

int LINESerial;
int current_value;
int previous_value;
int false_cur_degree;
int false_digits;
unsigned long line_time;
int cur_degree;
int pre_degree;
int degree;
int line_degree;

int F_line_serial()
{
  if (line_Serial.available() > 0) {
    current_value = line_Serial.read() * 2;
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
    cur_degree = 180;
//  } else if (23 <= line & line < 58) { //The white line is in the higher right corner.
//    false_cur_degree = 203;
//    false_digits = 1;
//    line_time = F_time_goal(1000);
//  } else if (58 <= line & line < 113) { //The white line is near 90 cur_degrees.
//    false_cur_degree = 270;
//    false_digits = 1;
//    line_time = F_time_goal(300);
//  }  else if (113 <= line & line < 158) { //The white line is in the lower right corner.
//    false_cur_degree = 338;
//    false_digits = 1;
//    line_time = F_time_goal(1000);
  } else if (158 <= line & line < 203) { //The white line is near 180 cur_degrees.
    cur_degree = 0;
//  } else if (203 <= line & line < 258) { //The white line is in the lower left corner.
//    false_cur_degree = 23;
//    false_digits = 1;
//    line_time = F_time_goal(1000);
//  }  else if (258 <= line & line < 303) { //The white line is near 270 cur_degrees.
//    false_cur_degree = 90;
//    false_digits = 1;
//    line_time = F_time_goal(300);
//  } else if (303 <= line & line < 338) { //The white line is in the higher left corner.
//    false_cur_degree = 158;
//    false_digits = 1;
//    line_time = F_time_goal(1000);
  } else if (338 <= line & line <= 360 | 0 < line & line < 23) {
    cur_degree = 360;
  }

//  if (F_time_get() >= line_time & line_time != 0)
//  {
//    line_time = 0;
//    false_digits = 0;
//  }

if(cur_degree == 0 & pre_degree == 360){
  degree = cur_degree;
} else {
  degree = pre_degree;
}
  
  pre_cur_degree = cur_cur_degree;
  return degree;
}

int F_just_pulled(int line){
    line_degree = line + 180; //in the court
  if(line_degree == 0){
    line_degree = 0;
  } else if(current_degree >= 360){
    line_degree -= 180;
  }
  return line_degree;
}
