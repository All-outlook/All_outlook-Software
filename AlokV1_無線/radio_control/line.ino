int line_read(int id) {
  line_analog_value[id] = analogRead(line_pin[id]);
  int line_value;

  if (line_analog_value[id] >= line_threshold[id]) {
    line_value = 1;
    digitalWrite(RED_LED_pin[id], HIGH);
  } else {
    line_value = 0;
    digitalWrite(RED_LED_pin[id], LOW);
  }

  return line_value;
}



// ※この子は上の子を使った後じゃないとマトモな値でないよ
int line_air() {
  // 0:地面 1:空中
  for (int id = 0; id <= 3; id += 1) {
    if (line_analog_value[id] >= 150) {
      return 0;
    } else if (id == 3) {
      return 1;
    }
  }

}
