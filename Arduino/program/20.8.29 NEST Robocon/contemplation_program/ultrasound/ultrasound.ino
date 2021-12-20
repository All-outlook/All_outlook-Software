/*Ultrasounnd
   ATTiny85-20SUR
  by Yoshito*/
#include <SPI.h>

#define echoPin 1
#define trigPin 2
double duration = 0;
double distance = 0;

void setup() {
  SPCR |= bit(SPE);
  pinMode(MISO, OUTPUT);
  SPI.attachInterrupt();
  Serial.begin(9600);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
}
void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);

  if (duration > 0) {
    duration = duration / 2;
    distance = duration * 340 * 100 / 1000000;
    Serial.print("distance:");
    Serial.print(distance);
    Serial.println("cm");
  }

  byte rxdata;
  ISR(SPI_STC_vect) {
    rxdata = SPDR; //konbからきた値をrxdataに入れる
    if (rxdata == 'A') {
      if (distance >= 0 & distance < 50) {
        SPDR = '1';

      } else if (distance >= 50 & distance < 100) {
        SPDR = '2';

      } else if (distance >= 100 & distance < 150) {
        SPDR = '3';

      } else if (distance >= 150 & distance < 200) {
        SPDR = '4';

      } else if (distance >= 200) {
        SPDR = '5';
      }
    }
  }
