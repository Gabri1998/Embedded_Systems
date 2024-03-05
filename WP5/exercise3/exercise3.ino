// (C) Amanda Turquis,Ahmed Algabri,David Hong, group: 13 (2024)
// Work package 5
// Exercise 3
// Submission code: 285867 (provided by your TA-s)

// Include the library for the DHT11 Sensor
#include <DHT.h>

// Define section
#define LED1 13 // LED1
#define LED2 12 // LED2
#define LED3 11 // LED3

#define TEMP 7 //  TEMP
#define DHTTYPE DHT11 // DHT11 Sensor

#define LIGHT A0 // DHT11 Sensor

// DHT sensor definition
DHT dht(TEMP, DHTTYPE);

// Setup part
void setup() {
  // Set LED1 as output
  pinMode(LED1, OUTPUT);
  // Set LED2 as output
  pinMode(LED2, OUTPUT);
  // Set LED3 as output
  pinMode(LED3, OUTPUT);

  // Set TEMP as input
  pinMode(TEMP, INPUT);

  // Set LIGHT as input
  pinMode(LIGHT, INPUT);

  // Begin serial connection
  Serial.begin(9600);

  // Begin DHT
  dht.begin();
}

// Function to read temperature
float readTemp() {
  // Return temp value
  return dht.readTemperature();
}

// Calculate temp dependency
int tempDependency(float temp) {
  // If temp < -12
  if (temp < -12) {
    // Return 1
    return 1;
  }

  // If temp is between -12 and 0
  else if (temp > -12 && temp <= 0) {
    // Return 2
    return 2;
  }

  // If temp is between 0 and 20
  else if (temp > 0 && temp <= 20) {
    // Return 3
    return 3;
  }

  // If temp is higher than 21
  else if (temp > 21) {
    // Return 4
    return 4;
  }
}

// Function to get Light
int getLight() {
  // Return light value
  return analogRead(LIGHT);
}

// Calculate light dependency
int lightDependency(int light) {
  // Variable declarations
  int lightIntensity = getLight(); // Get raw light info
  int lightPercentage = map(lightIntensity, 0, 1023, 0, 100); // Map it to between 0 to 100

  // If light is 0
  if (lightPercentage == 0) {
    // return 1
    return 1;
  }

  // If light is between 0 and 20
  else if (lightPercentage > 0 && lightPercentage <= 20) {
    // return 2
    return 2;
  }

  // If light is between 20 and 60
  else if (lightPercentage > 20 && lightPercentage <= 60) {
    // return 3
    return 3;
  }

  // If light is over 60
  else if (lightPercentage > 60) {
    // return 4
    return 4;
  }
}

// Function to change LED
void changeLED() {
  // Variable declarations
  float temp = readTemp(); // raw temp
  int light = getLight(); // raw light

  // Start with LED1 turned off
  digitalWrite(LED1, LOW);
  // Start with LED2 turned off
  digitalWrite(LED2, LOW);
  // Start with LED3 turned off
  digitalWrite(LED3, LOW);

  // Variable declarations
  int tempD = tempDependency(temp); // temp dependency
  int lightD = lightDependency(light); // light dependency

  // If temp dependency is lower than light dependency
  if (tempD < lightD) {
    // Turn on LED1
    digitalWrite(LED1, HIGH);
  }

  // If temp dependency is equal to light dependency
  else if (tempD == lightD) {
    // Turn on LED2
    digitalWrite(LED2, HIGH);
  }

  // If temp dependenct is higher than the light dependency
  else if (tempD > lightD) {
    // Turn on LED3
    digitalWrite(LED3, HIGH);
  }

  
}

// Loop
void loop() {
  // Variable declarations
  float temp = readTemp(); // Temperature
  float h = dht.readHumidity(); // Humidity just for fun
  int lightIntensity = getLight(); // Light
  int lightPercentage = map(lightIntensity, 0, 1018, 0, 100); // Map it to be between 0 to 100

  // Change LED based on the dependency
  changeLED();

  Serial.print("Temp: ");
  Serial.println(temp);

  Serial.print("Humidity: ");
  Serial.println(h);

  Serial.print("Light: ");
  Serial.println(lightPercentage);

  // Pause 1 sec
  delay(1000);


}