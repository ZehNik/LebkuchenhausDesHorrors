#include <FastLED.h>
#include "Light_Functions.h"



CRGB animationInsideChristmas[NUM_FRAMES_INSIDE_CHRISTMAS][NUM_INSIDE_LEDS] = 
{
{CRGB::White, CRGB::Yellow, CRGB::White, CRGB::Yellow, CRGB::White},
{CRGB::Green, CRGB::Blue, CRGB::Green, CRGB::Blue, CRGB::Green},
{CRGB::Red, CRGB::Orange, CRGB::Red, CRGB::Orange, CRGB::Red}
};

CRGB animationRoofChristmas[NUM_FRAMES_ROOF_CHRISTMAS][NUM_ROOF_LEDS] = 
{
{CRGB::White, CRGB::Yellow, CRGB::White, CRGB::Yellow, CRGB::White},
{CRGB::Green, CRGB::Blue, CRGB::Green, CRGB::Blue, CRGB::Green},
{CRGB::Red, CRGB::Orange, CRGB::Red, CRGB::Orange, CRGB::Red}
};

CRGB staticPictureRoofChristmas[NUM_ROOF_LEDS] = 
{
CRGB::Red, CRGB::Green, CRGB::Blue, CRGB::Red, CRGB::Red // and so on
};
