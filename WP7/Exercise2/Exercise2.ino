// (C) Amanda Turquis,Ahmed Algabri,David Hong, group: 13 (2024)
// Work package 6
// Exercise 2
// Submission code: XXXXXX (provided by your TA-s)

const int trigPin = 2;    // Trigger pin for ultrasonic sensor
const int echoPin = 3;    // Echo pin for ultrasonic sensor

const int ledPins[] = {4, 5, 6, 7};  // LEDs pin
const int speakerPin = 8;             // Pin for the speaker

void setup() {
  Serial.begin(9600);
  
  // Initialize LED pins
  for (int i = 0; i < 4; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  
  pinMode(speakerPin, OUTPUT);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  int distance = getDistance();
  
  // LED indication based on distance
  updateLEDs(distance);
  
  // Speaker indication based on distance
  updateSpeaker(distance);
  
  delay(100);  // Delay for stability
}

int getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  
  digitalWrite(trigPin, LOW);
  
  return pulseIn(echoPin, HIGH) * 0.0343 / 2;  // Calculates the distance in cm
}

void updateLEDs(int distance) {
  if (distance < 200 && distance >= 30) {
    for (int i = 0; i < 4; i++) {
      digitalWrite(ledPins[i], HIGH);
    }
  } else if (distance < 30) {
    for (int i = 0; i < 4; i++) {
      digitalWrite(ledPins[i], HIGH);
    }
  } else {
    for (int i = 0; i < 4; i++) {
      digitalWrite(ledPins[i], LOW);
    }
  }
}

void updateSpeaker(int distance) {
  if (distance < 200 && distance >= 25) {
    tone(speakerPin, 1000 + (200 - distance) * 10);  // Adjust tone frequency based on distance
  } else if (distance < 25) {
    // Super annoying tone for immediate danger
    tone(speakerPin, 2000);
    delay(200);
    noTone(speakerPin);
    delay(200);
  } else {
    noTone(speakerPin);
  }
}