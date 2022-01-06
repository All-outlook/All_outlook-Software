#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32_Jun_robot");
  //デバイス名は"ESP32"としました。サンプルスケッチではESP32testとなっています。

  Serial.println("The device started, now you can pair it with bluetooth!");


  pinMode(32, OUTPUT);
  pinMode(33, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(25, OUTPUT);

}

unsigned long myreceive;
unsigned long mysend;

void loop() {
  F_time_read();

  if (SerialBT.available()) {
    Serial.write(SerialBT.read());
    Serial.flush();
    myreceive = F_time_goal(100);;
  }
  
  if (Serial.available()) {
    SerialBT.write(Serial.read());
    mysend = F_time_goal(100);
  }

  if( myreceive > F_time_get()){
    digitalWrite(33, HIGH);
    digitalWrite(32, HIGH);
  }else{
    digitalWrite(33, LOW);
    digitalWrite(32, LOW);
  }
  if( mysend > F_time_get()){
    digitalWrite(26, HIGH);
    digitalWrite(25, LOW);
  }else{
    digitalWrite(26, LOW);
    digitalWrite(25, LOW);
  }
}
