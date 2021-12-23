void setup() {
  Serial.begin(38400);
  F_GYRO_setup();
}

void loop() {
  Serial.println(F_GYRO_read());
  delay(100);
}

void F_GYRO_setup(){
  Serial2.begin(38400, SERIAL_8E1);
}

int F_GYRO_read(){
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
