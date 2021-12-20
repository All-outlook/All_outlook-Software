#include <SPI.h>
const int IR_PIN[] = {2, 3, 4, 5, 6, 7, 8, 9, A0, A1, A2, A3, A4, A5, 0, 1};
long duration[16];
const int mytimeout = 1725;
int more;
int best_duration;
int best;
int knob;

void setup() {
  SPCR |= bit(SPE);
  pinMode(MISO, OUTPUT);
  SPI.attachInterrupt();
  //Serial.begin(115200);
  for (int id = 0; id <= 15; id++) {
    pinMode(IR_PIN[id], INPUT);
  }
}

void loop() {
  for (int id = 0; id <= 15; id++) {
    duration[id] = pulseIn(IR_PIN[id], LOW, mytimeout);
  }

  /*for (int id = 0; id <= 15; id++) {
    Serial.print(id);
    Serial.print(":");
    Serial.print(duration[id]);
    Serial.print(", ");
  }
  Serial.println();*/

  more = 0;
  best_duration = 0;
  for (int id = 0; id <= 15; id++) {
    more = max(more, duration[id]);

    if (more == duration[id]) {
      best = id;
      best_duration = duration[id];
    }
  }

  if (best_duration == 0) {
    best = 20;
  }
  Serial.println(best);
}

ISR(SPI_STC_vect) {
  knob = SPDR;
  SPDR = best;
}
