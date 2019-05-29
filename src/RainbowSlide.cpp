#include <RainbowSlide.h>

// Fill the dots one after the other with a color
void colorWipe(CRGB c, uint8_t wait, CRGB strip[], double size)  {
  for(uint16_t i=0; i<size; i++) {
    strip[i].setRGB(c.r, c.g, c.b);
    FastLED.show();
    delay(wait);
  }
}