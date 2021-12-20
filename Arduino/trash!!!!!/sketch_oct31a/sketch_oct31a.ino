int length = 500;
double value;
#define PI 3.14159265358979
void setup() {
Serial.begin(38400);
}

void loop() {
value = asin(140 / length);
Serial.println(value);
}
