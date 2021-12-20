void kicker() {
  for (int id = 0; id <= 1; id++) {
    capture_read[id] = analogRead(CAPTURE_PIN[id]);
    if (capture_read[id] >= capture_threshold[id]) {
      capture_value[id] = 1;
    } else {
      capture_value[id] = 0;
    }
    /*Serial.print("capture");
      Serial.print(id);
      Serial.print(":");
      Serial.print(capture_value[id]);
      Serial.print(", ");*/
  }

  if (capture_value[0] == 1 & capture_value[1] == 1) {
    digitalWrite(KICKER_PIN, HIGH);
  } else {
    digitalWrite(KICKER_PIN, LOW);
  }

  Serial.print("k");
  if (KICKER_PIN == HIGH) {
    Serial.print("on");
    kicker_reaction = 1;
    kicker_count = goal_count(100);
  } else if (kicker_reaction == LOW) {
    Serial.print("off");
  }

  if (kicker_reaction == 1) {
    digitalWrite(KICKER_PIN, LOW);
  } else if (kicker_reaction == 0) {
  }

  if (period_count == kicker_count) {
    kicker_count = -1;
    kicker_reaction = -1;
  }
}
