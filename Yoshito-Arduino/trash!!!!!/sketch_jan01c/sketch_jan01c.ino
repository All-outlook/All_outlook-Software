#include <SoftwareSerial.h>
SoftwareSerial IR_Serial(23, 53); // RX, TX
void setup() {
  //Serial.begin(115200);
  IR_Serial.begin(9600);
}

void loop() {
 IR_Serial.write(200);
  IR_Serial.flush();
}
