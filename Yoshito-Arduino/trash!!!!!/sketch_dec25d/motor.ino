#define PI 3.1415
int MT_angle[] = {45, 135, 225, 315};

int F_MT_Il_speed(int id, int either_degree)
{
    int MT_speed;
    int power = 200;
    int theta = MT_angle[id] - either_degree;

    MT_speed = sin(theta * PI / 180) * power;
    return MT_speed;
}
