#include <SPI.h>

const int RESET_PIN[] = {2, 3, 4, 5, 6, 7, 8, 10};

const int KICKER_PIN = 11; // HIGH 打つ  LOW 打たない
const int KICKER_CUT_PIN = 9; // キッカー絶縁用 HIGH 絶縁  LOW 充電
const int CAPTURE_PIN[] = {A7, A8};

const int BUZZER = 35;
const int TOGGLE_PIN = 41;
const int LED_PIN[] = {30, 31, 32, 33};

const int SS_IR = 56;
const int SS_LINE = 57;

void setup() {
  Serial.begin(115200);
  Serial2.begin(9600);
  SPI.begin();

  all_reset();
  Serial_setup();
  DISPLAY_LED_setup();

  pinMode(BUZZER, OUTPUT);
  pinMode(CAPTURE_PIN[0], INPUT);
  pinMode(CAPTURE_PIN[1], INPUT);
  pinMode(TOGGLE_PIN, INPUT);

  pinMode(SS_IR, OUTPUT);
  digitalWrite(SS_IR, HIGH);
  pinMode(SS_LINE, OUTPUT);
  digitalWrite(SS_LINE, HIGH);
}

void loop() {
  if (digitalRead(TOGGLE_PIN) == 0) {
    //スタートスイッチON
    F_full_led_setup(0, 30, 0);
    LED_WRITE(0);

    //IRセンサ
    //値取得から回り込み角度まで。
    int IR_degree = wrap_around(SPI_IR_degree());
    UART_gyro_degree();//オーバーフロー対策

    //ラインセンサ
    //値取得 値=進行方向 0のときはラインなし
    int line_degree = 2 * SPI_line_degree();
    UART_gyro_degree();//オーバーフロー対策

    //ジャイロセンサ
    //値取得からモーターへのパワー計算まで
    //パワー 0,100-200
    int gyro_power = Gyro_attitude(UART_gyro_degree());

    //Serial.print(IR_degree);
    //Serial.print(',');
    //Serial.print(line_degree);
    //Serial.print(',');
    Serial.println(UART_gyro_degree());
    //Serial.print(',');
    //Serial.println(gyro_power);

    //---ここからモーター---
    //1,角度(ライン、IR)からスピード計算
    //2,角度(ジャイロ)からスピード計算
    //3,スピードを足し合わせる
    //4,正負が切り替わるタイミングだった場合、数秒間補正かける
    //5,スピード値をコマンドに変換して送信
    for (int i = 0; i <= 3; i++) {
      //1
      
      //2
      int speed_gyro[i] = gyro_power;
      //3

      //4
      int MT_speed[i] = speed_gyro[i];
      
      //5
      speed_send(i, MT_speed[i]);
    }

  } else if (digitalRead(TOGGLE_PIN) == 1) {
    //スタートスイッチOFF
    F_full_led_setup(30, 0, 0);
    LED_WRITE(1);

    UART_gyro_degree();//オーバーフロー対策

    for (int i = 0; i <= 3; i++) {
      speed_send(i, 0);
    }

  }
}


void all_reset() {
  for (int id = 0; id <= 7; id++) {
    pinMode(RESET_PIN[id], OUTPUT);
    digitalWrite(RESET_PIN[id], HIGH);
    digitalWrite(RESET_PIN[id], LOW);
    digitalWrite(RESET_PIN[id], HIGH);
  }
}
