
const int LED_PIN[] = {30, 31, 32, 33};
const int TOGGLE_PIN = 41;
const int TACT_SWITCH[] = {22, 23, 24, 25, 26, 27};// Y,B,X,A,☓,✓



void setup() {
  F_BUZ_setup();
  F_full_led_setup(0,10,0);
  F_LCD_setup();
  pinMode(11,OUTPUT);
}

void loop(){
  F_full_led_setup(0,250,0);
  digitalWrite(11,HIGH);
  delay(10);
  digitalWrite(11,LOW);
  F_LCD_All_outlok();
  F_full_led_setup(250,0,0);  
  F_BUZ_DarthVader();
  F_full_led_setup(0,0,10);
  F_BUZ_doremi();
  F_full_led_setup(0,10,10);
  F_BUZ_koinobori();
  F_full_led_setup(10,10,0);
  F_BUZ_ElectricalParade();
  F_full_led_setup(10,0,10);
  F_BUZ_Haruno_ogawa();
}
