int SPI_IR_degree() {
  byte IR_transmission;
  int IR_recive;

  IR_transmission = 'I';
  digitalWrite(SS_IR, LOW);
  SPI.transfer(IR_transmission);
  digitalWrite(SS_IR, HIGH);

  digitalWrite(SS_IR, LOW);
  IR_recive = SPI.transfer(0);
  digitalWrite(SS_IR, HIGH);

  return IR_recive;
}

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

void SPI_MT_speed(int id, int rotation, int myspeed) {
  int MT_transmission;
  int MT_recive;

  MT_transmission = rotation;
  digitalWrite(SS_MT[id], LOW);
  SPI.transfer(MT_transmission);
  digitalWrite(SS_MT[id], HIGH);

  digitalWrite(SS_MT[id], LOW);
  MT_recive = SPI.transfer(0);
  digitalWrite(SS_MT[id], HIGH);

  MT_transmission = myspeed;
  digitalWrite(SS_MT[id], LOW);
  SPI.transfer(MT_transmission);
  digitalWrite(SS_MT[id], HIGH);
  delayMicroseconds(100);

  digitalWrite(SS_MT[id], LOW);
  MT_recive = SPI.transfer(0);
  digitalWrite(SS_MT[id], HIGH);

  /*Serial.print('m');
  Serial.print(MT_recive);
  Serial.print(", ");*/
}
