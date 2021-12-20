int button = 7;

int val;
int val0ld;
boolean state;

void setup() {
  Serial.begin(9600);
  pinMode(button, INPUT);
}

void loop() {
  val = digitalRead(button);
  if(val == HIGH){
    state = !state;
  }
  val0ld = val;

  if (state == HIGH) {
    Serial.write("o");
  } else {
    Serial.write("f");
  }
  delay(10);
}
