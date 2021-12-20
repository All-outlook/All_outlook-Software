#include <SPI.h>
#include <Adafruit_NeoPixel.h>
const int motor_right_pin[] = {2, 4, 6, 8};
const int motor_left_pin[] = {3, 5, 7, 9};
const int switch_LED_pin = 10;
const int start_switch = 11;
const int gyro_switch = 12;
const int capture_LED_pin = 14;
const int kicker_pin = 22;
const int red_LED_pin[] = {40, 41, 42, 43};
const int GW_LED_pin[] =  {44, 45, 46, 47};
const int line_pin[] = {A0, A1, A2, A3};
const int capture_pin[] = {A4, A5};

#define PI 3.141592653589793
int MT_degree[] = {45, 135, 225, 315};
int MT_speed[4];
int MT_ILspeed[4];
int MT_go_degree;
int gyro_value;
int gyro_degree_MT_speed;
int IR_value;
int IR_degree;
int line_threshold[] = {300, 500, 400, 400};
int line_value[4];
int line_degree;
int line_thou;
int line_degree_MT_speed;
int front = 15;
int behind = 90;
int right = 90;
int left = 90;
int line_count;
int line_reaction;

unsigned int period_count = 0;
unsigned long gauge = 0;
int gyro_switch_count = 0;
int gyro_reference;
int switch_count = 0;
int MT_direction[] = { -1, -1, 1, 1};
int pre_MT_direction[] = { -1, -1, 1, 1};
int MT_rest[4];
int MT_rest_goal[4];

int capture_threshold[] = {200, 200};
int LED_count = 2;
int capture_read[2];
int capture_value[2];
int kicker_count;
int kicker_reaction;
Adafruit_NeoPixel pixels(LED_count, capture_LED_pin, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(38400);
  SPI.begin();
  pinMode(SS, HIGH);
  for (int id = 0; id <= 3; id++) {
    pinMode(motor_right_pin[id], OUTPUT);
    pinMode(motor_left_pin[id], OUTPUT);
    pinMode(line_pin[id], INPUT);
    pinMode(red_LED_pin[id], OUTPUT);
    pinMode(GW_LED_pin[id], OUTPUT);
  }
  pixels.begin();
  for (int id = 0; id <= 1; id++) {
    pinMode(capture_pin[id], INPUT);
    pixels.setPixelColor(id, pixels.Color(128, 128, 128));
    //pixels.setPixelColor(id, pixels.Color(0, 128, 32));
    pixels.show();
  }
  pinMode(switch_LED_pin, OUTPUT);
  pinMode(start_switch, INPUT);
  pinMode(gyro_switch, INPUT);
  pinMode(kicker_pin, OUTPUT);
  gyro_configuration();
  digitalWrite(GW_LED_pin[3], HIGH);
  Serial.println("----------gyro_completion----------");
}

void loop() {
  if (gyro_switch_count == 0) {
    gauge = 0;
    while (!digitalRead(gyro_switch)) {
      gauge++;
    }
    if (gauge > 10000) {
      gyro_reference = gyro_loop();
    }
    digitalWrite(GW_LED_pin[2], HIGH);
    Serial.println("gyro_reset");
    gyro_switch_count = 1;
  }

  if (switch_count == 0) {
    gauge = 0;
    while (!digitalRead(start_switch)) {
      gauge++;
      gyro_loop();
    }
    if (gauge > 10000) {
    }
    digitalWrite(switch_LED_pin, HIGH);
    Serial.println("----------start----------");
    switch_count = 1;
  }

  if (period_count == 1000) {
    period_count = 0;
  }
  period_count++;
  Serial.print("count:");
  Serial.print(period_count);
  Serial.print(", ");

  if (450 <= period_count & period_count <= 500 | 900 <= period_count) {
    digitalWrite(GW_LED_pin[0], HIGH);
  } else {
    digitalWrite(GW_LED_pin[0], LOW);
  }

  gyro_value = gyro_loop();
  gyro_degree_MT_speed = attitude(gyro_value);

  IR_value = SPI_correspodence() * 2;
  if (IR_value == 400) {
    IR_value = -1;
  }
  Serial.print("IR:");
  Serial.print(IR_value);
  Serial.print(", ");
  //IR_degree = IR_value;
  IR_degree = wrap_around(IR_value);

  for (int id = 0; id <= 3; id++) {
    line_value[id] = line_loop(id);
  }
  line_thou = (line_value[0] * 1000) + (line_value[1] * 100) + (line_value[2] * 10) + (line_value[3] * 1);

  if (line_reaction == 0) {
    line_reaction = 1;

    if (line_thou == 1111) {
      line_degree = -1;
    } else if (line_thou == 1110) {
      line_degree = 270;
      line_count = goal_count(front);
    } else if (line_thou == 1101) {
      line_degree = 180;
      line_count = goal_count(front);
    } else if (line_thou == 1100) {
      line_degree = 225;
      line_count = goal_count(front);
    } else if (line_thou == 1011) {
      line_degree = 90;
      line_count = goal_count(front);
    } else if (line_thou == 1010) {
      line_degree = -1;
    } else if (line_thou == 1001) {
      line_degree = 135;
      line_count = goal_count(front);
    } else if (line_thou == 1000) {
      line_degree = 180;
      line_count = goal_count(front);
    } else if (line_thou == 111) {
      line_degree = 0;
      line_count = goal_count(front);
    } else if (line_thou == 110) {
      line_degree = 315;
      line_count = goal_count(front);
    } else if (line_thou == 101) {
      line_degree = -1;
    } else if (line_thou == 100) {
      line_degree = 270;
      line_count = goal_count(front);
    } else if (line_thou == 11) {
      line_degree = 45;
      line_count = goal_count(front);
    } else if (line_thou == 10) {
      line_degree = 0;
      line_count = goal_count(front);
    } else if (line_thou == 1) {
      line_degree = 90;
      line_count = goal_count(front);
    } else if (line_thou == 0) {
      line_degree = -1;
    }
  }  else if (line_reaction == 1) {}

  Serial.print("line_degree:");
  Serial.print(line_degree);
  Serial.print(", ");

  if (line_degree == -1) {
    line_reaction = 0;
  }

  if (period_count == line_count) {
    line_reaction = 0;
    line_degree = -1;
  }

  if (line_degree == -1) {
    MT_go_degree = IR_degree;

  } else if (line_degree >= 0) {
    MT_go_degree = line_degree;

  } else if (line_degree == -1 & IR_degree == -1) {
    MT_go_degree = -1;

    /*} else if (line_degree >= 0 & IR_degree >= 0) {
      //MT_go_degree = adjust_angle(add_angle(IR_degree, line_degree, 10));
      MT_go_degree = (IR_degree +  line_degree_MT_speed * 9) / 10;*/
  }

  Serial.print("MT_go_degree");
  Serial.print(MT_go_degree);
  Serial.print(", ");

  if (MT_go_degree == line_degree & MT_go_degree >= 0) {
    for (int id = 0; id <= 3; id += 1) {
      MT_ILspeed[id] = MT_last_speed(MT_degree[id], MT_go_degree);
    }
    for (int id = 0; id <= 3; id++) {
      MT_speed[id] = MT_ILspeed[id];
    }

  } else if (MT_go_degree == IR_degree & MT_go_degree >= 0) {
    for (int id = 0; id <= 3; id += 1) {
      MT_ILspeed[id] = MT_last_speed(MT_degree[id], MT_go_degree);
    }
    for (int id = 0; id <= 3; id++) {
      MT_speed[id] = (MT_ILspeed[id] * 0.7) + (gyro_degree_MT_speed * 0.3);
    }

  } else {
    for (int id = 0; id <= 3; id++) {
      MT_speed[id] = gyro_degree_MT_speed;
    }
  }

  for (int id = 0; id <= 3; id++) {
    if (MT_speed[id] > 0) {
      MT_direction[id] = 1;

    } else if (MT_speed[id] < 0) {
      MT_direction[id] = -1;

    } else if (MT_speed[id] == 0) {
      MT_direction[id] = 0;
    }

    if (MT_direction[id] == 0 | pre_MT_direction[id] == 0) {
    } else if (MT_direction[id] == pre_MT_direction[id]) {
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
    Serial.print("MT");
    Serial.print(id);
    Serial.print(":");
    if (MT_rest[id] == 1) {
      MT_stop(id);
      Serial.print("stop");
    } else if (MT_speed[id] == 0) {
      MT_stop(id);
      Serial.print("stop");
    } else if (MT_rest[id] == 0) {
      motor_speed(id, MT_speed[id]);
      Serial.print(MT_speed[id]);
    }
    Serial.print(", ");
  }

  for (int id = 0; id <= 3; id++) {
    pre_MT_direction[id] = MT_direction[id];
  }
  //kicker();
  Serial.println();
}
