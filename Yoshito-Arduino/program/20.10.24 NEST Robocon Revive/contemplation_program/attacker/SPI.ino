int SPI_correspodence() {
  int SPI_transmission_value;
  int SPI_recive_value;

  SPI_transmission_value = 'A';
  digitalWrite(SS, LOW);
  SPI.transfer(SPI_transmission_value);
  digitalWrite(SS, HIGH);
  delayMicroseconds(100);

  digitalWrite(SS, LOW);
  SPI_recive_value = SPI.transfer(0);
  digitalWrite(SS, HIGH);
  return SPI_recive_value;
}
