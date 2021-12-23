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

int wrap_around(int IR) {
  const int C_IR_length = 16.25; //距離が500時、16.25°。距離がxの時、arcsin(140 / x)°
  int IR_wrap_degree;
  if (IR == 0){
    IR_wrap_degree = 360;
  } else if(1 <= IR & IR <= 8){
    IR_wrap_degree = (IR * 22.5) + C_IR_length;
  }else if(9 <= IR & IR <= 15){
    IR_wrap_degree = (IR * 22.5) - C_IR_length;
  } else if(IR == 20 | IR == 73 | IR == 255){ //error_value
    IR_wrap_degree = 0;
  }
 
  return IR_wrap_degree;
}
