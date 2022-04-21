
#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel pixels(1, 6, NEO_GRB + NEO_KHZ800);


void setup() {

  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  Serial.begin(115200);

  pinMode(A0, INPUT);

}

int read_value[50] = {0, 0, 0, 0, 0,0, 0, 0, 0, 0};
void loop() {
  pixels.clear();
  pixels.setPixelColor(0, pixels.Color(100, 1, 1));
pixels.setBrightness(255);
  pixels.show();

  for (int i = 0; i < 49; i++) {
    read_value[i + 1] = read_value[i];
  }
  read_value[0] = analogRead(A0);

  int sum = 0;
  for (int i = 0; i < 50; i++) {
    sum += read_value[i];
  }
  Serial.print(sum / 50);
  Serial.print("       ");
  Serial.println(read_value[0]);
}
