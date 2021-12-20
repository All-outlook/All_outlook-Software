/*15, 16が死亡している可能性大
 * 
 */
#define IR11 A2
#define IR12 A3
#define IR13 A4
#define IR14 A5
#define IR15 A6
#define IR16 A7

int mytimeout  = 1725;

unsigned long duration11;
unsigned long duration12;
unsigned long duration13;
unsigned long duration14;
unsigned long duration15;
unsigned long duration16;

void setup() {
  Serial.begin(9600);
  pinMode(IR11,INPUT);
  pinMode(IR12,INPUT);
  pinMode(IR13,INPUT);
  pinMode(IR14,INPUT);
  pinMode(IR15,INPUT);
  pinMode(IR16,INPUT);

}

void loop() {
  duration11 = pulseIn(IR11,LOW, mytimeout);
  duration12 = pulseIn(IR12,LOW, mytimeout);
  duration13 = pulseIn(IR13,LOW, mytimeout);
  duration14 = pulseIn(IR14,LOW, mytimeout);
  duration15 = pulseIn(IR15,LOW, mytimeout);
  duration16 = pulseIn(IR16,LOW, mytimeout); 

  Serial.print(duration11); Serial.print(", ");
  Serial.print(duration12); Serial.print(", ");
  Serial.print(duration13); Serial.print(", ");
  Serial.print(duration14); Serial.print(", ");
  Serial.print(duration15); Serial.print(", ");
  Serial.println(duration16);
}
