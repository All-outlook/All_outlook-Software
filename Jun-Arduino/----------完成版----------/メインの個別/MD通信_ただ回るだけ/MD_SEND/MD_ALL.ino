#define BREAK_TIME 10 //ミリ秒(1/1000秒)

const int MOTOR_DEG[] = {45, 135, 225, 315}; // モーター配置角度

int out_speed[4];//出力値

int pos_or_neg[4] = {0, 0, 0, 0};//正負を判断する
int pre_pos_or_neg[4] = {0, 0, 0, 0};

unsigned long force_break_time[4] = {0, 0, 0, 0};

void F_MD_rotate(int LINEIR, int GYRO, int SPEED) {
  /*
    LINEIR 進行角度(0:無動作,1-360:進む)
    GYRO   目標傾き角度(1-360)
    SPEED  加減速(0:無動作,1-10:進む) 進行角度に係る
  */

  //出力値決定ゾーン
  for (int i = 0; i < 4; i++) {
    out_speed[i] = F_MD_gyro(GYRO) * 0.3 + F_MD_lineIr(LINEIR, MOTOR_DEG[i], SPEED) * 0.7;


    pos_or_neg[i] = F_MD_pos_or_neg(out_speed[i]);//正負を判断する


    int force_break = F_MD_break_chack(pos_or_neg[i], pre_pos_or_neg[i]); //止めるかどうか決める
    if (force_break == 1) {
      force_break_time[i] = F_time_goal(BREAK_TIME);
    }
    if (force_break_time[i] <= F_time_get()) {
      force_break_time[i] = 0;
    }

    if (force_break_time[i] != 0) {
      out_speed[i] = -1;
    }

    //おそすぎると回らないのでテコ入れ
    if(0 < out_speed[i] && out_speed[i] < 70){
      out_speed[i] = 70;
    }else if(-1 > out_speed[i] && out_speed[i] > -70){
      out_speed[i] = -70;
    }

    pre_pos_or_neg[i] = pos_or_neg[i];// 最後にメモ
  }

  //出力ゾーン
  for (int i = 0; i < 4; i++) {
    F_speed_send(i, out_speed[i]);
    Serial.print(out_speed[i]);
    Serial.print(':');
  }
}



int F_MD_break_chack(int numA, int numB) {
  //AとBが1と-1のセットのとき1を返します
  /*
    1   1 問題なし
    1   0 問題なし
    1  -1 アウト

    0   1 問題なし
    0   0 問題なし
    0  -1 問題なし

    -1  1 アウト
    -1  0 問題なし
    -1 -1 問題なし
  */
  int result;
  if (numA == 0 || numB == 0) {
    //何もしない
    result = 0;
  } else if (numA == numB) {
    //何もしない
    result = 0;
  } else if (numA != numB) {
    //アウト
    result = 1;
  }
  return result;
}


int F_MD_pos_or_neg(int num) {
  /*プラマイ判断するよ！！
    正  1
    負 -1
    0   0
  */
  int result;
  if (num > 0) {
    result = 1;
  } else if (num < 0) {
    result = -1;
  } else if (num == 0) {
    result = 0;
  }
  return result;
}


int F_MD_lineIr(int lineIr_deg, int MT_deg, int myspeed) {
  /*
    返り値：0-250
  */
  int pwm_val = 0;

  if (lineIr_deg != 0) {
    int sine_angle = MT_deg - lineIr_deg;
    pwm_val = F_MD_speed(myspeed) *  sin(sine_angle * PI / 180);

  } else {
    pwm_val = 0;
  }

  return pwm_val;
}

int F_MD_speed(int myspeed) {
  int val = 150 + (myspeed * 10);
  return val;
}


int F_MD_gyro(int gyro_deg) {
  /*
    返り値：80-250
    それぞれのモーターごとに計算してね！！
  */
  int pwm_val = 0;
  if (gyro_deg != 0) {
    if (5 <= gyro_deg && gyro_deg <= 180) {
      //左回り
      pwm_val = map(gyro_deg, 0, 180, -80, -250);

    } else if (180 <= gyro_deg && gyro_deg <= 355) {
      //右回り
      pwm_val = map(gyro_deg, 360, 180, 80, 250);

    } else {
      //回らない
      pwm_val = 0;
    }
  } else {
    pwm_val = 0;
  }

  return pwm_val;
}
