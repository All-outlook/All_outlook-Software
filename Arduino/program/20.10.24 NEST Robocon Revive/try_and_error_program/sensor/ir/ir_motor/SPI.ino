int spi() {
  char knob = "A";
  char IR_degree;

  knob = 'A';
  digitalWrite(SS, LOW); //送信
  SPI.transfer(knob);
  digitalWrite(SS, HIGH);
  delayMicroseconds(100);

  digitalWrite(SS, LOW); //受信
  IR_degree = SPI.transfer(0);
  digitalWrite(SS, HIGH);

  IR_degree *= 2;
  return IR_degree;
  Serial.println(IR_degree);
}
