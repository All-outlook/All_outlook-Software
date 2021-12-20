const int MT_FORWARD[] = {2, 4, 6, 8};  //MT ancestry
const int MT_REVERSAL[] = {3, 5, 7, 9}; //MT ancestry

char MT_number[] = {'A', 'B', 'C', 'D'};
int MT_speed[4];
int MT_rotate[4];
int pre_MT_rotate[4];
int MT_rest[4];
int MT_rest_count[4];

unsigned long period_count;
void setup() {
  Serial.begin(115200);
  for (int id = 0; id <= 3; id++) {
    pinMode(MT_FORWARD[id], OUTPUT);
    pinMode(MT_REVERSAL[id], OUTPUT);
  }

}

void loop() {
  for (int id = -255; id <= 255; id += 20) {
    for (int id = 0; id <= 3; id++) {
      if (MT_speed[id] > 0) {
        MT_rotate[id] = 1;
      } else if (MT_speed[id] == 0) {
        MT_rotate[id] = 0;
      } else if (MT_speed[id] < 0) {
        MT_rotate[id] = -1;
      }

      if (MT_rotate[id] != pre_MT_rotate[id]) {
        MT_rest[id] = 1;
        MT_rest_count[id] = goal_count(30);
      }

      if (period_count == MT_rest_count[id]) {
        MT_rest[id] = 0;
        MT_rest_count[id] = -1;
      }

      Serial.print(MT_number[id]);
      if (MT_rest[id] == 1) {
        F_MT_brake(id);
        Serial.print("brake");
      } else if (MT_speed[id] == 0) {
        F_MT_stop(id);
        Serial.print("stop");
      } else if (MT_rest[id] == 0) {
        F_motor_speed(id, MT_speed[id]);
        Serial.print(MT_speed[id]);
      } else {
        F_motor_speed(id, MT_speed[id]);
        Serial.print(MT_speed[id]);
      }
      Serial.print(",");
    }
    Serial.println();
    for (int id = 0; id <= 3; id++) {
      pre_MT_rotate[id] = MT_rotate[id];
    }
  }
}
