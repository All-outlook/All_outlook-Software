void setup() {
  Serial.begin(115200);
  Serial3.begin(115200);
}

void loop() {
  while (Serial3.available() > 10) {
    int g = Serial3.read();
  }

modoru:
  uint8_t data = (uint8_t)Serial3.read();
  if (data == 0xFF) {
    uint8_t deg = Serial3.read() * 1.5;
    uint8_t dis = Serial3.read();

    Serial.print(deg);
    Serial.print(" ");
    Serial.println(dis);
  } else {
    goto modoru;
  }
  delay(100);
}










void F_GYRO_setup() {
  Serial2.begin(38400);
}

int F_GYRO_read() {
  int i;
  while (Serial2.available() > 1) {
    int g = Serial2.read();
  }
  if (Serial2.available()) {
    i = Serial2.read() * 2;
  }
  return i;
}



























//  if (Serial.available()) {
//    uint8_t data = Serial1.read();
//    if (data == 0xff) {
//      uint8_t a = Serial1.read();
//      uint8_t b = Serial1.read();
//      if (a != 255) {
//        Serial.println(a, DEC);
//      }
//      if (b != 255) {
//        Serial.println(b, DEC);
//      }
//
//    }
//  }




/*
  void receive()
  {
    uint8_t data = (uint8_t)Serial.read();
    if (data == 0xFF) // check if incoming byte is header
    {
        uint8_t r = Serial.read();
        uint8_t g = Serial.read();
        uint8_t b = Serial.read();
    }

    // change led color with rgb data
  }

  if (Serial.read() == 0x80) {
  Serial.readBytes(buf, 2);
  mySerial.print(buf[0]);
  mySerial.print(buf[1]);
  delay(10);
  }

*/
