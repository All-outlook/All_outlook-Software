/*6, 7, 9が死亡している可能性大
 * 
 */
#define IR6 7
#define IR7 8
#define IR8 9
#define IR9 A0 
#define IR10 A1

int mytimeout  = 1000;

unsigned long duration6;
unsigned long duration7;
unsigned long duration8;
unsigned long duration9;
unsigned long duration10;

void setup(){
  Serial.begin(9600);
  pinMode(IR6,INPUT);
  pinMode(IR7,INPUT);
  pinMode(IR8,INPUT);
  pinMode(IR9,INPUT);
  pinMode(IR10,INPUT);
}

void loop(){
  duration6 = pulseIn(IR6,HIGH, mytimeout);
  duration7 = pulseIn(IR7,HIGH, mytimeout);
  duration8 = pulseIn(IR8,HIGH, mytimeout);
  duration9 = pulseIn(IR9,HIGH, mytimeout);
  duration10 = pulseIn(IR10,HIGH, mytimeout);
  
  Serial.print(duration6); Serial.print(", ");
  Serial.print(duration7); Serial.print(", ");
  Serial.print(duration8); Serial.print(", ");
  Serial.print(duration9); Serial.print(", ");
  Serial.println(duration10); 
  delay(300);
}
