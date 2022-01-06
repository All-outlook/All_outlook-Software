const int MT_RX[] = {42, 43, 44, 45};
const int MT_TX[] = {53, 54, 59, 58};

SoftwareSerialParity MT0_Serial(MT_RX[0], MT_TX[0]); // rx,tx
SoftwareSerialParity MT1_Serial(MT_RX[1], MT_TX[1]); // rx,tx
SoftwareSerialParity MT2_Serial(MT_RX[2], MT_TX[2]); // rx,tx
SoftwareSerialParity MT3_Serial(MT_RX[3], MT_TX[3]); // rx,tx

#define PI 3.1415
int MT_angle[] = {45, 135, 225, 315};

int F_MT_Il_speed(int id, int either_degree)
{
    int MT_speed;
    int power = 254;
    int theta = MT_angle[id] - either_degree;

    MT_speed = sin(theta * PI / 180) * power;
    return MT_speed;
}
