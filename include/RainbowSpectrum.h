#include <math.h>
#include <FastLED.h>
#include <LEDMatrix.h>
#include "Common.h"

//projects a hsv gradient over the input matrix
void SpectrumStatic(cLEDMatrix<ROW_LENGTH, NUM_ROWS, HORIZONTAL_MATRIX> ledMatrix);

//spectrum static moving
void SpectrumWave(cLEDMatrix<ROW_LENGTH, NUM_ROWS, HORIZONTAL_MATRIX> ledMatrix);