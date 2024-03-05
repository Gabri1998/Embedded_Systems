// (C) Amanda Turquis,Ahmed Algabri,David Hong, group: 13 (2024)
// Work package 6
// Exercise 2
// Submission code: 13676511 (provided by your TA-s)

// ultrasonic sensor pins
#define echoPin 12 // Set the EchoPin to be 12
#define SIG 11     // Set the sensor as pin 11
#define Speaker 9 // Set the speaker to be 9
#define led1 2    // Set the LED1 to be 2
#define led2 3    // Set the LED2 to be 3
#define led3 4    // Set the LED3 to be 4
#define led4 5    // Set the LED4 to be 5

// thresholds
int th1 = 200, th2 = 130, th3 = 90, th4 = 30, th5 = 25;

// Initial setup for the arduino
void setup()
{
  Serial.begin(9600);
  //Set pins 5-2 as output
  DDRD = B00111100;
  // Set pin 11,9 as output and 12 as input
  DDRB = B00001010;
}

// Part that runs while the program is alive
void loop()
{
  // get current distance
  float distance = readDistance();
  // print distance
  Serial.println(distance);
  // set leds and play sound
  setLeds(distance);
  playSound(distance);
}

// Read the distance from the sensor
float readDistance()
{
  // reset trigger
  digitalWrite(SIG, LOW);
  // pasue
  delay(2);
  // If signal, set the sound
  digitalWrite(SIG, HIGH);
  // pause
  delay(10);
  // reset the trigger
  digitalWrite(SIG, LOW);
  // calculate the duration of the pulse signal
  float duration = pulseIn(echoPin, HIGH);
  // Calculate the distance to the object
  float distance = duration * 0.034 / 2;
  // Return the distance
  return distance;
}

// Turn on the leds
void setLeds(int distance)
{
  // Reset LEDS
  PORTD = 0;
  // evaluate which leds to turn on based on the given distance

  // If the distance is closer than distance th1
  if (distance < th1)
  {
    // Turn on LED
    digitalWrite(led1, HIGH);
  }
  // If the distance is closer than distance th2
  if (distance < th2)
  {
    // Turn on LED
    digitalWrite(led2, HIGH);
  }
  // If the distance is closer than distance th3
  if (distance < th3)
  {
    // Turn on LED
    digitalWrite(led3, HIGH);
  }
  // If the distance is closer than distance th4
  if (distance < th4)
  {
    // Turn on LED
    digitalWrite(led4, HIGH);
  }
  // If the distance is closer than distance th5
  if (distance < th5)
  {
    // if leds below threshold 5, turn them off, wait 200ms and turn them on again
    // this is done to create a blinking effect
    PORTD = 0;
    delay(200);
    PORTD = B00111100;
  }
}

// Play the beeping sound based on the distance
void playSound(int distance)
{
  // evaluate how often the sound should play based on the distance
  if (distance < th5)
  {
    // Turn on the beeping noise
    tone(Speaker, 2500, 300);
    delay(20);
  }
  // If the distance is closer than th4
  else if (distance < th4)
  {
    // Turn on the beeping noise
    tone(Speaker, 2500, 100);
    delay(90);
  }
  // If the distance is closer than th3
  else if (distance < th3)
  {
    // Turn on the beeping noise
    tone(Speaker, 2500, 100);
    delay(200);
  }
  // If the distance is closer than th2
  else if (distance < th2)
  {
    // Turn on the beeping noise
    tone(Speaker, 2500, 100);
    delay(500);
  }
  // If the distance is closer than th1
  else if (distance < th1)
  {
    // Turn on the beeping noise
    tone(Speaker, 2500, 100);
    delay(900);
  }
}