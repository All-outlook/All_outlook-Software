void setup() {
  Serial.begin(9600);
  
  //pinMode(52,INPUT_PULLUP);while(digitalRead(52)==HIGH);
}
//line pin data   pin place:data
int line[15]={840, //0  1 :
              000, //1  2 :
              850, //2  3 :
              850, //3  4 :
              700, //4  5 :
              830, //5  6 :
              000, //6  7 :light up
              000, //7  8 :light up
              950, //8  9 :
              900, //9  10:
              880, //10 11:
              860, //11 12:
              960, //12 13:
              000, //13 14:
              860};//14 15:

void loop() {
motorAngle(0);
Serial.println(analogRead(1));

//int i;
//int Max = 99999;
////Serial.println("-");
//for(i=0;i<15;i++){
//  Serial.println(analogRead(1));
//  if(analogRead(i)<line[i]){
//    motorAngle(i*24);
//    Serial.println(i);
//    break;
//  }else{
//    //motor(0,0,0);
//  }
//}

  delay(100);
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

//  Serial.println(M1);
//  Serial.println(M2);
//  Serial.println(M3);

  int motor_all_list[3] = {49, 51, 53};
  int motor_pin_list[3] = {46, 48, 50};
  int motor_pwm_list[3] = {2, 3, 4};
  for (int MOTF = 0; MOTF <= 2; MOTF++) {
    int HL;
    digitalWrite(motor_all_list[MOTF] , HIGH);
    if (SFlist[MOTF] >= 0) {HL = LOW;} else {HL = HIGH;}
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
