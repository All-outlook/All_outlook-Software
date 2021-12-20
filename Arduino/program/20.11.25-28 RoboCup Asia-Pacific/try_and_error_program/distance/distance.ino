const int IR_PIN = 2;
long duration;
const int mytimeout = 1725;
void setup() {
  Serial.begin(115200);
  pinMode(IR_PIN, INPUT);
}

void loop() {
  duration = pulseIn(IR_PIN, LOW, mytimeout);
  Serial.print(duration);
  Serial.println();
}
