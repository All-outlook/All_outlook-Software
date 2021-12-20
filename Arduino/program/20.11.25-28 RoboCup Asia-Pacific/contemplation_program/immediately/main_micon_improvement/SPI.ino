#include <SPI.h>
int mySS = 53;
void F_SPI_setup(){
  SPI.begin();
  pinMode(mySS, OUTPUT);
  digitalWrite(mySS, HIGH);
}

int F_SPI_correspodence() {
  int SPI_transmimySSion_value;
  int SPI_receive_value;

  SPI_transmimySSion_value = 'I';
  digitalWrite(mySS, LOW);
  SPI.transfer(SPI_transmimySSion_value);
  digitalWrite(mySS, HIGH);

  digitalWrite(mySS, LOW);
  SPI_receive_value = SPI.transfer(0);
  digitalWrite(mySS, HIGH);
  return SPI_receive_value;
}
