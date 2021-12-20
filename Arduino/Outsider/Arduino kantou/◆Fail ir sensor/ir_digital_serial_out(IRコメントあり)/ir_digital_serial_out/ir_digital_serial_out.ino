int X = 400;
int Y = 420;
int Z = 500;
unsigned long a;
unsigned long b;
unsigned long c;
unsigned long d;
unsigned long e;
unsigned long f;
unsigned long g;
unsigned long h;
unsigned long i;
unsigned long j;
unsigned long k;
unsigned long m;
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
}

void loop() {
  b = pulseIn(3, HIGH);
  a = pulseIn(2, HIGH);
  c = pulseIn(4, HIGH);
  d = pulseIn(5, HIGH);
  e = pulseIn(6, HIGH);
  f = pulseIn(7, HIGH);
  g = pulseIn(8, HIGH);
  h = pulseIn(9, HIGH);
  i = pulseIn(10, HIGH);
  j = pulseIn(11, HIGH);
  k = pulseIn(12, HIGH);
  m = pulseIn(13, HIGH);
  Serial.println(a);
  delay(100);

  int BS = 1000;

  for(int JJ = 2 ; JJ <= 13 ; JJ++){
    int SM = pulseIn(JJ, HIGH);
    
    if(SM < BS){
      SM = BS;
    }
  }

  Serial.println(BS);
  delay(2000);

}
  
//  if (X > a) {
//    Serial1.print('A');
//    delay(200);
// 
//} else 
//  if (X > d) {
//      Serial1.print('D');
//        delay(200);
//    } else if (X > g ) {
//        Serial1.print('G');
//          delay(200);
//      } else if (X > j) {
//          Serial1.print('J');
//            delay(200);
//        } else if (X > i) {
//            Serial1.print('I');
//              delay(200);
//          } else if (X > e) {
//              Serial1.print('E');
//                delay(200);
//            } else if (X > h ) {
//                Serial1.print('H');
//                  delay(200);
//              } else if (X > k ) {
//                  Serial1.print('K');
//                    delay(200);
//                } else if (Y > c ) {
//                    Serial1.print('C');
//                      delay(200);
//                  } else if (X > f ) {
//                      Serial1.print('F');
//                        delay(200);
//                    } else if (X > b) {
//                        Serial1.print('B');
//                          delay(200);
//                      } else if (X > m ) {
//                          Serial1.print('M');
//                          delay(200);
//                        }
//                   }
