// (C) Amanda Turquis,Ahmed Algabri,David Hong, group: 13 (2024)
// Work package 3
// Exercise 3a
// Submission code: XXXXXX (provided by your TA-s)

// Library for the temperature sensor
#define TMP36_PIN A0 // Temperature sensor (TMP36) pin

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int sensorValue = analogRead(TMP36_PIN); // read analog value from temperature sensor
  float voltage = sensorValue * 5.0 / 1023.0; // convert analog value to voltage
  float temperature = (voltage - 0.5) * 100.0; // calculate temperature using the formula

  // Display temperature on the multimeter
  analogWrite(A1, sensorValue); // simulate voltage on multimeter

  // Print temperature to the serial port
  Serial.println("Temperature: " + String(temperature) + " °C");

  delay(500); // Set the periodicity in milliseconds
}