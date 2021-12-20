#define LED_PIN 13
void setup() {
  Serial.begin(9600);
  Serial.write("\n");
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int input;
  input = Serial.read();
  if (input != -1) {
    switch (input) {
      case 'o':
        digitalWrite(LED_PIN, HIGH);
        Serial.print("LED ON\n");
        break;
        
      case'f':
        digitalWrite(LED_PIN, LOW);
        Serial.print("LED OFF\n");
        break;

    }
  }
}
