// (C) Amanda Turquis,Ahmed Algabri,David Hong, group: 13 (2024)
// Work package 3
// Exercise 2
// Submission code: 021513 (provided by your TA-s)

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
  pinMode(RED_LED, OUTPUT);   // set red LED to output
  pinMode(GREEN_LED, OUTPUT); // set green LED to output
  pinMode(BLUE_LED, OUTPUT);  // set blue LED to output
}

void loop()
{
  int temperature = readTemperature();                              // variable for temperature sensor
  int lightIntensity = getLightIntensity();                         // variable for light intensity sensor
  int tempDependency = calculateTemperatureDependency(temperature); // variable for temperature dependency
  int lightDependency = calculateLightDependency(lightIntensity);   // variable for light dependency

  Serial.print("light :");
  Serial.println(lightIntensity);
  Serial.print("temp :");
  Serial.println(temperature);
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
  if (temperature <= -12) // if temperature is smaller or equal -12 degrees
  {
    return 0;
  }
  else if (temperature > -12 && temperature <= 0) // if the temp is between -12 and 0 degrees, including zero
  {
    return 1;
  }
  else if (temperature > 0 && temperature <= 20) // if the temp is between 0 and 20 degrees, including 20
  {
    return 2;
  }
  else if (temperature >= 21) // if the temp is higher or equal 21 degrees
  {
    return 3;
  }
}

// light dependencies
int calculateLightDependency(int lightIntensity)
{
  // Model simplification based on a linear map.
  int lightIntensity_percent = map(lightIntensity, 49, 969, 100, 0);

  if (lightIntensity_percent <= 0) // if light intensity is equal to 0%
  {
    return 0;
  }
  else if (lightIntensity_percent > 1 && lightIntensity_percent <= 20) // if light intensity is higher then 1% and smaller or equal 20%
  {
    return 1;
  }
  else if (lightIntensity_percent > 21 && lightIntensity_percent <= 60) // if light intensity is higher then 21% and smaller or equal 60%
  {
    return 2;
  }
  else if (lightIntensity_percent >= 61 && lightIntensity_percent <= 100) // if light intensity is higher or equal then 61% and smaller or equal 100%
  {
    return 3;
  }
}

void updateLEDs(int tempDependency, int lightDependency)
{
  digitalWrite(RED_LED, LOW);   // sets red LED to LOW
  digitalWrite(GREEN_LED, LOW); // sets green LED to LOW
  digitalWrite(BLUE_LED, LOW);  // sets blue LED to LOW

  if (lightDependency == 0) // if light dependency returns 0
  {
    if (tempDependency == 0) // it enter the second if statement and check if the temp dependency returns 0
    {
      digitalWrite(GREEN_LED, HIGH); // it set green LED to high, criteria met
    }
    else
    {
      digitalWrite(RED_LED, HIGH); // else it sets the red LED to high, since temp is higher then the criteria
    }
  }
  else if (lightDependency == 1) // if light dependency returns 1
  {
    if (tempDependency == 1) // it enter the second if statement and check if temp dependency returns 1
    {
      digitalWrite(GREEN_LED, HIGH); // it set green LED to high, since the criteria is fullfilled
    }
    else if (tempDependency == 0) // if temp dependency returns 0
    {
      digitalWrite(BLUE_LED, HIGH); // it sets the blue led to high, since the temp is smaller then the criteria
    }
    else
    {
      digitalWrite(RED_LED, HIGH); // else it sets the red led to high, since it doesn't meet the criteria
    }
  }
  else if (lightDependency == 2) // if light dependency returns 2
  {
    if (tempDependency == 2) // it enter the second if statement and check if temp dependency returns 2
    {
      digitalWrite(GREEN_LED, HIGH); // it sets the green led to high, since it meets the ideal conditions
    }
    else if (tempDependency <= 1) // if the lightDependency is equal 2 and tempDependency is equal or smaller then 1
    {
      digitalWrite(BLUE_LED, HIGH); // set the blue led to high, since the temp is smaller then the criteria
    }
    else if (tempDependency > 2) // if the tempDependency is higher then 2
    {
      digitalWrite(RED_LED, HIGH); // it sets the red led to high, since the temp is higher then it should for the lightIntensity
    }
  }
  else if (lightDependency == 3) // if lightDependency is equal to 3
  {
    if (tempDependency == 3) // if tempDependency is equal to 3
    {
      digitalWrite(GREEN_LED, HIGH); // it sets the green led to high, since the criteria between light and temp are met
    }
    else
    {
      digitalWrite(BLUE_LED, HIGH); // else the temp is lower then the criteria and set the led to blue
    }
  }
}
