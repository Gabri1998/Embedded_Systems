#define RED_PIN 13
#define GREEN_PIN 12
#define BLUE_PIN 11
#define ORANGE_PIN 10
#define YELLOW_PIN 9

#define TEMP_PIN A0

volatile int temperatureUpdate = 0;

volatile float currentTemperature;

void setup()
{
    pinMode(RED_PIN, OUTPUT);
    pinMode(GREEN_PIN, OUTPUT);
    pinMode(BLUE_PIN, OUTPUT);
    pinMode(ORANGE_PIN, OUTPUT);
    pinMode(YELLOW_PIN, OUTPUT);

    pinMode(TEMP_PIN, INPUT);

    Serial.begin(9600);

    cli();

    TCCR1A = 0;
    TCCR1B = 0;
    TCNT1 = 0;

    OCR1A = 15624;

    TCCR1B |= (1 << WGM12);
    TCCR1B |= (1 << CS12) | (1 << CS10);
    TIMSK1 |= (1 << OCIE1A);

    sei();
}

float convertToTemp()
{
    int reading = analogRead(TEMP_PIN);
    float voltage = reading * 5.0 / 1023.0;
    // Serial.println(voltage);
    return (voltage - 0.5) * 100.0;
}

void changeLED(float temperature)
{
    digitalWrite(RED_PIN, LOW);
    digitalWrite(GREEN_PIN, LOW);
    digitalWrite(BLUE_PIN, LOW);
    digitalWrite(ORANGE_PIN, LOW);
    digitalWrite(YELLOW_PIN, LOW);

    if (temperature >= 0 && temperature < 10)
    {
        digitalWrite(RED_PIN, HIGH);
    }
    else if (temperature >= 10 && temperature < 20)
    {
        digitalWrite(GREEN_PIN, HIGH);
    }
    else if (temperature >= 20 && temperature < 30)
    {
        digitalWrite(BLUE_PIN, HIGH);
    }
    else if (temperature >= 30 && temperature < 40)
    {
        digitalWrite(ORANGE_PIN, HIGH);
    }
    else if (temperature >= 40 && temperature < 50)
    {
        digitalWrite(YELLOW_PIN, HIGH);
    }
}

ISR(TIMER1_COMPA_vect)
{
    temperatureUpdate = 1;
    // Serial.println("Temperature Update");
}

void loop()
{
    if (temperatureUpdate)
    {
        currentTemperature = convertToTemp();
        Serial.println("New Temperature Received");
        Serial.println(currentTemperature);
        changeLED(currentTemperature);
        // Serial.println("LED Changed");

        temperatureUpdate = 0;
    }
}
