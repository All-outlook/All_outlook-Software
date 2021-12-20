const int motor_right[] = {2, 4, 6, 8};
const int motor_left[] = {3, 5, 7, 9};

const int line_pin[] = {A0, A1, A2, A3};
const int red_led[] = {40, 41, 42, 43};
int MT_speed[4];

#define PI 3.141592653589793
int MT_degree[] = {45, 135, 225, 315};
int MT_degree_speed[4];
int go_degree;

void setup() {
  Serial.begin(38400);
  for (int i = 0; i <= 3; i++) {
    pinMode(line_pin[i], INPUT);
    pinMode(red_led[i], OUTPUT);
    pinMode(motor_right[i], OUTPUT);
    pinMode(motor_left[i], OUTPUT);
  }
}

void loop() {
  go_degree = 0;

  for (int id = 0; id <= 3; id += 1) {
    MT_degree_speed[id] = MT_last_speed(MT_degree[id], go_degree);
  }

  for (int id = 0; id <= 3; id += 1) {
    MT_speed[id] = MT_degree_speed[id];
    motor_speed(id, MT_speed[id]);
  }
}
