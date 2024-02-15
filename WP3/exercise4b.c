// (C) Amanda Turquis,Ahmed Algabri,David Hong, group: 13 (2024)
// Work package 3
// Exercise 4
// Submission code: XXXXXX (provided by your TA-s)

#include <Keypad.h> // the library

const byte ROWS = 4; /* four rows */
const byte COLS = 4; /* four columns */
/* define the symbols on the buttons of the keypads */
char hexaKeys[ROWS][COLS] = {  // costum keymap
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'E','0','F','D'}
};
byte rowPins[ROWS] = {11, 10, 9, 8}; /* connect to the row pinouts of the keypad */
byte colPins[COLS] = {7, 6, 5, 4}; /* connect to the column pinouts of the keypad */

/* initialize an instance of class NewKeypad */
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup(){
Serial.begin(9600);
}

void loop(){
 // char customKey = 0;
  customKey = customKeypad.getKey(); // getting the key
// check if the key exists then print the key
  if (customKey){
    Serial.println(customKey);
  }
}