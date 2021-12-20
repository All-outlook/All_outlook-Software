int pin = 8;

unsigned long duration;

void setup(){
  pinMode(pin,INPUT);
  Serial.begin(9800);
}

void loop(){
  duration = pulseIn(pin,HIGH);

  Serial.println(duration);
}
