int line_read() {
  for (int id = 0; id <= 7; id++) {
    line_choice[id];
    line_count[id] = analogRead(MULTIPLEXER[0]);
    line_count[id + 8] = analogRead(MULTIPLEXER[1]);
    line_count[id + 16] = analogRead(MULTIPLEXER[2]);
    line_count[id + 24] = analogRead(MULTIPLEXER[3]);
  }

  for (int id = 0; id <= 31; id++) {
  //  line_count[id] = line_count[id] >= 500 ? 1 : 0;
    Serial.print(line_count[id]);
    Serial.print(", ");
  }
  Serial.println();

  int go_degree = 0;
  return go_degree;
}
