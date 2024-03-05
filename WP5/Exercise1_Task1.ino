// C++ code


/* Define Motor Control pins */
#define motorInput1    5  // Assigns pin 5 to motorInput1 for motor control
#define motorInput2    6  // Assigns pin 6 to motorInput2 for motor control

/* Define Variables speed , direction */
int motorSpeed = 0;       // Initializes motorSpeed variable to control the speed of the motor
bool clockwise = true;    // Initializes clockwise variable to set the direction of the motor rotation

void setup()
{
  initializeMotor();      // Calls the initializeMotor function to set up motor control pins
  Serial.begin(9600);     // Initializes serial communication at 9600 bits per second
}

void loop()
{
  readInput();            // Calls readInput function to read user input from the serial monitor
  controlMotor();         // Calls controlMotor function to adjust the motor based on user input
  printSetting();         // Calls printSetting function to print the current motor settings
}

// Function for Initializing Motor (pin -> output, input)
void initializeMotor(void)
{
  pinMode(motorInput1, OUTPUT);  // Sets motorInput1 pin as an OUTPUT
  pinMode(motorInput2, OUTPUT);  // Sets motorInput2 pin as an OUTPUT
  
  // Initialize motor to a low speed to indicate it's ready
  analogWrite(motorInput1, 10);  // Writes a low value to motorInput1 to start the motor softly
  delay(500);                    // Waits for 500 milliseconds
  analogWrite(motorInput2, 10);  // Writes a low value to motorInput2 to continue soft start
}

void readInput(void)
{
  Serial.println("Pick a direction (F->clockwise, B-> anti-clockwise)");  // Prompts user for direction
  while(Serial.available() == 0);  // Waits for user input
  
  char direction = Serial.read();  // Reads the direction character from serial input
  if((direction != 'F' && direction != 'f') && (direction != 'B' && direction != 'b'))
  {
    Serial.println("Invalid direction Please Enter F or B");  // Error message for invalid direction
    return;  // Exits the function if invalid input is received
  }
  Serial.println("Enter desired speed(0-255)");  // Prompts user for speed input
  while(Serial.available() == 0);  // Waits for user input
  
  motorSpeed = Serial.parseInt();  // Parses the next integers entered as the motor speed
  if(motorSpeed < 0 || motorSpeed > 255)
  {
    Serial.println("Invalid Speed, Please Enter a value between 0 and 255");  // Error message for invalid speed
    return;  // Exits the function if invalid speed is received
  }
  clockwise = (direction == 'F' || direction == 'f');  // Sets the direction based on user input    
}

void controlMotor(void)
{
  if(clockwise == true)  // Checks if the direction is clockwise
  {
    analogWrite(motorInput1, motorSpeed);  // Sets motorInput1 to the specified speed, stops motorInput2
    analogWrite(motorInput2, 0);  // Stops motorInput2
  }
  else  // If the direction is not clockwise, then it is anti-clockwise
  {
    analogWrite(motorInput1, 0);  // Stops motorInput1
    analogWrite(motorInput2, motorSpeed);  // Sets motorInput2 to the specified speed
  }
}

void printSetting(void)
{
  // Prints a summary of the current motor settings
  Serial.println("---------------------------------------------");
  Serial.print("Direction: ");
  Serial.println(clockwise ? "Clockwise" : "Anti-clockwise");  // Prints the direction of rotation
  Serial.print("Speed: ");
  Serial.println(motorSpeed);  // Prints the current speed
  Serial.println("--------------------------------------------");
}
