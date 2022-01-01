#define MOTOR_A 6   
#define MOTOR_B 5  
#define MOTOR_C 10   
#define MOTOR_D 9  

//#define MOTOR_A 5
//#define MOTOR_B 6
//#define MOTOR_C 9
//#define MOTOR_D 10

#define LED 13      //LED

// 初期化
void setup(){
  pinMode(MOTOR_A, OUTPUT);   //正転pwm
  pinMode(MOTOR_B, OUTPUT);   //逆転pwm
  pinMode(MOTOR_C, OUTPUT);   //正転pwm
  pinMode(MOTOR_D, OUTPUT);   //逆転pwm
  pinMode(LED, OUTPUT);       //LED
}
 
// メインループ
void loop() {

  //正転
  analogWrite(MOTOR_A, 40);
  analogWrite(MOTOR_B, 0);
  analogWrite(MOTOR_C, 40);
  analogWrite(MOTOR_D, 0);
  digitalWrite(LED, HIGH);
  delay(5000);


  //逆転
  analogWrite(MOTOR_A, 0);
  analogWrite(MOTOR_B, 254);
  analogWrite(MOTOR_C, 0);
  analogWrite(MOTOR_D, 254);
  digitalWrite(LED, LOW);
  delay(600);

}
