#include <Adafruit_NeoPixel.h>
const int FULL_COLOR = 40;
const int C_fullcolor_count = 31;
Adafruit_NeoPixel flame(C_fullcolor_count, FULL_COLOR, NEO_GRB + NEO_KHZ800);

void F_flame_setup()
{
    flame.begin();
    for (id = 0; id <= 31; id++)
    {
        // flame.setPixelColor(id, flame.Color(128, 128, 128));
        flame.setPixelColor(id, flame.Color(0, 0, 0));
        flame.show();
    }
}
