
void F_serial_setup()
{
  Serial.begin(38400);            // micon to PC
  Serial2.begin(38400, SERIAL_8E1); // gyro
  Serial3.begin(38400);             // IR
  line_Serial.begin(9600, ODD);
  MT0_Serial.begin(38400, ODD);
  MT1_Serial.begin(38400, ODD);
  MT2_Serial.begin(38400, ODD);
  MT3_Serial.begin(38400, ODD);
  pinMode(IR_RX, INPUT);
  pinMode(LINE_RX, INPUT);
  for (id = 0; id <= 3; id++)
  {
    pinMode(MT_RX[id], INPUT);
    pinMode(MT_TX[id], OUTPUT);
  }
}

void F_speed_send(int id, int mySpeed)
{
  if (mySpeed > 100)
  {
    F_MT_UART(id, 10);
    F_MT_UART(id, mySpeed);
  }
  else if (mySpeed < -100)
  {
    F_MT_UART(id, 20);
    F_MT_UART(id, abs(mySpeed));
  }
  else if (mySpeed == 30)
  {
    F_MT_UART(id, 30);
  }
  else if (mySpeed == 40)
  {
    F_MT_UART(id, 40);
  }
}


void F_MT_UART(int id, int knob)
{
  if (id == 0)
  {
    MT0_Serial.write(knob);
    MT0_Serial.flush();
  }
  else if (id == 1)
  {
    MT1_Serial.write(knob);
    MT1_Serial.flush();
  }
  else if (id == 2)
  {
    MT2_Serial.write(knob);
    MT2_Serial.flush();
  }
  else if (id == 3)
  {
    MT3_Serial.write(knob);
    MT3_Serial.flush();
  }
  else
  {
  }
}
