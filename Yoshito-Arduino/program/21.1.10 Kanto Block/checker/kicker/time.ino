unsigned long current_time;

void F_time_read() {
  current_time = micros();
}

unsigned long F_time_get() {
  return current_time;
}

unsigned long F_time_goal(unsigned long interval_time) {
  interval_time *= 1000;
  unsigned long goal_time = F_time_get() + interval_time;
  return goal_time;
}
