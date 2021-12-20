
    pinMode(RED_LED[id], OUTPUT);
  }
}

int F_line_read() {
  int line_read[4];
  int line_digits[4];
  int line_binary;

  for (int id = 0; id <= 3; id++) {
    line_read[id] = analogRead(LINE[id]);

    if (C_line_threshold[id] <= line_read[id]) {
      line_digits[id] = 1;
      digitalWrite(RED_LED[id], HIGH);
    } else {
      line_digits[id] = 0;
      digitalWrite(RED_LED[id], LOW);
    }
    /*Serial.print("c");
    Serial.print(id);
    Serial.print(":");
    Serial.print(line_read[id]);
    Serial.print(", ");*/
  }
  line_binary = (line_digits[0] * 1000) + (line_digits[1] * 100) + (line_digits[2] * 10) + (line_digits[3] * 1);
  return line_binary;
}

int F_line_step(int line) {
  int fixed = 100; //mills_value

  if (line == 1111) {
    //line_avoid = 0;
  } else if (line == 1110) {
    line_avoid = 270;
    line_time = F_time_goal(fixed);
  } else if (line == 1101) {
    line_avoid = 180;
    line_time = F_time_goal(fixed);
  } else if (line == 1100) {
    line_avoid = 225;
    line_time = F_time_goal(fixed);
  } else if (line == 1011) {
    line_avoid = 90;
    line_time = F_time_goal(fixed);
  } else if (line == 1010) {
    //line_avoid = 0;
  } else if (line == 1001) {
    line_avoid = 135;
    line_time = F_time_goal(fixed);
  } else if (line == 1000) {
    line_avoid = 180;
    line_time = F_time_goal(fixed);
  } else if (line == 111) {
    line_avoid = 360;
    line_time = F_time_goal(fixed);
  } else if (line == 110) {
    line_avoid = 315;
    line_time = F_time_goal(fixed);
  } else if (line == 101) {
    //line_avoid = 0;
  } else if (line == 100) {
    line_avoid = 270;
    line_time = F_time_goal(fixed);
  } else if (line == 11) {
    line_avoid = 45;
    line_time = F_time_goal(fixed);
  } else if (line == 10) {
    line_avoid = 360;
    line_time = F_time_goal(fixed);
  } else if (line == 1) {
    line_avoid = 90;
    line_time = F_time_goal(fixed);
  } else if (line == 0) {
    //line_avoid = 0;
  }

  if (F_time_get() >= line_time) {
    line_time = 0;
  }

  int line_return;
  if (line_time != 0) {
    line_return = line_avoid;
  } else {
    line_return = 0;
  }

  return line_return;
}
