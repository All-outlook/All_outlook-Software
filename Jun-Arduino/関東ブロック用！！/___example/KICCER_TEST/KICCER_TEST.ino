

void setup() {
  Serial.begin(9600);
  F_KICCER_SETUP();

  delay(3000);
}

int i = 0;
void loop() {
  F_time_read();
  F_KICCER_roop();
//  Serial.println(i);

  i++;
//  if (i > 20000) {
    F_KICCER_kick();
    i = 0;
//  }

  //  digitalWrite(KICCER_CUT,LOW);
  //  digitalWrite(KICCER, HIGH);
  //  delay(1500);
  //  digitalWrite(KICCER, LOW);
  //  digitalWrite(KICCER_CUT,HIGH);
  //  delay(5000);
}
