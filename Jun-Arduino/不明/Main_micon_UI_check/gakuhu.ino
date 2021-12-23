const int BUZZER = 35;

void F_BUZ_setup() {
  pinMode(BUZZER, OUTPUT);
}
void F_BUZ_doremi() {
  int Bt = 200;
  tone(BUZZER, 262, Bt); //ド
  delay(Bt);
  tone(BUZZER, 294, Bt); //レ
  delay(Bt);
  tone(BUZZER, 330, Bt); //ミ
  delay(Bt);
  tone(BUZZER, 349, Bt); //ファ
  delay(Bt);
  tone(BUZZER, 392, Bt); //ソ
  delay(Bt);
  tone(BUZZER, 440, Bt); //ラ
  delay(Bt);
  tone(BUZZER, 494, Bt); //シ
  delay(Bt);
  tone(BUZZER, 523, Bt); //ド
  delay(1000);
}


void F_BUZ_koinobori() {
  tone(BUZZER, 330, 300);
  delay(300);
  tone(BUZZER, 294, 300);
  delay(300);
  tone(BUZZER, 262, 600);
  delay(600);
  tone(BUZZER, 294, 600);
  delay(600);
  tone(BUZZER, 330, 600);
  delay(600);
  tone(BUZZER, 440, 600);
  delay(600);
  tone(BUZZER, 392, 300);
  delay(600);
  tone(BUZZER, 330, 300);
  delay(300);
  tone(BUZZER, 330, 300);
  delay(300);
  tone(BUZZER, 330, 600);
  delay(600);
  tone(BUZZER, 294, 300);
  delay(300);
  tone(BUZZER, 262, 300);
  delay(300);
  tone(BUZZER, 294, 600);

  delay(1000);
}

void F_BUZ_DarthVader() {
  //音の長さ(msec)を定義する(BPM=100)
#define Bt2 1200 //2分音符
#define Bt4 500 //4分音符、スタッカート気味
#define Bt8f 450 //付点8分音符
#define Bt8 300 //8分音符
#define Bt16 150 //16分音符

  //音符に対してのDelay Time(msec)を設定
#define Dt2 1100
#define Dt4 500
#define Dt8f 350
#define Dt8 200
#define Dt16 50

  //音程を定義する
#define G4 392 //ソ
#define Ds4 311 //レ＃
#define As4 466 //ラ＃
#define D5 587 //レ
#define Ds5 622 //レ＃
#define Fs4 370 //ファ＃
#define G5 784 //ソ
#define Fs5 740 //ファ＃
#define F5 698 //ファ
#define E5 659 //ミ
#define Gs4 415 //ソ＃
#define Cs5 554 //ド＃
#define C5 523 //ド
#define B4 494 //シ
#define A4 440 //ラ


  tone(BUZZER, G4, Bt4);
  delay(Dt4);
  tone(BUZZER, G4, Bt4);
  delay(Dt4);
  tone(BUZZER, G4, Bt4);
  delay(Dt4);
  tone(BUZZER, Ds4, Bt8f);
  delay(Dt8f);
  tone(BUZZER, As4, Bt8);
  delay(Dt8);
  tone(BUZZER, G4, Bt4);
  delay(Dt4);
  tone(BUZZER, Ds4, Bt8f);
  delay(Dt8f);
  tone(BUZZER, As4, Bt8);
  delay(Dt8);
  tone(BUZZER, G4, Bt2);
  delay(Dt2);

  //3~4小節
  tone(BUZZER, D5, Bt4);
  delay(Dt4);
  tone(BUZZER, D5, Bt4);
  delay(Dt4);
  tone(BUZZER, D5, Bt4);
  delay(Dt4);
  tone(BUZZER, Ds5, Bt8f);
  delay(Bt8f);
  tone(BUZZER, As4, Bt16);
  delay(Dt16);
  tone(BUZZER, Fs4, Bt4);
  delay(Dt4);
  tone(BUZZER, Ds4, Bt8f);
  delay(Dt8f);
  tone(BUZZER, As4, Bt16);
  delay(Dt16);
  tone(BUZZER, G4, Bt2);
  delay(Dt2);

  //5~6小節
  tone(BUZZER, G5, Bt4);
  delay(Dt4);
  tone(BUZZER, G4, Bt8f);
  delay(Dt8f + 50);
  tone(BUZZER, G4, Bt16);
  delay(Dt16);
  tone(BUZZER, G5, Bt4);
  delay(Dt4);
  tone(BUZZER, Fs5, Bt8f);
  delay(Dt8f);
  tone(BUZZER, F5, Bt16);
  delay(Dt16 + 100);
  tone(BUZZER, E5, Bt16);
  delay(Dt16 + 100);
  tone(BUZZER, Ds5, Bt8);
  delay(Dt8);
  delay(Bt8 - 50);
  tone(BUZZER, Gs4, Bt8);
  delay(Dt8);
  tone(BUZZER, Cs5, Bt4);
  delay(Dt4);
  tone(BUZZER, C5, Bt8f);
  delay(Dt8f);
  tone(BUZZER, B4, Bt16);
  delay(Bt16);

  //7~8小節
  tone(BUZZER, As4, Bt16);
  delay(Dt16 + 100);
  tone(BUZZER, A4, Bt16);
  delay(Dt16 + 100);
  tone(BUZZER, Gs4, Bt8);
  delay(Dt8);
  delay(Bt8 - 50);
  tone(BUZZER, Ds4, Bt8);
  delay(Dt8);
  tone(BUZZER, Fs4, Bt4);
  delay(Dt4);
  tone(BUZZER, Ds4, Bt8f);
  delay(Dt8f);
  tone(BUZZER, As4, Bt16);
  delay(Dt16);
  tone(BUZZER, G4, Bt4);
  delay(Dt4);
  tone(BUZZER, Ds4, Bt8f);
  delay(Dt8f);
  tone(BUZZER, As4, Bt16);
  delay(Dt16);
  tone(BUZZER, G4, Bt2);
  delay(Dt2);

  delay(1000);

}


void F_BUZ_ElectricalParade() {

#define NOTE_C3  131//ド
#define NOTE_CS3 139
#define NOTE_D3  147//レ
#define NOTE_DS3 156
#define NOTE_E3  165//ミ
#define NOTE_F3  175//ファ
#define NOTE_FS3 185
#define NOTE_G3  196//ソ
#define NOTE_GS3 208
#define NOTE_A3  220//ラ
#define NOTE_AS3 233
#define NOTE_B3  247//シ
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976

  tone(BUZZER, NOTE_G4, 300) ;
  delay(350);
  tone(BUZZER, NOTE_G4, 100) ;
  delay(150);
  tone(BUZZER, NOTE_G4, 100) ;
  delay(150);
  tone(BUZZER, NOTE_G4, 800) ;
  delay(1150);

  tone(BUZZER, NOTE_G4, 150) ;
  delay(200);
  tone(BUZZER, NOTE_A4, 150) ;
  delay(200);
  tone(BUZZER, NOTE_D4, 150) ;
  delay(200);
  tone(BUZZER, NOTE_G4, 350) ;
  delay(550);

  tone(BUZZER, NOTE_C5, 150) ;
  delay(200);
  tone(BUZZER, NOTE_B4, 150) ;
  delay(200);
  tone(BUZZER, NOTE_C5, 150) ;
  delay(200);
  tone(BUZZER, NOTE_D5, 350) ;
  delay(500);

  tone(BUZZER, NOTE_D5, 300) ;
  delay(350);
  tone(BUZZER, NOTE_D5, 100) ;
  delay(150);
  tone(BUZZER, NOTE_D5, 100) ;
  delay(150);
  tone(BUZZER, NOTE_D5, 150) ;
  delay(200);
  tone(BUZZER, NOTE_E5, 150) ;
  delay(200);
  tone(BUZZER, NOTE_C5, 150) ;
  delay(200);
  tone(BUZZER, NOTE_D5, 350) ;
  delay(500);

  tone(BUZZER, NOTE_G5, 300) ;
  delay(500);

  tone(BUZZER, NOTE_G5, 150) ;
  delay(200);
  tone(BUZZER, NOTE_A5, 150) ;
  delay(200);
  tone(BUZZER, NOTE_FS5, 150) ;
  delay(200);
  tone(BUZZER, NOTE_G5, 350) ;
  delay(500);

  tone(BUZZER, NOTE_C6, 250) ;
  delay(300);
  tone(BUZZER, NOTE_A5, 250) ;
  delay(300);
  tone(BUZZER, NOTE_D6, 300) ;
  delay(350);
  tone(BUZZER, NOTE_D6, 100) ;
  delay(150);
  tone(BUZZER, NOTE_D6, 100) ;
  delay(150);
  tone(BUZZER, NOTE_D6, 800) ;
  delay(950);

  delay(800);
  tone(BUZZER, NOTE_G4, 550) ;
  delay(600);
  tone(BUZZER, NOTE_D4, 550) ;
  delay(600);
  tone(BUZZER, NOTE_G4, 550) ;
  delay(600);
  tone(BUZZER, NOTE_D4, 550) ;
  delay(600);
  tone(BUZZER, NOTE_G4, 550) ;
  delay(600);
  tone(BUZZER, NOTE_D4, 550) ;
  delay(600);
  tone(BUZZER, NOTE_G4, 280);
  delay(330);
  tone(BUZZER, NOTE_D4, 240) ;
  delay(290);
  tone(BUZZER, NOTE_E4, 240) ;
  delay(290);
  tone(BUZZER, NOTE_FS4, 240) ;
  delay(290);

  //サビ
  tone(BUZZER, NOTE_G5, 300) ;
  delay(350);
  tone(BUZZER, NOTE_B5, 100) ;
  delay(150);
  tone(BUZZER, NOTE_C6, 100) ;
  delay(150);
  tone(BUZZER, NOTE_D6, 300) ;
  delay(350);
  tone(BUZZER, NOTE_G5, 300) ;
  delay(350);
  tone(BUZZER, NOTE_E5 , 300) ;
  delay(350);
  tone(BUZZER, NOTE_A5, 100) ;
  delay(150);
  tone(BUZZER, NOTE_G5, 100) ;
  delay(150);
  tone(BUZZER, NOTE_FS5, 100) ;
  delay(150);
  tone(BUZZER, NOTE_E5 , 100) ;
  delay(150);
  tone(BUZZER, NOTE_FS5, 100) ;
  delay(150);
  tone(BUZZER, NOTE_D5, 100) ;
  delay(150);
  tone(BUZZER, NOTE_G5, 300) ;
  delay(350);
  tone(BUZZER, NOTE_G5, 100) ;
  delay(150);
  tone(BUZZER, NOTE_A5, 100) ;
  delay(150);
  tone(BUZZER, NOTE_B5, 100) ;
  delay(150);
  tone(BUZZER, NOTE_A5, 100) ;
  delay(150);
  tone(BUZZER, NOTE_B5, 100) ;
  delay(150);
  tone(BUZZER, NOTE_G5, 100) ;
  delay(150);
  tone(BUZZER, NOTE_A5, 100) ;
  delay(150);
  tone(BUZZER, NOTE_B5, 100) ;
  delay(150);
  tone(BUZZER, NOTE_A5, 100) ;
  delay(150);
  tone(BUZZER, NOTE_G5, 100) ;
  delay(150);
  tone(BUZZER, NOTE_FS5, 100) ;
  delay(150);
  tone(BUZZER, NOTE_E5 , 100) ;
  delay(150);
  tone(BUZZER, NOTE_FS5, 100) ;
  delay(150);
  tone(BUZZER, NOTE_D5, 100) ;
  delay(150);
  tone(BUZZER, NOTE_G5, 300) ;
  delay(350);
  tone(BUZZER, NOTE_B5, 100) ;
  delay(150);
  tone(BUZZER, NOTE_C6, 100) ;
  delay(150);
  tone(BUZZER, NOTE_D6, 300) ;
  delay(350);
  tone(BUZZER, NOTE_G5, 300) ;
  delay(350);
  tone(BUZZER, NOTE_E5 , 300) ;
  delay(350);
  tone(BUZZER, NOTE_A5, 100) ;
  delay(150);
  tone(BUZZER, NOTE_G5, 100) ;
  delay(150);
  tone(BUZZER, NOTE_FS5, 100) ;
  delay(150);
  tone(BUZZER, NOTE_E5 , 100) ;
  delay(150);
  tone(BUZZER, NOTE_FS5, 100) ;
  delay(150);
  tone(BUZZER, NOTE_D5, 100) ;
  delay(150);
  tone(BUZZER, NOTE_G5, 100) ;
  delay(150);
  tone(BUZZER, NOTE_A5, 100) ;
  delay(150);
  tone(BUZZER, NOTE_B5, 100) ;
  delay(150);
  tone(BUZZER, NOTE_G5, 100) ;
  delay(150);
  tone(BUZZER, NOTE_A5, 100) ;
  delay(150);
  tone(BUZZER, NOTE_B5, 100) ;
  delay(150);
  tone(BUZZER, NOTE_A5, 100) ;
  delay(150);
  tone(BUZZER, NOTE_G5, 100) ;
  delay(150);
  tone(BUZZER, NOTE_FS5, 100) ;
  delay(150);
  tone(BUZZER, NOTE_E5 , 100) ;
  delay(150);
  tone(BUZZER, NOTE_FS5, 100) ;
  delay(150);
  tone(BUZZER, NOTE_D5, 100) ;
  delay(150);
  tone(BUZZER, NOTE_G5, 300) ;
  delay(350);

  delay(1000);
}


void F_BUZ_Haruno_ogawa() {
  tone(BUZZER, 330) ; // BUZZER番ピンにミ(330Hz)を出力する
  delay(750) ; // 四分音符(750ミリ秒)
  tone(BUZZER, 392) ;
  delay(750) ;
  tone(BUZZER, 440) ;
  delay(750) ;
  tone(BUZZER, 392) ;
  delay(750) ;
  tone(BUZZER, 330) ;
  delay(750) ;
  tone(BUZZER, 392) ;
  delay(750) ;
  tone(BUZZER, 523) ;
  delay(730) ;
  noTone(BUZZER) ; // 12番ピンの出力を停止する
  delay(20) ; // そのまま20ミリ秒待機する
  tone(BUZZER, 523) ;
  delay(750) ;
  tone(BUZZER, 440) ;
  delay(730) ;
  noTone(BUZZER) ;
  delay(20) ;
  tone(BUZZER, 440) ;
  delay(750) ;
  tone(BUZZER, 392) ;
  delay(750) ;
  tone(BUZZER, 330) ;
  delay(750) ;
  tone(BUZZER, 262) ;
  delay(750) ;
  tone(BUZZER, 294) ;
  delay(750) ;
  tone(BUZZER, 330) ;
  delay(750) ;
  noTone(BUZZER) ;
}

//
//// https://dev.classmethod.jp/articles/the-imperial-march-with-edison/
//void F_BUZ_Haruno_ogawa() {
//  #define NOTE_B0  31
//#define NOTE_C1  33
//#define NOTE_CS1 35
//#define NOTE_D1  37
//#define NOTE_DS1 39
//#define NOTE_E1  41
//#define NOTE_F1  44
//#define NOTE_FS1 46
//#define NOTE_G1  49
//#define NOTE_GS1 52
//#define NOTE_A1  55
//#define NOTE_AS1 58
//#define NOTE_B1  62
//#define NOTE_C2  65
//#define NOTE_CS2 69
//#define NOTE_D2  73
//#define NOTE_DS2 78
//#define NOTE_E2  82
//#define NOTE_F2  87
//#define NOTE_FS2 93
//#define NOTE_G2  98
//#define NOTE_GS2 104
//#define NOTE_A2  110
//#define NOTE_AS2 117
//#define NOTE_B2  123
//#define NOTE_C3  131
//#define NOTE_CS3 139
//#define NOTE_D3  147
//#define NOTE_DS3 156
//#define NOTE_E3  165
//#define NOTE_F3  175
//#define NOTE_FS3 185
//#define NOTE_G3  196
//#define NOTE_GS3 208
//#define NOTE_A3  220
//#define NOTE_AS3 233
//#define NOTE_B3  247
//#define NOTE_C4  262
//#define NOTE_CS4 277
//#define NOTE_D4  294
//#define NOTE_DS4 311
//#define NOTE_E4  330
//#define NOTE_F4  349
//#define NOTE_FS4 370
//#define NOTE_G4  392
//#define NOTE_GS4 415
//#define NOTE_A4  440
//#define NOTE_AS4 466
//#define NOTE_B4  494
//#define NOTE_C5  523
//#define NOTE_CS5 554
//#define NOTE_D5  587
//#define NOTE_DS5 622
//#define NOTE_E5  659
//#define NOTE_F5  698
//#define NOTE_FS5 740
//#define NOTE_G5  784
//#define NOTE_GS5 831
//#define NOTE_A5  880
//#define NOTE_AS5 932
//#define NOTE_B5  988
//#define NOTE_C6  1047
//#define NOTE_CS6 1109
//#define NOTE_D6  1175
//#define NOTE_DS6 1245
//#define NOTE_E6  1319
//#define NOTE_F6  1397
//#define NOTE_FS6 1480
//#define NOTE_G6  1568
//#define NOTE_GS6 1661
//#define NOTE_A6  1760
//#define NOTE_AS6 1865
//#define NOTE_B6  1976
//#define NOTE_C7  2093
//#define NOTE_CS7 2217
//#define NOTE_D7  2349
//#define NOTE_DS7 2489
//#define NOTE_E7  2637
//#define NOTE_F7  2794
//#define NOTE_FS7 2960
//#define NOTE_G7  3136
//#define NOTE_GS7 3322
//#define NOTE_A7  3520
//#define NOTE_AS7 3729
//#define NOTE_B7  3951
//#define NOTE_C8  4186
//#define NOTE_CS8 4435
//#define NOTE_D8  4699
//#define NOTE_DS8 4978
//
//
//}
