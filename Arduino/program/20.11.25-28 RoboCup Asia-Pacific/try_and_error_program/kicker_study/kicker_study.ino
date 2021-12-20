const int KICKER = 22;
const int KICKER_SWITCH = 24;

void setup() {
  pinMode(KICKER, OUTPUT);
  pinMode(KICKER_SWITCH, INPUT);
}

void loop() {
  digitalWrite(KICKER_SWITCH, LOW);
  digitalWrite(KICKER, HIGH);
  delay(10);
  digitalWrite(KICKER_SWITCH, HIGH);
  digitalWrite(KICKER, LOW);
  delay(1000);
}
