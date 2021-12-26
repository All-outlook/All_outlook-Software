const int MT_RX[] = {42, 43, 44, 45};
const int MT_TX[] = {53, 54, 59, 58};
const int IR_RX = 66;
const int LINE_RX = 68;
const int LINE_TX = 49;
SoftwareSerialParity MT0_Serial(MT_RX[0], MT_TX[0]); // rx,tx
SoftwareSerialParity MT1_Serial(MT_RX[1], MT_TX[1]); // rx,tx
SoftwareSerialParity MT2_Serial(MT_RX[2], MT_TX[2]); // rx,tx
SoftwareSerialParity MT3_Serial(MT_RX[3], MT_TX[3]); // rx,tx
SoftwareSerialParity line_Serial(LINE_RX, LINE_TX);  // rx,tx
#define SERIAL_8E1 0x26

void F_serial_setup()
{
  Serial.begin(115200);            // micon to PC
  Serial2.begin(9600, SERIAL_8E1); // gyro
  Serial3.begin(9600);             // IR
  line_Serial.begin(9600, ODD);
  MT0_Serial.begin(9600, ODD);
  MT1_Serial.begin(9600, ODD);
  MT2_Serial.begin(9600, ODD);
  MT3_Serial.begin(9600, ODD);
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
