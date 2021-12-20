#include <SPI.h>
#include <Adafruit_NeoPixel.h>
const int RESET_PIN[] = {2, 3, 4, 5, 6, 7, 8, 10};
const int KICKER_PIN = 11;
const int CAPTURE_LED = 12;
const int LED_PIN[] = {30, 31, 32, 33};
const int BUZZER = 35;
const int FLAME_LED = 40;
const int TOGGLE_PIN = 41;
const int SS_IR = 56;
const int SS_MT[] = {53, 54, 59, 58};
const int SS_LINE = 57;
const int SS_remainder = 55;
const int CAPTURE_PIN[] = {A7, A8};
int toggle_value;
int IR_value;
int IR_degree;
int line_value;
int line_degree;
int line_reaction;
int line_count;
const int line_time = 30;
int gyro_value;
int gyro_speed;
#define PI 3.1415
int MT_degree[] = {45, 135, 225, 315};
char MT_number[] = {'A', 'B', 'C', 'D'};
int MT_go_degree;
int MT_Il_degree;
int MT_Il_speed[4];
int MT_speed[4];
int MT_rotate[] = { -1, -1, 1, 1};
int pre_MT_rotate[] = { -1, -1, 1, 1};
int MT_rest[4];
int MT_rest_count[4];
int capture_threshold[] = {200, 200};
int flame_LED_count = 31;
Adafruit_NeoPixel pixels(flame_LED_count, FLAME_LED, NEO_GRB + NEO_KHZ800);
int capture_LED_count = 2;
//Adafruit_NeoPixel pixels(capture_LED_count, CAPTURE_LED, NEO_GRB + NEO_KHZ800);
int capture_read[2];
int capture_value[2];
int kicker_reaction;
int kicker_count;
unsigned int period_count = 0;


void setup() {
  Serial.begin(115200);
  Serial2.begin(9600);
  SPI.begin();
  pinMode(BUZZER, OUTPUT);
  pinMode(SS_IR, OUTPUT);
  pinMode(CAPTURE_PIN[0], INPUT);
  pinMode(CAPTURE_PIN[1], INPUT);
  for (int id = 0; id <= 7; id++) {
    pinMode(RESET_PIN[id], OUTPUT);
    digitalWrite(RESET_PIN[id], HIGH);
    digitalWrite(RESET_PIN[id], LOW);
    digitalWrite(RESET_PIN[id], HIGH);
  }
  pinMode(TOGGLE_PIN, INPUT);
  for (int id = 0; id <= 3; id++) {
    pinMode(LED_PIN[id], OUTPUT);
    pinMode(SS_MT[id], OUTPUT);
    digitalWrite(SS_MT[id], HIGH);
  }
  digitalWrite(SS_IR, HIGH);
  pinMode(SS_LINE, OUTPUT);
  digitalWrite(SS_LINE, HIGH);
  pixels.begin();
  pinMode(FLAME_LED, OUTPUT);
  for (int id = 0; id <= 30; id++) {
   // pixels.setPixelColor(id, pixels.Color(60, 60, 60));
    pixels.setPixelColor(id, pixels.Color(0, 128, 32));
    pixels.show();
  }
}

void loop() {
  if (period_count == 1000) {
    period_count = 0;
  }
  period_count++;
  /*Serial.print("count:");
    Serial.print(period_count);
    Serial.print(", ");*/

  /*Serial.print("count:");
    Serial.print(period_count);
    Serial.print(", ");*/

  toggle_value = digitalRead(TOGGLE_PIN);
  if (toggle_value == 0) {
    for (int id = 0; id <= 3; id++) {
      digitalWrite(LED_PIN[id], LOW);
    }
    
    if (450 <= period_count & period_count <= 500) {
      digitalWrite(LED_PIN[0], HIGH);
    } else {
      digitalWrite(LED_PIN[0], LOW);
    }

    if (900 <= period_count) {
      digitalWrite(LED_PIN[1], HIGH);
    } else {
      digitalWrite(LED_PIN[1], LOW);
    }

    String recive_value = Serial2.readStringUntil('&');
    gyro_value = recive_value.toInt();
    Serial.print('g');
    Serial.print(gyro_value);
    Serial.print(", ");

    gyro_speed = attitude(gyro_value);
    Serial.print('a');
    Serial.print(gyro_speed);
    Serial.print(", ");

    IR_value = SPI_IR_degree();
    Serial.print('i');
    Serial.print(IR_value);
    Serial.print(", ");

    IR_degree = wrap_around(IR_value);
    Serial.print('w');
    Serial.print(IR_degree);
    Serial.print(", ");

    line_value = SPI_line_degree() * 2;
    line_degree = line_step(line_value);
    Serial.print('l');
    Serial.print(line_degree);
    Serial.print(", ");


    if (line_degree != 0 & IR_degree != 0 | line_degree != 0 & IR_degree == 0) {
      MT_Il_degree = line_degree;
    } else if (line_degree == 0 & IR_degree != 0) {
      MT_Il_degree = IR_degree;
    } else if (line_degree == 0 & IR_degree == 0) {
      MT_Il_degree = 0;
    }
    Serial.print("m");
    Serial.print(MT_Il_degree);
    Serial.print(",");


    if (MT_Il_degree != 0 & gyro_speed <= -100 | MT_Il_degree != 0 & 100 <= gyro_speed) {
      for (int id = 0; id <= 3; id++) {
        MT_Il_speed[id] = MT_last_speed(MT_degree[id], MT_Il_degree);
      }
      for (int id = 0; id <= 3; id++) {
        MT_speed[id] = (MT_Il_speed[id] * 0.7) + (gyro_speed * 0.3);
      }
    } else if (MT_Il_degree != 0 & -100 < gyro_speed & gyro_speed < 100) {
      for (int id = 0; id <= 3; id += 1) {
        MT_Il_speed[id] = MT_last_speed(MT_degree[id], MT_Il_degree);
      }
      for (int id = 0; id <= 3; id++) {
        MT_speed[id] = MT_Il_speed[id];
      }
    } else if (MT_Il_degree == 0 & gyro_speed <= -100 | MT_Il_degree == 0 & 100 <= gyro_speed) {
      for (int id = 0; id <= 3; id++) {
        MT_speed[id] = gyro_speed;
      }
    } else if (MT_Il_degree == 0 & -100 < gyro_speed & gyro_speed < 100) {
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
        MT_rest_count[id] = goal_count(30);
      }

      if (period_count == MT_rest_count[id]) {
        MT_rest[id] = 0;
        MT_rest_count[id] = -1;
      }

      Serial.print(MT_number[id]);
      if (MT_rest[id] == 1) {
        SPI_MT_speed(id, 40, 0);
        Serial.print("brake");
      } else if (MT_speed[id] == 0) {
        SPI_MT_speed(id, 30, 0);
        Serial.print("stop");
      } else if (MT_rest[id] == 0) {
        Serial.print(MT_speed[id]);
        if (MT_speed[id] >= 100) {
          SPI_MT_speed(id, 10, MT_speed[id]);
        } else if ( MT_speed[id] <= -100) {
          MT_speed[id] = abs(MT_speed[id]);
          SPI_MT_speed(id, 20, MT_speed[id]);
        }
      } else {
        Serial.print(MT_speed[id]);
        if (MT_speed[id] >= 100) {
          SPI_MT_speed(id, 10, MT_speed[id]);
        } else if ( MT_speed[id] <= -100) {
          MT_speed[id] = abs(MT_speed[id]);
          SPI_MT_speed(id, 20, MT_speed[id]);
        }
      }
      Serial.print(",");
    }
    //kicker();
    Serial.println();
    recive_value = Serial2.readStringUntil('&'); //発散～！
    recive_value = Serial2.readStringUntil('&'); //発散～！

  } else {
    Serial.println("OFF");
    for (int id = 0; id <= 3; id++) {
      digitalWrite(LED_PIN[id], HIGH);
      SPI_MT_speed(id, 30, 0);
    }
  }
  for (int id = 0; id <= 3; id++) {
    pre_MT_rotate[id] = MT_rotate[id];
  }
}
