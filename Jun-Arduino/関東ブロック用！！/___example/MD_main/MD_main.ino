
#include <SoftwareSerial.h>
SoftwareSerial mySerial(8, 18); // RX, TX

const int MOTOR_A[] = {5, 6};
const int MOTOR_B[] = {9, 10};

const int M_LED_A[] = {14, 15};
const int M_LED_B[] = {16, 17};

const int LED[] = {2, 3, 4};

void setup() {
  Serial.begin(115200);
  mySerial.begin(38400);
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
}

int id = 0;
int rotation = 3;
int myspeed = 40;

void loop() {
  if (mySerial.available()) {
    int knob = mySerial.read();
    Serial.println(knob);

    if (knob < 35) {
      id = knob % 10;
      rotation = knob / 10;
    } else {
      myspeed = knob;
    }
  }

  if (id == 0 || id == 2) {
    //------------------------------------
    if (rotation == 0) {
      digitalWrite(MOTOR_A[0], 1);
      digitalWrite(MOTOR_A[1], 1);
      digitalWrite(M_LED_A[0], 0);
      digitalWrite(M_LED_A[1], 0);
    } else if (rotation == 1) {
      analogWrite(MOTOR_A[0], myspeed);
      digitalWrite(MOTOR_A[1], 0);
      digitalWrite(M_LED_A[0], 1);
      digitalWrite(M_LED_A[1], 0);
    } else if (rotation == 2) {
      digitalWrite(MOTOR_A[0], 0);
      analogWrite(MOTOR_A[1], myspeed);
      digitalWrite(M_LED_A[0], 0);
      digitalWrite(M_LED_A[1], 1);
    } else if (rotation == 3) {
      digitalWrite(MOTOR_A[0], 0);
      digitalWrite(MOTOR_A[1], 0);
      digitalWrite(M_LED_A[0], 1);
      digitalWrite(M_LED_A[1], 1);
    }
    //------------------------------------
  } else if (id ==  1 || id == 3) {
    if (rotation == 0) {
      digitalWrite(MOTOR_B[0], 1);
      digitalWrite(MOTOR_B[1], 1);
      digitalWrite(M_LED_B[0], 0);
      digitalWrite(M_LED_B[1], 0);
    } else if (rotation == 1) {
      analogWrite(MOTOR_B[0], myspeed);
      digitalWrite(MOTOR_B[1], 0);
      digitalWrite(M_LED_B[0], 1);
      digitalWrite(M_LED_B[1], 0);
    } else if (rotation == 2) {
      digitalWrite(MOTOR_B[0], 0);
      analogWrite(MOTOR_B[1], myspeed);
      digitalWrite(M_LED_B[0], 0);
      digitalWrite(M_LED_B[1], 1);
    } else if (rotation == 3) {
      digitalWrite(MOTOR_B[0], 0);
      digitalWrite(MOTOR_B[1], 0);
      digitalWrite(M_LED_B[0], 1);
      digitalWrite(M_LED_B[1], 1);
    }
  }
}
