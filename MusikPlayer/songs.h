#include "pitches.h"

// Song 1: Alle meine Entchen

#define SONG_1_LENGTH 40 //in notes
#define SONG_1_NUM_TRACKS 2 // tone() has to be added for each track
int notesSong1[SONG_1_NUM_TRACKS][SONG_1_LENGTH] = {
  {
  NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4,
  NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4,
  NOTE_A4, NOTE_A4, NOTE_A4, NOTE_A4,
  NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4,
  NOTE_A4, NOTE_A4, NOTE_A4, NOTE_A4,
  NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4,
  NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4,
  NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4,
  NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4,
  NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4
  },{
  NOTE_G3, NOTE_G3, NOTE_C3, NOTE_D3,
  NOTE_C3, NOTE_C3, NOTE_C3, NOTE_C3,
  NOTE_F3, NOTE_F3, NOTE_F3, NOTE_F3,
  NOTE_E3, NOTE_E3, NOTE_E3, NOTE_E3,
  NOTE_F3, NOTE_F3, NOTE_F3, NOTE_F3,
  NOTE_E3, NOTE_E3, NOTE_E3, NOTE_E3,
  NOTE_D3, NOTE_D3, NOTE_D3, NOTE_D3,
  NOTE_C3, NOTE_C3, NOTE_C3, NOTE_C3,
  NOTE_A2, NOTE_G3, NOTE_G3, NOTE_G3,
  NOTE_C3, NOTE_C3, NOTE_C3, NOTE_C3
  }
};
bool interruptionsSong1[SONG_1_NUM_TRACKS][SONG_1_LENGTH] = { // 1 is for an interruption at the end of a note
  {
  1, 1, 1, 1,
  0, 1, 0, 1,
  1, 1, 1, 1,
  0, 0, 0, 1,
  1, 1, 1, 1,
  0, 0, 0, 1,
  1, 1, 1, 1,
  0, 1, 0, 1,
  1, 1, 1, 1,
  0, 0, 0, 1
  },{
  1, 1, 1, 1,
  0, 1, 0, 1,
  1, 1, 1, 1,
  0, 0, 0, 1,
  1, 1, 1, 1,
  0, 0, 0, 1,
  1, 1, 1, 1,
  0, 1, 0, 1,
  1, 1, 1, 1,
  0, 0, 0, 1
  }
};



//Song 2: Alle meine Entchen weil faul

#define SONG_2_LENGTH 40 //in notes
#define SONG_2_NUM_TRACKS 2 // tone() has to be added for each track
int notesSong2[SONG_2_NUM_TRACKS][SONG_2_LENGTH] = {
  {
  NOTE_C4, NOTE_D4, NOTE_E4, NOTE_F4,
  NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4,
  NOTE_A4, NOTE_A4, NOTE_A4, NOTE_A4,
  NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4,
  NOTE_A4, NOTE_A4, NOTE_A4, NOTE_A4,
  NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4,
  NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4,
  NOTE_E4, NOTE_E4, NOTE_E4, NOTE_E4,
  NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4,
  NOTE_C4, NOTE_C4, NOTE_C4, NOTE_C4
  },{
  NOTE_G3, NOTE_G3, NOTE_C3, NOTE_D3,
  NOTE_C3, NOTE_C3, NOTE_C3, NOTE_C3,
  NOTE_F3, NOTE_F3, NOTE_F3, NOTE_F3,
  NOTE_E3, NOTE_E3, NOTE_E3, NOTE_E3,
  NOTE_F3, NOTE_F3, NOTE_F3, NOTE_F3,
  NOTE_E3, NOTE_E3, NOTE_E3, NOTE_E3,
  NOTE_D3, NOTE_D3, NOTE_D3, NOTE_D3,
  NOTE_C3, NOTE_C3, NOTE_C3, NOTE_C3,
  NOTE_A2, NOTE_G3, NOTE_G3, NOTE_G3,
  NOTE_C3, NOTE_C3, NOTE_C3, NOTE_C3
  }
};
bool interruptionsSong2[SONG_2_NUM_TRACKS][SONG_2_LENGTH] = { // 1 is for an interruption at the end of a note
  {
  1, 1, 1, 1,
  0, 1, 0, 1,
  1, 1, 1, 1,
  0, 0, 0, 1,
  1, 1, 1, 1,
  0, 0, 0, 1,
  1, 1, 1, 1,
  0, 1, 0, 1,
  1, 1, 1, 1,
  0, 0, 0, 1
  },{
  1, 1, 1, 1,
  0, 1, 0, 1,
  1, 1, 1, 1,
  0, 0, 0, 1,
  1, 1, 1, 1,
  0, 0, 0, 1,
  1, 1, 1, 1,
  0, 1, 0, 1,
  1, 1, 1, 1,
  0, 0, 0, 1
  }
};
