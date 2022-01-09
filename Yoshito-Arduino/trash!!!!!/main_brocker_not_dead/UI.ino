const int UI_Y = 22;
const int UI_B = 23;
const int UI_X = 24;
const int UI_A = 25;
const int UI_NO = 26;
const int UI_OK = 27;

void F_snuggle_setup() {
  pinMode(UI_Y, INPUT);
  pinMode(UI_B, INPUT);
  pinMode(UI_X, INPUT);
  pinMode(UI_A, INPUT);
  pinMode(UI_NO, INPUT);
  pinMode(UI_OK, INPUT);
}
