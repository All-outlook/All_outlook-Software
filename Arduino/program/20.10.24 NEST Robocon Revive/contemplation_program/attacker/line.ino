int line_loop(int id) {
  int line_read;
  int line_digits;
  line_read = analogRead(line_pin[id]);

  if (line_read >= line_threshold[id]) {
    line_digits = 1;
    digitalWrite(red_LED_pin[id], HIGH);
  } else {
    line_digits = 0;
    digitalWrite(red_LED_pin[id], LOW);
  }
  /*Serial.print("line");
  Serial.print(id);
  Serial.print(":");
  Serial.print(line_read);
  Serial.print(", ");*/
  return line_digits;
}

/*int line_degree_function() {
  int line_thou = (line_value[0] * 1000) + (line_value[1] * 100) + (line_value[2] * 10) + (line_value[3] * 1);
  int line_degree_value;

  if (line_thou == 1111) {
    line_degree_value = -1;
  } else if (line_thou == 1110) {
    line_degree_value = 270;
  } else if (line_thou == 1101) {
    line_degree_value = 180;
  } else if (line_thou == 1100) {
    line_degree_value = 225;
  } else if (line_thou == 1011) {
    line_degree_value = 90;
  } else if (line_thou == 1010) {
    line_degree_value = -1;
  } else if (line_thou == 1001) {
    line_degree_value = 135;
  } else if (line_thou == 1000) {
    line_degree_value = 180;
  } else if (line_thou == 111) {
    line_degree_value = 0;
  } else if (line_thou == 110) {
    line_degree_value = 315;
  } else if (line_thou == 101) {
    line_degree_value = -1;
  } else if (line_thou == 100) {
    line_degree_value = 270;
  } else if (line_thou == 11) {
    line_degree_value = 45;
  } else if (line_thou == 10) {
    line_degree_value = 0;
  } else if (line_thou == 1) {
    line_degree_value = 90;
  } else if (line_thou == 0) {
    line_degree_value = -1;
  }
  Serial.print("line_degree:");
  Serial.print(line_degree_value);
  Serial.print(", ");
  return line_degree_value;
}*/
