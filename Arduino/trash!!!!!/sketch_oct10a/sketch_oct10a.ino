int MT_speed[4];
int MT_direction[4];
int pre_direction[4];
void setup() {
  // put your setup code here, to run once:

}

void loop() {

  for (int id = 0; id <= 3; id++) {
    if (MT_speed[id] > 0) {
      MT_direction[id] = 1;

    } else if (MT_speed[id] < 0) {
      MT_direction[id] = -1;

    } else if (MT_speed[id] == 0) {
      MT_direction[id] = 0;
    }

    if (MT_direction[id] == 0 | pre_MT_direction[id] == 0) {
      Serial.println("0");
    } else if (MT_direction[id] == pre_MT_direction[id]) {
      Serial.println("onaji");
    } else if (MT_direction[id] != pre_MT_direction[id]) { //一周期前と違ったら、
      Serial.println("tigau");
    }
  }
    for (int id = 0; id <= 3; id++) {
    pre_MT_direction[id] = MT_direction[id];
  }
}
