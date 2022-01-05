#include <SoftwareSerialParity.h>
void setup() {
  Serial.begin(38400);
  F_MD_setup();
  F_SWITCH_setup();
}

void loop() {

  F_speed_send(0, 255);
  F_speed_send(1, 255);
  F_speed_send(2, -255);
  F_speed_send(3, -255);
  delay(1000);

  for (int id = 0; id <= 3; id++) {
    F_speed_send(id, -1);
  }
  delay(1000);
  
  F_speed_send(0, -255);
  F_speed_send(1, -255);
  F_speed_send(2, 255);
  F_speed_send(3, 255);
  delay(1000);

  for (int id = 0; id <= 3; id++) {
    F_speed_send(id, -1);
  }
  delay(1000);
}
