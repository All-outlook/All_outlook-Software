const int BUZZER = 35;
long random_digits;

void setup() {
  pinMode(BUZZER, OUTPUT);
  randomSeed(analogRead(0));
  random_digits = random(0, 6);

  Serial.print(random_digits);
  Serial.print("..........");
}

void loop() {
  
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
