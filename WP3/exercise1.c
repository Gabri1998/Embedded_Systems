// (C) Amanda Turquis,Ahmed Algabri,David Hong, group: 13 (2024)
// Work package 3
// Exercise 1
// Submission code: 021513 (provided by your TA-s)

OUTPUT;
HIGH;
LOW;
INPUT;

// C++ code

int pushbutton = 0;

void setup()
{
  //pinMode(13, OUTPUT);
  pinMode(12, INPUT);
}

void loop()
{
  digitalWrite(13, HIGH);
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(13, LOW);
  delay(1000); // Wait for 1000 millisecond(s)

  // read state pushbutton
  pushbutton = digitalRead(12);
  // check if pushbutton is pressed
  if (pushbutton < HIGH) {
    // turn LED on
    digitalWrite(12, HIGH);
  } else {
    // turn LED off
    digitalWrite(12, LOW);
  }
}