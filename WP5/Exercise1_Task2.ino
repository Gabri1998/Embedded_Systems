// C++ code
//
/* Define Motor Control pins */
#define motorInput1    5
#define motorInput2    6
#define ENCA        2
#define ENCB        3

// from encoder datasheet replace with correct number
const int encoderResolution = 1000;
// Calculate the degrees per pulse
const float degreesPerPulse = 360.0 / encoderResolution;

/* Define Variables position , direction */
int motorSpeed = 0;
volatile long currentPosition = 0;
bool clockwise = true;

void setup()
{
  initializeMotor();
  Serial.begin(9600);
}

void loop()
{
  /* read input serial monitor */
  readInput();
  controlMotor();
  printSetting();
  Serial.print("Current Position: ");
  Serial.println(currentPosition);
  Serial.print("Direction: ");
  Serial.println(clockwise?"Clockwise":"Anti-Clockwise");
  
  pulsesToDegrees(currentPosition);
  Serial.print("Current Position (Degrees): ");
  Serial.println(pulsesToDegrees(currentPosition));
  
}
/* Function for Initializing Motor (pin -> output, input) */
void initializeMotor(void)
{
  pinMode(motorInput1, OUTPUT);
  pinMode(motorInput2, OUTPUT);
  
  pinMode(ENCA, INPUT);
  pinMode(ENCB, INPUT);
  
   /* initialize motor */
  analogWrite(motorInput1, 10);
  delay(500);
  analogWrite(motorInput2, 10);
  
  attachInterrupt(digitalPinToInterrupt(ENCA), encoderAISR, RISING);  
 
}
void encoderAISR(void)
{
  if(digitalRead(ENCB) > 0)
  {
    currentPosition++;
    clockwise = true;
  }
  else
  {
    currentPosition--;
    clockwise = false;
  }
 
}
void readInput(void)
{
  Serial.println("Pick a direction (F->clockwise, B-> anti-clockwise)");
  // Wait for input
  while(Serial.available() == 0);
  /* read direction input */
  char direction = Serial.read();
  if((direction != 'F' && direction != 'f')&& (direction != 'B' && direction != 'b'))
  {
    Serial.println("Invalid direction Please Enter F or B");
    return;
  }
  Serial.println("Enter desired speed(0-255)"); 
  // Wait for input
  while(Serial.available() == 0);
  /* read direction input */
  motorSpeed = Serial.parseInt();
  if(motorSpeed < 0 || motorSpeed > 255)
  {
    Serial.println("Invalid Speed, Please Enter a value between 0 and 255");
    return;
  }
  clockwise = (direction == 'F' || direction == 'f');    
}
  
void controlMotor(void)
{
  if(clockwise == true)
  {
    analogWrite(motorInput1, motorSpeed);
    analogWrite(motorInput2, 0);
  }
  else
  {
    analogWrite(motorInput1, 0);
    analogWrite(motorInput2, motorSpeed);
  }
    
    
}
void printSetting(void)
{
  Serial.println("---------------------------------------------");
  Serial.print("Direction: ");
  Serial.println(clockwise?"Clockwise": "Anti-clockwise");
  Serial.print("Speed: ");
  Serial.println(motorSpeed);
  Serial.println("--------------------------------------------");
}
// Function to convert pulses to degrees
float pulsesToDegrees(long pulses) {
    return pulses * degreesPerPulse;
}