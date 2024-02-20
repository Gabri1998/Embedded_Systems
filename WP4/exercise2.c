// (C) Amanda Turquis,Ahmed Algabri,David Hong, group: 13 (2024)
// Work package 4
// Exercise 2
// Submission code: XXXXXX (provided by your TA-s)

#include <Servo.h>

// Define servo and timer interrupt variables
Servo myServo;
const int servoPin = 9; // Connect servo to pin 9
volatile unsigned long elapsedTime = 0; // Elapsed time in seconds

void setup()
{
    Serial.begin(9600);

    // Attach the servo to the pin
    myServo.attach(servoPin);

    // Set up Timer1 for interrupt every 1 second
    cli(); // Disable interrupts
    TCCR1A = 0; // Reset Timer1 control registers
    TCCR1B = 0;
    TCNT1 = 0; // Reset the counter

    // Set prescaler to 256, Timer1 will overflow every 1 second
    TCCR1B |= (1 << CS12);

    // Enable Timer1 overflow interrupt
    TIMSK1 |= (1 << TOIE1);
    sei(); // Enable interrupts
}

void loop()
{
    // Main loop (empty as we're using interrupts)
}

ISR(TIMER1_OVF_vect)
{
    // Timer1 overflow interrupt, called every 1 second

    // Increment elapsed time
    elapsedTime++;

    // Move the servo based on elapsed time
    moveServo(elapsedTime);

    // Send elapsed time to serial port
    Serial.print("Elapsed Time: ");
    Serial.println(elapsedTime);
}

void moveServo(unsigned long time)
{
    // Move the servo based on elapsed time
    int angle = map(time, 0, 60, 0, 180); // Map time to servo angle (0-60 seconds to 0-180 degrees)
    myServo.write(angle);
    delay(15); // Delay to allow servo to reach the position
}
