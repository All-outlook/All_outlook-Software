//goal_time(n), n = millis
const int START_SWITCH = 11; //else
const int GYRO_SWITCH = 12;  //else

int gyro_value;
int gyro_speed;
int IR_value;
int IR_degree;
int line_value;
int line_degree;
int pre_line_horizontal;
int pre_line_vertically;
int kicker_value;

int either_degree;
int either_speed[4];
char MT_number[] = {'A', 'B', 'C', 'D'};
int MT_speed[4];
int MT_rotate[4];
int pre_MT_rotate[4];
int MT_rest[4];
unsigned long MT_rest_time[4];
unsigned long MT_stop_time[4];
int gyro_switch_count;
int switch_count;
int gyro_reference;
unsigned long gauge;


//const int GW_LED[] =  {44, 45, 46, 47}; //else
//const int SWITCH_LED = 10;              //else
const int GW_LED[] =  {30, 31, 32, 33};   //else
const int SWITCH_LED = 34;                //else

void setup() {
  Serial.begin(115200);
  F_MT_setup();
  F_SPI_setup();
  F_line_setup();
  F_kicker_setup();
  pinMode(SWITCH_LED, OUTPUT);
  pinMode(START_SWITCH, INPUT);
  pinMode(GYRO_SWITCH, INPUT);
  for (int id = 0; id <= 3; id++) {
    pinMode(GW_LED[id], OUTPUT);
  }

  F_gyro_configuration();
  Serial.println("I set the gyro sensor.");
  digitalWrite(GW_LED[3], HIGH);
}

void loop() {
  if (gyro_switch_count == 0) {
    gauge = 0;
    while (!digitalRead(GYRO_SWITCH)) {
      gauge++;
    }
    if (gauge > 1000) {
      gyro_reference = F_gyro_loop();
    }
    digitalWrite(GW_LED[2], HIGH);
    Serial.println("You pushed the gyro switch, right?");
    gyro_switch_count = 1;
  }

  if (switch_count == 0) {
    gauge = 0;
    while (!digitalRead(START_SWITCH)) {
      gauge++;
      F_gyro_loop();
    }
    if (gauge > 10000) {
    }
    digitalWrite(SWITCH_LED, HIGH);
    Serial.println('s');
    switch_count = 1;
  }

  F_time_read();
  /*Serial.print('t');
  Serial.print(F_time_get());
  Serial.print(",");*/

  gyro_value = F_gyro_loop();
  Serial.print('g');
  Serial.print(gyro_value);
  Serial.print(",");
  gyro_speed = F_attitude(gyro_value);
  Serial.print('a');
  Serial.print(gyro_speed);
  Serial.print(",");

  IR_value = F_SPI_correspodence();
  Serial.print('i');
  Serial.print(IR_value);
  Serial.print(",");
  IR_degree = F_wrap_around(IR_value);
  Serial.print('w');
  Serial.print(IR_degree);
  Serial.print(",");

  line_value = F_line_read();
  Serial.print('l');
  Serial.print(line_value);
  Serial.print(",");
  line_degree = F_line_step(line_value);
  Serial.print('a');
  Serial.print(line_degree);
  Serial.print(",");


  if (line_value == 1000) {
    if (IR_value == 20) {
      either_degree = line_degree;
    } else if (IR_value == 0 | IR_value == 15) {
      either_degree = 0;
    } else if (1 <= IR_value & IR_value <= 3) {
      either_degree = 90;
    } else if (4 <= IR_value & IR_value <= 11) {
      either_degree = IR_degree;
    } else if (12 <= IR_value & IR_value <= 14) {
      either_degree = 270;
    }
    pre_line_vertically = line_degree;

  } else if (line_value == 100) {
    if (IR_value == 20) {
      either_degree = line_degree;
    } else if (0 <= IR_value & IR_value <= 2) {
      either_degree = 360;
    } else if (3 <= IR_value & IR_value <= 4) {
      either_degree = 0;
    } else if (5 <= IR_value & IR_value <= 7) {
      either_degree = 180;
    } else if (8 <= IR_value & IR_value <= 15) {
      either_degree = IR_degree;
    }
    pre_line_horizontal = line_degree;

  } else if (line_value == 10) {
    if (IR_value == 20) {
      either_degree = line_degree;
    } else if (12 <= IR_value & IR_value <= 15 | 0 <= IR_value & IR_value <= 3) {
      either_degree = IR_degree;
    } else if (4 <= IR_value & IR_value <= 6) {
      either_degree = 90;
    } else if (7 <= IR_value & IR_value <= 8) {
      either_degree = 0;
    } else if (9 <= IR_value & IR_value <= 11) {
      either_degree = 270;
    }
    pre_line_vertically = line_degree;

  } else if (line_value == 1) {
    if (IR_value == 20) {
      either_degree = line_degree;
    } else if (0 <= IR_value & IR_value <= 7) {
      either_degree = IR_degree;
    } else if (8 <= IR_value & IR_value <= 10) {
      either_degree = 180;
    } else if (11 <= IR_value & IR_value <= 12) {
      either_degree = 0;
    } else if (13 <= IR_value & IR_value <= 15) {
      either_degree = 360;
    }
    pre_line_horizontal = line_degree;


  } else if (line_value == 1010) {
    either_degree = pre_line_horizontal;

  } else if (line_value == 101) {
    either_degree = pre_line_vertically;

  } else {
    if (line_degree != 0 & IR_degree != 0 | line_degree != 0 & IR_degree == 0) {
      either_degree = line_degree;
    } else if (line_degree == 0 & IR_degree != 0) {
      either_degree = IR_degree;
    } else if (line_degree == 0 & IR_degree == 0) {
      either_degree = 0;
    }
  }
  Serial.print("e");
  Serial.print(either_degree);
  Serial.print(",");

  if (either_degree != 0 & gyro_speed <= -100 | either_degree != 0 & 100 <= gyro_speed) {
    for (int id = 0; id <= 3; id++) {
      either_speed[id] = F_MT_Il_speed(id, either_degree);
    }
    for (int id = 0; id <= 3; id++) {
      MT_speed[id] = (either_speed[id] * 0.7) + (gyro_speed * 0.3);
    }

  } else if (either_degree != 0 & -100 < gyro_speed & gyro_speed < 100) {
    for (int id = 0; id <= 3; id++) {
      either_speed[id] = F_MT_Il_speed(id, either_degree);
    }
    for (int id = 0; id <= 3; id++) {
      MT_speed[id] = either_speed[id];
    }

  } else if (either_degree == 0 & gyro_speed <= -100 | either_degree == 0 & 100 <= gyro_speed) {
    for (int id = 0; id <= 3; id++) {
      MT_speed[id] = gyro_speed;
    }

  } else if (either_degree == 0 & -100 < gyro_speed & gyro_speed < 100) {
    for (int id = 0; id <= 3; id++) {
      MT_speed[id] = 0;
    }
  }

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
      MT_rest_time[id] = F_time_goal(70);
    }

    if (F_time_get() >= MT_rest_time[id] & MT_rest[id] == 1) {
      MT_rest_time[id] = 0;
      MT_rest[id] = 2;
      MT_stop_time[id] = F_time_goal(30);
    }
    
    if (F_time_get() >= MT_stop_time[id] & MT_rest[id] == 2) {
      MT_rest[id] = 0;
      MT_stop_time[id] = 0;
    }

    if (1 <= MT_speed[id] & MT_speed[id] <= 100) {
      MT_speed[id] = 100;
    } else if (-100 <= MT_speed[id] && MT_speed[id] <= -1) {
      MT_speed[id] = -100;
    }
    
    Serial.print(MT_number[id]);
    if (MT_rest[id] == 0) {
      F_motor_speed(id, MT_speed[id]);
      Serial.print(MT_speed[id]);
    } else if (MT_rest[id] == 1) {
      F_MT_brake(id);
      Serial.print("brake");
    } else if (MT_rest[id] == 2) {
      F_MT_stop(id);
      Serial.print("stop");
    } else if (MT_speed[id] == 0) {
      F_MT_stop(id);
      Serial.print("stop");
    } else {
      F_motor_speed(id, MT_speed[id]);
      Serial.print(MT_speed[id]);
    }
    Serial.print(",");
  }

  /*kicker_value = F_kicker();
    Serial.print('k');
    Serial.print(kicker_value);
    Serial.print(",");*/

  Serial.println();
  for (int id = 0; id <= 3; id++) {
    pre_MT_rotate[id] = MT_rotate[id];
  }
}
