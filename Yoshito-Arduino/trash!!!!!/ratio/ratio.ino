#define PI 3.14
const int MT_angle[] = {45, 135, 225, 315};
int MT_speed[4];
int either_degree = 0;
const float power = 254.0;
int theta;
int more;
float ratio;
int id;


void setup() {
  Serial.begin(115200);
}

void loop() {
  for (id = 0; id <= 3; id++) {
    theta = MT_angle[id] - either_degree;
    MT_speed[id] = sin(theta * PI / 180) * power;
  }
  //↑ここまでで一つの関数　returnで一つずつ

  more = 0;
  for (id = 0; id <= 3; id++) {
    more = max(more, abs(MT_speed[id]));
  }
  ratio = power / more;
//↑ここまでで一つの関数 returnで

  for (id = 0; id <= 3; id++) {
    MT_speed[id] *= ratio;

    if (MT_speed[id] > 254) {
      MT_speed[id] = 254;
    } else if (MT_speed[id] < -254) {
      MT_speed[id] = -254;
    } else if (-20 < MT_speed[id] & MT_speed < 20) {
      MT_speed[id] = 0;
    } else if (20 <= MT_speed[id] & MT_speed[id] < 40) {
      MT_speed[id] = 40;
    } else if (-40 <= MT_speed[id] & MT_speed[id] < -20) {
      MT_speed[id] = -40;
    }
  }
  //↑ここまでで一つの関数　returnで
  Serial.println();
}
