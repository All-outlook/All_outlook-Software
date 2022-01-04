void setup() {
  Serial.begin(115200);
  Serial3.begin(9600);
  pinMode(66, INPUT);
}

int IR_value;
void loop() {
  if(Serial3.available() >= 0){
  IR_value = Serial3.read() * 2;
  } else {
    int nothing = Serial3.read()  ;
  }
  Serial.println(IR_value);
}
