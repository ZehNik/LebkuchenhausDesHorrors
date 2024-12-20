#ifndef LIGHT_FUNCTIONS_H
#define LIGHT_FUNCTIONS_H

#include <Arduino.h>
#include <FastLED.h>

// DEFINES
#define NUM_LEDS 15
#define NUM_LEDS_UNUSED 0 // unused leds

#define DATA_PIN 0
#define BASE_FRAME_LENGTH 100 // if you change it nothing works i dont know why,    it seems to be 10 ms

#define NUM_INSIDE_LEDS 5
#define OFFSET_INSIDE 2 // position of the first led used for inside -1 (first led on the strip is 1)
#define NUM_FRAMES_INSIDE_CHRISTMAS 3
#define INSIDE_DIVIDER_CHRISTMAS_ANIMATED 100 // ganzzahlige Vielfache
#define INSIDE_DIVIDER_RANDOM_FADE 100 // ganzzahlige Vielfache

#define NUM_ROOF_LEDS 5 // placeholder
#define OFFSET_ROOF 0 // position of the first led used for ROOF -1 (first led on the strip is 1)
#define NUM_FRAMES_ROOF_CHRISTMAS 3
#define ROOF_DIVIDER_CHRISTMAS_ANIMATED 100 // ganzzahlige Vielfache

#define NUM_OVEN_LEDS 3 // placeholder
#define OFFSET_OVEN 0 // placeholder
#define OVEN_DIVIDER_RANDOM_FADE 100 // ganzzahlige Vielfache





//code between here

extern CRGB allLEDs[NUM_LEDS];

// core functions
void setupLEDs(void);
void drawLED(void);

// functions that fill the buffer
void drawStaticLED(void);
void drawAnimatedLED(void);
void insideChristmasAnimated(void);
void insideRandomFade(void);
// buffer to Output with the library
void bufferToOut(void);



// per Bluetooth callable functions
void lpa0_OFF(void);
void lpa1_AllPresets1(void);
void lpo0_OFF(void);
void lpo1_Burning(void);
void lpr0_OFF(void);
void lpr1_Christmas(void);
void lpr2_ChristmasAnimated(void);
void lpr3_ChristmasAnimatedFade(void);
void lpi0_OFF(void);
void lpi1_Yellow(void);
void lpi2_YellowRandomFade(void);
void lpi3_ChristmasAnimated(void);


//code between here


#endif