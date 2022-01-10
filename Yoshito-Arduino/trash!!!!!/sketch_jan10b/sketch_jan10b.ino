int F_line_avoid(int line)
{
  int line_degree;
  int degree;
  if (line == 0) { //in the court
    line_degree = 180;
    
  } else if (23 <= line & line < 58) { //The white line is in the higher right corner.
//    false_degree = 290; //203
//    false_digits = 1;
//    line_time = F_time_goal(1);
    
  } else if (58 <= line & line < 113) { //The white line is near 90 line.
    false_degree = 360;
    false_digits = 1;
    line_time = F_time_goal(500);
    
  }  else if (113 <= line & line < 158) { //The white line is in the lower right corner.
    false_degree = 80;
    false_digits = 1;
    line_time = F_time_goal(300);
    
  } else if (158 <= line & line < 203) { //The white line is near 180 line.
    line_degree = 0;
    
  } else if (203 <= line & line < 258) { //The white line is in the lower left corner.
    false_degree = 280; //23
    false_digits = 1;
    line_time = F_time_goal(300);
    
  }  else if (258 <= line & line < 303) { //The white line is near 270 line.
    false_degree = 360;
    false_digits = 1;
    line_time = F_time_goal(500);
    
  } else if (303 <= line & line < 338) { //The white line is in the higher left corner.
//    line_degree = 158;
    
  } else if (338 <= line & line <= 360 | 0 < line & line < 23) {
    line_degree = 360;
  }
