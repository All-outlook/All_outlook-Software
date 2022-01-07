#define PI 3.14
const int MT_angle[] = {45, 135, 225, 315};
int either_speed;
int either_degree = 0;
const float power = 254.0;
int theta;
int more;
float ratio;
int id;

void setup() {
}

void loop() {
  int F_MT_Il_speed(int id, int either) {
    theta = MT_angle[id] - either;
    either_speed = sin(theta * PI / 180) * power;
    return MT_speed;
  }

    more = 0;
  for (id = 0; id <= 3; id++) {
    more = max(more, abs(MT_value));
  }
  ratio = power / more;

  int F_max_speed(int ratio, int MT_value){
      MT_value *= ratio;

    if (MT_value > 254) {
      MT_value = 254;
    } else if (MT_value < -254) {
      MT_value = -254;
    } else if (-20 < MT_value & MT_speed < 20) {
      MT_value = 0;
    } else if (20 <= MT_value & MT_value < 40) {
      MT_value = 40;
    } else if (-40 <= MT_value & MT_value < -20) {
      MT_value = -40;
    }
    return MT_value;
  }
}
