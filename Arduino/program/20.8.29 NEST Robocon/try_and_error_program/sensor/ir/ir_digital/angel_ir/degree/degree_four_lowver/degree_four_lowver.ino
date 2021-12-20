#define IR1 2
#define IR5 6
#define IR9 A0
#define IR13 A4
unsigned long duration1;
unsigned long duration5;
unsigned long duration9;
unsigned long duration13;
int mytimeout = 1725;

int x_axis;
int y_axis;
#define PI 3.141592653589793

void setup() {
 Serial.begin(9600);
 pinMode(IR1, INPUT);
 pinMode(IR5, INPUT);
 pinMode(IR9, INPUT);
 pinMode(IR13, INPUT);
}

void loop() {
 duration1 = pulseIn(IR1, LOW, mytimeout);
 duration5 = pulseIn(IR5, LOW, mytimeout);
 duration9 = pulseIn(IR9, LOW, mytimeout);
 duration13 = pulseIn(IR13, LOW, mytimeout);

  if(duration1 == 0){
  duration1 = 100;
 }
  if(duration5 == 0){
  duration5 = 100;
 }
  if(duration9 == 0){
  duration9 = 100;
 }
  if(duration13 == 0){
  duration13 = 100;
 }


 
 y_axis = duration1 - duration9;
 x_axis = duration13 - duration5;
 
float degree = (atan2((y_axis), (x_axis)) * 180 / PI);

if (degree < 0){
  degree = degree + 360;
}

long pre_distance = pow(x_axis, 2) + pow(y_axis, 2);
//Serial.println(pre_distance);
long distance = (sqrt(pre_distance)); 

 Serial.print("degree:"); Serial.print(degree); Serial.println("° / "); 
 //Serial.print("distance:"); Serial.print(distance); Serial.print("cm? / ");
 //Serial.print("x_axis:"); Serial.print(x_axis); Serial.print(", "); 
 //Serial.print("y_axis:"); Serial.println(y_axis);

 /*Serial.print("A:"); Serial.print(duration1); Serial.print(", ");
 Serial.print("E:"); Serial.print(duration5); Serial.print(", ");
 Serial.print("I:"); Serial.print(duration9); Serial.print(", ");
 Serial.print("L:"); Serial.println(duration13);*/
 delay(750);
}
