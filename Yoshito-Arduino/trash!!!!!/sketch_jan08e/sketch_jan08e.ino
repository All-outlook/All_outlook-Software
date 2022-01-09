unsigned long count = 0;
int IR = 10;
void setup() {
  Serial.begin(115200);
}

void loop() {
  if (0 < IR) {
    count++;
  }
  Serial.println(count);
}
