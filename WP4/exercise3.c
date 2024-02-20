// (C) Amanda Turquis,Ahmed Algabri,David Hong, group: 13 (2024)
// Work package 4
// Exercise 3
// Submission code: XXXXXX (provided by your TA-s)

#include <Adafruit_NeoPixel.h>

#define PIN 6          // Pin connected to the NeoPixel ring
#define NUMPIXELS 12   // Number of NeoPixel LEDs
#define RED_LED_PIN 13 // Pin for the red LED

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

const int temperatureSensorPin = A0; // Analog pin for the temperature sensor
const int redThreshold = 100;        // Threshold for turning on the red LED

void setup()
{
    strip.begin();
    strip.show(); // Initialize all pixels to 'off'

    pinMode(RED_LED_PIN, OUTPUT);
    digitalWrite(RED_LED_PIN, LOW);

    Serial.begin(9600);

    // Set up periodic measurement using Timer1
    noInterrupts(); // Disable interrupts
    TCCR1A = 0;     // Reset Timer1 control registers
    TCCR1B = 0;
    TCNT1 = 0; // Reset the counter

    // Set prescaler to 256, Timer1 will overflow every 1 second
    TCCR1B |= (1 << CS12);

    // Enable Timer1 overflow interrupt
    TIMSK1 |= (1 << TOIE1);
    interrupts(); // Enable interrupts
}

void loop()
{
    // Main loop (empty as we're using interrupts)
}

ISR(TIMER1_OVF_vect)
{
    // Timer1 overflow interrupt, called every 1 second

    // Read the sensor value
    int sensorValue = analogRead(temperatureSensorPin);

    // Map the sensor value to the number of NeoPixel LEDs
    int numPixelsToLight = map(sensorValue, 0, 1023, 0, NUMPIXELS);

    // Display the value on NeoPixel ring
    displayNeoPixels(numPixelsToLight);

    // Check if all NeoPixel LEDs are lit
    if (numPixelsToLight == NUMPIXELS)
    {
        digitalWrite(RED_LED_PIN, HIGH); // Turn on the red LED
    }
    else
    {
        digitalWrite(RED_LED_PIN, LOW); // Turn off the red LED
    }
}

void displayNeoPixels(int numPixels)
{
    // Display the value on NeoPixel ring
    for (int i = 0; i < NUMPIXELS; i++)
    {
        if (i < numPixels)
        {
            strip.setPixelColor(i, strip.Color(0, 255, 0)); // Green color for lit pixels
        }
        else
        {
            strip.setPixelColor(i, strip.Color(0, 0, 0)); // Turn off unlit pixels
        }
    }
    strip.show(); // Update NeoPixel ring
}
