int LINE_receive;

void F_LINE_setup() {
  Serial1.begin(38400);
}

void F_LINE_read() {
  
  while (Serial1.available() > 5) {
    int g = Serial1.read();
  }
  if (Serial1.available()) {
    LINE_receive = Serial1.read() * 2;
  }
}

int F_LINE_get() {
  return LINE_receive;
}

void F_LINE_debug(){
  Serial.print(" LINE:");
  Serial.print(LINE_receive);
}
