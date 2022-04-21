


//const int MOTOR_A[] = {6, 5};
const int MOTOR_A[] = {11, 3};
const int MOTOR_B[] = {10, 9};

const int M_LED_A[] = {14, 15};
const int M_LED_B[] = {16, 17};

//const int LED[] = {2, 3, 4};
const int LED[] = {2, 12, 4};



void setup() {
  for (int i = 0; i < 2; i++) {
    pinMode(MOTOR_A[i], OUTPUT);
    pinMode(MOTOR_B[i], OUTPUT);
    pinMode(M_LED_A[i], OUTPUT);
    pinMode(M_LED_B[i], OUTPUT);
  }


  TCCR1B &= B11111000;
  TCCR1B |= B00000001;

  TCCR2B &= B11111000;
  TCCR2B |= B00000001;


//  TCCR1B &= B11111000;
//  TCCR1B |= B00000101;
//
//  TCCR2B &= B11111000;
//  TCCR2B |= B00000111;

}

void loop() {
  int myspeed = 100;
  if (false) {
    digitalWrite(MOTOR_A[0], LOW);
    analogWrite(MOTOR_A[1], myspeed);
    digitalWrite(M_LED_A[0], LOW);
    digitalWrite(M_LED_A[1], HIGH);

    digitalWrite(MOTOR_B[0], LOW);
    analogWrite(MOTOR_B[1], myspeed);
    digitalWrite(M_LED_B[0], LOW);
    digitalWrite(M_LED_B[1], HIGH);
  } else {
    digitalWrite(MOTOR_A[1], LOW);
    analogWrite(MOTOR_A[0], myspeed);
    digitalWrite(M_LED_A[0], LOW);
    digitalWrite(M_LED_A[1], HIGH);

    digitalWrite(MOTOR_B[1], LOW);
    analogWrite(MOTOR_B[0], myspeed);
    digitalWrite(M_LED_B[0], LOW);
    digitalWrite(M_LED_B[1], HIGH);
  }


}
