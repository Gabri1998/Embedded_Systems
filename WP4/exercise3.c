// (C) Amanda Turquis,Ahmed Algabri,David Hong, group: 13 (2024)
// Work package 4
// Exercise 3
// Submission code: 4468947 (provided by your TA-s)

#include <Adafruit_NeoPixel.h>

// define number of LEDs and pin number
#define NUM_LEDS 13
#define NUM_PIN 2

// define the neopixel strip
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, NUM_PIN, NEO_GRB + NEO_KHZ800);

void setup()
{
    Serial.begin(9600);  // initialize serial communication
    pinMode(13, OUTPUT); // initialize digital pin 12 as an output
    setup_timer1();      // initialize timer1
    strip.begin();       // initialize neopixel strip
}

void setup_timer1()
{
    cli();
    TCCR1A = 0; // set entire TCCR1A register to 0
    TCCR1B = 0; // same for TCCR1B
    TCNT1 = 0;  // initialize counter value to 0

    OCR1A = 15624;                       // set compare match register for 1hz increments
    TCCR1B |= (1 << WGM12);              // turn on CTC mode
    TCCR1B |= (1 << CS12) | (1 << CS10); // set CS10 and CS12 bits for 1024 prescaler
    TIMSK1 |= (1 << OCIE1A);             // enable timer compare interrupt
    sei();
}

// unused, because we are using interrupts instead
void loop()
{
}

// interrupt service routine for timer1
ISR(TIMER1_COMPA_vect)
{
    cli();                       // stop interrupts
    float temp = analogRead(A0); // read analog value from A0
                                 // temp = (temp5 * 5.0) / 1000; // convert to millivolts
                                 // temp = (temp-500)/10; // convert to degrees celcius
    temp = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125);
    Serial.println(temp); // print temperature to serial monitor
    strip.clear();        // clear the neopixel strip

    // fill the neopixel strip with red LEDs, the number of LEDs is proportional to the temperature
    // each LED represents 5 degrees celcius
    strip.fill(strip.Color(255, 0, 0), 0, temp / 5);
    strip.show(); // show the neopixel strip

    // if all LEDs are red, turn on the LED on digital pin 12
    uint32_t lastLED = strip.getPixelColor(11); // get the color of the last LED
    if (lastLED == strip.Color(255, 0, 0))
    {
        digitalWrite(13, HIGH);
    }
    else
    {
        // if not all LEDs are red, turn off the LED on digital pin 12
        digitalWrite(13, LOW);
    }
    sei();
}