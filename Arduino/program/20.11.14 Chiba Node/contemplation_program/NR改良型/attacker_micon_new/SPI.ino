int SPI_correspodence() {
  int SPI_transmission_value;
  int SPI_receive_value;

  SPI_transmission_value = 'I';
  digitalWrite(SS, LOW);
  SPI.transfer(SPI_transmission_value);
  digitalWrite(SS, HIGH);

  digitalWrite(SS, LOW);
  SPI_receive_value = SPI.transfer(0);
  digitalWrite(SS, HIGH);
  return SPI_receive_value;
}
