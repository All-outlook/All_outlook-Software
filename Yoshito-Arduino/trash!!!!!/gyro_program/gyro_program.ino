const int LED_DONE = 2;
const int SWITCH_LED = 3;
const int GYRO_SWITCH = 4;
const int LED_CIRCLE[] = {5, 6, 7, 8, 9, 10, 11, 12};

unsigned long gauge = 0;
int gyro_degree;
int gyro_switch_count;
int switch_count;

void setup()
{
  Serial.begin(115200);
  pinMode(LED_DONE, OUTPUT);
  pinMode(SWITCH_LED, OUTPUT);
  pinMode(GYRO_SWITCH, INPUT);
  for (int id = 0; id <= 7; id++)
  {
    pinMode(LED_CIRCLE[id], OUTPUT);
    digitalWrite(LED_CIRCLE[id], HIGH);
  }
  gyro_configuration();
  for (int id = 0; id <= 7; id++)
  {
    digitalWrite(LED_CIRCLE[id], LOW);
  }
  digitalWrite(LED_DONE, HIGH);
  Serial.print("start");
}

void loop()
{
  //  if (gyro_switch_count == 0) {
  //    gauge = 0;
  //    while (!digitalRead(GYRO_SWITCH)) {
  //      gauge++;
  //      gyro_loop();
  //    }
  //    if (gauge > 10000) {
  //    }
  //    digitalWrite(SWITCH_LED, HIGH);
  //    switch_count = 1;
  //  }

  gyro_degree = gyro_loop();

  LED_shine(gyro_degree);

  Serial.write(gyro_degree);
  Serial.flush();
}
