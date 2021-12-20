#include <Wire.h>

int tact = 8;

uint8_t DEVICE_ADDRESS = 0x3E;  // デバイスアドレス(スレーブ）
char line1[] = "tact:";
char line2[] = "val";
 
void setup() {
  pinMode(tact, INPUT);
  Serial.begin(9600);

  Wire.begin();   // マスタとしてI2Cバスに接続する
  init_LCD();   // LCDの初期設定
  writeCommand(0x02);   // カーソルをホームへ戻す

 
}
 
void loop() {
  int val = digitalRead(tact);
  Serial.println(val);
  
  writeCommand(0x02); // カーソルをホームへ戻す
 
  // tact:の表示
  for (int i = 0; i < sizeof(line1); i++) {
    writeData(line1[i]);
  }
  // valの表示
  for (int j = 0; j < sizeof(line2); j++) {
    writeCommand(0x40 + 0x80 + j);
    writeData(line2[j]);
  }
}
 
// データ書き込み
void writeData(byte t_data)
{
  Wire.beginTransmission(DEVICE_ADDRESS);
    Wire.write(0x40);
    Wire.write(t_data);
  Wire.endTransmission();
  delay(1);
}
 
// コマンド書き込み
void writeCommand(byte t_command)
{
  Wire.beginTransmission(DEVICE_ADDRESS);
    Wire.write(0x00);
    Wire.write(t_command);
  Wire.endTransmission();
  delay(10);
}
 
// 液晶初期化
void init_LCD()
{
  delay(100);
  writeCommand(0x38); // FUNCTION SET
  delay(20);
  writeCommand(0x39); // IS=1
  delay(20);
  writeCommand(0x14); // INT OSC FREQUENCY
  delay(20);
  writeCommand(0x7A); // CONTRAST SET 0,1,2,3
  delay(20);
  writeCommand(0x54); // CONTRAST SET 4,5
  delay(20);
  writeCommand(0x6C); // F0LLOWER CONTROL
  delay(20);
  writeCommand(0x38); // IS=0
  delay(20);
  writeCommand(0x0C); // Display ON
  delay(20);
  writeCommand(0x01); // Clear Display
  delay(20);
  writeCommand(0x06); // Entry Mode
  delay(20);
}
