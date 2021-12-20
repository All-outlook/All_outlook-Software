const int START_TOGGLE = 41;

void F_SWITCH_setup(){
  pinMode(START_TOGGLE,INPUT);
}

int F_SWITCH_VALUE(){
  int val = digitalRead(START_TOGGLE);
  return val;
}
