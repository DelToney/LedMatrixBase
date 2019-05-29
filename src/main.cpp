
#include "FileRead.h"
#include "RainbowSlide.h"
#include "RainbowSpectrum.h"
#include "Common.h"

#define LED_STRING_1 10





void UpdateLEDStrip() {
  for(int i = 0; i < NUM_ROWS; i++) {
    for (int j = 0; j < ROW_LENGTH; j++) {
      int ledIndex = ledMatrixLayout[i][j];
      if (ledIndex != -1) {
        ledString[ledIndex] = ledBuffer[i][j];
      }
    }
  }
}

void PrintMatrix() {
  int ledIndex = 0;
  for(int i = 0; i < NUM_ROWS; i++) {
    for (int j = 0; j < ROW_LENGTH; j++) {
      ledIndex = ledMatrixLayout[i][j];
      if (ledIndex != -1) {
        Serial.printf("%i ", ledIndex);
      }
    }
    Serial.println();
  }
}

void InitializeMatrix() {
  for(int i = 0; i < NUM_ROWS; i++) {
    for (int j = 0; j< ROW_LENGTH; j++) {
      ledBuffer[i][j] = 0;
    }
  }
  Serial.println("Matrix Initialized!");
}

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:  
  FastLED.addLeds<NEOPIXEL, LED_STRING_1>(ledString, NUM_LEDS);
  InitializeMatrix();

}

void loop() {
  PrintMatrix();

  
  UpdateLEDStrip();

  // SpectrumStatic(ledString, ledStringSize);

  // colorWipe(CRGB(25, 47, 160), 200, ledString, ledStringSize);

  delay(20);
}



