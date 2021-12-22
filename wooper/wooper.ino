volatile int button = 0;
int TACT = 3;

int IR1_top = 4;    //前
int IR2_left = 6;   //左
int IR3_light = 5;  //右
int IR4_back = 7;   //後

int LINE5_top = 0;  //前
int LINE6_left = 8; //左
int LINE7_light = 1;//右
int LINE8_back = 2; //後

void setup() {
  Serial.begin(9600);
  Serial3.begin(19200);
  pinMode(TACT, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(TACT), click, FALLING);

  pinMode(IR1_top, INPUT);
  pinMode(IR2_left, INPUT);
  pinMode(IR3_light, INPUT);
  pinMode(IR4_back, INPUT);

  pinMode(LINE5_top, INPUT);
  pinMode(LINE6_left, INPUT);
  pinMode(LINE7_light, INPUT);
  pinMode(LINE8_back, INPUT);
}

void loop() {
  while (button) {
    int val = analogRead(IR1_top);
    if (val > 600) {
      Serial3.println("1F1002F1003F1004R100");
    }

    int val1 = analogRead(IR3_light);
    if (val1 > 600) {
      Serial3.println("2R1004F100");
    }

    int val2 = analogRead(IR2_left);
    if (val2 > 600) {
      Serial3.println("1R1003R100");
    }

    int val3 = analogRead(IR4_back);
    if (val3 > 600) {
      Serial3.println("2R1004F100");
    }

    int val4 = analogRead(LINE6_left);
    if (val4 > 600) {
      Serial3.println("1F1002R1003F1004F100");
    }

    int val5 = analogRead(IR4_back);
    if (val5 > 600) {
      Serial3.println("1F1002R1003R1004R100");
    }

    int val6 = analogRead(LINE7_light);
    if (val6 > 600) {
      Serial3.println("1R1002F1003R1004R100");
    }

    int val7 = analogRead(LINE8_back);
    if (val7 > 600) {
      Serial3.println("1R1002R1003F1004R100");
    }
  }
}
void click() {
  button = !button;
}
