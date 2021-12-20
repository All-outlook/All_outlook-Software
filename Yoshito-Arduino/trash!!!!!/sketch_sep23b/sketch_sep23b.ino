int line_pin = A1;
int line_angle = 90;
int line_degree;
int line_read;
int line_value;

void setup() {
  Serial.begin(38400);
  pinMode(line_pin, INPUT);
}

void loop() {
  line_read = analogRead(line_pin);

  if (line_read >= 800) {
    line_value = 1;
  } else {
    line_value = 0;
  }

  if(line_value == 1){
    line_degree = line_angle + 180;
  }

 if(line_degree >= 360){
  line_degree -= 360;
 }
 Serial.println(line_degree);
 
}
