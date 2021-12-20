#include <SoftwareSerialParity.h>
const int MT_RX[] = {42, 43, 44, 45};
const int MT_TX[] = {53, 54, 59, 58};
const int IR_RX = 66;
const int LINE_RX = 68;
const int LINE_TX = 49;
SoftwareSerialParity MT0_Serial(MT_RX[0], MT_TX[0]); // rx,tx
SoftwareSerialParity MT1_Serial(MT_RX[0], MT_TX[1]); // rx,tx
SoftwareSerialParity MT2_Serial(MT_RX[0], MT_TX[2]); // rx,tx
SoftwareSerialParity MT3_Serial(MT_RX[0], MT_TX[3]); // rx,tx
SoftwareSerialParity line_Serial(LINE_RX, LINE_TX);  // rx,tx
#define SERIAL_8E1 0x26

void F_serial_setup()
{
    Serial.begin(115200); // micon to PC
    Serial2.begin(38400, SERIAL_8E1); // gyro
    Serial3.begin(38400); //IR
    line_Serial.begin(38400, ODD);
    MT0_Serial.begin(38400, ODD);
    MT1_Serial.begin(38400, ODD);
    MT2_Serial.begin(38400, ODD);
    MT3_Serial.begin(38400, ODD);
    for (id = 0; id <= 3; id++)
    {
        pinMode(MT_RX[id], INPUT);
        pinMode(MT_TX[id], OUTPUT);
    }
    pinMode(IR_RX, INPUT);
    pinMode(LINE_RX, INPUT);
}
