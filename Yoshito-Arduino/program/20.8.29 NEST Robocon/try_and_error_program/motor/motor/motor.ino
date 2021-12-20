const int Ichinose_F = 2 ; //F = forward rotation(正転)
const int Ichinose_R = 3 ; //R =  reversal(逆転)
const int Nikaido_F = 4 ;
const int Nikaido_R = 5 ;
const int Mieno_F = 6 ;
const int Mieno_R = 7 ;
const int Yotsuya_F = 8 ;
const int Yotsuya_R = 9 ;

int speed;
void setup() {
  Serial.begin(9600);
  pinMode(Ichinose_F, OUTPUT);
  pinMode(Ichinose_R, OUTPUT);
  pinMode(Nikaido_F, OUTPUT);
  pinMode(Nikaido_R, OUTPUT);
  pinMode(Mieno_F, OUTPUT);
  pinMode(Mieno_R, OUTPUT);
  pinMode(Yotsuya_F, OUTPUT);
  pinMode(Yotsuya_R, OUTPUT);
}

void loop() {
  analogWrite(Ichinose_F, 0);
  analogWrite(Ichinose_R, 0);
  analogWrite(Nikaido_F, 0);
  analogWrite(Nikaido_R, 0);
  analogWrite(Mieno_F, 0);
  analogWrite(Mieno_R, 0);
  analogWrite(Yotsuya_F, 0);
  analogWrite(Yotsuya_R, 0);
  
  speed = 0; //前進
 while(speed <= 255){
  Serial.println(speed);
analogWrite(Ichinose_R, speed);
analogWrite(Nikaido_R, speed);
analogWrite(Mieno_F, speed);
analogWrite(Yotsuya_F, speed);
  delay(150);
  speed = speed + 45;
 }
  delay(1000);

  speed = 255;
  while(speed >= 0){
    Serial.println(speed);
analogWrite(Ichinose_R, speed);
analogWrite(Nikaido_R, speed);
analogWrite(Mieno_F, speed);
analogWrite(Yotsuya_F, speed);
    delay(50);
    speed = speed - 45;
  }

    speed = 0; //後進
 while(speed <= 255){
  Serial.println(speed);
analogWrite(Ichinose_F, speed);
analogWrite(Nikaido_F, speed);
analogWrite(Mieno_R, speed);
analogWrite(Yotsuya_R, speed);
  delay(150);
  speed = speed + 45;
 }
  delay(500);

  speed = 255;
  while(speed >= 0){
    Serial.println(speed);
analogWrite(Ichinose_F, speed);
analogWrite(Nikaido_F, speed);
analogWrite(Mieno_R, speed);
analogWrite(Yotsuya_R, speed);
    delay(50);
    speed = speed - 45;
  }
  delay(1000);

    speed = 0; //左
 while(speed <= 255){
  Serial.println(speed);
analogWrite(Ichinose_F, speed);
analogWrite(Nikaido_R, speed);
analogWrite(Mieno_R, speed);
analogWrite(Yotsuya_F, speed);
  delay(150);
  speed = speed + 45;
 }
  delay(1000);

  speed = 255;
  while(speed >= 0){
    Serial.println(speed);
analogWrite(Ichinose_F, speed);
analogWrite(Nikaido_R, speed);
analogWrite(Mieno_R, speed);
analogWrite(Yotsuya_F, speed);
    delay(50);
    speed = speed - 45;
  }

    speed = 0; //右
 while(speed <= 255){
  Serial.println(speed);
analogWrite(Ichinose_R, speed);
analogWrite(Nikaido_F, speed);
analogWrite(Mieno_F, speed);
analogWrite(Yotsuya_R, speed);
  delay(150);
  speed = speed + 45;
 }
  delay(500);

  speed = 255;
  while(speed >= 0){
    Serial.println(speed);
analogWrite(Ichinose_R, speed);
analogWrite(Nikaido_F, speed);
analogWrite(Mieno_F, speed);
analogWrite(Yotsuya_R, speed);
    delay(50);
    speed = speed - 45;
  }

      speed = 0; //前左
 while(speed <= 255){
  Serial.println(speed);
analogWrite(Nikaido_F, speed);
analogWrite(Yotsuya_F, speed);
  delay(150);
  speed = speed + 45;
 }
  delay(1000);

  speed = 255;
  while(speed >= 0){
    Serial.println(speed);
analogWrite(Nikaido_F, speed);
analogWrite(Yotsuya_F, speed);
    delay(50);
    speed = speed - 45;
  }

    speed = 0; //後右
 while(speed <= 255){
  Serial.println(speed);
analogWrite(Nikaido_R, speed);
analogWrite(Yotsuya_R, speed);
  delay(150);
  speed = speed + 45;
 }
  delay(500);

  speed = 255;
  while(speed >= 0){
    Serial.println(speed);
analogWrite(Nikaido_R, speed);
analogWrite(Yotsuya_R, speed);
    delay(50);
    speed = speed - 45;
  }
  delay(1000);

    speed = 0; //左回転
 while(speed <= 255){
  Serial.println(speed);
analogWrite(Ichinose_R, speed);
analogWrite(Nikaido_F, speed);
analogWrite(Mieno_R, speed);
analogWrite(Yotsuya_F, speed);
  delay(150);
  speed = speed + 45;
 }
  delay(1000);

  speed = 255;
  while(speed >= 0){
    Serial.println(speed);
analogWrite(Ichinose_R, speed);
analogWrite(Nikaido_F, speed);
analogWrite(Mieno_R, speed);
analogWrite(Yotsuya_F, speed);
    delay(50);
    speed = speed - 45;
  }

    speed = 0; //右回転
 while(speed <= 255){
  Serial.println(speed);
analogWrite(Ichinose_F, speed);
analogWrite(Nikaido_R, speed);
analogWrite(Mieno_F, speed);
analogWrite(Yotsuya_R, speed);
  delay(150);
  speed = speed + 45;
 }
  delay(500);

    speed = 255;
  while(speed >= 0){
    Serial.println(speed);
analogWrite(Ichinose_F, speed);
analogWrite(Nikaido_R, speed);
analogWrite(Mieno_F, speed);
analogWrite(Yotsuya_R, speed);
    delay(50);
    speed = speed - 45;
  }
}
