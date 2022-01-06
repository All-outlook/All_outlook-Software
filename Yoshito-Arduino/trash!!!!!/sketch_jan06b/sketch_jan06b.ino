int F_line_avoid(int line, int IR)
{
  current_degree = line + 180; //in the court
 if(current_degree > 360){
    current_degree -= 180;
  }
↑クリア！


  if (abs(current_degree - previous_degree) >= 130 & current_degree != 0 & previous_degree != 0 & F_time_get() - lineMicros >= 1000000) { //1000000 = 1second
    lineMicros = F_time_get();
    point = 1;
  } else {
    point = 0;
  }
↑クリア！

  if (point == 1) {
    return_degree = previous_degree;
    cur_re_degree = previous_degree;
    if (cur_re_degree != pre_re_degree & cur_re_degree != 0 & pre_re_degree != 0) {
      return_digits = 1;
      false_degree = pre_re_degree;
      line_time = F_time_goal(300); //300
    }
    pre_re_degree = cur_re_degree;
  }

  if (F_time_get() > line_time & line_time != 0) {
    return_digits = 0;
    return_degree = 0;
    false_degree = 0;
    current_degree = 0;
    previous_degree = 0;
    pre_re_degree = 0;
    cur_re_degree = 0;
    line_time = 0;
  }

  if (current_degree == 0 & return_degree > 0) {
    degree = return_degree;
  } else if (return_digits == 1) {
    degree = false_degree;
  } else if (return_digits == 0) {
    degree = 0;
  } else {
    degree = 0;
  }

  previous_degree = current_degree;
  degree = line; //後で消してください。
  return degree;
}
