const int motor_right[] = {2, 4, 6, 8};
const int motor_left[] = {3, 5, 7, 9};

int gyro_LED = 40;
int GW_LED[] = {45, 46, 47, 48};

float gyro_value;
int MT_speed;

unsigned int period_count = 0;
int MT_direction[] = { -1, -1, 1, 1};
int pre_MT_direction[] = { -1, -1, 1, 1};
int MT_rest[] = {0, 0, 0, 0};
int MT_rest_goal[] = {0, 0, 0, 0};

void setup() {
  Serial.begin(38400);
  pinMode(gyro_LED, OUTPUT);
  for (int i = 0; i <= 3; i++) {
    pinMode(GW_LED[i], OUTPUT);
    pinMode(motor_right[i], OUTPUT);
    pinMode(motor_left[i], OUTPUT);
  }

  gyro_configuration();
  digitalWrite(gyro_LED, HIGH);
}

void loop() {
  gyro_value = gyro_loop();

  Serial.print("gyro_value:"); Serial.print(gyro_value); Serial.print(",  ");

    MT_speed = turning(gyro_value); // 回転向き決定

  if (period_count == 1000) {
    period_count = 0;
  }
  period_count += 1;

  if (450 <= period_count & period_count <= 500 | 900 <= period_count) {
    digitalWrite(GW_LED[0], HIGH);
  } else {
    digitalWrite(GW_LED[0], LOW);
  }
  
  for (int id = 0; id <= 3; id++) {
    if (MT_speed > 0) {
      MT_direction[id] = 1;
    } else if (MT_speed < 0) {
      MT_direction[id] = -1;
    } else if (MT_speed == 0) {
      MT_direction[id] = 0;
    }

    if (MT_direction[id] == 0) { //何もしない //0~10, 350~160の範囲
      //なんでこの空白があるのか
    } else if (pre_MT_direction[id] == 0) { //一周期前が0~10, 350~160の範囲

    } else if (MT_direction[id] != pre_MT_direction[id]) { //一周期前と違ったら、
      MT_rest[id] = 1; //MT_rest[id]を1とする
      MT_rest_goal[id] = goal_count(20); //MT_rest_goal[id]にcount20を入れる
    }

    if (period_count == MT_rest_goal[id]) { //period_count と MT_rest_goal[id]が同じだったら、
      MT_rest[id] = 0; //MT_rest[id]を0とする
      MT_rest_goal[id] = -1; //MT_rest_goal[id]を-1とする
    }
  }

  for (int id = 0; id <= 3; id++) { //出力
    Serial.print(id);
    Serial.print(":");
    if (MT_rest[id] == 1) {
      MT_brake(id);
      Serial.print("brake");
      
    } else if (MT_rest[id] == 0) {
      motor_speed(id, MT_speed);
      Serial.print(MT_speed);
    }
    Serial.print("  ");
  }
  Serial.println();

  for (int id = 0; id <= 3; id++) {
    pre_MT_direction[id] = MT_direction[id];
  }
}
