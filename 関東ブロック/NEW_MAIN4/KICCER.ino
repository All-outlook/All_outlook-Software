const int KICCER = 11;
const int KICCER_CUT = 62;

const int LASER = 12;
const int CATCH[] = {A14, A12, A11, A10, A9, A7};

const int KICK_LED = 30;

unsigned long kick_time = 0;
unsigned long kick_rest_time = 0;

void F_KICCER_SETUP() {
  pinMode(KICCER_CUT, OUTPUT);
  pinMode(KICCER, OUTPUT);
  pinMode(KICK_LED,OUTPUT);

  pinMode(LASER, OUTPUT);
  digitalWrite(LASER, HIGH);

  for (int i = 0; i < 6 ; i++) {
    pinMode(CATCH[i], INPUT);
  }
}


void F_KICCER_kick() {
  //キックしたいときに呼び出す
  if (kick_time == 0) {
    kick_time = F_time_goal(10);
    kick_rest_time = F_time_goal(1500);
  }
  if (kick_rest_time < F_time_get()) {
    kick_time = 0;
  }
}


void F_KICCER_loop() {
  //毎ループ呼び出す
  if (kick_time > F_time_get()) {
    digitalWrite(KICCER_CUT, LOW);
    digitalWrite(KICCER, HIGH);
    digitalWrite(KICK_LED, HIGH);
  } else {
    digitalWrite(KICCER, LOW);
    digitalWrite(KICCER_CUT, HIGH);
    digitalWrite(KICK_LED, LOW);
  }
}


int best_value = 0;
unsigned long kick_judge_time = 0;

int F_KICCER_judge_V2() {
  //1:ある 0:ない
  best_value = 0;
  for (int i = 0; i < 6 ; i++) {
    int catch_value;
    catch_value = analogRead(CATCH[i]);
    best_value = max(best_value, catch_value);
  }
  
  if (best_value < 500 && kick_judge_time == 0) {
    kick_judge_time = F_time_goal(100);
  } 
  if (best_value >= 500){
    kick_judge_time = 0;
  }

  if(kick_judge_time != 0 && kick_judge_time < F_time_get()){
    kick_judge_time = 0;
    return 1;
  }else{
    return 0;
  }
}
int F_KICCER_judge() {
  //1:ある 0:ない
  best_value = 0;
  for (int i = 0; i < 6 ; i++) {
    int catch_value;
    catch_value = analogRead(CATCH[i]);
    best_value = max(best_value, catch_value);
  }
  if (best_value < 500) {
    return 1;
  } else {
    return 0;
  }
}


void F_KICCER_debug() {
  Serial.print(" CATCH:");
  Serial.print(best_value);
}
