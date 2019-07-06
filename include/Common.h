#ifndef __COMMON_H_INCLUDED__
#define __COMMON_H_INCLUDED__
#include <Arduino.h>
#include <FastLED.h>
#include <LEDMatrix.h>
#include <Wire.h>

//number of LED's in your Strip
const int NUM_LEDS = 26;

//number of led strips in your matrix
const int NUM_ROWS = 7;

//length of the longest row in your matrix 
const int ROW_LENGTH = 7;

const int NUM_BUFFER_LEDS = NUM_ROWS*ROW_LENGTH;


static CRGB ledString[NUM_LEDS];


//this holds the template for the LED Matrix; 
//TODO make this read from a json doc 
const int ledMatrixLayout[NUM_ROWS][ROW_LENGTH] = { // test templpate
    {1,2,3,-1,14,15,16},
    {5,4,-1,-1,-1,18,17},
    {6,-1,-1,-1,-1,-1,19},
    {7,-1,-1,-1,-1,-1,20},
    {8,-1,-1,-1,-1,-1,21},
    {10,9,-1,-1,-1,23,22},
    {11,12,13,-1,24,25,26}
};

#endif