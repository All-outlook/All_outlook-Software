int line_angle[] = {0, 90, 180, 270};

void line_read () {
  int line_read_value[4];
  int line_value[4];
  int line_degree;
  for (int id = 0; id <= 3; id++) {
    line_read_value[id] = analogRead(line_pin[id]);

    if (line_read_value[id] >= 800) {
      line_value[id] = 1;
      digitalWrite(red_led[id], HIGH);
    } else {
      line_value[id] = 0;
      digitalWrite(red_led[id], LOW);
    }
    
    Serial.print("line");
    Serial.print(id);
    Serial.print(":");
    Serial.print(line_value[id]);
    Serial.print(", ");
    
    if (line_value[id] == 1){
      line_degree = line_angle - 180;
    }
    if (line_degree < 0){
      line_degree += 180;
    }
    Serial.print(line_degree);
  }
  Serial.println();
}
