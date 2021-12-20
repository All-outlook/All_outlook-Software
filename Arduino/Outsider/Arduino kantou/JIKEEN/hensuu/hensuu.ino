int test = 1;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  Serial.println(test);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(test);
  test = 2;
  Serial.println(test);

  Htest();

  Serial.println(test);
}

void Htest(){
  Serial.println(test);
  test = 3;
}
