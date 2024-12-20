#include "MusikAddOn.h"
#include "pitches.h"
#include "songs.h"

int BPM = 100; // normally one beat is a quarter note
int SONGEND_PAUSE = 8; // in beats
int NOTE_CUT_TIME = 100; // in ms



int songMode = 1;

void setupMusic() {
  pinMode(BUZZER1_PIN, OUTPUT);
  pinMode(BUZZER2_PIN, OUTPUT);
}

void playMusic() {
  static int currentBeat = 0;
  static int lastTime = millis(); // !!!!!!!!! -> unsigned long

  switch(songMode){
    case 0:
      break;

    case 1:
      if(millis() >= (lastTime + (BPM * 6000))) { // BPM * 60(min) * 1000(millis)
        tone(BUZZER1_PIN, notesSong1[0][currentBeat]);
        tone(BUZZER2_PIN, notesSong1[1][currentBeat]);

        currentBeat++;
        lastTime = millis();
      }

      if(millis() >= (lastTime + (BPM * 6000)) - NOTE_CUT_TIME) {
        interruptBeat1(BUZZER1_PIN, 1-1, currentBeat); // 1-1 = Track 1 (-1 because its an array)
        interruptBeat1(BUZZER2_PIN, 2-1, currentBeat);
      }

      if(currentBeat >= SONG_1_LENGTH + SONGEND_PAUSE){
        currentBeat = 0;
      }
      break;

    case 2: 
      if(millis() >= (lastTime + (BPM * 6000))) { // BPM * 60(min) * 1000(millis)
        tone(BUZZER1_PIN, notesSong2[0][currentBeat]);
        tone(BUZZER2_PIN, notesSong2[1][currentBeat]);

        currentBeat++;
        lastTime = millis();
      }

      if(millis() >= (lastTime + (BPM * 6000)) - NOTE_CUT_TIME) {
        interruptBeat2(BUZZER1_PIN, 1-1, currentBeat);
        interruptBeat2(BUZZER2_PIN, 2-1, currentBeat);
      }

      if(currentBeat >= SONG_2_LENGTH + SONGEND_PAUSE){
        currentBeat = 0;
      }
      break;
    
    default:
      songMode = 0;
  }

  
}

void interruptBeat1(int Pin, int Track, int currentBeat) {
  if(interruptionsSong1[Track][currentBeat]) {
    tone(Pin, 0);
  }
}
void interruptBeat2(int Pin, int Track, int currentBeat) {
  if(interruptionsSong2[Track][currentBeat]) {
    tone(Pin, 0);
  }
}