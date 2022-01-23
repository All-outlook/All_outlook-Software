int LINE_receive;

int LINESerial;
int current_value;
int previous_value;
unsigned long lineMicros = 0;
int point;
int return_degree;
int current_degree;
int previous_degree;
int line_count;
unsigned long line_time = 0;
int degree;

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

int F_line_avoid(int line, int IR)
{
  current_degree = line + 180; //in the court
  if (current_degree > 360) {
    current_degree -= 180;
  }

  if (abs(current_degree - previous_degree) >= 130 & current_degree != 0 & previous_degree != 0 & F_time_get() - lineMicros >= 1000000) { //1000000 = 1second
    lineMicros = F_time_get();
    point = 1;
  } else {
    point = 0;
  }

  if (point == 1) {
    return_degree = previous_degree;
  }

  if (abs(return_degree - IR) <= 90 & return_degree != 0 & IR_degree != 0) {
    line_count = 1;
    line_time = F_time_goal(500);
  }

  if (F_time_get() >= line_time & line_count == 1) {
    point = 0;
    return_degree = 0;
    line_count = 0;
    line_time = 0;
  }

  if (line_count == 1) {
    degree == 0;
  } else if (current_degree == 0 & return_degree > 0) {
    degree = return_degree;
  } else {
    degree = 0;
  }

  previous_degree = current_degree;
  return degree;
}
