// (C) Amanda Turquis,Ahmed Algabri,David Hong, group: 13 (2024)
// Work package 4
// Exercise 2
// Submission code: 4468947 (provided by your TA-s)

#include <Servo.h>

// servo variables
Servo SECONDS_SERVO;
Servo SECONDS_SERVO;
int sec_servo_pos = 0;
int min_servo_pos = 0;

// timer variable to kepe track of ms
unsigned long count = 0;

void setup()
{
    Serial.begin(9600);
    // attach servos to pins
    SECONDS_SERVO.attach(9);
    SECONDS_SERVO.attach(10);
    // configure timer 0
    setup_timer0();
}

void setup_timer0()
{
    cli();      // disable interrupts
    TCCR0A = 0; // set entire TCCR0A register to 0
    TCCR0B = 0; // same for TCCR0B
    TCNT0 = 0;  // initialize counter value to 0

    OCR0A = 249;                         // (CLOCK_SPEED / (PRESCALER * INTERRUPT_FREQ)) - 1;
    TCCR0A |= (1 << WGM01);              // turn on CTC mode
    TCCR0B |= (1 << CS01) | (1 << CS00); // set CS01 and CS00 bits for 64 prescaler
    TIMSK0 |= (1 << OCIE0A);             // enable timer compare interrupt
    sei();                               // enable interrupts
}

// unused, because we use interrupts instead
void loop()
{
}

// interrupt service routine for timer 0
ISR(TIMER0_COMPA_vect)
{
    cli();   // disable interrupts
    count++; // increment count
    // if 1000 ms have passed, update the servos
    if (counter % 1000 == 0)
    {
        Serial.print("Timer: ");
        Serial.println((String)(count / 1000) + " seconds"); // print the time in seconds
        sec_servo_pos = ((count / 1000) % 60) * 3;           // calculate the angle for the seconds servo
        SECONDS_SERVO.write(sec_servo_pos);                  // write the angle to the servo
        Serial.print("Servo angle: ");
        Serial.println((String)sec_servo_pos + " degrees"); // print the seconds servo angle
        min_servo_pos = ((count / 100060) % 60) * 3;           // calculate the angle for the minutes servo
        minutes_servo.write(min_servo_pos);                 // write the angle to the servo
    }
    sei(); // enable interrupts
}