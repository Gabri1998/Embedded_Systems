// (C) Amanda Turquis,Ahmed Algabri,David Hong, group: 13 (2024)
// Work package 5
// Exercise 2
// Submission code: XXXXXX (provided by your TA-s)


#include <DHT.h>

#define DHTPIN 2      // Digital pin connected to the DHT11 sensor
#define DHTTYPE DHT11 // DHT11 sensor

#define RED_LED 3     // Pin for the red LED
#define YELLOW_LED 5  // Pin for the yellow LED
#define GREEN_LED 6   // Pin for the green LED
#define BLUE_LED 9    // Pin for the blue LED
#define WHITE_LED 10  // Pin for the white LED

// Define the temperature ranges
#define TEMP_RANGE_1 10  // 0-10 degrees Celsius
#define TEMP_RANGE_2 20  // 11-20 degrees Celsius
#define TEMP_RANGE_3 30  // 21-30 degrees Celsius
#define TEMP_RANGE_4 40  // 31-40 degrees Celsius

#define DELAY_PERIOD 5000  // Delay 5 seconds

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(WHITE_LED, OUTPUT);

  digitalWrite(RED_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(BLUE_LED, LOW);
  digitalWrite(WHITE_LED, LOW);

  Serial.begin(9600);
}

void loop() {
  float temperature = dht.readTemperature();  // Read temperature

  Serial.print("Temperature: ");
  Serial.println(temperature);

  updateLeds(temperature);

  delay(DELAY_PERIOD);  // Wait 5 seconds before the next temperature reading
}

void updateLeds(float temperature) {
  // Turn off all LEDs
  digitalWrite(RED_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(BLUE_LED, LOW);
  digitalWrite(WHITE_LED, LOW);

  // Check temperature ranges and turn on the correct LEDs for that temperature range
  if (temperature <= TEMP_RANGE_1) {
    digitalWrite(RED_LED, HIGH);
  } else if (temperature <= TEMP_RANGE_2) {
    digitalWrite(YELLOW_LED, HIGH);
  } else if (temperature <= TEMP_RANGE_3) {
    digitalWrite(GREEN_LED, HIGH);
  } else if (temperature <= TEMP_RANGE_4) {
    digitalWrite(BLUE_LED, HIGH);
  } else {
    digitalWrite(WHITE_LED, HIGH);
  }
}