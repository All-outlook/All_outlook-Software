#include <SPI.h>
const int RESET_PIN[] = {2, 3, 4, 5, 6, 7, 8, 10};
const int SS_IR = 56;
const int SS_LINE = 57;
const int SS_PIN[] = {53, 54, 59, 58};
int IR_value;
int line_degree;
void setup() {
  SPI.begin();
  Serial.begin(115200);
  pinMode(SS_IR, OUTPUT);
  digitalWrite(SS_IR, HIGH);
  pinMode(SS_LINE, OUTPUT);
  digitalWrite(SS_LINE, HIGH);
  for (int id = 0; id <= 7; id++) {
    pinMode(RESET_PIN[id], OUTPUT);
    digitalWrite(RESET_PIN[id], HIGH);
    digitalWrite(RESET_PIN[id], LOW);
    digitalWrite(RESET_PIN[id], HIGH);
  }
  for (int id = 0; id <= 3; id++) {
    pinMode(SS_PIN[id], OUTPUT);
    digitalWrite(SS_PIN [id], HIGH);
  }
}

void loop() {
  IR_value = SPI_IR_degree();
  Serial.print('i');
  Serial.print(IR_value);
  Serial.print(", ");

  line_degree = SPI_line_degree() * 2;
  Serial.print('r');
  Serial.print(line_degree);
  Serial.print(", ");

  //int id = 3;
  int rotate1 = 10;
  int rotate2 = 20;
  int rotate_stop = 40;
  int my_speed = 200;
  int delay_count = 1000;

  for (int id = 0; id <= 3; id++) {
    SPI_rotate_speed(id, rotate1, my_speed);
  }
  delay(delay_count);

  for (int id = 0; id <= 3; id++) {
    SPI_rotate_speed(id, rotate_stop, my_speed);
  }
  delay(delay_count);

  for (int id = 0; id <= 3; id++) {
    SPI_rotate_speed(id, rotate2, my_speed);
  }
  delay(delay_count);

  for (int id = 0; id <= 3; id++) {
    SPI_rotate_speed(id, rotate_stop, my_speed);
  }
  delay(delay_count);
}
