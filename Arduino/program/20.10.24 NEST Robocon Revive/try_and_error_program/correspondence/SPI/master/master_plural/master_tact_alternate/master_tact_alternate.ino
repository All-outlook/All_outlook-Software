#include <SPI.h>
int tact = 8;
int SS1 = 7;

void setup() {
  Serial.begin(9600);
  pinMode(tact, INPUT);
  SPI.begin();
  digitalWrite(SS, HIGH);
  digitalWrite(SS1, HIGH);
}

boolean switching = 0;
unsigned long currentMillis = 0; //curent→現在の　millis→ミリ秒(s→second)
unsigned long previousMil_switch = 0; //previous→前の

int knob = 54;
void loop() {
  int val = digitalRead(tact);
  Serial.println(val);

  currentMillis = millis(); //ミリ秒カウント
  //Serial.println(currentMillis);
  
 // if(currentMillis - previousMil_switch >= 10){ //チャタリング防止
  if(digitalRead(tact) == 0){
   while(digitalRead(tact) == 0){
   }
   switching = !switching;
   
   byte rxdata;

    knob = 54;
    digitalWrite(SS, LOW);
    SPI.transfer(knob);
    digitalWrite(SS, HIGH);
    digitalWrite(SS, LOW);
    rxdata = SPI.transfer(0);
    digitalWrite(SS, HIGH);

    Serial.print("tx:");
    Serial.print(knob);
    Serial.print("rx:");
    Serial.println(rxdata);
    
   } else {
    byte rxdata;

    knob = 44;
    digitalWrite(SS1, LOW);
    SPI.transfer(knob);
    digitalWrite(SS1, HIGH);
    digitalWrite(SS1, LOW);
    rxdata = SPI.transfer(0);
    digitalWrite(SS1, HIGH);

    Serial.print("tx:");
    Serial.print(knob);
    Serial.print("rx:");
    Serial.println(rxdata);
  }
  previousMil_switch = currentMillis;
}
//}
