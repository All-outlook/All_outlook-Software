#include <SPI.h>

byte rxdata;

void setup() {
  SPCR |= bit(SPE); //
  pinMode(MISO, OUTPUT); //
  SPI.attachInterrupt(); //
}

void loop() {
}

ISR(SPI_STC_vect) {
  rxdata = SPDR;
  SPDR = 2;
}
