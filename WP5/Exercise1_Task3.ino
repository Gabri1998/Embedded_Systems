// C++ code
//
/* Define Motor Control pins */
#define motorInput1    5
#define motorInput2    6
#define ENCA        2
#define ENCB        3

// from encoder datasheet replace with correct number
// PPR(Pulse per revolution)
const int encoderResolution = 1000;
// Calculate the degrees per pulse
const float degreesPerPulse = 360.0 / encoderResolution;

/* Define Variables position , direction */
int motorSpeed = 0;
volatile long currentPosition = 0;
int    targetPosition = 0;
int error = 0;
const float kp = 0.1;
int controlSignal = 0;
bool clockwise = true;
int flag = 0;

void setup()
{
  initializeMotor();
  Serial.begin(9600);
}

void loop()
{
  /* read input serial monitor */
  //readInput();
  //controlMotor();
  //printSetting();
  /* task3 */
  Serial.println("Enter Target Poistion(degrees): ");
  while(Serial.available() == 0);
  targetPosition = Serial.parseInt();
  
  // error 
  error = targetPosition - currentPosition;
  
  /* for Simulation */
  while(error)
  { 
    controlSignal = error * kp;
    /* for Simulation */
    currentPosition+= controlSignal;
    if(controlSignal > 0)
    {
      analogWrite(motorInput1, controlSignal);
      analogWrite(motorInput2, 0);
      /* for Simulation */
      flag = 1;
    }
    else if(controlSignal < 0)
    {
      analogWrite(motorInput1, 0);
      analogWrite(motorInput2, -1 * controlSignal);
      /* for Simulation */
      flag = 0;
    }
    else
    {
      // Stop the motor 
      digitalWrite(motorInput1, LOW);
      digitalWrite(motorInput2, LOW);
      flag = -1;
    }
    
    Serial.print("Current Position (Degrees): ");
      Serial.println(pulsesToDegrees(currentPosition));
    /* for Simulation here*/
    error -= currentPosition;
    if(flag == 1 && error <= 0)
      error = 0;
    
    else if(flag == 0 && error >= 0)
      error = 0;
   /* for Simulation untill here*/
      Serial.print("Error: ");
      Serial.println(error);
    delay(1000);
   
    
    
  }/*Serial.print("Current Position: ");
  Serial.println(currentPosition);
  Serial.print("Direction: ");
  Serial.println(clockwise?"Clockwise":"Anti-Clockwise");
  pulsesToDegrees(currentPosition);
  Serial.print("Current Position (Degrees): ");
  Serial.println(pulsesToDegrees(currentPosition));
  
  delay(1000);*/
  
  
  
  
  
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