//NOBのArduino日記！_AE-AQM1602Aの使い方_画面クリア編(20170320)
#include <Wire.h>//関数読み込み
String LCD_STRING; char s[16]; double SET; //変数の宣言

//コマンド書き込み
void writeCommand(byte command) {
  Wire.beginTransmission(0x3E);
  Wire.write(0x00);
  Wire.write(command);
  Wire.endTransmission(); delay(10);
}

//データ書き込み
void writeData(byte data) {
  Wire.beginTransmission(0x3E);
  Wire.write(0x40);
  Wire.write(data);
  Wire.endTransmission(); delay(1);
}

//LCDの1行目にデータ書き込み
void LCD_DISP_16_1(void) {
  writeCommand(0x80);//DDRAMアドレスを2行目先頭にセット
  for (int i = 0; i < 16; i++) {
    writeData(LCD_STRING[i]);
  }
}

//LCDの2行目にデータ書き込み
void LCD_DISP_16_2(void) {
  writeCommand(0x40 + 0x80); //DDRAMアドレスを2行目先頭にセット
  for (int i = 0; i < 16; i++) {
    writeData(LCD_STRING[i]);
  }
}

//液晶初期化
void F_LCD_setup() {
  Wire.begin(); delay(100);
  writeCommand(0x38); delay(20);
  writeCommand(0x39); delay(20);
  writeCommand(0x14); delay(20);
  writeCommand(0x7A); delay(20); //3.3V=0x73, 5V=0x7A
  writeCommand(0x54); delay(20); //3.3V=0x56, 5V=0x54
  writeCommand(0x6C); delay(20);
  writeCommand(0x38); delay(20);
  writeCommand(0x01); delay(20);
  writeCommand(0x0C); delay(20);
}

//無限ループ
void F_LCD_All_outlok() {
  writeCommand(0x01); 
  writeCommand(0x38);
  LCD_STRING = "All_outlook";
  LCD_DISP_16_1();                  //LCD一行目に変数を出力する
  LCD_STRING = "       in night";  //「NobArduinoDiary!」代入
  LCD_DISP_16_2(); 
  delay(2000);     //LCD二行目に変数を出力し1秒表示する

  writeCommand(0x01); 
  writeCommand(0x35);
  LCD_STRING = "All_nightlook"; 
  LCD_DISP_16_1();
  delay(300);
  writeCommand(0x01); 
  delay(300);
  LCD_DISP_16_1();
  delay(300);
  writeCommand(0x01); 
  delay(300);
  LCD_DISP_16_1();
  delay(2000);
  
  writeCommand(0x01);
  delay(1000);
}
