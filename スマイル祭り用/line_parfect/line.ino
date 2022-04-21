void F_AMP_setup() {
  for (int id = 0; id <= 3; id++) {
    pinMode(AMP_PIN[id], INPUT);
    pinMode(AMP_PIN[id], LOW);
  }
  pinMode(A_PIN, OUTPUT);
  pinMode(B_PIN, OUTPUT);
  pinMode(C_PIN, OUTPUT);
}

void F_line_choice(int choice) {
  int choice_output[3];
  switch (choice) {
    case 0:
      choice_output[2] = 0;
      choice_output[1] = 0;
      choice_output[0] = 0;
      break;
    case 1:
      choice_output[2] = 0;
      choice_output[1] = 0;
      choice_output[0] = 1;
      break;
    case 2:
      choice_output[2] = 0;
      choice_output[1] = 1;
      choice_output[0] = 0;
      break;
    case 3:
      choice_output[2] = 0;
      choice_output[1] = 1;
      choice_output[0] = 1;
      break;
    case 4:
      choice_output[2] = 1;
      choice_output[1] = 0;
      choice_output[0] = 0;
      break;
    case 5:
      choice_output[2] = 1;
      choice_output[1] = 0;
      choice_output[0] = 1;
      break;
    case 6:
      choice_output[2] = 1;
      choice_output[1] = 1;
      choice_output[0] = 0;
      break;
    case 7:
      choice_output[2] = 1;
      choice_output[1] = 1;
      choice_output[0] = 1;
      break;
      //default:
  }

  if (choice_output[2] == 1) {
    digitalWrite(C_PIN, HIGH);
  } else {
    digitalWrite(C_PIN, LOW);
  }

  if (choice_output[1] == 1) {
    digitalWrite(B_PIN, HIGH);
  } else {
    digitalWrite(B_PIN, LOW);
  }

  if (choice_output[0] == 1) {
    digitalWrite(A_PIN, HIGH);
  } else {
    digitalWrite(A_PIN, LOW);
  }
}




int line_degree_read() {
  int line_min[32];
  int line_max[32];
  float smallest = 0.0;
  float biggest = 0.0;
  int line_degree = 0;
  int line_value_ori[32];
  int line_digits[32];

  for (int id = 0; id <= 7; id++) {
    F_line_choice(id);
    line_value_ori[id] = analogRead(AMP_PIN[0]); //0-7
    line_value_ori[id + 8] = analogRead(AMP_PIN[1]); //8-15
    line_value_ori[id + 16] = analogRead(AMP_PIN[2]); //15-23
    line_value_ori[id + 24] = analogRead(AMP_PIN[3]); //24-31
  }
  line_value_ori[28] = 0; //This is incompetence!!!!

  //    for (id = 0; id <= 31; id++) { //Please comment here as well.
  //      Serial.print(line_value[id]);
  //      Serial.print(",");
  //    } //Please comment here as well.

  for (int id = 0; id <= 31; id++) {
    if (line_value_ori[id] >= C_line_threshold) {
      line_digits[id] = 1;
    } else {
      line_digits[id] = 0;
    }
  }

  for (int id = 0; id <= 31; id++) {
    if (line_digits[id] == 1) {
      line_min[id] = id;
      line_max[id] = id;
    } else {
      line_min[id] = 31;
      line_max[id] = 0;
    }
  }

  smallest = 31;
  biggest = 0;
  for (int id = 0; id <= 31; id++) {
    smallest = min(smallest, line_min[id]);
    biggest = max(biggest, line_max[id]);
  }
  //    Serial.print(smallest);
  //    Serial.print(",");
  //    Serial.print(biggest);
  //    Serial.print(",");

  float line_value;
  if (biggest - smallest > 16) {
    line_value = (biggest + smallest) / 2 + 16;
    if (line_value <= 32) {
      line_value -= 32;
    }
  } else if (0 < biggest - smallest & biggest - smallest <= 16) {
    line_value = (biggest + smallest) / 2;
  } else if (biggest == 0 & smallest == 31) {
    line_value = -1;
  }
  line_degree = round(line_value * 11.25);

  if (line_degree == 0) {
    line_degree = 360;
  } else if (line_degree > 360) {
    line_degree -= 360;
  } else if (line_degree < 0 & line_degree != -11) {
    line_degree += 360;
  } else if (line_degree == -11) {
    line_degree = 0;
  }
  return line_degree;
}
