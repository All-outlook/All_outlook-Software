void setup() {
Serial.begin(115200);
}

void loop() {
unsigned long current_time = micros();
Serial.println(current_time);
}
