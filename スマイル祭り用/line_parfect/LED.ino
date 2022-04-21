void F_LED_setup(int R, int G, int B) {
  pixels.begin();
  pixels.clear();
  for (int id = 0; id <= 31; id++) {
    pixels.setPixelColor(id, pixels.Color(R, G, B));
  }
  pixels.show();
}

void F_LED_loop(int R, int G, int B) {
  for (int id = 0; id <= 31; id++) {
    pixels.setPixelColor(id, pixels.Color(R, G, B));
  }
  pixels.show();
}
