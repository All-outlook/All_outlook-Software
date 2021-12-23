
void setup() {
  F_MD_Serial_setup();
  F_all_reset();
  Serial.begin(38400);
}

void loop() {
  F_time_read();

  for (int i = 1; i <= 360; i += 1) {
    Serial.print(i );
    Serial.print("__");
    F_MD_rotate(i , 0, 10);
    Serial.println();
  }
}











































void mawarudake() {
  int kyuukei = 10;
  for (int i = 0; i < 150; i++) {
    kurukuru(80, 80, -80, -80);
    delay(1);
  }
  for (int i = 0; i < kyuukei; i++) {
    kurukuru(0, 0, 0, 0);
    delay(1);
  }

  for (int i = 0; i < 150; i++) {
    kurukuru(-200, 200, 200, -200);
    delay(1);
  }
  for (int i = 0; i < kyuukei; i++) {
    kurukuru(0, 0, 0, 0);
    delay(1);
  }

  for (int i = 0; i < 150; i++) {
    kurukuru(-200, -200, 200, 200);
    delay(1);
  }
  for (int i = 0; i < kyuukei; i++) {
    kurukuru(0, 0, 0, 0);
    delay(1);
  }

  for (int i = 0; i < 150; i++) {
    kurukuru(200, -200, -200, 200);
    delay(1);
  }
  for (int i = 0; i < kyuukei; i++) {
    kurukuru(0, 0, 0, 0);
    delay(1);
  }

}


void kurukuru(int a, int b, int c, int d) {
  F_speed_send(0, a);
  F_speed_send(1, b);
  F_speed_send(2, c);
  F_speed_send(3, d);
}
