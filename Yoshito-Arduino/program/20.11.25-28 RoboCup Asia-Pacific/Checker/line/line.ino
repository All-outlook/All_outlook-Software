// ライン読み取り


int line_threshold[] = {600, 600, 800, 600};//しきい値指定
int line_pin[] = {A0, A1, A2, A3};
int RED_LED_pin[] = {40, 41, 42, 43};
int line_analog_value[] = {0, 0, 0, 0}; // ライン読み取り値 関数内用


int line_value[] = {0, 0, 0, 0}; // ライン読み取り値 制御用


void setup() {
  Serial.begin(115200);
  for (int id = 0; id <= 3; id += 1) {
    pinMode(line_pin[id], INPUT);
    pinMode(RED_LED_pin[id], OUTPUT);
  }
}

void loop() {
  Serial.print("Sensor ");
  for (int id = 0; id <= 3; id += 1) {
    Serial.print(" ");
    Serial.print(id);
    Serial.print(":");
    line_value[id] = line_read(id);
    Serial.print(":");
    Serial.print(line_value[id]);
  }


  Serial.print("   air:");
  Serial.println(line_air());


}

int line_read(int id) {
  line_analog_value[id] = analogRead(line_pin[id]);
  Serial.print( line_analog_value[id]);
  int line_value;

  if (line_analog_value[id] >= line_threshold[id]) {
    line_value = 1;
    digitalWrite(RED_LED_pin[id], HIGH);
  } else {
    line_value = 0;
    digitalWrite(RED_LED_pin[id], LOW);
  }

  return line_value;
}

int line_air() {
  // 0:地面 1:空中
  for (int id = 0; id <= 3; id += 1) {
    if (line_analog_value[id] >= 200) {
      return 0;
    } else if (id == 3) {
      return 1;
    }
  }

}
