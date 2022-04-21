void setup() {
  // put your setup code here, to run once:
  F_MD_setup();
  Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:
    F_MD_rotate(360, 0, 55);
    F_MD_debug();

    Serial.println();

}
