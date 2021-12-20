#include <Wire.h>
 
uint8_t DEVICE_ADDRESS = 0x3E; // デバイスアドレス(スレーブ) //0x→16進数　3×16 + 9+5 = 62
 
char line1[] = "All_outlook"; //おーるあうとるっくの表示

void setup() {
  Wire.begin(); // マスタとしてI2Cバスに接続する
  
  init_LCD(); // LCD(液晶ディスプレイ)の初期設定
 
  writeCommand(0x02);  // カーソルをホームへ戻す 
}
 
void loop() {
  writeCommand(0x02);  // カーソルをホームへ戻す
 
 // おーるあうとるっくの表示
  for (int i = 0; i < sizeof(line1); i++) {
    writeData(line1[i]);
  }
}
 
// データ書き込み
void writeData(byte t_data){
  Wire.beginTransmission(DEVICE_ADDRESS);
    Wire.write(0x40);
    Wire.write(t_data);
  Wire.endTransmission();
  delay(1);
}
 
// コマンド書き込み
void writeCommand(byte t_command){
  Wire.beginTransmission(DEVICE_ADDRESS);
    Wire.write(0x00);
    Wire.write(t_command);
  Wire.endTransmission();
  delay(10);
}
 
// 液晶初期化
void init_LCD(){
  delay(100);
  writeCommand(0x38); // FUNCTION SET //56
  delay(20);
  writeCommand(0x39); // IS=1 //57
  delay(20);
  writeCommand(0x14); // INT OSC FREQUENCY //20
  delay(20);
  writeCommand(0x7A); // CONTRAST SET 0,1,2,3 //122
  delay(20);
  writeCommand(0x54); // CONTRAST SET 4,5 //84
  delay(20);
  writeCommand(0x6C); // F0LLOWER CONTROL //108
  delay(20);
  writeCommand(0x38); // IS=0 //56
  delay(20);
  writeCommand(0x0C); // Display ON //12
  delay(20);
  writeCommand(0x01); // Clear Display //1
  delay(20);
  writeCommand(0x06); // Entry Mode //6
  delay(20);
}
