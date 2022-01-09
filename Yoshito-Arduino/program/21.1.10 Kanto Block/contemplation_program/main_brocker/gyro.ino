int GYRO_receive = 0;

int gyro_attitude;
int cur_line_value;
int pre_line_value;
int gyro_digits;
unsigned long gyro_time = 0;

void F_GYRO_setup() {
  Serial2.begin(115200);
}

void F_GYRO_read() {
  while (Serial2.available() > 1) {
    int g = Serial2.read();
  }
  if (Serial2.available() > 0) {
    GYRO_receive = Serial2.read() * 2;
  }
}

int F_GYRO_get() {
  return GYRO_receive;
}

int F_gyro_tilt(int line, int gyro) {
  cur_line_value = line;
  if ( cur_line_value == 0 & 58 <= pre_line_value & pre_line_value < 113) {
    gyro_digits = 1;
  } else if (cur_line_value == 0 &  258 <= pre_line_value & pre_line_value < 303) {
    gyro_digits = 2;
  } else {
    gyro_digits = 0;
  }

  if (gyro_digits > 0) {
    gyro_time = F_time_goal(10000);
  }

  if (F_time_get() >= gyro_time & gyro_digits > 0) {
    gyro_digits = 0;
    gyro_time = 0;
  }

  pre_line_value = cur_line_value;
  return gyro_digits;
}

int F_attitude_control(int gyro, int tilt)
{
  if (tilt == 0 | IR_digits == 0) {
    if (0 <= gyro & gyro < 5 | 355 <= gyro & gyro <= 360)
    {
      gyro_attitude = 0;
    }
    else if (5 <= gyro & gyro < 180)
    {
      gyro_attitude = map(gyro, 5, 180, 40, 210);
    }
    else if (180 <= gyro & gyro < 355)
    {
      gyro_attitude = map(gyro, 180, 355, -210, -40);
    }

  } else if (tilt == 1) {
    if (320 <= gyro & gyro < 340)
    {
      gyro_attitude = 0;
    }
    else if (340 <= gyro & gyro <= 360)
    {
      gyro_attitude = map(gyro, 340, 360, 40, 60);
    }
    else if (0 < gyro & gyro < 150)
    {
      gyro_attitude = map(gyro, 0, 150, 60, 210);
    }
    else if (150 <= gyro & gyro <= 320)
    {
      gyro_attitude = map(gyro, 150, 320, -210, -40);
    } else {
      gyro_attitude = 0;
    }

  } else if (tilt == 2) {
    if (20 <= gyro & gyro < 40)
    {
      gyro_attitude = 0;
    }
    else if (40 <= gyro & gyro < 210)
    {
      gyro_attitude = map(gyro, 40, 210, 40, 210);
    }
    else if (210 <= gyro & gyro <= 360)
    {
      gyro_attitude = map(gyro, 220, 360, -210, -60);
    }
    else if (0 < gyro & gyro < 20)
    {
      gyro_attitude = map(gyro, 0, 20, -60, -40);
    } else {
      gyro_attitude = 0;
    }
  }

  return gyro_attitude;
}
