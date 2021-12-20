#include <SPI.h>
int tact = 8;
int SS1 = 7;

void setup() {
  Serial.begin(9600);
  pinMode(tact, INPUT);
  SPI.begin();
 // SPI.setBitOrder(MSBFIRST);       //L(least→最下位）SBFIRST / M(most→最上位）SBFIRST
 // SPI.setClockDivider(SPI_CLOCK_DIV128);    //取り敢えずは最遅で設定するよ
 // SPI.setDataMode(SPI_MODE0);    //アイドル（休暇）時SCKはLow 立ち上がりでラッチ
  digitalWrite(SS, HIGH);
  digitalWrite(SS1, HIGH);
}


void loop() {
  int val = digitalRead(tact);
  //Serial.println(val);

 char knob = "A";
 char rxdata;
  
// if (val == 0) {

    knob = 'A';
    digitalWrite(SS, LOW); //送信
    SPI.transfer(knob);
    digitalWrite(SS, HIGH);
    delayMicroseconds(100);
    
    digitalWrite(SS, LOW); //受信
    rxdata = SPI.transfer(0);
    digitalWrite(SS, HIGH);
    
 /* } else {

    knob = 'B';
    digitalWrite(SS1, LOW);
    SPI.transfer(knob);
    digitalWrite(SS1, HIGH);
    delayMicroseconds(100);
    
    digitalWrite(SS1, LOW);
    rxdata = SPI.transfer(0);
    digitalWrite(SS1, HIGH);
  }*/
    Serial.print("tx:");
    Serial.print(knob);
    Serial.print("rx:");
    Serial.println(rxdata);
}
