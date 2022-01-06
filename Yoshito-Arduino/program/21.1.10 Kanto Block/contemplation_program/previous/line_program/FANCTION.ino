
#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel LINE_PIXLES(LED_NUM, LED_PIN, NEO_GRB + NEO_KHZ800);

const int fled_current = 150; //電流制限(0-255)


void F_line_setup() {
  for (int id = 0; id <= 3; id++) {
    pinMode(READ_PIN[id], INPUT);
  }
  pinMode(A_PIN, OUTPUT);
  pinMode(B_PIN, OUTPUT);
  pinMode(C_PIN, OUTPUT);
}


void F_pixle_setup(int r, int g, int b) {
  LINE_PIXLES.begin();
  LINE_PIXLES.setBrightness(fled_current);
  LINE_PIXLES.clear();
  for (int id = 0; id <= 31; id++) {
    LINE_PIXLES.setPixelColor(id, LINE_PIXLES.Color(r, g, b));
  }
  LINE_PIXLES.show();
}


int F_line_read() {


  int go_degree = 0;
  return go_degree;
}


void F_line_choice(int choice) {
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

  if (choice_output[2] == 1) {
    digitalWrite(C_PIN, 1);
  } else {
    digitalWrite(C_PIN, 0);
  }

  if (choice_output[1] == 1) {
    digitalWrite(B_PIN, 1);
  } else {
    digitalWrite(B_PIN, 0);
  }

  if (choice_output[0] == 1) {
    digitalWrite(A_PIN, 1);
  } else {
    digitalWrite(A_PIN, 0);
  }
}
