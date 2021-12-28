#include <Adafruit_NeoPixel.h>
#define PIN       2 // 信号用のピンを指定
#define NUMPIXELS 24 // LEDの数を指定

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);


int analogIn[] = {A0, A1, A2}; //A, B, C

int ApickOut = 5; //1
int BpickOut = 6; //2
int CpickOut = 7; //4

int binary[] = {(0, 0, 0), (0, 0, 1), (0, 1, 0), (0, 1, 1), (1, 0, 0), (1, 0, 1), (1, 1, 0), (1, 1, 1)};
int lineValue[24];


void setup() {
  for (int i = 0; i <= 3; i++) {
    pinMode(analogIn[i], INPUT);
  }
  pinMode(ApickOut, OUTPUT);
  pinMode(BpickOut, OUTPUT);
  pinMode(CpickOut, OUTPUT);

  pixels.begin();
  boot_led();

  Serial.begin(38400);
  line_led();
}


void loop() {
  int value = line_read();
  //Serial.println(value);

  line_choice(7);
}


int line_read() {

  for (int i = 0; i <= 7; i++) {
    line_choice(i);
    lineValue[i] = analogRead(analogIn[0]);
    lineValue[i + 8] = analogRead(analogIn[1]);
    lineValue[i + 16] = analogRead(analogIn[2]);
  }

  for (int i = 0; i <= 23; i++) {
    lineValue[i] = lineValue[i] >= 500 ? 1 : 0;
    Serial.print(lineValue[i]);
    Serial.print(" ");
  }
  Serial.println();

  int goAngle = 0;
  return goAngle;
}

void line_choice(int choice) {
  int choice_output[3];

  switch (choice) {
    case 0:
      choice_output[2] = 0;
      choice_output[1] = 0;
      choice_output[0] = 0;
      break;
    case 1:
      choice_output[2] = 0;
      choice_output[1] = 0;
      choice_output[0] = 1;
      break;
    case 2:
      choice_output[2] = 0;
      choice_output[1] = 1;
      choice_output[0] = 0;
      break;
    case 3:
      choice_output[2] = 0;
      choice_output[1] = 1;
      choice_output[0] = 1;
      break;
    case 4:
      choice_output[2] = 1;
      choice_output[1] = 0;
      choice_output[0] = 0;
      break;
    case 5:
      choice_output[2] = 1;
      choice_output[1] = 0;
      choice_output[0] = 1;
      break;
    case 6:
      choice_output[2] = 1;
      choice_output[1] = 1;
      choice_output[0] = 0;
      break;
    case 7:
      choice_output[2] = 1;
      choice_output[1] = 1;
      choice_output[0] = 1;
      break;
      //default:
  }

  if (choice_output[0] == 1) {
    digitalWrite(ApickOut, HIGH);
  } else {
    digitalWrite(ApickOut, LOW);
  }

  if (choice_output[1] == 1) {
    digitalWrite(BpickOut, HIGH);
  } else {
    digitalWrite(BpickOut, LOW);
  }

  if (choice_output[2] == 1) {
    digitalWrite(CpickOut, HIGH);
  } else {
    digitalWrite(CpickOut, LOW);
  }
}
