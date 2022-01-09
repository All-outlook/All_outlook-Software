const int LINE_RX = 68;
const int LINE_TX = 49;
SoftwareSerialParity line_Serial(LINE_RX, LINE_TX);  // rx,tx

int LINESerial;
int current_value;
int previous_value;
unsigned long lineMicros = 0;
int point;
int return_degree;
int current_degree;
int previous_degree;
int cur_re_degree;
int pre_re_degree;
int false_degree;
int return_digits;
unsigned long line_time = 0;
int degree;

int F_line_serial()
{
  if (line_Serial.available() > 0) {
    current_value = line_Serial.read() * 2;
  }
  if (current_value > 360) {
    current_value = 0;
  }
  if(current_value == 0 & previous_value != 0){
    LINESerial = previous_value;
  } else {
    LINESerial = current_value;
  }
  previous_value = current_value; 
  return LINESerial;
}

int F_line_avoid(int line, int IR)
{
  current_degree = line_degree;

  if (abs(current_degree - previous_degree) >= 130 & current_degree != 0 & previous_degree != 0 & F_time_get() - lineMicros >= 1000000) {
    lineMicros = F_time_get();
    point = 1;
  } else {
    point = 0;
  }

  if (point == 1) {
    return_degree = previous_degree;
    cur_re_degree = previous_degree;
    if (cur_re_degree != pre_re_degree & cur_re_degree != 0 & pre_re_degree != 0) {
      return_digits = 1;
      false_degree = pre_re_degree;
      line_time = F_time_goal(300);//300
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
