void F_AMP_setup() {
  for (id = 0; id <= 3; id++) {
    pinMode(AMP_PIN[id], INPUT);
    pinMode(AMP_PIN[id], LOW);
  }
  pinMode(A_PIN, OUTPUT);
  pinMode(B_PIN, OUTPUT);
  pinMode(C_PIN, OUTPUT);
}

void F_line_choice(int choice) {
  int choice_output[3];
  switch (choice) {
    case 0:
      choice_output[2] = 0;
      choice_output[1] = 0;
      choice_output[0] = 0;
      break;
    case 1:
      choice_output[2] = 0;
      choice_output[1] = 0;
      choice_output[0] = 1;
      break;
    case 2:
      choice_output[2] = 0;
      choice_output[1] = 1;
      choice_output[0] = 0;
      break;
    case 3:
      choice_output[2] = 0;
      choice_output[1] = 1;
      choice_output[0] = 1;
      break;
    case 4:
      choice_output[2] = 1;
      choice_output[1] = 0;
      choice_output[0] = 0;
      break;
    case 5:
      choice_output[2] = 1;
      choice_output[1] = 0;
      choice_output[0] = 1;
      break;
    case 6:
      choice_output[2] = 1;
      choice_output[1] = 1;
      choice_output[0] = 0;
      break;
    case 7:
      choice_output[2] = 1;
      choice_output[1] = 1;
      choice_output[0] = 1;
      break;
      //default:
  }

  if (choice_output[2] == 1) {
    digitalWrite(C_PIN, HIGH);
  } else {
    digitalWrite(C_PIN, LOW);
  }

  if (choice_output[1] == 1) {
    digitalWrite(B_PIN, HIGH);
  } else {
    digitalWrite(B_PIN, LOW);
  }

  if (choice_output[0] == 1) {
    digitalWrite(A_PIN, HIGH);
  } else {
    digitalWrite(A_PIN, LOW);
  }
}
