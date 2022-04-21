
#include <SoftwareSerial.h>
SoftwareSerial mySerial(8, 18); // RX, TX

//const int MOTOR_A[] = {6, 5};
const int MOTOR_A[] = {11, 3};
const int MOTOR_B[] = {10, 9};

const int M_LED_A[] = {14, 15};
const int M_LED_B[] = {16, 17};

//const int LED[] = {2, 3, 4};
const int LED[] = {2, 12, 4};

void setup() {
//  Serial.begin(115200);
  mySerial.begin(57600);
  pinMode(8, INPUT);

  for (int i = 0; i < 2; i++) {
    pinMode(MOTOR_A[i], OUTPUT);
    pinMode(MOTOR_B[i], OUTPUT);
    pinMode(M_LED_A[i], OUTPUT);
    pinMode(M_LED_B[i], OUTPUT);
  }
  for (int i = 0; i < 3; i++) {
    pinMode(LED[i], OUTPUT);
  }

  start();
}

int id = 0;
int rotation = 1;
int pre_rotation = 1;
int myspeed = 40;

void loop() {
  //  F_time_read();
  if (mySerial.available()) {
    for ( int nnn = 0; nnn < 2; nnn++) {
      int knob = mySerial.read();
//      Serial.print(' ');
//      Serial.print(knob);

      if (knob < 35) {
        id = knob % 10;
        rotation = knob / 10;
        if (rotation == 0 || rotation == 3) {
          nnn++;
        }
        pre_rotation = rotation;
      } else {
        myspeed = knob;
        nnn++;
      }
    }
  }
//  Serial.println();
//  Serial.print("------ id");
//  Serial.print(id);
//  Serial.print(" rotation");
//  Serial.print(rotation);
//
//  Serial.print(" speed");
//  Serial.println(myspeed);

  //rotationの急速切り替えを防ぐ----------------
  if ((rotation == 1 && pre_rotation == 2) || (rotation == 2 && pre_rotation == 1)) {
    rotation = 3;
  }
  // ------------------------------------------ -

  if (id == 0 || id == 2) {
    //D5,D6(Timer0のためデューティー比高め)
    myspeed = map(myspeed,40,254,40,254);
    //------------------------------------
    if (rotation == 0) {
      digitalWrite(MOTOR_A[0], LOW);
      digitalWrite(MOTOR_A[1], LOW);
      digitalWrite(M_LED_A[0], LOW);
      digitalWrite(M_LED_A[1], LOW);
      for (int i = 0; i < 3; i++) {
        digitalWrite(LED[i], HIGH);
      }
    } else if (rotation == 1) {
      analogWrite(MOTOR_A[0], myspeed);
      digitalWrite(MOTOR_A[1], LOW);
      digitalWrite(M_LED_A[0], HIGH);
      digitalWrite(M_LED_A[1], LOW);

      digitalWrite(LED[0], LOW);
      digitalWrite(LED[1], LOW);
    } else if (rotation == 2) {
      digitalWrite(MOTOR_A[0], LOW);
      analogWrite(MOTOR_A[1], myspeed);
      digitalWrite(M_LED_A[0], LOW);
      digitalWrite(M_LED_A[1], HIGH);

      digitalWrite(LED[0], LOW);
      digitalWrite(LED[1], LOW);
    } else if (rotation == 3) {
      digitalWrite(MOTOR_A[0], LOW);
      digitalWrite(MOTOR_A[1], LOW);
      digitalWrite(M_LED_A[0], HIGH);
      digitalWrite(M_LED_A[1], HIGH);

      digitalWrite(LED[0], HIGH);
      digitalWrite(LED[1], LOW);
    }
    //------------------------------------
  } else if (id ==  1 || id == 3) {
    myspeed = map(myspeed,40,254,40,254);
    if (rotation == 0) {
      digitalWrite(MOTOR_B[0], LOW);
      digitalWrite(MOTOR_B[1], LOW);
      digitalWrite(M_LED_B[0], LOW);
      digitalWrite(M_LED_B[1], LOW);
      for (int i = 0; i < 3; i++) {
        digitalWrite(LED[i], HIGH);
      }

    } else if (rotation == 1) {
      analogWrite(MOTOR_B[0], myspeed);
      digitalWrite(MOTOR_B[1], LOW);
      digitalWrite(M_LED_B[0], HIGH);
      digitalWrite(M_LED_B[1], LOW);

      digitalWrite(LED[2], LOW);
      digitalWrite(LED[1], LOW);

    } else if (rotation == 2) {
      digitalWrite(MOTOR_B[0], LOW);
      analogWrite(MOTOR_B[1], myspeed);
      digitalWrite(M_LED_B[0], LOW);
      digitalWrite(M_LED_B[1], HIGH);

      digitalWrite(LED[2], LOW);
      digitalWrite(LED[1], LOW);

    } else if (rotation == 3) {
      digitalWrite(MOTOR_B[0], LOW);
      digitalWrite(MOTOR_B[1], LOW);
      digitalWrite(M_LED_B[0], HIGH);
      digitalWrite(M_LED_B[1], HIGH);

      digitalWrite(LED[2], HIGH);
      digitalWrite(LED[1], LOW);
    }
  }
}
