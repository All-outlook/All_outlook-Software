/**
  Arduino nano SPI(Master)
**/
#include <SPI.h>
int MT_SS[] = {53, 54, 59, 58};


//SPISettings mySPISettings = SPISettings(125000, MSBFIRST, SPI_MODE0);
SPISettings mySPISettings = SPISettings(15625, MSBFIRST, SPI_MODE0);

void setup() {
  Serial.begin(9600);
  Serial.println("/-----START Main-----/");
  Serial.println("/---------SPI Master--------/");

  SPI.begin();
  SPI.beginTransaction(mySPISettings);

  for (int i = 0; i <= 3; i++) {
    pinMode(MT_SS[i], OUTPUT);
    digitalWrite(MT_SS[i], HIGH);
  }

  pinMode(SCK,OUTPUT);
  pinMode(MOSI,OUTPUT);
  pinMode(MISO,INPUT);
}

int knob = 10;
void loop() {
  for (int n = 0; n <= 1200; n++) {
    ALL_SPI(10);
    ALL_SPI(150);
  }

  for (int n = 0; n <= 120; n++) {
    ALL_SPI(40);
  }

  for (int n = 0; n <= 1200; n++) {
    ALL_SPI(20);
    ALL_SPI(150);
  }

  for (int n = 0; n <= 120; n++) {
    ALL_SPI(40);
  }

  //  Serial.print("tx:");
  //  Serial.print(knob);
  //  Serial.print(" rx:");
  //Serial.println(rxdata);

}


void ALL_SPI(int value) {
  for (int i = 0; i <= 3; i++) {
    MT_SPI(i, value);
  }

}
byte MT_SPI(int id, int knob) { //knob == 送信値
  byte rxdata;
  digitalWrite(MT_SS[id], LOW);
  SPI.transfer(knob);
  digitalWrite(MT_SS[id], HIGH);

  delayMicroseconds(5);

  digitalWrite(MT_SS[id], LOW);
  rxdata = SPI.transfer(0);
  digitalWrite(MT_SS[id], HIGH);

  return rxdata;
}
