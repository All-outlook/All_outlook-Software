#include <SoftwareSerialParity.h>
void setup() {
  Serial.begin(38400);
  F_MD_setup();
  F_SWITCH_setup();
}

void loop() {
  if (F_SWITCH_VALUE() == 0) {
    for (int id = 0; id <= 3; id++) {
      F_speed_send(id, 200);
    }
    delay(1000);

    for (int id = 0; id <= 3; id++) {
      F_speed_send(id, -1);
    }
    delay(1000);

    for (int id = 0; id <= 3; id++) {
      F_speed_send(id, -200);
    }
    delay(1000);

    for (int id = 0; id <= 3; id++) {
      F_speed_send(id, -1);
    }
    delay(1000);
    
  } else {
    for (int id = 0; id <= 3; id++) {
      F_speed_send(id, -1);
    }
  }
}
