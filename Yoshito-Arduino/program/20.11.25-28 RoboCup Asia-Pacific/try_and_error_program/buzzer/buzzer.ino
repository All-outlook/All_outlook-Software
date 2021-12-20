int melo = 200;   // 音の長さを指定
int pin = 35;     // ブザーを接続したピン番号
int TOGGLE_PIN;
int toggle_value;

void setup() {
  pinMode(TOGGLE_PIN, INPUT);
}

void loop() {
  toggle_value = digitalRead(TOGGLE_PIN);
  if (toggle_value == 0) {
    tone(pin, 262, melo) ; // ド
    delay(melo) ;         // 音がなっている間待機
    tone(pin, 294, melo) ; // レ
    delay(melo) ;
    tone(pin, 330, melo) ; // ミ
    delay(melo) ;

    delay(1000) ;         // 1秒待機
  }
}
