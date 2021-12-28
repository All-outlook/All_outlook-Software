#include <Adafruit_NeoPixel.h>
#define PIN       2 // 信号用のピンを指定
#define NUMPIXELS 24 // LEDの数を指定

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);


int line_read_pin[] = {A0, A1, A2}; //A, B, C

int select1[] = {5, 8, 11};// A, B, C
int select2[] = {6, 9, 12};// A, B, C
int select3[] = {7, 10, 13};// A, B, C


void setup() {
  for (int i = 0; i <= 3; i++) {
    pinMode(line_read[i], INPUT);
    pinMode(select1[i], OUTPUT);
    pinMode(select2[i], OUTPUT);
    pinMode(select3[i], OUTPUT);
  }
  
  pixels.begin();
  boot_led();

  Serial.begin(38400);
}


void loop() {
  line_led();
  int value = line_read(16);
  Serial.println(value);

}


int line_read(int input_pin) {
  int pin;
  int id;
  int value;

  if (input_pin <= 7) { // A
    pin = input_pin;
    id = 0;
  } else if (input_pin <= 15) { // B
    pin = (input_pin - 8);
    id = 1;
  } else if (input_pin <= 15) { // C
    pin = (input_pin - 16);
    id = 2;
  }

  line_choice(id, pin);
  value = analogRead(line_read_pin[id]);

  return value;
}












void line_choice(int id, int pin) {
  int choice_output[3];

  switch (pin) {
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


  if (choice_output[2] == 1) {
    digitalWrite(select3[id], 1);
  } else {
    digitalWrite(select3[id], 0);
  }
  
  if (choice_output[1] == 1) {
    digitalWrite(select2[id], 1);
  } else {
    digitalWrite(select2[id], 0);
  }
  
  if (choice_output[0] == 1) {
    digitalWrite(select1[id], 1);
  } else {
    digitalWrite(select1[id], 0);
  }
}












void line_led() {
  pixels.clear();
  for (int id = 0; id <= 23; id += 1) {
    pixels.setPixelColor(id, pixels.Color(250, 0, 0));
  }
  pixels.show();
}
