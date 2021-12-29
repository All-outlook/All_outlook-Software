void boot_led() {
  pixels.clear();
  for (int id = 0; id <= 23; id += 1) {
    pixels.setPixelColor(id, pixels.Color(10, 10, 10));
  }
  pixels.show();
  delay(1000);
}

void line_led() {
  pixels.clear();
  for (int id = 0; id <= 23; id += 1) {
    pixels.setPixelColor(id, pixels.Color(250, 0, 0));
  }
  pixels.show();
}
