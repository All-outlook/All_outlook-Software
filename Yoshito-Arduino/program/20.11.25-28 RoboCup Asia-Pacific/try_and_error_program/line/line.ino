

int line_value;
int line_degree;

unsigned long period_count;

void setup() {
  Serial.begin(115200);
  F_line_setup();
}

void loop() {
  time_get();

  
  if (period_count == 1000) {
    period_count = 0;
  }
  period_count++;

  line_value = F_line_read();
//  Serial.print('l');
//  Serial.print(line_value);
//  Serial.print(",");

  line_degree = F_line_step(line_value);
//  Serial.print('a');
//  Serial.print(line_degree);
//  Serial.print(",");
//  Serial.println();
}
