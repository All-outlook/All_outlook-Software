const int KICKER_INSULATION = 62;
const int KICKER_PIN = 11;
const int LASER_PIN = 12;
const int CAPTURE_PIN[] = {A7, A9, A10, A11, A12, A14};

const int C_capture_threshold = 100;
int kicker_shoot = 0;
unsigned long previousMicros = 0;
unsigned long kicker_time = 0;

void F_kicker_setup()
{
  pinMode(KICKER_PIN, OUTPUT);
  pinMode(KICKER_INSULATION, OUTPUT);
  pinMode(LASER_PIN, OUTPUT);
  digitalWrite(LASER_PIN, HIGH);
}

void F_kicker()
{
  int capture_value[6];
  int more;
  int capture_number;

  for (id = 0; id <= 5; id++)
  {
    capture_value[id] = analogRead(CAPTURE_PIN[id]);
    //    Serial.print('d');
    //    Serial.print(capture_value[id]);
    //    Serial.print(",");
  }

  more = 0;
  for (id = 0; id <= 5; id++) {
    more = max(more, capture_value[id]);
  }

  if (more <=  C_capture_threshold)
  {
    capture_number = 1;
  }
  else
  {
    capture_number = 0;
  }

  if (capture_number == 1 & (F_time_get() - previousMicros) >= 1000000)
  { //1secons
    previousMicros = F_time_get();
    kicker_time = F_time_goal(300);
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
    kicker_value = 1;
  }
  else if (kicker_shoot == 0)
  {
    digitalWrite(KICKER_PIN, LOW);
    digitalWrite(KICKER_INSULATION, LOW);
    kicker_value = 2;
  }
}
