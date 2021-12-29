/**********************************************
  Arduino SPI(Master) com8
**********************************************/
#include <SPI.h>

int mySS[] = {56, 53, 55, 54, 57, 59, 58};
SPISettings mySPISettings = SPISettings(125000, MSBFIRST, SPI_MODE0);

void setup() {
  Serial.begin(9600);
  Serial.println("/-----START Arduino nano-----/");
  Serial.println("/---------SPI Master--------/");

  SPI.begin();

  for (int i = 0; i <= 6 ; i++) {
    pinMode(mySS[i], OUTPUT);
    digitalWrite(mySS[i], HIGH);
  }
}


int knob;
int SS_MT[] = {53, 54, 59, 58};

void loop() {
  zentai();
}




void ikko() {
  int mySS = 54;
  byte rxdata;


  int n = 5;
  for (int i = 0; i < 4; i++) {
    delayMicroseconds(n);
    knob = 40;
    digitalWrite(SS_MT[i], LOW);
    delayMicroseconds(n);
    SPI.transfer(knob);
    digitalWrite(SS_MT[i], HIGH);
    
    delayMicroseconds(n);
    
    digitalWrite(SS_MT[i], LOW);
    rxdata = SPI.transfer(0);
    digitalWrite(SS_MT[i], HIGH);


    delayMicroseconds(n);
    knob = 100;
    digitalWrite(SS_MT[i], LOW);
    SPI.transfer(knob);
    delayMicroseconds(n);
    digitalWrite(SS_MT[i], HIGH);
    
    delayMicroseconds(n);
    
    digitalWrite(SS_MT[i], LOW);
    rxdata = SPI.transfer(0);
    digitalWrite(SS_MT[i], HIGH);
  }
}


void zentai() {
  byte rxdata;
  knob = 10;
  for (int i = 0; i <= 6; i++) {
    digitalWrite(mySS[i], LOW);
    SPI.transfer(knob);
    digitalWrite(mySS[i], HIGH);
    //delay(10);
    digitalWrite(mySS[i], LOW);
    rxdata = SPI.transfer(0);
    digitalWrite(mySS[i], HIGH);

    //Serial.print(" id:");
    //Serial.print(i);
    Serial.print('a');
    Serial.print(rxdata);
  }
  Serial.println();
}
