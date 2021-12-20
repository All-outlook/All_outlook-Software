#include <Adafruit_NeoPixel.h>
const int DIN_PIN = 10; // D10
const int LED_COUNT = 20; // LEDの数
Adafruit_NeoPixel pixels(LED_COUNT, DIN_PIN, NEO_GRB + NEO_KHZ800);

#define echoPin 11
#define trigPin 12
double Duration = 0;
double Distance = 0;

void setup() {
  pixels.begin();
  Serial.begin(38400);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  Duration = pulseIn(echoPin, HIGH);

  if (Duration > 0) {
    Duration = Duration / 2;
    Distance = Duration * 340 * 100 / 1000000;
    Serial.print("Distance:");
    Serial.print(Distance);
    Serial.println("cm");

    if (Distance > 30 && Distance <= 50) {
      for (int i = 0; i < LED_COUNT; i++)
        pixels.setPixelColor(i, pixels.Color(10, 0, 0));
      pixels.show();

    }else if (Distance > 20 && Distance <= 30) {
        for (int i = 0; i < LED_COUNT; i++)
          pixels.setPixelColor(i, pixels.Color(0, 10, 0));
        pixels.show();

      } else if (Distance > 10 && Distance <= 20) {
        for (int i = 0; i < LED_COUNT; i++)
          pixels.setPixelColor(i, pixels.Color(0, 0, 10));
        pixels.show();

      } else if (Distance > 0 && Distance <= 10) {
        for (int i = 0; i < LED_COUNT; i++)
          pixels.setPixelColor(i, pixels.Color(20, 20, 20));
        pixels.show();

      } else {
        for (int i = 0; i < LED_COUNT; i++)
          pixels.setPixelColor(i, pixels.Color(0, 0, 0));
        pixels.show();
      }
    }
  }
