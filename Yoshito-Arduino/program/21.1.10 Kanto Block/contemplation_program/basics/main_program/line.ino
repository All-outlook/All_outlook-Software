const int LINE_RX = 68;
const int LINE_TX = 49;
SoftwareSerialParity line_Serial(LINE_RX, LINE_TX);  // rx,tx

int Line_serial;
int line_step;

int F_line_serial()
{
Srial_error:
  while (line_serial.available() > 0) {
    int g = line_serial.read();
  }
  if (line_Serial.available()) {
    Line_serial = line_Serial.read();
  }

  if (Line_serial > 50) {
    goto Serial_error;
  }
  return Line_serial;
}

int F_line_avoid(int line)
{
  if (0 <= line < line <= 32)
  {
    line_step = line * 11.25;
  }
  else
  {
    line_step = 0;
  }
  return line_step;
}
