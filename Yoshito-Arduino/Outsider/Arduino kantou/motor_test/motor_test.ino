void setup() {
  // put your setup code here, to run once:
  pinMode(52,INPUT_PULLUP);
  while(digitalRead(52)==HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  motorAngle(90);
  delay(1000);
  motorAngle(-90);
  delay(1000);
//  motorAngle(270);
//  delay(1000);
//  motorAngle(0);
//  delay(1000);
}

void motorAngle(int theta){ //モーター角度
  int sita = theta;
  int power = 150;
  int M1;
  int M2;
  int M3;
  M1 = sin((sita - 60) * 3.14 / 180) * power;
  M2 = sin((sita - 180) * 3.14 / 180) * power;
  M3 = sin((sita - 300) * 3.14 / 180) * power;

  int SFlist[3] = {M1 , M2 , M3};
  int motor_all_list[3] = {49, 51, 53}; //個体値？ by  Yoshito
  int motor_pin_list[3] = {46, 48, 50}; //
  int motor_pwm_list[3] = {2, 3, 4};　
  for (int MOTF = 0; MOTF <= 2; MOTF++) {
    int HL;
    digitalWrite(motor_all_list[MOTF] , HIGH);
    if (SFlist[MOTF] >= 0) {
      HL = LOW;
      } else {
        HL = HIGH;
    digitalWrite(motor_pin_list[MOTF] , HL);
    analogWrite(motor_pwm_list[MOTF] , abs(SFlist[MOTF]));
  }
}

void motor(int MpinIN0 , int MpinIN1 , int MpinIN2){ //モーター(pololu)
  int Mpin[3] = {MpinIN0 , MpinIN1 , MpinIN2};
  int motor_all_list[3] = {49, 51, 53};
  int motor_pin_list[3] = {46, 48, 50};
  int motor_pwm_list[3] = {2, 3, 4};
  for (int MOTF = 0; MOTF <= 2; MOTF++) {
    int HL;
    digitalWrite(motor_all_list[MOTF] , HIGH);
    if (Mpin[MOTF] >= 0) {
      HL = HIGH;
    } else {
      HL = LOW;
    }
    digitalWrite(motor_pin_list[MOTF] , HL);
    analogWrite(motor_pwm_list[MOTF] , abs(Mpin[MOTF]));
  }
}
