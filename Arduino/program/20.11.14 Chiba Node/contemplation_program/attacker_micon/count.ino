int goal_count(int interval_count) {
  int last_count = period_count + interval_count;

  if (last_count > 1000) {
    last_count -= 1000;
  }

  return last_count;
}
