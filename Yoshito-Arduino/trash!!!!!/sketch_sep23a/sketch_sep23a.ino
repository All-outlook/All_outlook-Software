const int motor_right[] = {2, 4, 6, 8};
const int motor_left[] = {3, 5, 7, 9};

const int line_pin[] = {A0, A1, A2, A3};
const int red_led[] = {40, 41, 42, 43};
int line_val;
int MT_speed;

void setup() {
  Serial.begin(38400);
  for (int i = 0; i <= 3; i++) {
    pinMode(line_pin[i], INPUT);
    pinMode(red_led[i], OUTPUT);
    pinMode(motor_right[i], OUTPUT);
    pinMode(motor_left[i], OUTPUT);
  }
}

void loop() {
 line_read ();

}
