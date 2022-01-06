const int KICCER = 11;
const int KICCER_CUT = 62;

const int LASER = 12;
const int CATCH = A7;

unsigned long kick_time = 0;
unsigned long kick_rest_time = 0;

void F_KICCER_SETUP() {
  pinMode(KICCER_CUT, OUTPUT);
  pinMode(KICCER, OUTPUT);

  pinMode(LASER, OUTPUT);
  digitalWrite(LASER, HIGH);

  pinMode(CATCH, INPUT);
}


void F_KICCER_kick(){
  //キックしたいときに呼び出す
  if (kick_time == 0) {
    kick_time = F_time_goal(1000);
    kick_rest_time = F_time_goal(3000);
  }
  if(kick_rest_time < F_time_get()){
    kick_time = 0;
  }
}


void F_KICCER_roop() {
  //毎ループ呼び出す
  if (kick_time > F_time_get()) {
    digitalWrite(KICCER_CUT, LOW);
    digitalWrite(KICCER, HIGH);
    Serial.println('y');
  } else {
    digitalWrite(KICCER, LOW);
    digitalWrite(KICCER_CUT, HIGH);
//    Serial.println('n');
  }
}


void F_KICCER_judge() {

}
