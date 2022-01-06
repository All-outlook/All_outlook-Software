#include <SoftwareSerialParity.h>
const int LINE_RX = 68;
const int LINE_TX = 49;
SoftwareSerialParity line_Serial(LINE_RX, LINE_TX);  // rx,tx

int line_degree;

void setup() {
  Serial.begin(115200);
  line_Serial.begin(9600, ODD);
}

void loop() {                                                   
    if (line_Serial.available() > 0) {
    line_degree = line_Serial.read() * 2;
  }
  if(line_degree == 0 | line_degree > 360){
    line_degree = 0;
  }
  Serial.println(line_degree);
}
