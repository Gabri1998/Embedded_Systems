// (C) Amanda Turquis,Ahmed Algabri,David Hong, group: 13 (2024)
// Work package 4
// Exercise 2
// Submission code: XXXXXX (provided by your TA-s)

// Define the temperature sensor pin
const int temperatureSensorPin = A0; // Analog pin for TMP36

// Define the LED pins
const int ledPins[] = {3, 4, 5, 6, 7};

// Define temperature thresholds for each LED
const int temperatureThresholds[] = {10, 20, 30, 40}; 

// Define LED colors corresponding to temperature intervals
const int ledColors[][3] = {
  {0, 0, 255},  // Blue for 0-10 degrees Celsius
  {0, 255, 0},  // Green for 11-20 degrees Celsius
  {255, 0, 0},  // Red for 21-30 degrees Celsius
  {255, 255, 0}, // Yellow for 31-40 degrees Celsius
  {255, 0, 255} // White for above 40 degrees Celsius
};

void setup() {
  // Set LED pins as OUTPUT
  for (int i = 0; i < 5; i++) {
    pinMode(ledPins[i], OUTPUT);
  }

  // Start serial communication
  Serial.begin(9600);

  // Attach interrupt to check temperature periodically
  attachInterrupt(digitalPinToInterrupt(temperatureSensorPin), checkTemperature, CHANGE);
}

void loop() {
  // Main loop (empty as we're using interrupts)
}

void checkTemperature() {
  // Read analog voltage from TMP36
  int sensorValue = analogRead(temperatureSensorPin);

  // Convert analog reading to temperature in degrees Celsius
  float temperature = (sensorValue * 0.004882814) * 100.0;

  // Print temperature to serial monitor
  Serial.print("Temperature: ");
  Serial.println(temperature);

  // Turn off all LEDs
  turnOffAllLEDs();

  // Check temperature range and turn on corresponding LED
  for (int i = 0; i < 5; i++) {
    if (temperature <= temperatureThresholds[i]) {
      // Turn on the corresponding LED with the assigned color
      digitalWrite(ledPins[i], HIGH);  // Turn on LED
      digitalWrite(ledPins[i + 1], HIGH);
      digitalWrite(ledPins[i + 2], HIGH);
      break;
    }
  }
}


void turnOffAllLEDs() {
  // Turn off all LEDs
  for (int i = 0; i < 5; i++) {
    analogWrite(ledPins[i], 0);
  }
}
