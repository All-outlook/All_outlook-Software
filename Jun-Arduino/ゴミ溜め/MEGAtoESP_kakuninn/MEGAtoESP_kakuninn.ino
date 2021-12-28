void setup() {
  // ビットレート9600でシリアル通信を開始
  Serial.begin(9600);
  Serial1.begin(9600);
  pinMode(33, OUTPUT);
}

void loop() {
  while (Serial1.available())

  switch(Serial1.read()){
    case 'A':
      // 「A」を受信
      digitalWrite(33, HIGH);
      break;
    case 'B':
      // 「B」を受信
      digitalWrite(33, LOW);
      break;
  }
}
