int F_360_correct(int degree){
  while(degree < 0){
    degree += 360;
  }
  while(degree > 360){
    degree -= 360;
  }
  return degree;
}
