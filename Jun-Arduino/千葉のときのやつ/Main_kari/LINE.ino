int SPI_line_degree() {
  int line_transmission;
  int line_recive;

  line_transmission = 'L';
  digitalWrite(SS_LINE, LOW);
  SPI.transfer(line_transmission);
  digitalWrite(SS_LINE, HIGH);

  digitalWrite(SS_LINE, LOW);
  line_recive = SPI.transfer(0);
  digitalWrite(SS_LINE, HIGH);

  return line_recive;
}
