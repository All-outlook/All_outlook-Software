  #include <SPI.h>
void setup(){
  Serial.begin(115200);
  SPI.begin();
  pinMode(SS, OUTPUT);
  digitalWrite(SS, HIGH);
}

void loop() {
  int SPI_transmission_value;
  int SPI_receive_value;

  SPI_transmission_value = 63;
  digitalWrite(SS, LOW);
  SPI.transfer(SPI_transmission_value);
  digitalWrite(SS, HIGH);

  digitalWrite(SS, LOW);
  SPI_receive_value = SPI.transfer(0);
  digitalWrite(SS, HIGH);
 Serial.println(SPI_receive_value);
}
