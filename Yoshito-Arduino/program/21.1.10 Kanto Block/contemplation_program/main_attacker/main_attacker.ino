#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>
#include <Adafruit_NeoPixel.h>

// 1 second = 1,000 millis = 1,000,000 micros
// goal_time(n), n = millis
int id;
int gyro_degree;
int gyro_speed;
int IR_degree;
int IR_value;
int line_digits;
int line_degree;
int either_degree;
int either_speed[4];
int more;
float ratio;
const float power = 254.0;
char MT_number[] = {'A', 'B', 'C', 'D'};
int MT_speed[4];

void setup()
{
  F_switch_setup();
  F_LED_setuo();
  F_IR_setup();
  F_GYRO_setup();
  F_LINE_setup();
  F_serial_setup();
  F_flame_setup();
  F_kicker_setup();
  F_reset_setup();
  F_buzzer_setup();
}

void loop()
{
  F_time_read();
  F_GYRO_read();
  F_IR_read();
  F_LINE_read();

  if (F_switch_value() == 0)
  {
    F_LED_turnon() ;

    gyro_degree = F_GYRO_get();
    Serial.print('g');
    Serial.print(gyro_degree);
    Serial.print(",");
    gyro_speed = F_attitude_control(gyro_degree);
    Serial.print('a');
    Serial.print(gyro_speed);
    Serial.print(",");

    IR_value = F_IR_get();
    Serial.print('i');
    Serial.print(IR_value);
    Serial.print(",");
    IR_degree = F_wrap_degree(IR_value);
    Serial.print('w');
    Serial.print(IR_degree);
    Serial.print(",");

    line_digits = F_LINE_get();
    Serial.print('l');
    Serial.print(line_digits);
    Serial.print(",");
    line_degree = F_line_avoid(line_digits, IR_value);
    Serial.print('s');
    Serial.print(line_degree);
    Serial.print(",");

    if (line_degree != 0 & IR_degree != 0 | line_degree != 0 & IR_degree == 0)
    {
      either_degree = line_degree;
    }
    else if (line_degree == 0 & IR_degree != 0)
    {
      either_degree = IR_degree;
    }
    else if (line_degree == 0 & IR_degree == 0)
    {
      either_degree = 0;
    }
    Serial.print("e");
    Serial.print(either_degree);
    Serial.print(",");

    if (either_degree != 0 & gyro_speed <= -100 | either_degree != 0 & 100 <= gyro_speed)
    {
      for (id = 0; id <= 3; id++)
      {
        either_speed[id] = F_MT_Il_speed(id, either_degree);
      }
      for (id = 0; id <= 3; id++)
      {
        MT_speed[id] = (either_speed[id] * 0.7) + (gyro_speed * 0.3);
      }
    }
    else if (either_degree != 0 & -100 < gyro_speed & gyro_speed < 100)
    {
      for (id = 0; id <= 3; id++)
      {
        either_speed[id] = F_MT_Il_speed(id, either_degree);
      }
      for (id = 0; id <= 3; id++)
      {
        MT_speed[id] = either_speed[id];
      }
    }
    else if (either_degree == 0 & gyro_speed <= -100 | either_degree == 0 & 100 <= gyro_speed)
    {
      for (id = 0; id <= 3; id++)
      {
        MT_speed[id] = gyro_speed;
      }
    }
    else if (either_degree == 0 & -100 < gyro_speed & gyro_speed < 100)
    {
      for (id = 0; id <= 3; id++)
      {
        MT_speed[id] = 0;
      }
    }

    more = 0;
    for (id = 0; id <= 3; id++) {
      more = max(more, abs(MT_speed[id]));
    }
    ratio = power / more;
    for (id = 0; id <= 3; id++) {
      MT_speed[id] = F_max_speed(ratio, MT_speed[id]);

      Serial.print(MT_number[id]);
      Serial.print(MT_speed[id]);
      Serial.print(",");
      F_speed_send(id, MT_speed[id]);
    }

    F_kicker();
  }
  else
  {
    Serial.print("OFF");
    for (id = 0; id <= 3; id++);
    {
      F_speed_send(id, 40);
    }
    F_LED_turnon();
  }
  Serial.println();
}
