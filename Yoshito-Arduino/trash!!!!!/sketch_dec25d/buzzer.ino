const int BUZZER = 35;
long random_digits;

const int Do = 261;
const int Re = 294;
const int Mi = 329;
const int Fa = 349;
const int So = 392;
const int La = 440;
const int Si = 493;
const int Do2 = 523;
const int Re2 = 587;
const int Mi2 = 659;
const int Fa2 = 698;
const int So2 = 784;
const int La2 = 880;
const int Si2 = 988;
const int Do3 = 1047;
const int Re3 = 1175;
const int Mi3 = 1319;
const int Fa3 = 1397;
const int So3 = 1568;

const int oneup[6] = { Mi2, So2, Mi3, Do3, Re3, So3};
const int mario[13] = {Mi2, Mi2, 0, Mi2, 0, Do2, Mi2, 0, So2, 0, 0, 0, So};
const int fire[3] = {So, So2, So3};
const int dead[9] = {Si, Fa2, 0, Fa2, Fa2, Mi2, 0, Re2, Do2};
const int damage[18] = {La2, Mi, La, 0, 0, 0, La2, Mi, La, 0, 0, 0, La2, Mi, La, 0, 0, 0};
const int star[32] = {Do2, 0, Do2, 0, Do2, 0, Re, Do2, 0, Do2, 0, Re, Do2, 0, Do2, 0,
                      Si , 0, Si, 0, Si, 0, Do, Si, 0, Si, 0, Do, Si, 0, Si, 0};

void F_buzzer_setup()
{
  pinMode(BUZZER, OUTPUT);
  randomSeed(analogRead(0));
  random_digits = random(0, 6);

  Serial.print(random_digits);
  Serial.print("..........");
  
  if (random_digits == 0)
  {
    F_buzzer_zero();
  }
  else if (random_digits == 1)
  {
    F_buzzer_one();
  }
  else if (random_digits == 2)
  {
    F_buzzer_two();
  }
  else if (random_digits == 3)
  {
    F_buzzer_three();
  }
  else if (random_digits == 4)
  {
    F_buzzer_four();
  }
  else if (random_digits == 5)
  {
    F_buzzer_five();
  }
  Serial.println("finish");
}

void F_buzzer_zero() {
    tone(35, 740, 300);
    delay(300) ;
    tone(35, 587, 300);
    delay(300) ;
    tone(35, 440, 300);
    delay(300) ;
    tone(35, 587, 300);
    delay(300) ;
    tone(35, 659, 300);
    delay(300) ;
    tone(35, 880, 300);
    delay(600) ;
    tone(35, 880, 300);
    delay(300) ;
    tone(35, 659, 300);
    delay(300) ;
    tone(35, 740, 300);
    delay(300) ;
    tone(35, 659, 300);
    delay(300) ;
    tone(35, 440, 300);
    delay(300) ;
    tone(35, 587, 300);
    delay(600) ;
  }

  void F_buzzer_one() {
    tone(35, 262, 150);
    delay(225);
    tone(35, 262, 150);
    delay(225);
    tone(35, 294, 150);
    delay(225);
    tone(35, 294, 150);
    delay(225);
    tone(35, 330, 150);
    delay(225);
    tone(35, 330, 150);
    delay(225);
    tone(35, 349, 150);
    delay(225);
    tone(35, 349, 150);
    delay(225);
    tone(35, 330, 225);
    delay(425);
    tone(35, 294, 225);
    delay(425);
    tone(35, 262, 225);
    delay(425);
}

void F_buzzer_two() {
  for (id = 0; id < 3; id++) {
    tone(35, Si2, 100);
    delay(50);
    tone(35, Mi3, 250);
    delay(250);
  }
  delay(200);

  for (id = 0; id <= 2; id++) {
    for (id = 0; id < 6; id++) {
      tone(35, oneup[i], 100);
      delay(125);
    }
  }
}

void F_buzzer_three() {
    for (id = 0; id < 32; id++) {
    tone(35, star[i], 100);
    delay(100);
  }
}

void F_buzzer_four() {
    for (id = 0; id < 13; id++) {
    tone(35, mario[i], 50);
    delay(140);
  }
}

void F_buzzer_five() {
  tone(35, 880);
  delay(500);
  tone(35, 698);
  delay(500);
  tone(35, 784);
  delay(500);
  tone(35, 523);
  delay(500);
  noTone(35);
  delay(500);

  tone(35, 523);
  delay(500);
  tone(35, 784);
  delay(500);
  tone(35, 880);
  delay(500);
  tone(35, 698);
  delay(800);
  noTone(35);
}
