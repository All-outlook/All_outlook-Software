int line_read () {
  int line_read_value[4];
  int line_value;
  for (int id = 0; id <= 3; id++) {
    line_read_value[id] = analogRead(line_pin[id]);

    if (line_read_value[id] >= 800) {
      line_value = 1;
      digitalWrite(red_led[id], HIGH);
    } else {
      line_value = 0;
      digitalWrite(red_led[id], LOW);
    }

    Serial.print("line");
    Serial.print(id);
    Serial.print(":");
    Serial.print(line_read_value[id]);
    Serial.print(", ");
  }
  Serial.println();
  return line_value;
}

int line_degree() {
  int line_degree_value;
  int line_thou = (line_val[0] * 1000) + (line_val[1] * 100) + (line_val[2] * 10) + (line_val[3] * 1);

  if (line_thou == 1111) {
    line_degree_value = -1;
  } else if (line_thou == 1110) {
    line_degree_value = 270;
  } else if (line_thou == 1101) {
    line_degree_value = 180;
  } else if (line_thou == 1100) {
    line_degree_value = 215;
  } else if (line_thou == 1011) {
    line_degree_value = 90;
  } else if (line_thou == 1010) {
    line_degree_value = -1;
  } else if (line_thou == 1001) {
    line_degree_value = 135;
  } else if (line_thou == 1000) {
    line_degree_value = 180;
  } else if (line_thou == 0111) {
    line_degree_value = 0;
  } else if (line_thou == 0110) {
    line_degree_value = 315;
  } else if (line_thou == 0101) {
    line_degree_value = -1;
  } else if (line_thou == 0100) {
    line_degree_value = 270;
  } else if (line_thou == 0011) {
    line_degree_value = 315;
  } else if (line_thou == 0010) {
    line_degree_value = 0;
  } else if (line_thou == 0001) {
    line_degree_value = 90;
  } else if (line_thou == 0000) {
    line_degree_value = -1;
  }
  return line_degree_value;

  Serial.print(" line＿degree:");
  Serial.print(line_degree_value);
}
