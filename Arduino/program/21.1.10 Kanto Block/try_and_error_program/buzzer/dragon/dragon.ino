void setup() {
  pinMode(35, OUTPUT);
}

void loop() {
    tone(35, 330) ; // 35番ピンにミ(330Hz)を出力する
    delay(750) ; // 四分音符(750ミリ秒)
    tone(35, 392) ;
    delay(750) ;
    tone(35, 440) ;
    delay(750) ;
    tone(35, 392) ;
    delay(750) ;
    tone(35, 330) ;
    delay(750) ;
    tone(35, 392) ;
    delay(750) ;
    tone(35, 523) ;
    delay(730) ;
    noTone(35) ; // 35番ピンの出力を停止する
    delay(20) ; // そのまま20ミリ秒待機する
    tone(35, 523) ;
    delay(750) ;
    tone(35, 440) ;
    delay(730) ;
    noTone(35) ;
    delay(20) ;
    tone(35, 440) ;
    delay(750) ;
    tone(35, 392) ;
    delay(750) ;
    tone(35, 330) ;
    delay(750) ;
    tone(35, 262) ;
    delay(750) ;
    tone(35, 294) ;
    delay(750) ;
    tone(35, 330) ;
    delay(750) ;
    noTone(35) ;
}
