#include <SPI.h>
int LED = 9;
volatile byte receiveValue;

void setup() {
  pinMode(LED,OUTPUT);
  SPCR |= bit(SPE);
  pinMode(MISO,OUTPUT);
  SPI.attachInterrupt();
}

void loop() {
  digitalWrite(LED, receiveValue);
  
}

ISR(SPI_STC_vect){
  receiveValue = SPDR;
}
