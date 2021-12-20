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

void SPI_rotate_speed(int id, int rotate, int my_speed) {
  int IR_recive;
  digitalWrite(SS_PIN[id], LOW);
  SPI.transfer(rotate);
  digitalWrite(SS_PIN[id], HIGH);

  digitalWrite(SS_PIN[id], LOW);
  IR_recive = SPI.transfer(0);
  digitalWrite(SS_PIN[id], HIGH);

  digitalWrite(SS_PIN[id], LOW);
  SPI.transfer(my_speed);
  digitalWrite(SS_PIN[id], HIGH);


  digitalWrite(SS_PIN[id], LOW);
  IR_recive = SPI.transfer(0);
  digitalWrite(SS_PIN[id], HIGH);
  Serial.print(id);
  Serial.print(":");
  Serial.println(IR_recive);
}
