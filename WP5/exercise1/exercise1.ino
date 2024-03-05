// (C) Amanda Turquis,Ahmed Algabri,David Hong, group: 13 (2024)
// Work package 5
// Exercise 1
// Submission code: 285867 (provided by your TA-s)

int blueLed = 13;    // Pin for blue LED
int greenLed = 9;    // Pin for green LED, than only bnlinks when the pushbutton is pressed
int pushbuttonPin = 12;   // Pin for the pushbutton

void setup() {
  pinMode(blueLed, OUTPUT); // blue led
  pinMode(greenLed, OUTPUT); //green led
  pinMode(pushbuttonPin, INPUT); // pushbutton
}

void loop() {
  // Blink blue LED every second
  digitalWrite(blueLed, HIGH);
  delay(1000);
  digitalWrite(blueLed, LOW); // turn off the blue led
  delay(1000);

  // Read the pushbutton
  int pushbuttonState = digitalRead(pushbuttonPin);

  // Check if pushbutton is pressed
  if (pushbuttonState == LOW) {
    // Green LED ON when the button is pressed
    digitalWrite(greenLed, HIGH);
    digitalWrite(greenLed, LOW);
  } else {
    // Turn off the green LED when the button is not pressed
    digitalWrite(greenLed, LOW);
  }
}