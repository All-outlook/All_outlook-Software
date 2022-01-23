const int BUZZER = 35;
long random_number;

void F_buzzer_setup()
{
  pinMode(BUZZER, OUTPUT);
  randomSeed(analogRead(0));
  random_number = random(0, 6);
//random_number = 0;
  Serial.print(random_number);
  Serial.print("..........");
  
  if (random_number == 0)
  {
    F_buzzer_zero();
  }
  else if (random_number == 1)
  {
    F_buzzer_one();
  }
  else if (random_number == 2)
  {
    F_buzzer_two();
  }
  else if (random_number == 3)
  {
    F_buzzer_three();
  }
  else if (random_number == 4)
  {
    F_buzzer_four();
  }
  else if (random_number == 5)
  {
    F_buzzer_five();
  }
  Serial.println("finish");
}
