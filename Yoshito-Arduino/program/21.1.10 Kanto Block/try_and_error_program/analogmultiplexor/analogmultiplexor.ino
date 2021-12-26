#include <Adafruit_NeoPixel.h>
const int A_PIN = 2;
const int B_PIN = 3;
const int C_PIN = 4;
const int AMP_PIN[] = {A0, A1, A2, A3}; //AMP = Analog Multi Plexor

const int LED_PIN = 5;
const int C_LED_count = 32;
Adafruit_NeoPixel pixels(C_LED_count, LED_PIN, NEO_GRB + NEO_KHZ800);

int id;
int line_value[32];
const int C_line_threshold = 350;
int line_digits[32];

void setup() {
  F_time_read();
  Serial.begin(115200);
  F_AMP_setup();
  F_LED_setup(60, 60, 60);
}

void loop() {

  F_LED_loop(128, 1, 1);
  for (int id = 0; id <= 7; id++) {
    F_line_choice(id);
    line_value[id] = analogRead(AMP_PIN[0]); //0-7
    line_value[id + 8] = analogRead(AMP_PIN[1]); //8-15
    line_value[id + 16] = analogRead(AMP_PIN[2]); //15-23
    line_value[id + 24] = analogRead(AMP_PIN[3]); //24-31
  }
  for (id = 0; id <= 31; id++) {
    Serial.print(line_value[id]);
    Serial.print(",");
  }

  for (id = 0; id <= 31; id++) {
    if (line_value[id] >= C_line_threshold) {
      line_digits[id] = 1;
    } else {
      line_digits[id] = 0;
    }
    //        Serial.print(line_digits[id]);
    //        Serial.print(",");
  }

  Serial.println();
}
