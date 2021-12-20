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
