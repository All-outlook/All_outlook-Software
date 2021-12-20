const int LINE[] = {A0, A1, A2, A3};    //line ancestry
const int RED_LED[] = {40, 41, 42, 43}; //else
 
//ラインの閾値
const int line_threshold[] = {500, 600, 800, 450};
 
void F_line_setup() {
  for (int id = 0; id <= 3; id++) {
    pinMode(LINE[id], INPUT);
    pinMode(RED_LED[id], OUTPUT);
  }
}
 
int F_line_read() {
  int line_read[4];
  int line_digits[4];
  int line_binary;
 
  for (int id = 0; id <= 3; id++) {
    line_read[id] = analogRead(LINE[id]);
 
    if (line_threshold[id] <= line_read[id]) {
      line_digits[id] = 1;
      digitalWrite(RED_LED[id], HIGH);
    } else {
      line_digits[id] = 0;
      digitalWrite(RED_LED[id], LOW);
    }
    /*Serial.print("c");
      Serial.print(id);
      Serial.print(":");
      Serial.print(line_read);
      Serial.print(", ");*/
  }
  line_binary = (line_digits[0] * 1000) + (line_digits[1] * 100) + (line_digits[2] * 10) + (line_digits[3] * 1);
  return line_binary; //4つのセンサの複合値を出力
}


 
int F_line_step(int line) {//line 4つのセンサの複合値
  int line_reaction = 0;
  int line_avoid;
  int line_count;
  int fixed = 300;
 
   if (line_reaction == 0) {
    line_reaction = 1;
 
    if (line == 1111) {
      line_avoid = 0;
    } else if (line == 1110) {
      line_avoid = 270;
      line_count = time_goal(fixed);
    } else if (line == 1101) {
      line_avoid = 180;
      line_count = time_goal(fixed);
    } else if (line == 1100) {
      line_avoid = 225;
      line_count = time_goal(fixed);
    } else if (line == 1011) {
      line_avoid = 90;
      line_count = time_goal(fixed);
    } else if (line == 1010) {
      line_avoid = 0;
    } else if (line == 1001) {
      line_avoid = 135;
      line_count = time_goal(fixed);
    } else if (line == 1000) {
      line_avoid = 180;
      line_count = time_goal(fixed);
    } else if (line == 111) {
      line_avoid = 360;
      line_count = time_goal(fixed);
    } else if (line == 110) {
      line_avoid = 315;
      line_count = time_goal(fixed);
    } else if (line == 101) {
      line_avoid = 0;
    } else if (line == 100) {
      line_avoid = 270;
      line_count = time_goal(fixed);
    } else if (line == 11) {
      line_avoid = 45;
      line_count = time_goal(fixed);
    } else if (line == 10) {
      line_avoid = 360;
      line_count = time_goal(fixed);
    } else if (line == 1) {
      line_avoid = 90;
      line_count = time_goal(fixed);
    } else if (line == 0) {
      line_avoid = 0;
    }
  }  else if (line_reaction == 1) {
  }
 
  if (line_avoid == 0) {
    line_reaction = 0;
  }
 
  if (period_count == line_count) {
    line_reaction = 0;
    line_avoid = 0;
  }
  //line_avoid = 100;
  return line_avoid;
}
