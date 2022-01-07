void F_serial_setup()
{
  Serial.begin(115200);             // micon to PC
  Serial1.begin(38400);             //line
  Serial2.begin(38400, SERIAL_8E1); // gyro
  Serial3.begin(38400);             // IR
  MT_R_Serial.begin(38400);
  MT_L_Serial.begin(38400);
  pinMode(IR_RX, INPUT);
  pinMode(42, INPUT);
  pinMode(53, OUTPUT);
  pinMode(45, INPUT);
  pinMode(58, OUTPUT);
}

void F_speed_send(int id , int mySpeed) {
  if (id == 0 || id == 1) {
    if (mySpeed == -1) {
      //ブレーキ 0
      MT_R_Serial.write(0 + id);
    } else if (mySpeed > 0) {
      //正転 10
      MT_R_Serial.write(10 + id);
      MT_R_Serial.write(mySpeed);
    } else if (mySpeed < 0) {
      //後転 20
      MT_R_Serial.write(20 + id);
      MT_R_Serial.write(abs(mySpeed));
    } else if (mySpeed == 0) {
      //ストップ 30
      MT_R_Serial.write(30 + id);
    }
  } else if (id == 2 || id == 3) {
    if (mySpeed == -1) {
      //ブレーキ 0
      MT_L_Serial.write(0 + id);
    } else if (mySpeed > 0) {
      //正転 10
      MT_L_Serial.write(10 + id);
      MT_L_Serial.write(mySpeed);
    } else if (mySpeed < 0) {
      //後転 20
      MT_L_Serial.write(20 + id);
      MT_L_Serial.write(abs(mySpeed));
    } else if (mySpeed == 0) {
      //ストップ 30
      MT_L_Serial.write(30 + id);
    }
  }
}
