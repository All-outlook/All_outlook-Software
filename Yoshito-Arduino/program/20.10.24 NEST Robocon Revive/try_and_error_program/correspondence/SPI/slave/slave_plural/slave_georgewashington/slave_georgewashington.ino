#include <SPI.h>

byte rxdata;

int const Red_LED = 9;

void setup() {
  SPCR |= bit(SPE); //
  pinMode(MISO, OUTPUT); //
  pinMode(Red_LED, OUTPUT);
  SPI.attachInterrupt(); //
}

void loop() {
}

ISR(SPI_STC_vect) {
  rxdata = SPDR;
  if (rxdata == 'B') {
    digitalWrite(Red_LED, HIGH);
    SPDR = 'G';
  
  } else {
    digitalWrite(Red_LED, LOW);
  }
}
