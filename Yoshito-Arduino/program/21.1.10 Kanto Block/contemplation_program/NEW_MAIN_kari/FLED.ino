#include <Adafruit_NeoPixel.h>

const int FULL_LED = 40;
const int FULL_LED_NUM = 31;
Adafruit_NeoPixel FRAME(FULL_LED_NUM, FULL_LED, NEO_GRB + NEO_KHZ800);

const int fled_current = 50; //電流制限(0-255)



void F_fled_setup() {
  FRAME.begin();
  FRAME.setBrightness(fled_current);
}

void F_fled_start() {
  FRAME.clear();
}

void F_fled_finish() {
  FRAME.show();
}



void F_fled_RGB_show(int r, int g, int b) {
  for (int i = 0; i < FULL_LED_NUM; i++) {
    FRAME.setPixelColor(i, FRAME.Color(r, g, b));
  }
}


void F_fled_angle_show(int angle,int r, int g, int b) {
  FRAME.setPixelColor(F_angle_trans_num(angle), FRAME.Color(r, g, b));
}












int F_angle_trans_num(int angle) {
  int num;
  if (1 <= angle && angle <= 30) {
    num = 0;
  } else if (angle <= 45) {
    num = 1;
  } else if (angle <= 54) {
    num = 2;
  } else if (angle <= 57) {
    num = 3;
  } else if (angle <= 64) {
    num = 4;
  } else if (angle <= 74) {
    num = 5;
  } else if (angle <= 90) {
    num = 6;
  } else if (angle <= 102) {
    num = 7;
  } else if (angle <= 114) {
    num = 8;
  } else if (angle <= 126) {
    num = 9;
  } else if (angle <= 138) {
    num = 10;
  }

  else if (angle <= 141) {
    num = 11;
  } else if (angle <= 145) {
    num = 12;
  } else if (angle <= 155) {
    num = 13;
  } else if (angle <= 165) {
    num = 14;
  } else if (angle <= 175) {
    num = 15;
  } else if (angle <= 185) {
    num = 16;
  } else if (angle <= 195) {
    num = 17;
  } else if (angle <= 205) {
    num = 18;
  } else if (angle <= 215) {
    num = 19;
  } else if (angle <= 222) {
    num = 20;
  } else if (angle <= 245) {
    num = 21;
  }

  else if (angle <= 257) {
    num = 22;
  } else if (angle <= 264) {
    num = 23;
  } else if (angle <= 281) {
    num = 24;
  } else if (angle <= 293) {
    num = 25;
  } else if (angle <= 305) {
    num = 26;
  } else if (angle <= 317) {
    num = 27;
  } else if (angle <= 320) {
    num = 28;
  } else if (angle <= 324) {
    num = 29;
  } else if (angle <= 354) {
    num = 30;
  }else{
    num = 100;
  }

  num = 30 -num;

  return num;

}
