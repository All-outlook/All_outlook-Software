#define PI 3.141592653589793
void setup() {
  Serial.begin(9600);// put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("sin45°=");
  Serial.println(sin(PI / 4));
  Serial.print("cos45°=");
  Serial.println(cos(PI / 4));
  Serial.print("tan45°=");
  Serial.println(tan(PI / 4));
  delay(500);
}
