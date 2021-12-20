int JJ;
int IRpin;
unsigned long MinData;
unsigned long InData[12];

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
  Serial.begin(9600);
  Serial1.begin(9600);
}

int pul = 2000;

void loop() {
  InData[0] = pulseIn(2, HIGH,pul);
  InData[1] = pulseIn(3, HIGH,pul);
  InData[2] = pulseIn(4, HIGH,pul);
  InData[3] = pulseIn(5, HIGH,pul);
  InData[4] = pulseIn(6, HIGH,pul);
  InData[5] = pulseIn(7, HIGH,pul);
  InData[6] = pulseIn(8, HIGH,pul);
  InData[7] = pulseIn(9, HIGH,pul);
  InData[8] = pulseIn(10, HIGH,pul);
  InData[9] = pulseIn(11, HIGH,pul);
  InData[10] = pulseIn(12, HIGH,pul);
  InData[11] = pulseIn(13, HIGH,pul);

  MinData = 99999;
  IRpin = 0;
  for (JJ = 0 ; JJ < 12 ; JJ++) {
    if((InData[JJ] > 1000) || (InData[JJ] == 0)) InData[JJ] = 99999;
    if(InData[JJ] < MinData) {
      MinData = InData[JJ];
      IRpin = JJ;
    }
  }
    Serial1.println(IRpin);
//  Serial.println(MinData);

  delay(10); 
}
