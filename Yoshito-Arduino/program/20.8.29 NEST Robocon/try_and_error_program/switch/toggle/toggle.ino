int const LED = 13;
int button = 7;

int val;
int val0ld;
boolean state;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(button, INPUT);
}

void loop() {

  val = digitalRead(button);

  if ((val == HIGH) && (val0ld == LOW)) {
    state = !state;
  }

  val0ld = val;

  if (state == HIGH) {
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }
  delay(10);
}
