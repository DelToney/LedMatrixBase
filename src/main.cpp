#include <Arduino.h>
#include <FastLED.h>


#define NUM_LEDS 300
#define NUM_ROWS 10
#define ROW_LENGTH 10
#define LED_STRING_1 10

CRGB led_string[NUM_LEDS];

CRGB ledBuffer[NUM_LEDS/NUM_ROWS][ROW_LENGTH];


void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
}

CRGB ToXY(CRGB led_string[]) {

}