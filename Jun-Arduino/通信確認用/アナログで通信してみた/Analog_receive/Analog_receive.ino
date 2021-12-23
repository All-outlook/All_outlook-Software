

void setup() {
  Serial.begin(115200);
  pinMode(A0, INPUT);
}

void loop() {
 // Serial.print("____");
 Serial.println(analogRead(A0)/4);
}
