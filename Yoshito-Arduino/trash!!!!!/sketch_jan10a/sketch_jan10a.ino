int line_degree;
int degree;
if (line == 0) {
  line_degree = 180;

} else if (23 <= line & line < 58) {

} else if (58 <= line & line < 113)

}  else if (113 <= line & line < 158) {

} else if (158 <= line & line < 203) {
  line_degree = 0;

} else if (203 <= line & line < 258) {

}  else if (258 <= line & line < 303) {

} else if (303 <= line & line < 338) {


} else if (338 <= line & line <= 360 | 0 < line & line < 23) {
  line_degree = 360;
}

if (previous_degree == 360 & line_degree == 180) {
  false_degree = 360;
  false_digits = 2;
  line_time = F_time_goal(1500);
}

if (F_time_get() >= line_time & false_digits == 1)
{
  line_time = 0;
  false_degree = 0;
  false_digits = 0;
}

if ((line_degree == 0 & false_digits == 2) | (F_time_get() >= line_time & false_digits == 2)) {
  line_time = 0;
  false_digits = 0;
  false_degree = 0;
}

if (false_digits == 1 | false_digits == 2) {
  degree = false_degree;
} else {
  degree = line_degree;
}
previous_degree = line_degree;
return degree;
