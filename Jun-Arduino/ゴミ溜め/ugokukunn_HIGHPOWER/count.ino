int goal_count(int interval_count){
  // interval_count 何カウント後の値が欲しいのお？
  int last_count = period_count + interval_count;

  if (last_count > 1000){
    last_count = last_count - 1000;
  }

  return last_count;
}
