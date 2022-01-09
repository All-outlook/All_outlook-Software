#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>
#include <Adafruit_NeoPixel.h>

// 1 second = 1,000 millis = 1,000,000 micros
// goal_time(n), n = millis
int id;
int gyro_degree;
int gyro_speed;
int gyro_tilt;
int IR_degree;
int IR_value;
int IR_digits;
int IR_another;
int line_digits;
int line_degree;
int line_another;
int either_degree;
int either_speed[4];
int more;
float ratio;
const float power = 254.0;
char MT_number[] = {'A', 'B', 'C', 'D'};
int MT_speed[4];
int kicker_value;

void setup()
{
  Serial.begin(115200);
  F_switch_setup();
  F_LED_setup();
  F_MD_setup();
  F_IR_setup();
  F_GYRO_setup();
  F_LINE_setup();
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
    //    Serial.print('g');
    //    Serial.print(gyro_degree);
    //    Serial.print(",");
    //    gyro_tilt = F_gyro_tilt(gyro_degree, line_digits);
    //    Serial.print('t');
    //    Serial.print(gyro_tilt);
    //    Serial.print(",");
    //    gyro_speed = F_attitude_control(gyro_degree, gyro_tilt);
    //    Serial.print('a');
    //    Serial.print(gyro_speed);
    //    Serial.print(", ");

    IR_value = F_IR_get();
    //    Serial.print('i');
    //    Serial.print(IR_value);
    //    Serial.print(",");
    IR_degree = F_shed_degree(IR_value);
    //    Serial.print('s');
    //    Serial.print(IR_degree);
    //    Serial.print(",");
    IR_another = F_go_forward(IR_value);
    //    Serial.print('f');
    //    Serial.print(IR_another);
    //    Serial.print(", ");

    line_digits = F_LINE_get();
    //    Serial.print('l');
    //    Serial.print(line_digits);
    //    Serial.print(",");
    line_degree = F_line_avoid(line_digits);
        Serial.print('s');
        Serial.print(line_degree);
        Serial.print(",");
    line_another = F_just_pulled(line_digits);
    //    Serial.print('j');
    //    Serial.print(line_another);
    //    Serial.print(", ");

    if (IR_digits == 1) {
      either_degree = IR_another;

    } else if (IR_digits == 2) {
      if (line_another != 0 & IR_another != 0 | line_another != 0 & IR_another == 0)
      {
        either_degree = line_another;
      }
      else if (line_another == 0 & IR_another != 0)
      {
        either_degree = IR_another;
      }
      else if (line_another == 0 & IR_another == 0)
      {
        either_degree = 0;
      }

    } else if (IR_digits == 0) {
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
    }
    //    Serial.print("e");
    //    Serial.print(either_degree);
    //    Serial.print(",");
    
    int Speeeed;
    if (either_degree == 90 | either_degree == 270) {
      Speeeed = 254;
    } else {
      Speeeed = 150;
    }
    F_MD_rotate(either_degree, gyro_degree, Speeeed);

    F_kicker();
  }
  else
  {
    Serial.print("OFF");
    for (id = 0; id <= 3; id++);
    {
      F_speed_send(id, 0);
    }
    F_LED_turnon();
  }
  Serial.println();
}
