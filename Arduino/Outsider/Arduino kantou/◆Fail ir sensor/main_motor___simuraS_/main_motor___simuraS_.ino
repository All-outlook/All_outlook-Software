void setup() {
  pinMode(5, OUTPUT);//後
  pinMode(6, OUTPUT);//pwm後HH左
  pinMode(7, OUTPUT);//後
  pinMode(8, OUTPUT);//左
  pinMode(9, OUTPUT);//左
  pinMode(10, OUTPUT);//pwm左
  pinMode(11, OUTPUT); //9番ピンを出力モードにする
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int inputchar;
  inputchar = Serial.read();
  Serial.println(inputchar);//#
  int a = analogRead(A6); //前
  int c = analogRead(A7); //右
  int b = analogRead(A8); //後
  int d = analogRead(A9); //左
  
  if (inputchar != -1 ) {
    switch (inputchar) {
    
      case'A':
        digitalWrite(11, HIGH);//右
        digitalWrite(13, LOW);
        digitalWrite(8, HIGH);//左
        digitalWrite(10, HIGH);
        digitalWrite(5, LOW);
        analogWrite(12, 140);//右
        analogWrite(9, 140);//左
        break;
      case'B':
        digitalWrite(5, HIGH);//右
        digitalWrite(7, LOW);
        digitalWrite(8, HIGH);//左
        digitalWrite(10, LOW);
        digitalWrite(11, LOW);
        analogWrite(6, 100);//右
        analogWrite(9, 140);//左
        break;
      case'C':
        digitalWrite(11, HIGH);//右
        digitalWrite(13, HIGH);
        digitalWrite(8, HIGH);//左
        digitalWrite(10, LOW);
        digitalWrite(5, LOW);
        analogWrite(12, 140);//右
        analogWrite(9, 140);//左
        break;
      case'D':
        digitalWrite(11, HIGH);//右
        digitalWrite(13, HIGH);
        digitalWrite(8, HIGH);//左
        digitalWrite(10, LOW);
        digitalWrite(5, LOW);
        analogWrite(12, 140);//右
        analogWrite(9, 140);//左
        break;
      case'E':
        digitalWrite(11, HIGH);//右
        digitalWrite(13, HIGH);
        digitalWrite(5, HIGH);//左
        digitalWrite(7, HIGH);
        digitalWrite(8, LOW);
        analogWrite(12, 140);//右
        analogWrite(6, 140);//左
        break;
      case'F':
        digitalWrite(11, HIGH);//右
        digitalWrite(13, HIGH);
        digitalWrite(5, HIGH);//左
        digitalWrite(7, HIGH);
        digitalWrite(8, LOW);
        analogWrite(12, 140);//右
        analogWrite(6, 140);//左
        break;
      case'G':
        digitalWrite(11, HIGH);//右
        digitalWrite(13, HIGH);
        digitalWrite(5, HIGH);//左
        digitalWrite(7, HIGH);
        digitalWrite(8, LOW);
        analogWrite(12, 140);//右
        analogWrite(6, 140);//左
        break;
      case'H':
        digitalWrite(8, HIGH);//右
        digitalWrite(10, LOW);
        digitalWrite(5, HIGH);//左
        digitalWrite(7, LOW);
        digitalWrite(11, LOW);
        analogWrite(9, 140);//右
        analogWrite(6, 140);//左
        break;
      case'I':
        digitalWrite(5, HIGH);//右
        digitalWrite(7, LOW);
        digitalWrite(8, HIGH);//左
        digitalWrite(10, LOW);
        digitalWrite(11, LOW);
        analogWrite(6, 140);//右
        analogWrite(9, 140);//左
        break;
      case'J':
        digitalWrite(11, HIGH);//右
        digitalWrite(13, HIGH);
        digitalWrite(8, HIGH);//左
        digitalWrite(10, LOW);
        digitalWrite(5, LOW);
        analogWrite(12, 140);//右
        analogWrite(9, 140);//左
        break;
      case'K':
        digitalWrite(11, HIGH);//右
        digitalWrite(13, HIGH);
        digitalWrite(8, HIGH);//左
        digitalWrite(10, LOW);
        digitalWrite(8, LOW);
        analogWrite(12, 140);//右
        analogWrite(6, 140);//左
        break;
      case'M':
        digitalWrite(11, HIGH);//右
        digitalWrite(13, HIGH);
        digitalWrite(5, HIGH);//左
        digitalWrite(7, HIGH);
        digitalWrite(8, LOW);
        analogWrite(12, 140);//右
        analogWrite(6, 140);//左
        break;




    }
  } else {
   if(d >= 30){
    digitalWrite(11, HIGH);//SLP解除
    digitalWrite(13,HIGH);//反対方向
    digitalWrite(8, HIGH); //SLP解除
    digitalWrite(10, HIGH);//反対方向
    digitalWrite(5, HIGH);//SLP解除
    digitalWrite(7, HIGH);//反対方向
    analogWrite(12, 140);//前進240右90
    analogWrite(9, 40);//前進255右90
    analogWrite(6, 155);//スピード最大右250
    
  }else if (c >= 100) {
    digitalWrite(11, HIGH);//SLP解除
    digitalWrite(13,LOW);//反対方向
    digitalWrite(8, HIGH); //SLP解除
    digitalWrite(10, LOW);//反対方向
    digitalWrite(5, HIGH);//SLP解除
    digitalWrite(7, LOW);//反対方向
    analogWrite(12, 140);//前進240右90
    analogWrite(9, 40);//前進255右90
    analogWrite(6, 155);//スピード最大右250
  } else if (b >= 23) {
    digitalWrite(11, HIGH);//SLP解除
    digitalWrite(13, LOW);//反対方向
    digitalWrite(8, HIGH); //SLP解除
    digitalWrite(10, HIGH);//反対方向
    digitalWrite(5, LOW);//SLP解除
    digitalWrite(7, HIGH);//反対方向
    analogWrite(12, 140);//前進240右90
    analogWrite(9, 140);//前進255右90
    //analogWrite(6, 250);//スピード最大右

    }else if(a >= 25){
    digitalWrite(11, HIGH);//SLP解除
    digitalWrite(13, HIGH);//反対方向
    digitalWrite(8,HIGH);//SLP解除
    digitalWrite(10, LOW);//反対方向
    digitalWrite(5,LOW);
    analogWrite(12, 140);//前進240右90
    analogWrite(9, 140);//前進255右90

  }
}
}
