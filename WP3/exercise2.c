// (C) Amanda Turquis,Ahmed Algabri,David Hong, group: 13 (2024)
// Work package 3
// Exercise 2
// Submission code: XXXXXX (provided by your TA-s)

// Library for the temperature and light sensor
#define LDR_PIN A0   // Light sensor pin
#define RED_LED 7    // LED for high temperature deviation
#define GREEN_LED 8  // LED for normal dependency
#define BLUE_LED 9   // LED for low temperature deviation
#define TMP36_PIN A1 // Temperature sensor (TMP36) pin

unsigned OUTPUT, TMP36_PIN, LDR_PIN, HIGH, LOW;

void setup()
{
  Serial.begin(9600);
  pinMode(RED_LED, OUTPUT); // set red LED to output
  pinMode(GREEN_LED, OUTPUT); // set green LED to output
  pinMode(BLUE_LED, OUTPUT); // set blue LED to output
}

void loop()
{
  int temperature = readTemperature(); // variable for temperature sensor
  int lightIntensity = getLightIntensity(); // variable for light intensity sensor
  int tempDependency = calculateTemperatureDependency(temperature); // variable for temperature dependency
  int lightDependency = calculateLightDependency(lightIntensity); // variable for light dependency

  Serial.print("light :");
  Serial.println(lightDependency);
  Serial.print("temp :");
  Serial.println(tempDependency);
  updateLEDs(tempDependency, lightDependency);

  delay(1000); // Set the periodicity in milliseconds
}

// function to read the temperature
float readTemperature()
{
  int sensorValue = analogRead(TMP36_PIN);
  float voltage = sensorValue * 5.0 / 1023.0;
  return (voltage - 0.5) * 100.0;
}

// function to read the light intensity and convert to percentage
int getLightIntensity()
{
  return analogRead(LDR_PIN);
}

// temperature dependencies
int calculateTemperatureDependency(int temperature)
{
  if (temperature <= -12)
  {
    return 0;
  }
  else if (temperature > -12 && temperature <= 0)
  {
    return 1;
  }
  else if (temperature > 0 && temperature <= 20)
  {
    return 2;
  }
  else if (temperature >= 21)
  {
    return 3;
  }
}

// light dependencies
int calculateLightDependency(int lightIntensity)
{
  // Model simplification based on a linear map.
  int lightIntensity_percent = map(lightIntensity, 49, 969, 100, 0);

  if (lightIntensity_percent <= 0)
  {
    return 0;
  }
  else if (lightIntensity_percent > 1 && lightIntensity_percent <= 20)
  {
    return 1;
  }
  else if (lightIntensity_percent > 21 && lightIntensity_percent <= 60)
  {
    return 2;
  }
  else if (lightIntensity_percent >= 61 && lightIntensity_percent <= 100)
  {
    return 3;
  }
}

void updateLEDs(int tempDependency, int lightDependency)
{
  digitalWrite(RED_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(BLUE_LED, LOW);

  if (lightDependency == 0)
  {
    if (tempDependency == 0)
    {
      digitalWrite(GREEN_LED, HIGH);
    }
    else
    {
      digitalWrite(RED_LED, HIGH);
    }
  }
  else if (lightDependency == 1)
  {
    if (tempDependency == 1)
    {
      digitalWrite(GREEN_LED, HIGH);
    }
    else if (tempDependency == 0)
    {
      digitalWrite(BLUE_LED, HIGH);
    }
    else
    {
      digitalWrite(RED_LED, HIGH);
    }
  }
  else if (lightDependency == 2)
  {
    if (tempDependency == 2)
    {
      digitalWrite(GREEN_LED, HIGH);
    }
    else if (tempDependency <= 1)
    {
      digitalWrite(BLUE_LED, HIGH);
    }
    else if (tempDependency > 2)
    {
      digitalWrite(RED_LED, HIGH);
    }
  }
  else if (lightDependency == 3)
  {
    if (tempDependency == 3)
    {
      digitalWrite(GREEN_LED, HIGH);
    }
    else
    {
      digitalWrite(BLUE_LED, HIGH);
    }
  }
}