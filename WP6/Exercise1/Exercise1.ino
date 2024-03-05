// (C) Amanda Turquis,Ahmed Algabri,David Hong, group: 13 (2024)
// Work package 6
// Exercise 1
// Submission code: 13676511 (provided by your TA-s)

//
/* Define Motor Control pins */
#define motorInput1 5
#define motorInput2 6
#define ENCA 2
#define ENCB 3

// from encoder datasheet replace with correct number
// PPR(Pulse per revolution)
const int encoderResolution = 1000;
// Calculate the degrees per pulse
const float degreesPerPulse = 360.0 / encoderResolution;

/* Define Variables position , direction */
int motorSpeed = 0;                // Set initial motor speed as 0
volatile long currentPosition = 0; // Set initial current position as 0
int targetPosition = 0;            // Set initial target position as 0
int error = 0;                     // Set error as 0
const float kp = 5;                // Set initial kp as 5
int controlSignal = 0;             // Set initial control signal as 0
bool clockwise = true;             // Set initial rotation as clockwise
int flag = 0;                      // Set initial flag as 0

// Initial arduino setup
void setup()
{
  // Initialize the motor
  initializeMotor();
  // Initialize the serial communication
  Serial.begin(9600);
}

// Code that runs while the program is alive
void loop()
{
  /* read input serial monitor */
  readInput();
  controlMotor();
  printSetting();
  /* task3 */
  Serial.println("Enter Target Poistion(degrees): ");
  // Wait until the serial is available
  while (Serial.available() == 0)
    ;
  // Save the target position as an integer
  targetPosition = Serial.parseInt();

  // error case
  error = targetPosition - currentPosition;

  /* for Simulation */
  while (error)
  {
    // Set the control signal as error * kp
    controlSignal = error * kp;
    /* for Simulation */
    // Set the current position as control signal + current position
    currentPosition += controlSignal;
    // If the control signal is lager than 0
    if (controlSignal > 0)
    {
      // Rotate the motor input 1
      analogWrite(motorInput1, controlSignal);
      // Stop the motor input 2
      analogWrite(motorInput2, 0);
      /* for Simulation */
      flag = 1;
    }
    // If the control signal is smaller than 0
    else if (controlSignal < 0)
    {
      // Stop the motor input 1
      analogWrite(motorInput1, 0);
      // Rotate the motor input 1 as negative direction
      analogWrite(motorInput2, -1 * controlSignal);
      /* for Simulation */
      flag = 0;
    }

    // Other case
    else
    {
      // Stop the motor
      digitalWrite(motorInput1, LOW);
      // Stop motor
      digitalWrite(motorInput2, LOW);
      flag = -1;
    }

    Serial.print("Current Position (Degrees): ");
    Serial.println(pulsesToDegrees(currentPosition));
    /* for Simulation here*/
    // Error is equal to current position value - error
    error -= currentPosition;
    // If the flag is equal to 1 and the error is below 0, turn off the error
    if (flag == 1 && error <= 0)
      // Set the error as 0
      error = 0;

    // If the flag is equal to 0 and error is above 0, turn off error
    else if (flag == 0 && error >= 0)
      // Set the error as 0
      error = 0;
    /* for Simulation untill here*/
    Serial.print("Error: ");
    Serial.println(error);
    delay(100);
  }
  Serial.print("Current Position: ");
  Serial.println(currentPosition);
  Serial.print("Direction: ");
  Serial.println(clockwise ? "Clockwise" : "Anti-Clockwise");
  pulsesToDegrees(currentPosition);
  Serial.print("Current Position (Degrees): ");
  Serial.println(pulsesToDegrees(currentPosition));

  delay(500);
}
/* Function for Initializing Motor (pin -> output, input) */
void initializeMotor(void)
{
  // Set motor input 1 as output
  pinMode(motorInput1, OUTPUT);
  // Set motor input 2 as output
  pinMode(motorInput2, OUTPUT);

  // Set ENCA as input
  pinMode(ENCA, INPUT);
  // Set ENCB as input
  pinMode(ENCB, INPUT);

  /* initialize motor */
  analogWrite(motorInput1, 10);
  // Stop motor for 0.5 sec
  delay(500);
  // Rotate motor 2
  analogWrite(motorInput2, 10);

  // Interrupts for the motor
  attachInterrupt(digitalPinToInterrupt(ENCA), encoderAISR, RISING);
}
void encoderAISR(void)
{
  // If the ENCB value is larger than 0
  if (digitalRead(ENCB) > 0)
  {
    // Increase the current position
    currentPosition++;
    // Set the direction of the rotation as clockwise
    clockwise = true;
  }

  else
  {
    // Decrease the current position
    currentPosition--;
    // Set the direction of the rotation as counter clockwise
    clockwise = false;
  }
}

// Read input from the sensor
void readInput(void)
{
  Serial.println("Pick a direction (F->clockwise, B-> anti-clockwise)");
  // Wait for input
  while (Serial.available() == 0)
    ;
  /* read direction input */
  // Read the direction from the serial and save it as a char
  char direction = Serial.read();

  // If the direction is neither a forwards nor backwards return an error message
  if ((direction != 'F' && direction != 'f') && (direction != 'B' && direction != 'b'))
  {
    Serial.println("Invalid direction Please Enter F or B");
    return;
  }
  Serial.println("Enter desired speed(0-255)");
  // Wait for input
  while (Serial.available() == 0)
    ;
  /* read direction input */
  motorSpeed = Serial.parseInt();

  // If the speed is not valid, return an error message
  if (motorSpeed < 0 || motorSpeed > 255)
  {
    Serial.println("Invalid Speed, Please Enter a value between 0 and 255");
    return;
  }
  // Else, set the rotation direction as forwards
  clockwise = (direction == 'F' || direction == 'f');
}

// Function to control the motors
void controlMotor(void)
{
  // If the motor is rotating in clockwise
  if (clockwise == true)
  {
    // Rotate the motor1
    analogWrite(motorInput1, motorSpeed);
    // Stop motor2
    analogWrite(motorInput2, 0);
  }
  // Other case (CCW)
  else
  {
    // Stop motor1
    analogWrite(motorInput1, 0);
    // Rotate the motor2
    analogWrite(motorInput2, motorSpeed);
  }
}

// Print the settigns
void printSetting(void)
{
  Serial.println("---------------------------------------------");
  Serial.print("Direction: ");
  Serial.println(clockwise ? "Clockwise" : "Anti-clockwise");
  Serial.print("Speed: ");
  Serial.println(motorSpeed);
  Serial.println("--------------------------------------------");
}
// Function to convert pulses to degrees
float pulsesToDegrees(long pulses)
{
  // Return the degrees value
  return pulses * degreesPerPulse;
}