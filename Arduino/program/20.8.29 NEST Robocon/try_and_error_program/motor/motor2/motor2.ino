const int Ichinose_F = 2 ; //F = forward rotation(正転)
const int Ichinose_R = 3 ; //R =  reversal(逆転)
const int Nikaido_F = 4 ;
const int Nikaido_R = 5 ;
const int Mieno_F = 6 ;
const int Mieno_R = 7 ;
const int Yotsuya_F = 8 ;
const int Yotsuya_R = 9 ;
#define PI 3.141592653589793

void setup() {
  Serial.begin(9600);
  pinMode(Ichinose_F, OUTPUT);
  pinMode(Ichinose_R, OUTPUT);
  pinMode(Nikaido_F, OUTPUT);
  pinMode(Nikaido_R, OUTPUT);
  pinMode(Mieno_F, OUTPUT);
  pinMode(Mieno_R, OUTPUT);
  pinMode(Yotsuya_F, OUTPUT);
  pinMode(Yotsuya_R, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

}

void motorAngel(int theta) {
  int power = 127;
  int Ichinose;
  int Nikaido;
  int Mieno;
  int Yotsuya;
  Ichinose = sin((theta - 45) * PI / 180) * power;
  Nikaido = cos((theta - 135) * PI / 180) * power;
  Mieno = sin((theta - 225) * PI / 180) * power;
  Yotsuya = cos((theta - 315) * PI / 180) * power;

  int attendance_list[4] = {Ichinose, Nikaido, Mieno, Yotsuya};
  for(int 
}
