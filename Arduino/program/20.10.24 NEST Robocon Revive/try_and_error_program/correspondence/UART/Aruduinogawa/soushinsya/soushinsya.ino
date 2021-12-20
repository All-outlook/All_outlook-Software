int LED = 13;
String sendstr = "arduino";

void setup() {
 Serial.begin(9600);
 pinMode(LED, OUTPUT);
 Serial.println("start writeing.");
}

void loop() {
  digitalWrite(LED, LOW);
  for(int i = 0; i < sendstr.length(); i++){
    Serial.write(sendstr.charAt(i));
  }
Serial.write(0);
digitalWrite(LED, HIGH);
delay(2000);
}
