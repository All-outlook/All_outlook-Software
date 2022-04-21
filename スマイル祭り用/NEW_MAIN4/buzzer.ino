const int BUZZER = 35;

void F_BUZ_setup() {
  pinMode(BUZZER, OUTPUT);
}


void F_BUZ_frog() {
  int a = 150;
  int b = 225;
  int c = 300;
  int d = 425;
  tone(BUZZER, 262, a); //ド
  delay(b);
  tone(BUZZER, 262, a); //ド
  delay(b);
  tone(BUZZER, 294, a); //レ
  delay(b);
  tone(BUZZER, 294, a); //レ
  delay(b);
  tone(BUZZER, 330, a); //ミ
  delay(b);
  tone(BUZZER, 330, a); //ミ
  delay(b);
  tone(BUZZER, 349, a); //ファ
  delay(b);
  tone(BUZZER, 349, a); //ファ
  delay(b);

  tone(BUZZER, 330, b); //ミ
  delay(d);
  tone(BUZZER, 294, b); //レ
  delay(d);
  tone(BUZZER, 262, b); //ド
  delay(d);
}
