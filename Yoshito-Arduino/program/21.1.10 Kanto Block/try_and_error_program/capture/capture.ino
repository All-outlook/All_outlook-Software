const int LASER_PIN = 12;
const int CAPTURE_PIN[] = {A7, A9, A10, A11, A12, A14};
int capture_value[6];
const int C_capture_threshold[] = {100, 100, 100, 100, 100, 100};
int capture_digits[6];

void setup() {
  Serial.begin(115200);
  pinMode(LASER_PIN, OUTPUT);
  digitalWrite(LASER_PIN, HIGH);
  for (int id = 0; id <= 5; id++) {
    pinMode(CAPTURE_PIN, INPUT);
  }
}

void loop() {
  for (int id = 0; id <= 5; id++) {
    capture_value[id] = analogRead(CAPTURE_PIN[id]);

    if (C_capture_threshold[id] < capture_value[id])
    {
      capture_digits[id] = 1;
    }
    else
    {
      capture_digits[id] = 0;
    }
    Serial.print(capture_value[id]);
    Serial.print(",");
  }
  Serial.println();
}
