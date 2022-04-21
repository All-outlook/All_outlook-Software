//#include <SPI.h>
#include <SoftwareSerial.h>

const int A_PIN = 2;
const int B_PIN = 3;
const int C_PIN = 4;
const int LED_PIN = 5;
const int LED_NUM = 32;
const int READ_PIN[] = {A0, A1, A2, A3};

const int C_BORDER_WHITE_LINE = 250;


int line_value[32];

SoftwareSerial LINESerial(7, 10); //rx,tx


void setup() {
  Serial.begin(115200);
  LINESerial.begin(38400);
  pinMode(10,OUTPUT);
  F_line_setup();
}


int go_angle;

void loop() {
  F_pixle_setup(250, 1, 1);
  
//  SPCR |= bit(SPE);
//  pinMode(MISO, OUTPUT);
//  SPI.attachInterrupt();
  for (int id = 0; id <= 7; id++) {
    F_line_choice(id);
    line_value[id] = analogRead(READ_PIN[0]);
    line_value[id + 8] = analogRead(READ_PIN[1]);
    line_value[id + 16] = analogRead(READ_PIN[2]);
    line_value[id + 24] = analogRead(READ_PIN[3]);
  }

//  Serial.print("Moto_value       : ");
  for (int id = 0; id <= 31; id++) {
    Serial.print(id);
    Serial.print(":");
    Serial.print(line_value[id]);
    Serial.print(" ");
  }
  Serial.println();


  LINESerial.write(go_angle);
  LINESerial.flush();
}
