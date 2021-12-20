long randNumber;
int Do = 261;
int Re = 294;
int Mi = 329;
int Fa = 349;
int So = 392;
int La = 440;
int Si = 493;
int Do2 = 523;
int Re2 = 587;
int Mi2 = 659;
int Fa2 = 698;
int So2 = 784;
int La2 = 880;
int Si2 = 988;
int Do3 = 1047;
int Re3 = 1175;
int Mi3 = 1319;
int Fa3 = 1397;
int So3 = 1568;

int oneup[6] = { Mi2, So2, Mi3, Do3, Re3, So3};
int mario[13] = {Mi2, Mi2, 0, Mi2, 0, Do2, Mi2, 0, So2, 0, 0, 0, So};
int fire[3] = {So, So2, So3};
int dead[9] = {Si, Fa2, 0, Fa2, Fa2, Mi2, 0, Re2, Do2};
int damage[18] = {La2, Mi, La, 0, 0, 0, La2, Mi, La, 0, 0, 0, La2, Mi, La, 0, 0, 0};
int star[32] = {Do2, 0, Do2, 0, Do2, 0, Re, Do2, 0, Do2, 0, Re, Do2, 0, Do2, 0,
                Si , 0, Si, 0, Si, 0, Do, Si, 0, Si, 0, Do, Si, 0, Si, 0
               };

void setup() {
  Serial.begin(115200);
  randomSeed(analogRead(0));
  randNumber = random(0, 5);
}

void loop() {
  if (randNumber == 0) {
    #define BEAT 300 // 音の長さを指定
    tone(35, 740, BEAT) ; // ファ#
    delay(BEAT) ;
    tone(35, 587, BEAT) ; // レ
    delay(BEAT) ;
    tone(35, 440, BEAT) ; // ラ
    delay(BEAT) ;
    tone(35, 587, BEAT) ; // レ
    delay(BEAT) ;
    tone(35, 659, BEAT) ; // ミ
    delay(BEAT) ;
    tone(35, 880, BEAT) ; // ラ
    delay(600) ;
    tone(35, 880, BEAT) ; // ラ
    delay(BEAT) ;
    tone(35, 659, BEAT) ; // ミ
    delay(BEAT) ;
    tone(35, 740, BEAT) ; // ファ#
    delay(BEAT) ;
    tone(35, 659, BEAT) ; // ミ
    delay(BEAT) ;
    tone(35, 440, BEAT) ; // ラ
    delay(BEAT) ;
    tone(35, 587, BEAT) ; // レ
    delay(600) ;
    delay(2000) ; // 2秒後に繰り返す

  } else if (randNumber == 1) {
    int a = 150;
    int b = 225;
    int c = 300;
    int d = 425;
    tone(35, 262, a); //ド
    delay(b);
    tone(35, 262, a); //ド
    delay(b);
    tone(35, 294, a); //レ
    delay(b);
    tone(35, 294, a); //レ
    delay(b);
    tone(35, 330, a); //ミ
    delay(b);
    tone(35, 330, a); //ミ
    delay(b);
    tone(35, 349, a); //ファ
    delay(b);
    tone(35, 349, a); //ファ
    delay(b);

    tone(35, 330, b); //ミ
    delay(d);
    tone(35, 294, b); //レ
    delay(d);
    tone(35, 262, b); //ド
    delay(d);

  } else if (randNumber == 2) {
    for (int i = 0; i < 3; i++) {
      tone(35, Si2, 100);
      delay(50);
      tone(35, Mi3, 250);
      delay(250);
    }
    delay(200);

    for (int i = 0; i <= 2; i++) {
      for (int i = 0; i < 6; i++) {
        tone(35, oneup[i], 100);
        delay(125);
      }
    }
    delay(500);

  } else if (randNumber == 3) {
    for (int i = 0; i < 13; i++) {
      tone(35, mario[i], 50);
      delay(140);
    }

  } else if (randNumber == 4) {
    for (int i = 0; i < 32; i++) {
      tone(35, star[i], 100);
      delay(100);
    }
    delay(500);
  }
}
