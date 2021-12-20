#include <SPI.h>

int Blue_LED = 9;

void setup() {
  SPCR |= bit(SPE); 
  pinMode(MISO, OUTPUT); 
  Serial.begin(9600);
  pinMode(Blue_LED, OUTPUT);
  SPI.attachInterrupt(); 
}

void loop() {}

byte rxdata;
ISR(SPI_STC_vect) {
  rxdata = SPDR; //konbからきた値をrxdataに入れる
  if (rxdata == 'A') {
    digitalWrite(Blue_LED, HIGH);
    SPDR = 'P'; //knobからきた値(P)を送り返す
    
  } else {
    digitalWrite(Blue_LED, LOW);
  }
}
