void setup() {
  Serial.begin(9600);
}

void loop() {
  for (int tt = 3; tt < 8; tt++) {
    Serial.println(analogRead(tt));
  }

  int Line_R;
  for (int LR = 0; LR < 15; LR ++) { //right check
    if (analogRead(LR) > 1000){
      Line_R = LR + 1;
      break;
    }
  }

  int Line_L;
  for (int LL = 15; LL > 0; LL = LL - 1) { //right check
    if (analogRead(LL) > 1000){
      Line_L = LL;
      break;
    }
  }

  

  Serial.println(Line_R);
  Serial.println("");
  delay(500);
}
