/*Angel IR  
 *George Washington(ATMega328P-AU) 
 *by Yoshito*/
#define IR1 2
#define IR2 3
#define IR3 4
#define IR4 5
#define IR5 6
#define IR6 7
#define IR7 8
#define IR8 9
#define IR9 A0 
#define IR10 A1
#define IR11 A2
#define IR12 A3
#define IR13 A4
#define IR14 A5
#define IR15 A6
#define IR16 A7

int mytimeout  = 1725;

unsigned long duration1;
unsigned long duration2;
unsigned long duration3;
unsigned long duration4;
unsigned long duration5;
unsigned long duration6;
unsigned long duration7;
unsigned long duration8;
unsigned long duration9;
unsigned long duration10;
unsigned long duration11;
unsigned long duration12;
unsigned long duration13;
unsigned long duration14;
unsigned long duration15;
unsigned long duration16;

void setup(){
  Serial.begin(9600);
  pinMode(IR1,INPUT);
  pinMode(IR2,INPUT);
  pinMode(IR3,INPUT);
  pinMode(IR4,INPUT);
  pinMode(IR5,INPUT);
  pinMode(IR6,INPUT);
  pinMode(IR7,INPUT);
  pinMode(IR8,INPUT);
  pinMode(IR9,INPUT);
  pinMode(IR10,INPUT);
  pinMode(IR11,INPUT);
  pinMode(IR12,INPUT);
  pinMode(IR13,INPUT);
  pinMode(IR14,INPUT);
  pinMode(IR15,INPUT);
  pinMode(IR16,INPUT);
}

void loop(){
  duration1 = pulseIn(IR1,LOW, mytimeout);
  duration2 = pulseIn(IR2,LOW, mytimeout);
  duration3 = pulseIn(IR3,LOW, mytimeout);
  duration4 = pulseIn(IR4,LOW, mytimeout);
  duration5 = pulseIn(IR5,LOW, mytimeout);
  duration6 = pulseIn(IR6,LOW, mytimeout);
  duration7 = pulseIn(IR7,LOW, mytimeout);
  duration8 = pulseIn(IR8,LOW, mytimeout);
  duration9 = pulseIn(IR9,LOW, mytimeout);
  duration10 = pulseIn(IR10,LOW, mytimeout);
  duration11 = pulseIn(IR11,LOW, mytimeout);
  duration12 = pulseIn(IR12,LOW, mytimeout);
  duration13 = pulseIn(IR13,LOW, mytimeout);
  duration14 = pulseIn(IR14,LOW, mytimeout);
  duration15 = pulseIn(IR15,LOW, mytimeout);
  duration16 = pulseIn(IR16,LOW, mytimeout); 
  
  Serial.print("A:"); Serial.print(duration1); Serial.print(", ");
  Serial.print("B:"); Serial.print(duration2); Serial.print(", ");
  Serial.print("C:"); Serial.print(duration3); Serial.print(", ");
  Serial.print("D:"); Serial.print(duration4); Serial.print(", ");
  Serial.print("E:"); Serial.print(duration5); Serial.print(", ");
  Serial.print("F:"); Serial.print(duration6); Serial.print(", ");
  Serial.print("G:"); Serial.print(duration7); Serial.print(", ");
  Serial.print("H:"); Serial.print(duration8); Serial.print(", ");
  Serial.print("I:"); Serial.print(duration9); Serial.print(", ");
  Serial.print("J:"); Serial.print(duration10); Serial.print(", ");
  Serial.print("K:"); Serial.print(duration11); Serial.print(", ");
  Serial.print("L:"); Serial.print(duration12); Serial.print(", ");
  Serial.print("M:"); Serial.print(duration13); Serial.print(", ");
  Serial.print("N:"); Serial.print(duration14); Serial.print(", ");
  Serial.print("O:"); Serial.print(duration15); Serial.print(", ");
  Serial.print("P:"); Serial.println(duration16);
}
