int tact = 8;
int LED = 7;

void setup() {
 pinMode(tact, INPUT);
 pinMode(LED, OUTPUT);
 Serial.begin(9600);
}

boolean switching = 0;
unsigned long currentMillis = 0; //curent→現在の　millis→ミリ秒(s→second)
unsigned long preMil_switch = 0; //pre→前の

void loop() {
  currentMillis = millis(); //ミリ秒カウント
  Serial.println(currentMillis);
  
  if(currentMillis - preMil_switch >= 10){ //チャタリング防止
  if(digitalRead(tact) == 1){
   while(digitalRead(tact) == 1){
   }
   switching = !switching;
   digitalWrite(LED, switching);
   }
   preMil_switch = currentMillis;
  }
}
