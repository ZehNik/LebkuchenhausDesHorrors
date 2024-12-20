// ---------- defines ----------
#define COMMAND_SIZE 4
#define COMMAND_EXECUTIION_SIGN '!' // has to be a char

// ---------- includes ----------
#include <SerialBT.h>
#include <FastLED.h>
#include <Servo.h>
#include "Light_Functions.h"
#include "MusikAddOn.h"

void executeCommands(void);
void commandLight(void);


// ---------- variables ----------
char commands[COMMAND_SIZE]; // the commands will be saved here
int commandlength = 0; // the current length of the command after receiving a execution sign
int commandwritingposition = 0; // where the current command has to go to
char c= '0';


// ---------- setup ----------
void setup(){
  SerialBT.setName("PicoWTest 00:00:00:00:00:00");
  SerialBT.begin();
  setupMusic();
  setupLEDs();
}


// ---------- loop ----------
void loop() {
  playMusic();
  while(SerialBT.available()){ // check wethever chars are in the buffer

    c = SerialBT.read(); // deletes the read char out of the buffer
    if(c == COMMAND_EXECUTIION_SIGN){
      executeCommands();
      commandwritingposition = -1; // i dont know why tf we need -1!!!!! 0 should be sufficient but it seems like the "else if" is getting triggerd once after it should be by a weird unknown symbol which is very mean destroying my beautiful code
      
      
    }else if(c != '\r' && c != ' '){
      c = tolower(c);
      commands[commandwritingposition] = c;
      commandwritingposition++;
    }
  }
  drawLED();
}


// ---------- other functions ----------
void executeCommands(void){ // differentiates between the 3 different categorys: ligths, servo and buzzer
  //char category = commands[0]
  
  switch(commands[0]){
    case 'l': // lights
      commandLight();
      break;

    case 's': // servo
      commandServo();
      break;

    case 'b': // buzzer
      commandBuzzer();
      break;

    default:
    for(int i = 0; i == commandwritingposition; i++){
      SerialBT.write(commands[i]);
    }
      SerialBT.println(": ist kein gültiger Befehl!");
      SerialBT.println("Wenn du Hilfe brauchst gib ein: hilfe!");
  }
}


// ---------- filter Lights ----------
void commandLight(void){
  if(commands[1] == 'p'){ // the different Preset categorys
    char presetCategory = commands[2];
    char specificPreset = commands[3];
    switch(presetCategory){ // 
      case 'a': // ---------------------------------------------------------- Case All Start
        switch(specificPreset){
          case '0': // Off
            SerialBT.println("sucessfully executed: Lights - Presets - All - 0");
            break;

          case '1': // all 1 of the other presets
            SerialBT.println("sucessfully executed: Lights - Presets - All - 1");
            break;

          default: 
            SerialBT.println("Lights - Presets - All - 0(Off) / 1(Everything on first preset)");
        }
        break; // ---------------------------------------------------------- Case All End

      case 'o': // ---------------------------------------------------------- Case Oven Start
         switch(specificPreset){
          case '0': // Off
            SerialBT.println("sucessfully executed: Lights - Presets - Oven - Off");
            break;

          case '1': // Burning
            SerialBT.println("sucessfully executed: Lights - Presets - Oven - Burning");
            break;

          default:
            SerialBT.println("Lights - Presets - Oven - 0(Off) / 1(Burning)");
         }
        break; // ---------------------------------------------------------- Case Oven End

      case 'r': // ---------------------------------------------------------- Case Roof Start
        switch(specificPreset){
          case '0': // Off
            SerialBT.println("sucessfully executed: Lights - Presets - Roof - Off");
            break;

          case '1': // Christmas Static
            SerialBT.println("sucessfully executed: Lights - Presets - Roof - Christmas Static");
            break;

          case '2': // Christmas Animated
            SerialBT.println("sucessfully executed: Lights - Presets - Roof - Christmas Animated");
            break;

          case '3': // Christmas Random Fade
            SerialBT.println("sucessfully executed: Lights - Presets - Roof - Christmas Random Fade");
            break; 

          default:
            SerialBT.println("Lights - Presets - Roof - 0(Off) / 1(Christmas Static) / 2(Christmas Animated / 3(Christmas Random Fade)");
        }
        break; // ---------------------------------------------------------- Case Roof End
        
      case 'i': // ---------------------------------------------------------- Case Inside Start
        switch(specificPreset){
          case '0': // Off 
            lpi0_OFF();
            SerialBT.println("sucessfully executed: Lights - Presets - Inside - Off");
            break;

          case '1':
            lpi1_Yellow();
            SerialBT.println("sucessfully executed: Lights - Presets - Inside - Yellow");
            break;

          case '2': // Yellow Random Fade
            lpi2_YellowRandomFade();
            SerialBT.println("sucessfully executed: Lights - Presets - Inside - Yellow Random Fade");
            break;

          case '3': // Christmas Animated
            lpi3_ChristmasAnimated();
            SerialBT.println("sucessfully executed: Lights - Presets - Inside - Christmas Animated");
            break;

          default:
            SerialBT.println("Lights - Presets - Inside - 0(Off) / 1(Yellow Random Fade) / 2(Christmas Animated)");
        }
        break; // ---------------------------------------------------------- Case Inside Start
    }


  }else if (commands[1] == 'c'){ // Custom: a lot will be changable in future versions (maybe)
    SerialBT.println("Feature not available yet: Costum");
  }
}


// ---------- filter Servo ----------
void commandServo(){
  
  SerialBT.println("Servo Commands not available");
}


// ---------- filter Buzzer ----------
void commandBuzzer(){
  switch(commands[1]){
    case '0':
      b0();
      SerialBT.println("sucessfully executed: Buzzer - Off");
      break;

    case '1':
      b1();
      SerialBT.println("sucessfully executed: Buzzer - Song 1");
      break;

    case '2':
     b2();
     SerialBT.println("sucessfully executed: Buzzer - Song 2");
     break;
    
    default:
      SerialBT.println("Buzzer - 0(Off) / 1(Song 1) / 2(Song 2)");
  }
}


// Für NIggi




