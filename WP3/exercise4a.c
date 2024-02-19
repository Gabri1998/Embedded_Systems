// (C) Amanda Turquis,Ahmed Algabri,David Hong, group: 13 (2024)
// Work package 3
// Exercise 3b
// Submission code: 021513 (provided by your TA-s)

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns

char keys[ROWS][COLS] = { // custom keypad in multi array
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {11, 10, 9, 8}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {7,6, 5, 4}; //connect to the column pinouts of the keypad

void setup() {
  Serial.begin(9600);
  for (byte i = 0; i < ROWS; i++) {
    pinMode(rowPins[i], INPUT_PULLUP); //set row pins as INPUT_PULLUP
  }
}

void loop() {
  char key = getKey();// get the key by calling the method

  if (key != '\0') { // check if the key exists
    Serial.println(key);
    delay(500); //delay to debounce
  }
  //delay(200); //delay to debounce
}

char getKey() {
  for (byte col = 0; col < COLS; col++) {
    pinMode(colPins[col], OUTPUT); //set column pin as OUTPUT
    digitalWrite(colPins[col], LOW); //ground the column pin

    for (byte row = 0; row < ROWS; row++) {
      if (digitalRead(rowPins[row]) == LOW) { //check if any row pin is low
        while (digitalRead(rowPins[row]) == LOW){ //wait for key release
        digitalWrite(colPins[col], HIGH); //turn off the column
        return keys[row][col];
        }//return the pressed key
      }
    }

    digitalWrite(colPins[col], HIGH); //turn off the column
    pinMode(colPins[col], INPUT); //set column pin as INPUT
  }

  return '\0'; //return null character if no key is pressed
}