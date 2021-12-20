long randNumber;

void setup(){
  Serial.begin(115200);
  randomSeed(analogRead(0));
}

void loop() {
  randNumber = random(300); // 0から299の乱数を生成
  Serial.println(randNumber);
  delay(500);
}
