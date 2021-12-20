float adjust_angle(float angle) {
  while (angle >= 360) {
    angle -= 360;
  }

  while (angle < 0) {
    angle += 360;
  }

  return angle;
}

float add_angle(float I_degree, float L_degree, int L_power) {
  float X_axis;
  float Y_axis;

  X_axis = cos(I_degree * PI / 180.0) + (cos(L_degree * PI / 180.0) * L_power); //L priority
  Y_axis = sin(I_degree * PI / 180.0) + (sin(L_degree * PI / 180.0) * L_power);

  float angle = atan2(Y_axis, X_axis) * 180.0 / PI;

  while (angle < 0) {
    angle += 360.00;
  }

  if (abs(I_degree - L_degree) == 180.00) {
    angle = -1;
  }

  return angle;
}
