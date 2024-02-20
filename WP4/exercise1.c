// (C) Amanda Turquis,Ahmed Algabri,David Hong, group: 13 (2024)
// Work package 4
// Exercise 2
// Submission code: XXXXXX (provided by your TA-s)

// Define section
#define RED_PIN 13    // Set pin 13 for the RED_LED
#define GREEN_PIN 12  // Set pin 12 for the GREEN_LED
#define BLUE_PIN 11   // Set pin 11 for the BLUE_LED
#define ORANGE_PIN 10 // Set pin 10 for the ORANGE_LED
#define YELLOW_PIN 9  // Set pin 9 for the YELLOW_LED

#define TEMP_PIN A0 // Set analog pin A0 for the TEMPERATURE_SENSOR

// Variable declarations
volatile int temperatureUpdate = 0; // Variable for the interrupts
volatile float currentTemperature;  // Save the current temperature

// Initial setup for the arduino
void setup()
{
    // Set pin modes
    pinMode(RED_PIN, OUTPUT);    // RED_LED to be output
    pinMode(GREEN_PIN, OUTPUT);  // GREEN_LED to be output
    pinMode(BLUE_PIN, OUTPUT);   // BLUE_LED to be output
    pinMode(ORANGE_PIN, OUTPUT); // ORANGE_LED to be output
    pinMode(YELLOW_PIN, OUTPUT); // YELLOW_LED to be output

    pinMode(TEMP_PIN, INPUT); // TEMP_PIN to be input

    // Begin serial communication
    Serial.begin(9600);

    // Stop interrupts
    cli();

    // Settings for the timer1
    TCCR1A = 0; // Set TCCR1A as 0
    TCCR1B = 0; // Set TCCR1B as 0
    TCNT1 = 0;  // Set TCNT1 as 0

    OCR1A = 15624; // Give 1 second interval

    // CTC mode
    TCCR1B |= (1 << WGM12);
    // Set CS10 and CS12 bits for 1024 prescaler
    TCCR1B |= (1 << CS12) | (1 << CS10);
    // Enable timer compared interrupts
    TIMSK1 |= (1 << OCIE1A);

    // Start interrupts
    sei();
}

// Method to change the input into temperature value
float convertToTemp()
{
    // Get the reading value from the sensor
    int reading = analogRead(TEMP_PIN);
    // Change the reading value into voltage
    float voltage = reading * 5.0 / 1023.0;
    // Serial.println(voltage);
    // Return the temperature value
    return (voltage - 0.5) * 100.0;
}

// Change the LED status based on temperature
void changeLED(float temperature)
{
    // Initialize with all LEDs turned off
    digitalWrite(RED_PIN, LOW);    // RED_LED off
    digitalWrite(GREEN_PIN, LOW);  // GREEN_LED off
    digitalWrite(BLUE_PIN, LOW);   // BLUE_LED off
    digitalWrite(ORANGE_PIN, LOW); // ORANGE_LED off
    digitalWrite(YELLOW_PIN, LOW); // YELLOW_LED off

    // If the temperature is between 0 and 10
    if (temperature >= 0 && temperature < 10)
    {
        // Turn on RED
        digitalWrite(RED_PIN, HIGH);
    }
    // If the temperature is between 10 and 20
    else if (temperature >= 10 && temperature < 20)
    {
        // Turn on RED and GREEN
        digitalWrite(RED_PIN, HIGH);
        digitalWrite(GREEN_PIN, HIGH);
    }
    // If the temperature is between 20 and 30
    else if (temperature >= 20 && temperature < 30)
    {
        // Turn on RED, GREEN and BLUE
        digitalWrite(RED_PIN, HIGH);
        digitalWrite(GREEN_PIN, HIGH);
        digitalWrite(BLUE_PIN, HIGH);
    }
    // If the temperature is between 30 and 40
    else if (temperature >= 30 && temperature < 40)
    {
        // Turn on RED, GREEN, BLUE and ORANGE
        digitalWrite(RED_PIN, HIGH);
        digitalWrite(GREEN_PIN, HIGH);
        digitalWrite(BLUE_PIN, HIGH);
        digitalWrite(ORANGE_PIN, HIGH);
    }
    // If the temperature is between 40 and 50
    else if (temperature >= 40 && temperature < 50)
    {
        // Turn on RED, GREEN, BLUE, ORANGE and YELLOW
        digitalWrite(RED_PIN, HIGH);
        digitalWrite(GREEN_PIN, HIGH);
        digitalWrite(BLUE_PIN, HIGH);
        digitalWrite(ORANGE_PIN, HIGH);
        digitalWrite(YELLOW_PIN, HIGH);
    }
}

// Interrupts command
ISR(TIMER1_COMPA_vect)
{
    // Change the temperatureUpdate to 1
    temperatureUpdate = 1;
    // Serial.println("Temperature Update");
}

// Code that runs forever
void loop()
{
    // If the temperature should be updated (Based on time)
    if (temperatureUpdate)
    {
        // Get current temperture
        currentTemperature = convertToTemp();
        Serial.println("New Temperature Received");
        Serial.println(currentTemperature);
        // Change the LED settings
        changeLED(currentTemperature);
        // Serial.println("LED Changed");

        // Set the temperatureUpdate to be 0 again
        temperatureUpdate = 0;
    }
}
