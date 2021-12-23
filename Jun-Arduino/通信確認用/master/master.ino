/**********************************************
  Arduino SPI(Master) com8
**********************************************/
#include <SPI.h>

int mySS[] = {56, 53, 55, 54, 57, 59, 58};
int myLED[] = {30, 31, 32, 33};

//SPISettings mySPISettings = SPISettings(400000, MSBFIRST, SPI_MODE0);


void setup() {
  Serial.begin(38400);
  Serial.println("/-----START Arduino nano-----/");
  Serial.println("/---------SPI Master--------/");

  SPI.begin();
//  SPI.beginTransaction(mySPISettings);

  for (int i = 0; i <= 6 ; i++) {
    pinMode(mySS[i], OUTPUT);
    digitalWrite(mySS[i], HIGH);
  }
}



void loop() {
  for (int n = 0; n <= 5; n++) {
    for (int i = 100; i <= 150; i++) {
      SPI_send(10);
      SPI_send(i);
      SPI_send(i);
      write_LED(0);
    }

    write_LED(1);
    for (int i = 0; i < 10; i++) {
      SPI_send(40);
    }

    for (int i = 100; i <= 150; i++) {
      SPI_send(20);
      SPI_send(i);
      SPI_send(i);
      write_LED(2);
    }

    write_LED(3);
    for (int i = 0; i < 10; i++) {
      SPI_send(40);
    }
  }

  for (int n = 0; n <= 100; n++) {
      SPI_send(40);
  }
}


void SPI_send(int knob) {
  byte rxdata;
  //Serial.print(knob);
  for (int i = 0; i <= 6; i++) {
    //int i = 6;
    digitalWrite(mySS[i], LOW);
    //delayMicroseconds(5);
    SPI.transfer(knob);
    digitalWrite(mySS[i], HIGH);
    delayMicroseconds(5);
    digitalWrite(mySS[i], LOW);
    //delayMicroseconds(5);
    rxdata = SPI.transfer(0);
    digitalWrite(mySS[i], HIGH);

    //Serial.print(" id:");
    //Serial.print(i);
    Serial.print('a');
    Serial.print(rxdata);
  }
  Serial.println();
}


void write_LED(int j) {
  for (int i = 0; i <= 3; i++) {
    pinMode(myLED[i], OUTPUT);
    digitalWrite(myLED[i], LOW);
  }
  digitalWrite(myLED[j], HIGH);
}
