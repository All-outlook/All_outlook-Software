int Do = 261;
int Re = 294;
int Mi = 329;
int Fa = 349;
int So = 392;
int La = 440;
int Si = 493;
int Do2 = 523;
int Re2 = 587;
int Mi2 = 659;
int Fa2 = 698;
int So2 = 784;
int La2 = 880;
int Si2 = 988;
int Do3 = 1047;
int Re3 = 1175;
int Mi3 = 1319;
int Fa3 = 1397;
int So3 = 1568;

int oneup[6] = { Mi2, So2, Mi3, Do3, Re3, So3};
int mario[13] = {Mi2, Mi2, 0, Mi2, 0, Do2, Mi2, 0, So2, 0, 0, 0, So};
int fire[3] = {So, So2, So3};
int dead[9] = {Si, Fa2, 0, Fa2, Fa2, Mi2, 0, Re2, Do2};
int damage[18] = {La2, Mi, La, 0, 0, 0, La2, Mi, La, 0, 0, 0, La2, Mi, La, 0, 0, 0};
int star[32] = {Do2, 0, Do2, 0, Do2, 0, Re, Do2, 0, Do2, 0, Re, Do2, 0, Do2, 0,
                Si , 0, Si, 0, Si, 0, Do, Si, 0, Si, 0, Do, Si, 0, Si, 0
               };

void setup() {
}

void loop() {
  for (int i = 0; i < 13; i++) {
    tone(35, mario[i], 50);
    delay(115);
  }

  for (int i = 0; i < 32; i++) {
    tone(35, star[i], 100);
    delay(100);
  }

  for (int i = 0; i < 3; i++) {
    tone(35, Si2, 100);
    delay(100);
    tone(35, Mi3, 250);
    delay(250);
  }


  for (int i = 0; i < 6; i++) {
    tone(35, oneup[i], 100);
    delay(125);
  }
  delay(1000);
}
