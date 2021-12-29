














void full_led(int red, int green, int blue) {
  frameLED.clear();
  for (int id = 0; id <= FRAMELED - 1; id += 1) {
    frameLED.setPixelColor(id, frameLED.Color(red, green, blue));
  }
  frameLED.show();
}
