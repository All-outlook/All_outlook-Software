#include <SoftwareSerial.h>

SoftwareSerial MT_R_Serial(42, 53);//rx,tx
SoftwareSerial MT_L_Serial(45, 58);//rx,tx

const int MOTOR_DEG[] = {45, 135, 225, 315}; // モーター配置角度
int out_speed[4];//出力値

void F_MD_rotate(int LINEIR, int GYRO, int SPEED) {
  /*
    LINEIR 進行角度(0:無動作,1-360:進む)
    GYRO   目標傾き角度(1-360)
    SPEED  加減速(0-254) 進行角度に係る
  */
  for (int i = 0; i < 4; i++) {
    //何入れるか決める
    int gyro_speed = F_MD_gyro(GYRO, SPEED);
    int lineIr_speed = F_MD_lineIr(LINEIR, MOTOR_DEG[i], SPEED);
    //    Serial.print(gyro_speed);
    //    Serial.print(',');
    //    Serial.println(lineIr_speed);


    out_speed[i] = gyro_speed * 0.4 + lineIr_speed * 1;

  }


  for (int i = 0; i < 4; i++) {

    if (out_speed[i] == 0) {
      out_speed[i] = 0;
    } else if (out_speed[i] > 0) {
      out_speed[i] = constrain(out_speed[i], 40, 254);
    } else if (out_speed[i] < 0) {
      out_speed[i] = constrain(out_speed[i], -254, -40);
    }

    F_speed_send(i, out_speed[i]);
    Serial.print(i);
    Serial.print(':');
    Serial.print(out_speed[i]);
    Serial.print(' ');
  }
  Serial.println();
}


int F_MD_lineIr(int lineIr_deg, int MT_deg, int myspeed) {
  /*
    返り値：0-254
  */
  int pwm_val = 0;

  if (lineIr_deg != 0) {
    int sine_angle = MT_deg - lineIr_deg;
    pwm_val = myspeed *  sin(sine_angle * PI / 180);

  } else {
    pwm_val = 0;
  }

  return pwm_val;
}

int F_MD_gyro(int gyro_deg, int myspeed) {
  /*
    返り値：80-250
    それぞれのモーターごとに計算してね！！
  */
  int pwm_val = 0;
  if (gyro_deg != 0) {
    if (5 <= gyro_deg && gyro_deg <= 180) {
      //左回り
      pwm_val = map(gyro_deg, 0, 180, 40, myspeed);

    } else if (180 <= gyro_deg && gyro_deg <= 355) {
      //右回り
      pwm_val = map(gyro_deg, 360, 180, -40, -myspeed);

    } else {
      //回らない
      pwm_val = 0;
    }
  } else {
    pwm_val = 0;
  }

  return pwm_val;
}


void F_MD_setup() {
  pinMode(42, INPUT);
  pinMode(53, OUTPUT);
  pinMode(45, INPUT);
  pinMode(58, OUTPUT);


  MT_R_Serial.begin(38400);
  MT_L_Serial.begin(38400);
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
