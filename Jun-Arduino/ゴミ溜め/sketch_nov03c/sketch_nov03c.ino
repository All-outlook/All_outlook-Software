#include <Adafruit_NeoPixel.h>
const int A_PIN = 2;
const int B_PIN = 3;
const int C_PIN = 4;
const int LED_PIN = 5;
const int MULTIPLEXER[] = {A0, A1, A2, A3};

int line_count[32];
int LED_count = 32;
Adafruit_NeoPixel pixels(LED_count, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(38400);
  for (int id = 0; id <= 3; id++) {
    pinMode(MULTIPLEXER[id], INPUT);
  }
  pinMode(A_PIN, OUTPUT);
  pinMode(B_PIN, OUTPUT);
  pinMode(C_PIN, OUTPUT);

  pixels.begin();
  pixels.clear();
  for (int id = 0; id <= 31; id++) {
    pixels.setPixelColor(id, pixels.Color(128, 0, 0));
  }
  pixels.show();
}


void loop() {
  int value = line_read();
  /*for (int i = 0 ; i <= 7; i++ ) {
    line_choice(i);
    Serial.print("    ");
    Serial.print(i);
    Serial.print(":");
    Serial.print(analogRead(line_count[0]));
    Serial.print(" ");
    Serial.print(analogRead(line_count[1]));
    Serial.print(" ");
    Serial.print(analogRead(line_count[2]));
    Serial.print(" ");
    Serial.print(analogRead(line_count[3]));
    //delay(10);
  }
  Serial.println();
*/
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
