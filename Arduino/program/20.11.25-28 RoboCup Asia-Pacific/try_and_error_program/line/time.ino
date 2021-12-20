unsigned long current_time;

void time_read() {
  current_time = micros();
}

int time_get() {
  return current_time;
}

unsigned long time_goal(unsigned long interval_time) { //interval_timeはミリ秒
  interval_time = * 1000;
  unsigned long goal_time = current_time + interval_time;
  return goal_time;
}
