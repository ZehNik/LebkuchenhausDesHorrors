#include "pitches.h"
#include <Arduino.h>

#define BUZZER1_PIN 14
#define BUZZER2_PIN 14

void setupMusic(void);
void playMusic(void);
void interruptBeat(int Pin, int Track, int currentBeat);

void b0(void);
void b1(void);
void b2(void);

