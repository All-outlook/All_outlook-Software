#include <Adafruit_NeoPixel.h>
const int KICKER_INSULATION = 9;
const int KICKER_PIN = 11;
const int CAPTURE_LED = 12;
const int CAPTURE_PIN[] = {A7, A8};

const int C_capture_threshold[] = {100, 10};
const int C_LED_count = 2;
char capture_number[] = {'A', 'B'};
int capture_value[2];
int capture_digits[2];
int kicker_shoot = 0;
int kicker_digits;
unsigned long previousMicros = 0;
unsigned long kicker_time = 0;
Adafruit_NeoPixel pixels(C_LED_count, CAPTURE_LED, NEO_GRB + NEO_KHZ800);

void F_kicker_setup()
{
  pinMode(KICKER_PIN, OUTPUT);
  pinMode(KICKER_INSULATION, OUTPUT);
  pixels.begin();
  for (id = 0; id <= 1; id++)
  {
    pinMode(CAPTURE_PIN[id], INPUT);
    pixels.setPixelColor(id, pixels.Color(128, 128, 128));
    //    pixels.setPixelColor(id, pixels.Color(0, 0, 0));
    pixels.show();
  }
}

void F_kicker()
{
  for (id = 0; id <= 1; id++)
  {
    capture_value[id] = analogRead(CAPTURE_PIN[id]);
    if (C_capture_threshold[id] < capture_value[id])
    {
      capture_digits[id] = 1;
    }
    else
    {
      capture_digits[id] = 0;
    }
    /*Serial.print('d');
      Serial.print(capture_number[id]);
      Serial.print(capture_digits[id]);
      Serial.print(",");*/
  }

  if (capture_digits[0] == 0 & capture_digits[1] == 0 & F_time_get() - previousMicros >= 10000000)
  {
    previousMicros = F_time_get();
    kicker_time = F_time_goal(10);
    kicker_shoot = 1;
  }
  else
  {
    if (kicker_time >= F_time_get())
    { // This is point!
      kicker_shoot = 1;
    }
    else
    {
      kicker_shoot = 0;
    }
  }

  if (kicker_shoot == 1)
  {
    digitalWrite(KICKER_INSULATION, HIGH);
    digitalWrite(KICKER_PIN, HIGH);
    kicker_digits = 1;
  }
  else if (kicker_shoot == 0)
  {
    digitalWrite(KICKER_PIN, LOW);
    digitalWrite(KICKER_INSULATION, LOW);
    kicker_digits = 0;
  }
}
