#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerialParity.h>
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
char MT_number[] = {'A', 'B', 'C', 'D'};
int MT_speed[4];
int MT_rotate[4];
int pre_MT_rotate[4];
int MT_rest[4];
unsigned long MT_rest_time[4];
unsigned long MT_stop_time[4];
int kicker_value;

void setup()
{
  F_switch_setup();
  F_LED_setuo();
  F_serial_setup();
  F_flame_setup();
  F_kicker_setup();
  F_reset_setup();
  F_buzzer_setup();
}

void loop()
{
  F_time_read();

  if (F_switch_value() == 0)
  {
    F_LED_turnon() ;

    gyro_degree = F_gyro_serial();
    Serial.print('g');
    Serial.print(gyro_degree);
    Serial.print(",");
    gyro_speed = F_attitude_control(gyro_degree);
    Serial.print('a');
    Serial.print(gyro_speed);
    Serial.print(",");

    IR_value = F_IR_serial();
    Serial.print('i');
    Serial.print(IR_value);
    Serial.print(",");
    IR_degree = F_shed_degree(IR_value);
    Serial.print('s');
    Serial.print(IR_degree);
    Serial.print(",");
//    IR_degree = F_wrap_degree(IR_value);
//    Serial.print('w');
//    Serial.print(IR_degree);
//    Serial.print(",");

    line_digits = F_line_serial();
    Serial.print('l');
    Serial.print(line_digits);
    Serial.print(",");
    line_degree = F_line_avoid(line_digits);
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


//    if (either_degree == 360 & gyro_speed == 0) {
//      MT_speed[0] = 255;
//      MT_speed[1] = 255;
//      MT_speed[2] = -255;
//      MT_speed[3] = -255;
//    } else if (either_degree == 90 & gyro_speed == 0) {
//      MT_speed[0] = -255;
//      MT_speed[1] = 255;
//      MT_speed[2] = 255;
//      MT_speed[3] = -255;
//    } else if (either_degree == 180 & gyro_speed == 0) {
//      MT_speed[0] = -255;
//      MT_speed[1] = -255;
//      MT_speed[2] = 255;
//      MT_speed[3] = 255;
//    } else if (either_degree == 270 & gyro_speed == 0) {
//      MT_speed[0] = 255;
//      MT_speed[1] = -255;
//      MT_speed[2] = -255;
//      MT_speed[3] = 255;
//    }

    for (id = 0; id <= 3; id++)
    {
      if (MT_speed[id] > 0)
      {
        MT_rotate[id] = 1;
      }
      else if (MT_speed[id] == 0)
      {
        MT_rotate[id] = 0;
      }
      else if (MT_speed[id] < 0)
      {
        MT_rotate[id] = -1;
      }

      if (MT_rotate[id] != pre_MT_rotate[id])
      {
        MT_rest[id] = 1;
        MT_rest_time[id] = F_time_goal(70);
      }

      if (F_time_get() >= MT_rest_time[id] & MT_rest[id] == 1)
      {
        MT_rest_time[id] = 0;
        MT_rest[id] = 2;
        MT_stop_time[id] = F_time_goal(30);
      }

      if (F_time_get() >= MT_stop_time[id] & MT_rest[id] == 2)
      {
        MT_rest[id] = 0;
        MT_stop_time[id] = 0;
      }

      if (1 <= MT_speed[id] & MT_speed[id] <= 100)
      {
        MT_speed[id] = 100;
      }
      else if (-100 <= MT_speed[id] && MT_speed[id] <= -1)
      {
        MT_speed[id] = -100;
      }

      Serial.print(MT_number[id]);
      if (MT_rest[id] == 0)
      {
        F_speed_send(id, MT_speed[id]);
        Serial.print(MT_speed[id]);
      }
      else if (MT_rest[id] == 1)
      {
        F_speed_send(id, 40);
        Serial.print("brake");
      }
      else if (MT_rest[id] == 2)
      {
        F_speed_send(id, 30);
        Serial.print("stop");
      }
      else if (MT_speed[id] == 0)
      {
        F_speed_send(id, 30);
        Serial.print("stop");
      }
      else
      {
        F_speed_send(id, MT_speed[id]);
        Serial.print(MT_speed[id]);
      }
      Serial.print(",");
    }
    //    kicker_value = F_kicker();
    //    Serial.print('k');
    //    Serial.print(kicker_value);
    //    Serial.print(",");
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
  for (id = 0; id <= 3; id++)
  {
    pre_MT_rotate[id] = MT_rotate[id];
  }
  Serial.println();
}
