char buff[255];
int counter = 0;
int LED = 13;

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  Serial.println("start reading");
}

void loop() {
  while (Serial.available()) {
    char inchar = char(Serial.read());
    buff[counter] = inchar;
    counter++;
    if (inchar == '\0'){
        Serial.println(buff);
        digitalWrite(LED, HIGH);
        counter = 0;
      }else{
        digitalWrite(LED, LOW);
      }
     }
    }
