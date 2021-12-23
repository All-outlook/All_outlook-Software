

void setup() {
  //Serial.begin(38400);
  Serial_setup();
  

}

int knob = 10;
void loop() {
  for (int n = 150; n <= 200; n++) {
    ALL_UART(10);
    ALL_UART(n);
  }

  for (int n = 0; n <= 10; n++) {
    ALL_UART(40);
  }

  for (int n = 150; n <= 200; n++) {
    ALL_UART(20);
    ALL_UART(n);
  }

  for (int n = 0; n <= 10; n++) {
    ALL_UART(40);
  }


}
