#include <SoftwareSerialParity.h>

#include <SPI.h>
SoftwareSerialParity mySerial(31, 7);//rx,tx

const int LED_PIN[] = {2, 3, 4};
const int MT_R_PIN = 5;
const int MT_L_PIN = 6;
const int DIP_SWITCH[] = {14, 15, 16, 17};
int rotation;
int myspeed;
int knob;
int recieve_value;


void setup() {
  Serial.begin(38400);
  SPCR |= bit(SPE);
  pinMode(MISO, OUTPUT);

  SPI.attachInterrupt();
  pinMode(MISO, INPUT);
  pinMode(MOSI, INPUT);
  pinMode(SCK, INPUT);

  pinMode(MT_R_PIN, OUTPUT);
  pinMode(MT_L_PIN, OUTPUT);
  for (int id = 0; id <= 2; id++) {
    pinMode(LED_PIN[id], OUTPUT);
  }
  for (int id = 0; id <= 3; id++) {
    pinMode(DIP_SWITCH[id], INPUT);
  }

  //ソフトシリアル
  pinMode(31, INPUT);
  pinMode(7, OUTPUT);
  mySerial.begin(38400, ODD);

}

void loop() {
  UART_Receive();

  //rotation = 0; myspeed = 0;
  if (rotation == 10) { //worward
    analogWrite(MT_R_PIN, 0);
    analogWrite(MT_L_PIN, myspeed);

  } else if (rotation == 20) { //reversal
    analogWrite(MT_R_PIN, myspeed);
    analogWrite(MT_L_PIN, 0);

  } else if (rotation == 30) { //stop
    digitalWrite(MT_R_PIN, LOW);
    digitalWrite(MT_L_PIN, LOW);

  } else if (rotation == 40) { //brake
    digitalWrite(MT_R_PIN, HIGH);
    digitalWrite(MT_L_PIN, HIGH);

  } else if (rotation == 0) {} //error




//  if (digitalRead(DIP_SWITCH[0]) == HIGH) {
//    recieve_value = 100;
//  } else if (digitalRead(DIP_SWITCH[1]) == HIGH) {
//    recieve_value = 110;
//  } else if (digitalRead(DIP_SWITCH[2] ) == HIGH) {
//    recieve_value = 120;
//  } else if (digitalRead(DIP_SWITCH[3]) == HIGH) {
//    recieve_value = 130;
//  } else {
//    recieve_value = 200;
//  }



  //Serial.print('r'); //LEDが弱くなる
  //Serial.print(rotation);
  //Serial.print('s');
  //Serial.print(myspeed);
  //Serial.print('i');
  //Serial.println(recieve_value);

}
void UART_Receive() {
  if ( mySerial.available() ) {       // 受信データがあるか？

    int knob = mySerial.read();
    Serial.println(knob);
    if (knob == 0) {
      //nothing
    } else if (knob == 10 | knob == 20 | knob == 30 | knob == 40) {
      rotation = knob;
    } else {
      myspeed = knob;
    }

    //Serial.println(knob);
  } else {
    //Serial.println("no_data");
  }
}


//void UART_Receifdddve() {
//  if ( mySerial.available() ) {       // 受信データがあるか？
//
//    String str = mySerial.readStringUntil('&');
//
//    int knob = str.toInt();
//
//    while(Serial.available() > 0){
//      char t = Serial.read();
//    }
//
//    if (knob == 0) {
//      //nothing
//    } else if (knob == 10 | knob == 20 | knob == 30 | knob == 40) {
//      rotation = knob;
//    } else {
//      myspeed = knob;
//    }
//
//    Serial.println(knob);
//  } else {
//    //Serial.println("no_data");
//  }
//}


ISR(SPI_STC_vect) {
  int dummy = SPDR;
  //SPDR = recieve_value;
}
