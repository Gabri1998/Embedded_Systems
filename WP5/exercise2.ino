// ultrasonic sensor pins
#define SIG    7
#define Speaker    9
#define led1    2
#define led2    3
#define led3    4
#define led4    5


// led pins
//int led1 = 5, led2 = 4, led3 = 3, led4 = 2;
// speaker pin
//int speakerPin = 9;

//thresholds
int th1 = 200, th2 = 130, th3 = 90, th4 = 30, th5 = 25;

void setup()
{
  Serial.begin(9600);
  //Set pins 5-2,7 as output
  DDRD = B10111100;
  // Set pin 9 as output
  DDRB = B00000010;
}

void loop()
{
  //get current distance
  float distance = readDistance();
  // print distance
  Serial.println(distance);
  // set leds and play sound
  setLeds(distance);
  playSound(distance);
}

float readDistance(){
  //reset trigger
  digitalWrite(SIG, LOW);
  delay(2);
  digitalWrite(SIG, HIGH);
  delay(10);
  digitalWrite(SIG, LOW);
  pinMode(SIG, INPUT);
  float duration = pulseIn(SIG, HIGH);
  float distance = duration * 0.034/2;
  return distance;
}

void setLeds(int distance){
  // Reset LEDS
  PORTD = 0;
  // evaluate which leds to turn on based on the given distance
  if(distance < th1){
    digitalWrite(led1, HIGH);
  }
  if(distance < th2){
    digitalWrite(led2, HIGH);
  }
  if(distance < th3){
    digitalWrite(led3, HIGH);
  }
  if(distance < th4){
    digitalWrite(led4, HIGH);
  }
  if(distance < th5){
    // if leds below threshold 5, turn them off, wait 200ms and turn them on again
    // this is done to create a blinking effect
    PORTD = 0;
    delay(200);
    PORTD = B00111100;
  }
}

void playSound(int distance){
    // evaluate how often the sound should play based on the distance
  if(distance < th5){
    tone(Speaker, 2500, 300);
    delay(20);
  } else if(distance < th4){
    tone(Speaker, 2500, 100);
    delay(90);
  } else if(distance < th3){
    tone(Speaker, 2500, 100);
    delay(200);
  } else if(distance < th2){
    tone(Speaker, 2500, 100);
    delay(500);
  } else if(distance < th1){
    tone(Speaker, 2500, 100);
    delay(900);
  }
}