#define BEAT 300 // 音の長さを指定
#define PINNO 35 // 圧電スピーカを接続したピン番号

void setup() {
}
void loop() {
tone(PINNO,740,BEAT) ; // ファ#
delay(BEAT) ;
tone(PINNO,587,BEAT) ; // レ
delay(BEAT) ;
tone(PINNO,440,BEAT) ; // ラ
delay(BEAT) ;
tone(PINNO,587,BEAT) ; // レ
delay(BEAT) ;
tone(PINNO,659,BEAT) ; // ミ
delay(BEAT) ;
tone(PINNO,880,BEAT) ; // ラ
delay(600) ;
tone(PINNO,880,BEAT) ; // ラ
delay(BEAT) ;
tone(PINNO,659,BEAT) ; // ミ
delay(BEAT) ;
tone(PINNO,740,BEAT) ; // ファ#
delay(BEAT) ;
tone(PINNO,659,BEAT) ; // ミ
delay(BEAT) ;
tone(PINNO,440,BEAT) ; // ラ
delay(BEAT) ;
tone(PINNO,587,BEAT) ; // レ
delay(600) ;
delay(2000) ; // 2秒後に繰り返す
}
