#include <SPI.h>
void setup() {
  Serial.begin(9600);
  SPI.begin();
  digitalWrite(SS, HIGH);
}


void loop() {
  int knob;
  int degree;

  knob = 'A';
  digitalWrite(SS, LOW); //送信
  SPI.transfer(knob);
  digitalWrite(SS, HIGH);
  delayMicroseconds(100);

  digitalWrite(SS, LOW); //受信
  degree = SPI.transfer(0);
  digitalWrite(SS, HIGH);
  degree *= 2;

  Serial.print("knob:"); Serial.print(knob);
  Serial.print(", degree:");
    Serial.print(degree); Serial.println("°");
 // }
}
