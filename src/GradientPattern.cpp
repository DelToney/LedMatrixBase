#include "Common.h"

DEFINE_GRADIENT_PALETTE(custom_gp){
    0, 255, 255, 0,
    128, 225, 15, 0,
    255, 255, 255, 0};

CRGBPalette256 colorPalette = custom_gp;
TBlendType currentBlending = LINEARBLEND;
const int brightness = 50;


void DoSmoothGradient(cLEDMatrix<ROW_LENGTH, NUM_ROWS, HORIZONTAL_MATRIX> ledMatrix) {
static int count = 0;
    static byte colorIndex = 0;
    for (int i = 0; i < NUM_ROWS; i++)
    {

        for (int j = 0; j < ROW_LENGTH; j++)
        {
            int ledIndex = ledMatrixLayout[i][j];
            if (ledIndex != -1)
            {

                colorIndex = sin8((j * (256 / ROW_LENGTH) + count) % 256);

                CRGB Color = ColorFromPalette(colorPalette, colorIndex, brightness, currentBlending);
                ledMatrix(j, i).setRGB(Color.r, Color.g, Color.b);
            }
        }
    }

    if (count >= 256)
    {
        count = 0;
    }
    else
    {
        count += 2;
    }
}