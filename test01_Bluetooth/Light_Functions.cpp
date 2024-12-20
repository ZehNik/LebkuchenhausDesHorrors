#include "Light_Functions.h"
#include "animations.h"
#include <FastLED.h>


///////////////////////////////////////////////// FastLED.show();

// arrays;
CRGB allLEDs[NUM_LEDS];
bool usedAllLEDs[NUM_LEDS] =
{1,1,1,1,1,0,1,0,1,1,1,1,1,1,1};
CRGB allLEDsBuffer[NUM_LEDS - NUM_LEDS_UNUSED] = {CRGB::Black};

int modeInside = 0; // 0-3
int modeRoof = 0; // 0-3
int modeOven = 0; // 0-2

// variables for drawLED
bool changestostatic = 0;
unsigned int timekeeperAnimations;

// variables for insideChristmasAnimated
int inChAnFrCnt = 0; // Inside Christmas-Animated Frame Counter

int roChAnFrCnt = 0; // Roof Christmas Animated Frame Counter


// variables for drawanimatedLED
int divInChAnCnt = 0; // Dividerer Inside Christmas-Animated Counter
int divInRaFaCnt = 0; // Dividerer Inside Random-Fade Counter

int divRoChAnCnt = 0; // Divider Roof Christmas Animated Counter
int divRoRaFaCnt = 0; // Divider Roof Random Fade Counter

int divOvBuCnt = 0; // Divider Oven Burning Counter




void setupLEDs(){
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(allLEDs, NUM_LEDS);
  timekeeperAnimations = millis();
}







void drawLED(){ // is in the main loop // changes between static / animation
  if(changestostatic){
    drawStaticLED();
    changestostatic = 0; // is being set 1 by the input functions
  } 
  if(timekeeperAnimations >= BASE_FRAME_LENGTH){
    drawAnimatedLED();
    timekeeperAnimations = millis();
  }

  bufferToOut();
}


void bufferToOut(){
  int j = 0;
  for(int i = 0; i < NUM_LEDS; i++){
    if(usedAllLEDs[i] == 1){
      allLEDs[i] = allLEDsBuffer[j];
      j++;
    }
  }

}


void drawStaticLED(){
  // Inside
  if(modeInside == 0){
    for(int i = 0; i < NUM_INSIDE_LEDS; i++){
      allLEDsBuffer[i + OFFSET_INSIDE] = CRGB::Black;
    }
  }else if(modeInside == 1){
    for(int i = 0; i < NUM_INSIDE_LEDS; i++){
      allLEDsBuffer[i + OFFSET_INSIDE] = CRGB::Yellow;
    }
  }

  // Roof
  if(modeRoof == 0){
    for(int i = 0; i < NUM_INSIDE_LEDS; i++){
      allLEDsBuffer[i + OFFSET_ROOF] = CRGB::Black;
    }
  }else if(modeRoof == 1){
    for(int i = 0; i < NUM_ROOF_LEDS; i++){
      allLEDsBuffer[i + OFFSET_ROOF] = staticPictureRoofChristmas[i];
    }
  }

  // Oven
  if(modeOven == 0){
    for(int i = 0; i < NUM_INSIDE_LEDS; i++){
      allLEDsBuffer[i + OFFSET_OVEN] = CRGB::Black;
    }
  }

}



void drawAnimatedLED(){ // 
  divInChAnCnt++;
  divInRaFaCnt++;
  divRoChAnCnt++;
  divRoRaFaCnt++;
  divOvBuCnt++;

  if((divInRaFaCnt >= INSIDE_DIVIDER_RANDOM_FADE) && (modeInside == 2)){
    insideRandomFade();
    divInRaFaCnt = 0;
  }
  if((divInChAnCnt >= INSIDE_DIVIDER_CHRISTMAS_ANIMATED) && (modeInside == 3)){
    insideChristmasAnimated();
    divInChAnCnt = 0;
  }
  
  

  FastLED.show();
}


void insideRandomFade(){ // writes random Black or Yellow into the buffer
  for(int i = 0; i < NUM_INSIDE_LEDS; i++){
    if(1 == random(0, 2+1)){
      allLEDsBuffer[i + OFFSET_INSIDE] = CRGB::Yellow;
    }else{
      allLEDsBuffer[i + OFFSET_INSIDE] = CRGB::Black;
    }
    
  }
}

void insideChristmasAnimated(){ // writes with every call the next frame into the buffer
  if(inChAnFrCnt >= NUM_FRAMES_INSIDE_CHRISTMAS){
    inChAnFrCnt = 0;
  }
  for(int i = 0; i < NUM_INSIDE_LEDS; i++){
    allLEDsBuffer[i + OFFSET_INSIDE] = animationInsideChristmas[inChAnFrCnt][i];
  }
  inChAnFrCnt++;
}

void roofChristmasAnimated(){
  if(roChAnFrCnt >= NUM_FRAMES_ROOF_CHRISTMAS){
    roChAnFrCnt = 0;
  }
  for(int i = 0; i < NUM_ROOF_LEDS; i++){
    allLEDsBuffer[i + OFFSET_ROOF] = animationRoofChristmas[roChAnFrCnt][i];
  }
  roChAnFrCnt++;
}




void lpa0_OFF(){
  changestostatic = 1;


}

void lpa1_AllPresets1(){
  changestostatic = 1;

}

void lpo0_OFF(){
  changestostatic = 1;

}

void lpo1_Burning(){


}


void lpr0_OFF(){
  changestostatic = 1;

}


void lpr1_Christmas(){
  changestostatic = 1;

}


void lpr2_ChristmasAnimated(){


}


void lpr3_ChristmasAnimatedFade(){


}


void lpi0_OFF(){
  changestostatic = 1;
  modeInside = 0;
}

void lpi1_Yellow(){
  changestostatic = 1;
  modeInside = 1;
}

void lpi2_YellowRandomFade(){
  modeInside = 2;
}


void lpi3_ChristmasAnimated(){
  modeInside = 3;
}




