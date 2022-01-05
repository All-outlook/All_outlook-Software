const int Do = 261;
const int Re = 294;
const int Mi = 329;
const int Fa = 349;
const int So = 392;
const int La = 440;
const int Si = 493;
const int Do2 = 523;
const int Re2 = 587;
const int Mi2 = 659;
const int Fa2 = 698;
const int So2 = 784;
const int La2 = 880;
const int Si2 = 988;
const int Do3 = 1047;
const int Re3 = 1175;
const int Mi3 = 1319;
const int Fa3 = 1397;
const int So3 = 1568;

const int oneup[6] = { Mi2, So2, Mi3, Do3, Re3, So3};
const int mario[13] = {Mi2, Mi2, 0, Mi2, 0, Do2, Mi2, 0, So2, 0, 0, 0, So};
const int fire[3] = {So, So2, So3};
const int dead[9] = {Si, Fa2, 0, Fa2, Fa2, Mi2, 0, Re2, Do2};
const int damage[18] = {La2, Mi, La, 0, 0, 0, La2, Mi, La, 0, 0, 0, La2, Mi, La, 0, 0, 0};
const int star[32] = {Do2, 0, Do2, 0, Do2, 0, Re, Do2, 0, Do2, 0, Re, Do2, 0, Do2, 0,
                      Si , 0, Si, 0, Si, 0, Do, Si, 0, Si, 0, Do, Si, 0, Si, 0
                     };

int kurikaeshi = 0;
void setup() {
  // put your setup code here, to run once:

}
int id;
void loop() {
  for (id = 0; id <= 2; id++) {
    tone(35, Si2, 100);
    delay(50);
    tone(35, Mi3, 250);
    delay(250);
  }
  delay(200);

  while(kurikaeshi <= 2){;
    for (id = 0; id < 6; id++) {
      tone(35, oneup[id], 100);
      delay(125);
    }
    kurikaeshi++;
  }
  kurikaeshi = 0;
}
