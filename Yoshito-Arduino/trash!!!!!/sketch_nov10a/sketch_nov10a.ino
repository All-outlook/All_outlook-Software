void setup() {
  Serial.begin(115200);
  Serial2.begin(9600);
}

void loop() {
  String recive_value = Serial2.readStringUntil('&');
  int gyro = recive_value.toInt();
  Serial.print('g');
  Serial.println(gyro);
}
