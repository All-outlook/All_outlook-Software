const int BUZZER = 35;
int random_digits;

void F_buzzer_setup()
{
  pinMode(BUZZER, OUTPUT);
  randomSeed(analogRead(0));
  random_digits = random(6);

  Serial.print(random_digits);
  if (random_digits == 0)
  {
    F_buzzer_0();
  }
  else if (random_digits == 1)
  {
    F_buzzer_1();
  }
  else if (random_digits == 2)
  {
    F_buzzer_2();
  }
  else if (random_digits == 3)
  {
    F_buzzer_3();
  }
  else if (random_digits == 4)
  {
    F_buzzer_4();
  }
  else if (random_digits == 5)
  {
    F_buzzer_5();
  }
}