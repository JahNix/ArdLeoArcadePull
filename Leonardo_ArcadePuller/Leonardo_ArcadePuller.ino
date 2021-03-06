/* This is a Jah Nix Productions release... MAME-duino? MAME-onardo?
Essentially we have a Keyboard setup for MAME (based on my own usage).
Joystick mapped to Arrow Keys, 10 Player buttons (see jpg on Git), Coin In, Start, Select.

I had to do this to satisfy my own knowledge and skillset. This is not because I thought I could do it better.
Although that being said, I've added most of the variables in the definitions to make editing a bit easier
thank most of the examples I've seen.

I hope this helps someone like the many examples have helped me...!   */


#include "Keyboard.h"

// Player 1 Controls
#define keyP1_UP 218        // Keypress UP Arrow
#define keyP1_DOWN 217      // Keypress DOWN Arrow
#define keyP1_LEFT 216      // Keypress LEFT Arrow
#define keyP1_RIGHT 215     // Keypress RIGHT Arrow

// Player 1 Buttons
#define keyP1_B1 113        // Keypress Q
#define keyP1_B2 119        // Keypress W    
#define keyP1_B3 101        // Keypress E  
#define keyP1_B4 114        // Keypress R
#define keyP1_B5 116        // Keypress T
#define keyP1_B6 97         // Keypress A  
#define keyP1_B7 115        // Keypress S    
#define keyP1_B8 100        // Keypress D
#define keyP1_B9 102        // Keypress F
#define keyP1_B10 103       // Keypress G

// Player 1 MAME Controls
#define keyCOIN_IN  53      // Press Key 5
#define keyP1_START 1       // Keypress 1
//#define keyP1_SELECT         // NFI 

// Define Trigger Pins
const int COIN_IN = A0;      // A0
const int COIN_LIGHT = A1;   // A1
const int P1_START = A2;     // A2
const int P1_SELECT = A3;    // A3
// const int xxxxxxx = A4;   // A4
// const int xxxxxxx = A5;   // A5

const int P1_B1 = 0;         // D0
const int P1_B2 = 1;         // D1
const int P1_B3 = 2;         // D2
const int P1_B4 = 3;         // D3
const int P1_B5 = 4;         // D4
const int P1_B6 = 5;         // D5
const int P1_B7 = 6;         // D6
const int P1_B8 = 7;         // D7
const int P1_B9 = 8;         // D8
const int P1_B10 = 9;        // D9

const int P1_UP = 10;        // D10      
const int P1_DOWN = 11;      // D11      
const int P1_LEFT = 12;      // D12
const int P1_RIGHT = 13;     // D13

// LastButtonStateVariables
int COIN_IN_buttonState;                // the current reading from the COIN_IN pin
int COIN_IN_lastButtonState = LOW ;     // the previous reading from the COIN_IN pin
int P1_UP_buttonState;                  // the current reading from the P1_UP pin
int P1_UP_lastButtonState = HIGH;       // the previous reading from the P1_UP pin
int P1_DOWN_buttonState;                // the current reading from the P1_DOWN pin
int P1_DOWN_lastButtonState = HIGH;     // the previous reading from the P1_DOWN pin
int P1_LEFT_buttonState;                // the current reading from the P1_LEFT pin
int P1_LEFT_lastButtonState = HIGH;     // the previous reading from the P1_LEFT pin
int P1_RIGHT_buttonState;               // the current reading from the P1_RIGHT pin
int P1_RIGHT_lastButtonState = HIGH;    // the previous reading from the P1_RIGHT pin
int P1_B1_buttonState;                  // the current reading from the P1_B1 pin
int P1_B1_lastButtonState = HIGH;       // the previous reading from the P1_B1 pin
int P1_B2_buttonState;                  // the current reading from the P1_B2 pin     
int P1_B2_lastButtonState = HIGH;       // the previous reading from the P1_B2 pin
int P1_B3_buttonState;                  // the current reading from the P1_B3 pin
int P1_B3_lastButtonState = HIGH;       // the previous reading from the P1_B3 pin    
int P1_B4_buttonState;                  // the current reading from the P1_B4 pin
int P1_B4_lastButtonState = HIGH;       // the previous reading from the P1_B4 pin
int P1_B5_buttonState;                  // the current reading from the P1_B5 pin
int P1_B5_lastButtonState = HIGH;       // the previous reading from the P1_B5 pin
int P1_B6_buttonState;                  // the current reading from the P1_B6 pin
int P1_B6_lastButtonState = HIGH;       // the previous reading from the P1_B6 pin
int P1_B7_buttonState;                  // the current reading from the P1_B7 pin
int P1_B7_lastButtonState = HIGH;       // the previous reading from the P1_B7 pin
int P1_B8_buttonState;                  // the current reading from the P1_B8 pin
int P1_B8_lastButtonState = HIGH;       // the previous reading from the P1_B8 pin
int P1_B9_buttonState;                  // the current reading from the P1_B9 pin
int P1_B9_lastButtonState = HIGH;       // the previous reading from the P1_B9 pin
int P1_B10_buttonState;                  // the current reading from the P1_B10 pin
int P1_B10_lastButtonState = HIGH;       // the previous reading from the P1_B10 pin
int P1_START_buttonState;               // the current reading from the P1_START pin   
int P1_START_lastButtonState = HIGH;    // the previous reading from the P1_START pin
int P1_SELECT_buttonState;               // the current reading from the P1_SELECT pin
int P1_SELECT_lastButtonState = HIGH;    // the previous reading from the P1_SELECT pin


// Debounce Variables  
unsigned long lastDebounceTime_COIN_IN = 0;   // the last time the COIN_IN pin was toggled
unsigned long debounceDelay_COIN_IN = 30;     // the debounce time;
unsigned long lastDebounceTime_P1_UP = 0;     // the last time the P1_UP pin was toggled
unsigned long debounceDelay_P1_UP = 30;       // the debounce time;
unsigned long lastDebounceTime_P1_DOWN = 0;   // the last time the P1_DOWN pin was toggled
unsigned long debounceDelay_P1_DOWN = 30;     // the debounce time;
unsigned long lastDebounceTime_P1_LEFT = 0;   // the last time the P1_LEFT pin was toggled
unsigned long debounceDelay_P1_LEFT = 30;     // the debounce time;
unsigned long lastDebounceTime_P1_RIGHT = 0;  // the last time the P1_RIGHT pin was toggled
unsigned long debounceDelay_P1_RIGHT = 30;    // the debounce time;
unsigned long lastDebounceTime_P1_B1 = 0;     // the last time the P1_B1 was toggled
unsigned long debounceDelay_P1_B1 = 30;       // the debounce time;
unsigned long lastDebounceTime_P1_B2 = 0;     // the last time the P1_B2 pin was toggled
unsigned long debounceDelay_P1_B2 = 30;       // the debounce time;
unsigned long lastDebounceTime_P1_B3 = 0;     // the last time the P1_B3 pin was toggled
unsigned long debounceDelay_P1_B3 = 30;       // the debounce time;
unsigned long lastDebounceTime_P1_B4 = 0;     // the last time the P1_B4 pin was toggled
unsigned long debounceDelay_P1_B4 = 30;       // the debounce time;
unsigned long lastDebounceTime_P1_B5 = 0;     // the last time the P1_B5 pin was toggled
unsigned long debounceDelay_P1_B5 = 30;       // the debounce time;
unsigned long lastDebounceTime_P1_B6 = 0;     // the last time the P1_B6 pin was toggled
unsigned long debounceDelay_P1_B6 = 30;       // the debounce time;
unsigned long lastDebounceTime_P1_B7 = 0;     // the last time the P1_B7 pin was toggled
unsigned long debounceDelay_P1_B7 = 30;       // the debounce time;
unsigned long lastDebounceTime_P1_B8 = 0;     // the last time the P1_B8 pin was toggled
unsigned long debounceDelay_P1_B8 = 30;       // the debounce time;
unsigned long lastDebounceTime_P1_B9 = 0;     // the last time the P1_B9 pin was toggled
unsigned long debounceDelay_P1_B9 = 30;       // the debounce time;
unsigned long lastDebounceTime_P1_B10 = 0;     // the last time the P1_B10 pin was toggled
unsigned long debounceDelay_P1_B10 = 30;       // the debounce time;
unsigned long lastDebounceTime_P1_START = 0;  // the last time the P1_START pin was toggled
unsigned long debounceDelay_P1_START = 30;    // the debounce time;
unsigned long lastDebounceTime_P1_SELECT = 0; // the last time the P1_SELECT pin was toggled
unsigned long debounceDelay_P1_SELECT = 30;   // the debounce time;

void setup() {

  pinMode (COIN_IN, INPUT);
  pinMode (P1_START, INPUT_PULLUP);
  pinMode (P1_SELECT, INPUT_PULLUP);
  pinMode (P1_UP, INPUT_PULLUP);
  pinMode (P1_DOWN, INPUT_PULLUP);
  pinMode (P1_LEFT, INPUT_PULLUP);
  pinMode (P1_RIGHT, INPUT_PULLUP);
  pinMode (P1_B1, INPUT_PULLUP);
  pinMode (P1_B2, INPUT_PULLUP);
  pinMode (P1_B3, INPUT_PULLUP);
  pinMode (P1_B4, INPUT_PULLUP);
  pinMode (P1_B5, INPUT_PULLUP);
  pinMode (P1_B6, INPUT_PULLUP);
  pinMode (P1_B7, INPUT_PULLUP);
  pinMode (P1_B8, INPUT_PULLUP);
  pinMode (P1_B9, INPUT_PULLUP);
  pinMode (P1_B10, INPUT_PULLUP);
  pinMode (P1_START, INPUT_PULLUP);
  pinMode (P1_SELECT, INPUT_PULLUP);

  Keyboard.begin();
}

void loop() {

    checkCOIN_IN();
    checkP1_UP();
    checkP1_DOWN();
    checkP1_LEFT();
    checkP1_RIGHT();
    checkP1_B1();
    checkP1_B2();  
    checkP1_B3();
    checkP1_B4();    
    checkP1_B5();    
    checkP1_B6();
    checkP1_B7();
    checkP1_B8();
    checkP1_B9();
    checkP1_B10();
    

}

    //  Subscript to Call the If Functions

void checkCOIN_IN() {
      int COIN_IN_reading = digitalRead(COIN_IN);
      // If the switch changed, due to noise or pressing:
        if (COIN_IN_reading != COIN_IN_lastButtonState) {
        // reset the debouncing timer
        lastDebounceTime_COIN_IN = millis();
        }

        if ((millis() - lastDebounceTime_COIN_IN ) > debounceDelay_COIN_IN) {
        // whatever the reading is at, it's been there for longer
        // than the debounce delay, so take it as the actual current state:   
        // if the button state has changed:
        if (COIN_IN_reading != COIN_IN_buttonState) {
          COIN_IN_buttonState = COIN_IN_reading;

        // only toggle if the new button state is HIGH
        if (COIN_IN_buttonState == HIGH) {
        Keyboard.write(keyCOIN_IN);
              }
            }
          }
        COIN_IN_lastButtonState = COIN_IN_reading;  
        }
       
void checkP1_B1() {
      int P1_B1_reading = digitalRead(P1_B1);
      // If the switch changed, due to noise or pressing:
          if (P1_B1_reading != P1_B1_lastButtonState) {
          // reset the debouncing timer
          lastDebounceTime_P1_B1 = millis();
          }

          if ((millis() - lastDebounceTime_P1_B1 ) > debounceDelay_P1_B1) {
          // whatever the reading is at, it's been there for longer
          // than the debounce delay, so take it as the actual current state:
          // if the button state has changed:
          if (P1_B1_reading != P1_B1_buttonState) {
            P1_B1_buttonState = P1_B1_reading;

          // only toggle if the new button state is LOW
          if (P1_B1_buttonState == LOW) {
          Keyboard.press(keyP1_B1);

              }
          if (P1_B1_buttonState == HIGH) {
          Keyboard.release(keyP1_B1);
              }
            }
          }
        P1_B1_lastButtonState = P1_B1_reading;  
        }        

void checkP1_B2() {
      int P1_B2_reading = digitalRead(P1_B2);
      // If the switch changed, due to noise or pressing:
          if (P1_B2_reading != P1_B2_lastButtonState) {
          // reset the debouncing timer
          lastDebounceTime_P1_B2 = millis();
          }

          if ((millis() - lastDebounceTime_P1_B2 ) > debounceDelay_P1_B2) {
          // whatever the reading is at, it's been there for longer
          // than the debounce delay, so take it as the actual current state:
          // if the button state has changed:
          if (P1_B2_reading != P1_B2_buttonState) {
            P1_B2_buttonState = P1_B2_reading;

          // only toggle if the new button state is LOW
          if (P1_B2_buttonState == LOW) {
          Keyboard.press(keyP1_B2);

              }
          if (P1_B2_buttonState == HIGH) {
          Keyboard.release(keyP1_B2);
              }
            }
          }
        P1_B2_lastButtonState = P1_B2_reading;  
        }

void checkP1_B3() {
      int P1_B3_reading = digitalRead(P1_B3);
      // If the switch changed, due to noise or pressing:
          if (P1_B3_reading != P1_B3_lastButtonState) {
          // reset the debouncing timer
          lastDebounceTime_P1_B3 = millis();
          }

          if ((millis() - lastDebounceTime_P1_B3 ) > debounceDelay_P1_B3) {
          // whatever the reading is at, it's been there for longer
          // than the debounce delay, so take it as the actual current state:
          // if the button state has changed:
          if (P1_B3_reading != P1_B3_buttonState) {
            P1_B3_buttonState = P1_B3_reading;

          // only toggle if the new button state is LOW
          if (P1_B3_buttonState == LOW) {
          Keyboard.press(keyP1_B3);

              }
          if (P1_B3_buttonState == HIGH) {
          Keyboard.release(keyP1_B3);
              }
            }
          }
        P1_B3_lastButtonState = P1_B3_reading;  
        }

void checkP1_B4() {
      int P1_B4_reading = digitalRead(P1_B4);
      // If the switch changed, due to noise or pressing:
          if (P1_B4_reading != P1_B4_lastButtonState) {
          // reset the debouncing timer
          lastDebounceTime_P1_B4 = millis();
          }

          if ((millis() - lastDebounceTime_P1_B4 ) > debounceDelay_P1_B4) {
          // whatever the reading is at, it's been there for longer
          // than the debounce delay, so take it as the actual current state:
          // if the button state has changed:
          if (P1_B4_reading != P1_B4_buttonState) {
            P1_B4_buttonState = P1_B4_reading;

          // only toggle if the new button state is LOW
          if (P1_B4_buttonState == LOW) {
          Keyboard.press(keyP1_B4);

              }
          if (P1_B4_buttonState == HIGH) {
          Keyboard.release(keyP1_B4);
              }
            }
          }
        P1_B4_lastButtonState = P1_B4_reading;  
        }

void checkP1_B5() {
      int P1_B5_reading = digitalRead(P1_B5);
      // If the switch changed, due to noise or pressing:
          if (P1_B5_reading != P1_B5_lastButtonState) {
          // reset the debouncing timer
          lastDebounceTime_P1_B5 = millis();
          }

          if ((millis() - lastDebounceTime_P1_B5 ) > debounceDelay_P1_B5) {
          // whatever the reading is at, it's been there for longer
          // than the debounce delay, so take it as the actual current state:
          // if the button state has changed:
          if (P1_B5_reading != P1_B5_buttonState) {
            P1_B5_buttonState = P1_B5_reading;

          // only toggle if the new button state is LOW
          if (P1_B5_buttonState == LOW) {
          Keyboard.press(keyP1_B5);

              }
          if (P1_B5_buttonState == HIGH) {
          Keyboard.release(keyP1_B5);
              }
            }
          }
        P1_B5_lastButtonState = P1_B5_reading;  
        }

void checkP1_B6() {
      int P1_B6_reading = digitalRead(P1_B6);
      // If the switch changed, due to noise or pressing:
          if (P1_B6_reading != P1_B6_lastButtonState) {
          // reset the debouncing timer
          lastDebounceTime_P1_B6 = millis();
          }

          if ((millis() - lastDebounceTime_P1_B6 ) > debounceDelay_P1_B6) {
          // whatever the reading is at, it's been there for longer
          // than the debounce delay, so take it as the actual current state:
          // if the button state has changed:
          if (P1_B6_reading != P1_B6_buttonState) {
            P1_B6_buttonState = P1_B6_reading;

          // only toggle if the new button state is LOW
          if (P1_B6_buttonState == LOW) {
          Keyboard.press(keyP1_B6);

              }
          if (P1_B6_buttonState == HIGH) {
          Keyboard.release(keyP1_B6);
              }
            }
          }
        P1_B6_lastButtonState = P1_B6_reading;  
        }

void checkP1_B7() {
      int P1_B7_reading = digitalRead(P1_B7);
      // If the switch changed, due to noise or pressing:
          if (P1_B7_reading != P1_B7_lastButtonState) {
          // reset the debouncing timer
          lastDebounceTime_P1_B7 = millis();
          }

          if ((millis() - lastDebounceTime_P1_B7 ) > debounceDelay_P1_B7) {
          // whatever the reading is at, it's been there for longer
          // than the debounce delay, so take it as the actual current state: 
          // if the button state has changed:
          if (P1_B7_reading != P1_B7_buttonState) {
            P1_B7_buttonState = P1_B7_reading;

          // only toggle if the new button state is LOW
          if (P1_B7_buttonState == LOW) {
          Keyboard.press(keyP1_B7);

              }
          if (P1_B7_buttonState == HIGH) {
          Keyboard.release(keyP1_B7);
              }
            }
          }
        P1_B7_lastButtonState = P1_B7_reading;  
        }

void checkP1_B8() {
      int P1_B8_reading = digitalRead(P1_B8);
      // If the switch changed, due to noise or pressing:
          if (P1_B8_reading != P1_B8_lastButtonState) {
          // reset the debouncing timer
          lastDebounceTime_P1_B8 = millis();
          }

          if ((millis() - lastDebounceTime_P1_B8 ) > debounceDelay_P1_B8) {
          // whatever the reading is at, it's been there for longer
          // than the debounce delay, so take it as the actual current state:
          // if the button state has changed:
          if (P1_B8_reading != P1_B8_buttonState) {
            P1_B8_buttonState = P1_B8_reading;

          // only toggle if the new button state is LOW
          if (P1_B8_buttonState == LOW) {
          Keyboard.press(keyP1_B8);

              }
          if (P1_B8_buttonState == HIGH) {
          Keyboard.release(keyP1_B8);
              }
            }
          }
        P1_B8_lastButtonState = P1_B8_reading;  
        }

void checkP1_B9() {
      int P1_B9_reading = digitalRead(P1_B9);
      // If the switch changed, due to noise or pressing:
          if (P1_B9_reading != P1_B9_lastButtonState) {
          // reset the debouncing timer
          lastDebounceTime_P1_B9 = millis();
          }

          if ((millis() - lastDebounceTime_P1_B9 ) > debounceDelay_P1_B9) {
          // whatever the reading is at, it's been there for longer
          // than the debounce delay, so take it as the actual current state:
          // if the button state has changed:
          if (P1_B9_reading != P1_B9_buttonState) {
            P1_B9_buttonState = P1_B9_reading;

          // only toggle if the new button state is LOW
          if (P1_B9_buttonState == LOW) {
          Keyboard.press(keyP1_B9);

              }
          if (P1_B9_buttonState == HIGH) {
          Keyboard.release(keyP1_B9);
              }
            }
          }
        P1_B9_lastButtonState = P1_B9_reading;  
        }

void checkP1_B10() {
      int P1_B10_reading = digitalRead(P1_B10);
      // If the switch changed, due to noise or pressing:
          if (P1_B10_reading != P1_B10_lastButtonState) {
          // reset the debouncing timer
          lastDebounceTime_P1_B10 = millis();
          }

          if ((millis() - lastDebounceTime_P1_B10 ) > debounceDelay_P1_B10) {
          // whatever the reading is at, it's been there for longer
          // than the debounce delay, so take it as the actual current state:
          // if the button state has changed:
          if (P1_B10_reading != P1_B10_buttonState) {
            P1_B10_buttonState = P1_B10_reading;

          // only toggle if the new button state is LOW
          if (P1_B10_buttonState == LOW) {
          Keyboard.press(keyP1_B10);

              }
          if (P1_B10_buttonState == HIGH) {
          Keyboard.release(keyP1_B10);
              }
            }
          }
        P1_B10_lastButtonState = P1_B10_reading;  
      }

void checkP1_UP() {
      int P1_UP_reading = digitalRead(P1_UP);
      // If the switch changed, due to noise or pressing:
          if (P1_UP_reading != P1_UP_lastButtonState) {
          // reset the debouncing timer
          lastDebounceTime_P1_UP = millis();
          }

          if ((millis() - lastDebounceTime_P1_UP ) > debounceDelay_P1_UP) {
          // whatever the reading is at, it's been there for longer
          // than the debounce delay, so take it as the actual current state:
          // if the button state has changed:
          if (P1_UP_reading != P1_UP_buttonState) {
            P1_UP_buttonState = P1_UP_reading;

          // only toggle if the new button state is LOW
          if (P1_UP_buttonState == LOW) {
          Keyboard.press(keyP1_UP);

              }
          if (P1_UP_buttonState == HIGH) {
          Keyboard.release(keyP1_UP);
              }
            }
          }
        P1_UP_lastButtonState = P1_UP_reading;  
        }

void checkP1_DOWN() {
      int P1_DOWN_reading = digitalRead(P1_DOWN);
      // If the switch changed, due to noise or pressing:
          if (P1_DOWN_reading != P1_DOWN_lastButtonState) {
          // reset the debouncing timer
          lastDebounceTime_P1_DOWN = millis();
          }

          if ((millis() - lastDebounceTime_P1_DOWN ) > debounceDelay_P1_DOWN) {
          // whatever the reading is at, it's been there for longer
          // than the debounce delay, so take it as the actual current state:
          // if the button state has changed:
          if (P1_DOWN_reading != P1_DOWN_buttonState) {
            P1_DOWN_buttonState = P1_DOWN_reading;

          // only toggle if the new button state is LOW
          if (P1_DOWN_buttonState == LOW) {
          Keyboard.press(keyP1_DOWN);
              }
          if (P1_DOWN_buttonState == HIGH) {
          Keyboard.release(keyP1_DOWN);
              }
            }
          }
        P1_DOWN_lastButtonState = P1_DOWN_reading;  
        }

void checkP1_LEFT() {
      int P1_LEFT_reading = digitalRead(P1_LEFT);
      // If the switch changed, due to noise or pressing:
          if (P1_LEFT_reading != P1_LEFT_lastButtonState) {
          // reset the debouncing timer
          lastDebounceTime_P1_LEFT = millis();
          }

          if ((millis() - lastDebounceTime_P1_LEFT ) > debounceDelay_P1_LEFT) {
          // whatever the reading is at, it's been there for longer
          // than the debounce delay, so take it as the actual current state:
          // if the button state has changed:
          if (P1_LEFT_reading != P1_LEFT_buttonState) {
            P1_LEFT_buttonState = P1_LEFT_reading;

          // only toggle if the new button state is LOW
          if (P1_LEFT_buttonState == LOW) {
          Keyboard.press(keyP1_LEFT);
              }
          if (P1_LEFT_buttonState == HIGH) {
          Keyboard.release(keyP1_LEFT);
              }
            }
          }
        P1_LEFT_lastButtonState = P1_LEFT_reading;  
        }

void checkP1_RIGHT() {
      int P1_RIGHT_reading = digitalRead(P1_RIGHT);
      // If the switch changed, due to noise or pressing:
          if (P1_RIGHT_reading != P1_RIGHT_lastButtonState) {
          // reset the debouncing timer
          lastDebounceTime_P1_RIGHT = millis();
          }

          if ((millis() - lastDebounceTime_P1_RIGHT ) > debounceDelay_P1_RIGHT) {
          // whatever the reading is at, it's been there for longer
          // than the debounce delay, so take it as the actual current state:
          // if the button state has changed:
          if (P1_RIGHT_reading != P1_RIGHT_buttonState) {
            P1_RIGHT_buttonState = P1_RIGHT_reading;

          // only toggle if the new button state is LOW
          if (P1_RIGHT_buttonState == LOW) {
          Keyboard.press(keyP1_RIGHT);
              }
          if (P1_RIGHT_buttonState == HIGH) {
          Keyboard.release(keyP1_RIGHT);
              }
            }
          }
        P1_RIGHT_lastButtonState = P1_RIGHT_reading;  
        }
