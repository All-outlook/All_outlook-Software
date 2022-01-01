#include <Adafruit_NeoPixel.h>

#define KICC_VAL 200

const int KICCER_LED = 12;
const int KICCER_LED_NUM = 2;
Adafruit_NeoPixel KICCER(KICCER_LED_NUM, KICCER_LED, NEO_GRB + NEO_KHZ800);

const int KICC_PIN = 11;
const int DISCONNECT_PIN = 9;

const int BALL_CHECK_PINA = A7;
const int BALL_CHECK_PINB = A8;

const int kiccer_current = 50; //電流制限(0-255)



void F_KICCER_setup() {
  KICCER.begin();
  KICCER.setBrightness(kiccer_current);

  KICCER.clear();
  KICCER.setPixelColor(0, KICCER.Color(100, 100, 0));
  KICCER.setPixelColor(1, KICCER.Color(100, 100, 0));
  KICCER.show();

  pinMode(KICC_PIN, OUTPUT);
  digitalWrite(KICC_PIN,LOW);
  pinMode(DISCONNECT_PIN, OUTPUT);
  digitalWrite(DISCONNECT_PIN,LOW);
}

void F_KICCR_KICC(){
   digitalWrite(DISCONNECT_PIN,HIGH);
   delay(1000);
   digitalWrite(KICC_PIN,HIGH);
   delay(1000);
   digitalWrite(KICC_PIN,LOW);
   digitalWrite(DISCONNECT_PIN,LOW);
}

int F_KICCER_check(){
  //ボール補足見てしきい値以下だったら1を返す
  int result;
  if(analogRead(BALL_CHECK_PINA) >= KICC_VAL){
    if(analogRead(BALL_CHECK_PINB) >= KICC_VAL){
      result = 1 ;
    }  
  }else{
    result= 0;
  }
  return result;
}
