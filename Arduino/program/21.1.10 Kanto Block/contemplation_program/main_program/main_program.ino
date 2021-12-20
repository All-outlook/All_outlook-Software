//#include <Arduino.h>
// 1 second = 1,000 millis = 1,000,000 micros
// goal_time(n), n = millis
const int KICKER_INSULATION = 9;
const int KICKER_PIN = 11;
const int CPTURE_LED = 12;
const int LED_PIN[] = {30, 31, 32, 33};
const int FULL_COLOR = 40;
const int TOGGLE_PIN = 41;
const int CAPTURE_PIN[] = {A7, A8};
int id;
int toggle_value;
int 

void setup()
{
  pinMode(TOGGLE_PIN, INPUT);
  F_serial_setup();
  F_kicker_setup();
  F_reset_setup();
  F_buzzer_setup();
}

void loop()
{
  F_time_read();
 
  toggle_value = digitalRead(TOGGLE_PIN);
  if (toggle_value == 0) {
    for (int id = 0; id <= 3; id++) {
      digitalWrite(LED_PIN[id], LOW);

      String recive_value = Serial2.readStringUntil('&');
      gyro_value = recive_value.toInt();
      Serial.print('g');
      Serial.print(gyro_value);
      Serial.print(",");

      gyro_speed = F_attitude(gyro_value);
      Serial.print('a');
      Serial.print(gyro_speed);
      Serial.print(",");


    }  else {
      Serial.println("OFF");
      for (int id = 0; id <= 3; id++) {
        digitalWrite(LED_PIN[id], HIGH);
      }
    }
