#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(38400);
  SerialBT.begin("ESP32_Controller123");

  pinMode(33, OUTPUT);

  //デバイス名は"ESP32"としました。サンプルスケッチではESP32testとなっています。

  Serial.println("The device started, now you can pair it with bluetooth!");


  digitalWrite(33, HIGH);
}

int a;

void loop() {
  if (Serial.available()) {
    SerialBT.write(Serial.read());
  }
  if (SerialBT.available()) {
    Serial.write(SerialBT.read());
    Serial.flush();

    //Serial.write(SerialBT.readStringUntil("#"));
  }

}
