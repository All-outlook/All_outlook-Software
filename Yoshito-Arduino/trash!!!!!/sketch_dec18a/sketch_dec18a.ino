const int IR_PIN[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17};
int duration[16];
int mytimeout = 1725;
void setup() {
  Serial.begin(115200);
  for (int id = 0; id <= 15; id++) {
    pinMode(IR_PIN[id], INPUT);
  }
}

void loop() {
  for (int id = 0; id <= 15; id++) {
    duration[id] = pulseIn(IR_PIN[id], LOW, mytimeout);
    Serial.print(duration[id]);
    Serial.print(",");
  }
  Serial.println();
}
