const int LINE_RX = 68;
const int LINE_TX = 49;
SoftwareSerialParity line_Serial(LINE_RX, LINE_TX);  // rx,tx

int LINESerial;
int line_step;

int F_line_serial()
{
  if (line_Serial.available() > 0) {
    LINESerial = line_Serial.read() * 2;
  }
  if(LINESerial == 0 | LINESerial > 360){
    LINESerial = 0;
  }
  return LINESerial;
}

//int F_IR_serial()
//{
//  if(Serial3.available() > 0){
//  IR_serial = Serial3.read() * 2;
//  }
//if(IR_serial == 0 | IR_serial == -2){
//  IR_serial = 0;
//}
//  return IR_serial;
//}

int F_line_avoid(int line)
{
  line_step = line;
  return line_step;
}
