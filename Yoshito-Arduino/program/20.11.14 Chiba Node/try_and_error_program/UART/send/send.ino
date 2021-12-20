void setup() {
  Serial.begin(9600);
}

void loop() {
  int value = 348;
  Serial.print(value);  
  Serial.print('&');
}
