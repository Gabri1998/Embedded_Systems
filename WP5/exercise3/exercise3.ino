// (C) Amanda Turquis,Ahmed Algabri,David Hong, group: 13 (2024)
// Work package 5
// Exercise 3
// Submission code: XXXXX (provided by your TA-s)

#include <DHT.h>

#define LDR_PIN A0 // Light sensor pin
#define RED_LED 7  // LED for high temperature deviation
#define GREEN_LED 8  // LED for normal dependency
#define BLUE_LED 9  // LED for low temperature deviation
#define DHT_PIN 2  // Digital pin connected to the DHT11 sensor
#define DHT_TYPE DHT11 // DHT11 sensor type

DHT dht(DHT_PIN, DHT_TYPE);

void setup()
{
  Serial.begin(9600);
  pinMode(RED_LED, OUTPUT);   // Set red LED to output
  pinMode(GREEN_LED, OUTPUT); // Set green LED to output
  pinMode(BLUE_LED, OUTPUT);  // Set blue LED to output

  digitalWrite(RED_LED, LOW);   // Set red LED to LOW
  digitalWrite(GREEN_LED, LOW); // Set green LED to LOW
  digitalWrite(BLUE_LED, LOW);  // Set blue LED to LOW
}

void loop()
{
  float temperature = readTemperature();              // Variable for temperature sensor
  int lightIntensity = getLightIntensity();            // Variable for light intensity sensor
  int tempDependency = calculateTemperatureDependency(temperature); // Variable for temperature dependency
  int lightDependency = calculateLightDependency(lightIntensity);   // Variable for light dependency

  Serial.print("light :");
  Serial.println(lightIntensity);
  Serial.print("temp :");
  Serial.println(temperature);
  updateLEDs(tempDependency, lightDependency);

  delay(1000); // Set the periodicity in milliseconds
}

// Function to read the temperature
float readTemperature()
{
  return dht.readTemperature(); // Uses the DHT11 library to read the temperature
}

// Function to read the light intensity and convert to percentage
int getLightIntensity()
{
  return analogRead(LDR_PIN);
}

// Temperature dependencies
int calculateTemperatureDependency(float temperature)
{
  // Adjust the temperature ranges as needed for DHT11 sensor
  if (temperature <= 10) // If temperature is smaller or equal to 10 degrees Celsius
  {
    return 0;
  }
  else if (temperature <= 20) // If temperature is between 11 and 20 degrees Celsius
  {
    return 1;
  }
  else if (temperature <= 30) // If temperature is between 21 and 30 degrees Celsius
  {
    return 2;
  }
  else // If temperature is higher than 30 degrees Celsius
  {
    return 3;
  }
}

// Light dependencies
int calculateLightDependency(int lightIntensity)
{
  // Model simplification based on a linear map.
  int lightIntensity_percent = map(lightIntensity, 49, 969, 100, 0);

  if (lightIntensity_percent <= 0) // If light intensity is equal to 0%
  {
    return 0;
  }
  else if (lightIntensity_percent <= 20) // If light intensity is between 1% and 20%
  {
    return 1;
  }
  else if (lightIntensity_percent <= 60) // If light intensity is between 21% and 60%
  {
    return 2;
  }
  else // If light intensity is higher than 60%
  {
    return 3;
  }
}

void updateLEDs(int tempDependency, int lightDependency)
{
  digitalWrite(RED_LED, LOW);   // Set red LED to LOW
  digitalWrite(GREEN_LED, LOW); // Set green LED to LOW
  digitalWrite(BLUE_LED, LOW);  // Set blue LED to LOW

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