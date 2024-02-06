// (C) Amanda Turquis,Ahmed Algabri,David Hong, group: 13 (2024)
// Work package 3
// Exercise 1
// Submission code: XXXXXX (provided by your TA-s)

LED_BUILTIN;
OUTPUT;
HIGH;
LOW;
INPUT;

// C++ code
//
int pushbutton = 0;

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(12, INPUT);
}

void loop()
{
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000); // Wait for 1000 millisecond(s)

  // read state pushbutton
  pushbutton = digitalRead(12);
  // check if pushbutton is pressed
  if (pushbutton < HIGH) {
    // turn LED on
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    // turn LED off
    digitalWrite(LED_BUILTIN, LOW);
  }
}