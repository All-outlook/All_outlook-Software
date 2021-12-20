const int line_pin[] = {A0, A1, A2, A3};
const int red_led[] = {40, 41, 42, 43};
int line_read;
int line_value;

void setup() {
  Serial.begin(38400);
  for (int i = 0; i <= 3; i++) {
    pinMode(line_pin[i], INPUT);
    pinMode(red_led[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i <= 3; i++) {
    line_read = analogRead(line_pin[i]);
    
    if (line_read >= 800){
      line_value = 1;
      digitalWrite(red_led[i], HIGH);
    } else {
      line_value = 0;
      digitalWrite(red_led[i], LOW);
    }
    
    Serial.print("line");
    Serial.print(i);
    Serial.print(":");
    Serial.print(line_read);
    Serial.print(", ");
  }
  Serial.println();
}
