int GYRO_receive = 0;

int gyro_attitude;
int cur_line_value;
int pre_line_value;
int gyro_number;
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
