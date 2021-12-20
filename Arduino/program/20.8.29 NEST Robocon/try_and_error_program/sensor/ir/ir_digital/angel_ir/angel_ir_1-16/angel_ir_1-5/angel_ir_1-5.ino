/*4, 5が死亡している可能性大
 * 
 */
#define IR1 2
#define IR2 3
#define IR3 4
#define IR4 5
#define IR5 6

int mytimeout  = 1725;

unsigned long duration1;
unsigned long duration2;
unsigned long duration3;
unsigned long duration4;
unsigned long duration5;

void setup(){
  Serial.begin(9600);
  pinMode(IR1,INPUT);
  pinMode(IR2,INPUT);
  pinMode(IR3,INPUT);
  pinMode(IR4,INPUT);
  pinMode(IR5,INPUT);
}

void loop(){
  duration1 = pulseIn(IR1,LOW, mytimeout);
  /*
  duration2 = pulseIn(IR2,HIGH, mytimeout);
  duration3 = pulseIn(IR3,HIGH, mytimeout);
  duration4 = pulseIn(IR4,HIGH, mytimeout);
  duration5 = pulseIn(IR5,HIGH, mytimeout);
  */
  
  Serial.print(duration1); Serial.println(", ");
  /*
  Serial.print(duration2); Serial.print(", ");
  Serial.print(duration3); Serial.print(", ");
  Serial.print(duration4); Serial.print(", ");
  Serial.println(duration5);
  delay(100);
  */
}
