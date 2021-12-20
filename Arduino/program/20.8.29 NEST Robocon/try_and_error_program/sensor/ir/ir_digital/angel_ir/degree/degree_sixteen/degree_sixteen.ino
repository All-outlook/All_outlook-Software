const int IRpin[] = {2, 3, 4, 5, 6, 7, 8, 9, A0, A1, A2, A3, A4, A5, A6, A7};
const char IRprint[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P'};
long duration[16];
int mytimeout = 1725;

int incompetence = 0;
#define mysin22_5 0.38268
#define mycos22_5 0.92387
#define mysin45_0 0.70710
#define mycos45_0 0.70710
#define mysin67_5 0.92387
#define mycos67_5 0.38268
#define PI 3.141592653589793
int x_axis;
int y_axis;
int degree;
int alpha_distance;

void setup() {
  Serial.begin(38400);
  for (int i = 0; i <= 15; i++) {
    pinMode(IRpin[i], INPUT);
  }
}

void loop() {
  for (int i = 0; i <= 15; i++) {
    duration[i] = pulseIn(IRpin[i], LOW, mytimeout);
  }

  //無能をつぶす
  duration[14] = 0;
  duration[15] = 0;

  //感度補正(450)
  duration[0] *= 1.05;
  duration[1] *= 1.05;
  duration[2] *= 1.07;
  duration[3] *= 1.15;
  duration[4] *= 1.02;
  duration[5] *= 1.07;
  duration[6] *= 0.96;
  duration[7] *= 0.99;
  duration[8] *= 1.00;
  duration[9] *= 1.02;
  duration[10] *= 1.00;
  duration[11] *= 1.00;
  duration[12] *= 1.01;
  duration[13] *= 1.07;
  duration[14] *= 1.00;
  duration[15] *= 1.00;

  //感度補正 level.2
  if (duration[0] > 0 & duration[8] > 0 | duration[4] > 0 & duration[12] > 0 ) {
    for (int i = 0; i <= 13; i++) {
      if (duration[i] == 0) {
        duration[i] = 80;
      }
    }
  }

  long duration0of13 = mysin22_5 * duration[13];
  long duration12of13 = mycos22_5 * duration[13];
  long duration0of14 = mysin45_0 * duration[14];
  long duration12of14 = mycos45_0 * duration[14];
  long duration0of15 = mysin67_5 * duration[15];
  long duration12of15 = mycos67_5 * duration[15];
  long duration0of1 = mysin67_5 * duration[1];
  long duration4of1 = mycos67_5 * duration[1];
  long duration0of2 = mysin45_0 * duration[2];
  long duration4of2 = mycos45_0 * duration[2];
  long duration0of3 = mysin22_5 * duration[3];
  long duration4of3 = mycos22_5 * duration[3];
  long duration8of5 = mysin22_5 * duration[5];
  long duration4of5 = mycos22_5 * duration[5];
  long duration8of6 = mysin45_0 * duration[6];
  long duration4of6 = mycos45_0 * duration[6];
  long duration8of7 = mysin67_5 * duration[7];
  long duration4of7 = mycos67_5 * duration[7];
  long duration8of9 = mysin67_5 * duration[9];
  long duration12of9 = mycos67_5 * duration[9];
  long duration8of10 = mysin45_0 * duration[10];
  long duration12of10 = mycos45_0 * duration[10];
  long duration8of11 = mysin22_5 * duration[11];
  long duration12of11 = mycos22_5 * duration[11];

  long all_duration0 = duration[0] * 2 + duration0of13 + duration0of14 + duration0of15 + duration0of1 * 2 + duration0of2 + duration0of3;
  //duration0of14,duration0of15は0と出てしまうため、duration0,duration0of1を*2する
  long all_duration4 = duration[4] + duration4of1 + duration4of2 + duration4of3 + duration4of5 + duration4of6 + duration4of7;
  long all_duration8 = duration[5] + duration8of5 + duration8of6 + duration8of7 + duration8of9 + duration8of10 + duration8of11;
  long all_duration12 = duration[12] * 2 + duration12of9 + duration12of10 + duration12of11 + duration12of13 * 2 + duration12of14 + duration12of15;
  //duration12of14,duration12of15は0と出てしまうため、duration12,duration12of13を*2する

  y_axis = all_duration0 - all_duration8;
  x_axis = all_duration12 - all_duration4;

  degree = (atan2((y_axis), (x_axis)) * 180 / PI);

  //degree -= 90; //All_outlookの文字が上を向く位置を0°とする
  if (degree < 0) {
    degree += 360;
  }

  long distance = sqrt(pow(x_axis, 2) + pow(y_axis, 2));

  /*if (0 <= distance & distance < 10) {
    alpha_distance = 'A';
    } else if (10 <= distance & distance <= 20) {
    alpha_distance = 'B';
    } else if (20 <= distance & distance <= 30) {
    alpha_distance = 'C';
    } else if (30 <= distance & distance <= 40) {
    alpha_distance = 'D';
    } else if (40 <= distance & distance <= 50) {
    alpha_distance = 'E';
    } else if (50 <= distance & distance <= 60) {
    alpha_distance = 'F';
    } else if (60 <= distance & distance <= 70) {
    alpha_distance = 'G';
    } else if (70 <= distance & distance <= 80) {
    alpha_distance = 'H';
    } else if (80 <= distance & distance <= 90) {
    alpha_distance = 'I';
    } else if (90 <= distance) {
    alpha_distance = 'J';*/

  Serial.print("degree:"); Serial.print(degree); Serial.print("° / ");
  //Serial.print("distance:"); Serial.print(distance); Serial.print("cm / ");
  Serial.print("x_axis:"); Serial.print(x_axis); Serial.print(", ");
  Serial.print("y_axis:"); Serial.println(y_axis);

  Serial.print("0of1:"); Serial.print(duration0of1); Serial.print(", ");
  Serial.print("0of2:"); Serial.print(duration0of2); Serial.print(", ");
  Serial.print("0of3:"); Serial.print(duration0of3); Serial.print(", ");
  Serial.print("0of13:"); Serial.print(duration0of13); Serial.print(", ");
  Serial.print("0of14:"); Serial.print(duration0of14); Serial.print(", ");
  Serial.print("0of15:"); Serial.print(duration0of15); Serial.println(", ");
  Serial.print("4of1:"); Serial.print(duration4of1); Serial.print(", ");
  Serial.print("4of2:"); Serial.print(duration4of2); Serial.print(", ");
  Serial.print("4of3:"); Serial.print(duration4of3); Serial.print(", ");
  Serial.print("4of5:"); Serial.print(duration4of5); Serial.print(", ");
  Serial.print("4of6:"); Serial.print(duration4of6); Serial.print(", ");
  Serial.print("4of7:"); Serial.print(duration4of7); Serial.println(", ");
  Serial.print("8of5:"); Serial.print(duration8of5); Serial.print(", ");
  Serial.print("8of6:"); Serial.print(duration8of6); Serial.print(", ");
  Serial.print("8of7:"); Serial.print(duration8of7); Serial.print(", ");
  Serial.print("8of9:"); Serial.print(duration8of9); Serial.print(", ");
  Serial.print("8of10:"); Serial.print(duration8of10); Serial.print(", ");
  Serial.print("8of11:"); Serial.print(duration8of11); Serial.println(", ");
  Serial.print("12of9:"); Serial.print(duration12of9); Serial.print(", ");
  Serial.print("12of10:"); Serial.print(duration12of10); Serial.print(", ");
  Serial.print("12of11:"); Serial.print(duration12of11); Serial.print(", ");
  Serial.print("12of13:"); Serial.print(duration12of13); Serial.print(", ");
  Serial.print("12of14:"); Serial.print(duration12of14); Serial.print(", ");
  Serial.print("12of15:"); Serial.println(duration12of15);

  for (int i = 0; i <= 15; i++) {
    Serial.print(IRprint[i]);
    Serial.print(":");
    Serial.print(duration[i]);
    Serial.print(", ");
  }
  Serial.println();
  Serial.println();
}
