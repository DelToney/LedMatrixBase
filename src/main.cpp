
#include "RainbowSlide.h"
#include "RainbowSpectrum.h"
#include "Common.h"
#define LED_STRING_1 10


//instantiate LEDMatrix so that you can assign to it
static cLEDMatrix<ROW_LENGTH, NUM_ROWS, HORIZONTAL_MATRIX> ledBuffer;

//call whenever you wanna refresh the strip
void UpdateLEDStrip();

//print some element iteratedover the matrix
void PrintMatrix();

//prints over the ledString
void PrintString();

//fills the buffer with 0's
void InitializeMatrix();


void setup() {
  Serial.begin(9600);
  FastLED.addLeds<NEOPIXEL, LED_STRING_1>(ledString, NUM_LEDS);

  
  InitializeMatrix();

}

void loop() {
  SpectrumWave(ledBuffer);

  UpdateLEDStrip();
  delay(5);
}

void InitializeMatrix() {
  for(int i = 0; i < NUM_ROWS; i++) {
    for (int j = 0; j< ROW_LENGTH; j++) {
      ledBuffer(j, i) = 0;
    }
  }
  Serial.println("Matrix Initialized!");
}

void PrintString() {
  int ledIndex = 0;
  for(int i = 0; i < NUM_LEDS; i++) {
    Serial.printf("%i ", ledString[i].g);
  }
  Serial.println();
}

void PrintMatrix() {
  int ledIndex = 0;
  for(int i = 0; i < NUM_ROWS; i++) {
    for (int j = 0; j < ROW_LENGTH; j++) {
      ledIndex = ledMatrixLayout[i][j];
      Serial.printf("%i ", ledBuffer(j, i).g);
    }
    Serial.println();
  }
}

void UpdateLEDStrip() {
  for(int i = 0; i < NUM_ROWS; i++) {
    for (int j = 0; j < ROW_LENGTH; j++) {
      int ledIndex = ledMatrixLayout[i][j];
      if (ledIndex != -1) {
        ledString[ledIndex-1].setRGB(ledBuffer(j, i).r, ledBuffer(j, i).g, ledBuffer(j, i).b);
      }
    }
  }
  FastLED.show();
}