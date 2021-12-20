float adjust_angle(float angle) {
  // イカれた角度値を0～360に強制します。
  
  while (angle > 360) {
    angle -= 360;
  }

  while (angle < 0) {
    angle += 360;
  }

  return angle;
}

float add_angle(float A_angle, float B_angle, int B_power) {
  // B_power Aを1としたときのBのちからの割合
  // 進まないときは -1
  float X_axis;
  float Y_axis;

  X_axis = cos(A_angle * PI / 180.0) + (cos(B_angle * PI / 180.0) * B_power);
  Y_axis = sin(A_angle * PI / 180.0) + (sin(B_angle * PI / 180.0) * B_power);

  float angle = atan2(Y_axis, X_axis) * 180.0 / PI;

  while (angle < 0) {
    angle += 360.00;
  }

  if (abs(A_angle - B_angle) == 180.00) {
    angle = -1;
  }

  return angle;
}
