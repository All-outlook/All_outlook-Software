int LINE_receive;

void F_LINE_setup() {
  Serial1.begin(115200);
}

void F_LINE_read() {
  
  while (Serial1.available() > 5) {
    int g = Serial1.read();
  }
  if (Serial1.available() > 0) {
    LINE_receive = Serial1.read() * 2;
    if(LINE_receive > 0){
      LINE_receive = F_360_correct(180 + LINE_receive);
    }
  }
}

int F_LINE_get() {
  return LINE_receive;
}

void F_LINE_debug(){
  Serial.print(" LINE:");
  Serial.print(LINE_receive);
}
