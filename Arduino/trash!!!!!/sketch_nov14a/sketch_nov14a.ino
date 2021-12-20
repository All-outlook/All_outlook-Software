void setup() {
  Serial.begin(115200);


}

void loop() {
  int MT_degree = 45;
  int MT_go_degree = -1;

  int power = 255;
  int theta = MT_degree - MT_go_degree;

 int MT_speeeed = sin(theta * PI / 180) * power;
  Serial.println(MT_speeeed);
}
