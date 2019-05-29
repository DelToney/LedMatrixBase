#include <RainbowSpectrum.h>

// Fill the dots one after the other with a color
void SpectrumStatic(CRGB strip[], double size)  {
  
  for(uint16_t i=0; i<size; i++) {
    if(strip[i]){
      strip[i].setHSV((255/size)*i, 255, 50);
    }
  }
  FastLED.show();
}

//TODO make this for matrix
void SpectrumWave(CRGB strip[], double size)  {


  long currentUpdateTime = millis()/10;

  int8_t changeValue = (currentUpdateTime%256)/PI;


  for(uint16_t i=0; i<size; i++) {
    strip[i].setHSV((256/size)*i+changeValue, 255, 50);
    // Serial.printf("%i ", changeValue);
  }
  
  FastLED.show();
  delay(50);
}