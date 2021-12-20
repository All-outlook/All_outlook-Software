int JJ;
unsigned long MinData;
unsigned long InData[12];
int IRpin;
void setup() {
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(10, INPUT);
  pinMode(11, INPUT);
  pinMode(12, INPUT);
  pinMode(13, INPUT);
  Serial1.begin(9600);
  Serial.begin(9600);
}

void loop() {
  InData[0] = pulseIn(2, HIGH);
  InData[1] = pulseIn(3, HIGH);
  InData[2] = pulseIn(4, HIGH);
  InData[3] = pulseIn(5, HIGH);
  InData[4] = pulseIn(6, HIGH);
  InData[5] = pulseIn(7, HIGH);
  InData[6] = pulseIn(8, HIGH);
  InData[7] = pulseIn(9, HIGH);
  InData[8] = pulseIn(10, HIGH);
  InData[9] = pulseIn(11, HIGH);
  InData[10] = pulseIn(12, HIGH);
  InData[11] = pulseIn(13, HIGH);
  delay(100);

  Serial.println(InData[11]);


  MinData = 99999;
  IRpin = 0;
  for (JJ = 0 ; JJ < 12 ; JJ++) {
    if(InData[JJ] > 1000) InData[JJ] = 99999;
    if(InData[JJ] < MinData) {
      MinData = InData[JJ];
      IRpin = JJ;
    }
  }

  
  //Serial.println(InData[0]);
  
//  Serial1.write(IRpin);
//  Serial.print(IRpin);
//  Serial.print(':');
//  Serial.println(MinData);
  //delay(100);
}
