/**************************************

Timer0 (8bit timer)
delay
mills()
micros()
pwm 13,4

Timer1 (16bit timer)
pwm 12,11
servo lib

Timer2 (8bit timer)
pwm 10,9
tone(ブザー)
FlexiTimer2,MsTimer2

Timr3 (16bit timer)
pwm 5,3,2

Timer4 (16bit timer)
pwm 8,7,6

Timer5 (16bit timer)
pwm 46,45,44


参考:https://tomixrm.wordpress.com/2017/08/24/arduino-mega%E3%81%AE%E3%82%BF%E3%82%A4%E3%83%9E%E3%83%BC%E6%83%85%E5%A0%B1/

**************************************/

int pinA = 5;
int pinB = 6;


void setup() {
  TCCR4B = (TCCR4B & 0b11111000) | 0x01;
  
  Serial.begin(38400);
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
}

void loop() {
    for (int i = 0; i < 256; i++) {
      analogWrite(6, i);
      //Serial.println(i);
      delay(2);
    }
    for (int i = 256; i >= 0; i--) {
      analogWrite(6, i);
      //Serial.println(i);
    }
//  analogWrite(pinA, 100);
//  analogWrite(pinB, 125);
//  delay(1000);
//  analogWrite(pinB, 30);
//  delay(1000);
}
