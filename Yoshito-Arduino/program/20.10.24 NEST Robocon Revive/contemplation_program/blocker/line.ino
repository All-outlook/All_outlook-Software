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
