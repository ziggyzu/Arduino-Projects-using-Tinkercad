#include <LiquidCrystal.h>

const int trigPin = 9;
const int echoPin = 10;
const int buzzer = 7;
const int relayPin = 8;
const int tempPin = A0;

const int redLED = 6;
const int greenLED = A1;
const int blueLED = A2;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int tankHeight = 30; // cm

unsigned long pumpStartTime = 0;
unsigned long pumpRunTime = 0;
bool pumpIsRunning = false;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(relayPin, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);

  digitalWrite(relayPin, LOW); // Pump OFF initially

  lcd.begin(16, 2);
  lcd.clear();

  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;

  int waterLevel = tankHeight - distance;
  if (waterLevel < 0) waterLevel = 0;
  if (waterLevel > tankHeight) waterLevel = tankHeight;

  int levelPercent = map(waterLevel, 0, tankHeight, 0, 100);

  int tempReading = analogRead(tempPin);
  float temperature = tempReading * (5.0 / 1023.0) * 100;

  Serial.print("Level Percent: ");
  Serial.println(levelPercent);

  // Pump control with thresholds adjusted for testing
  if (levelPercent >= 70) {
    digitalWrite(relayPin, LOW);    // Pump OFF
    digitalWrite(buzzer, HIGH);
    Serial.println("Tank Full - Pump OFF");
    if (pumpIsRunning) {
      pumpIsRunning = false;
      pumpRunTime = millis() - pumpStartTime;
      Serial.print("Pump ran for (ms): ");
      Serial.println(pumpRunTime);
    }
  } else if (levelPercent <= 10) {
    digitalWrite(relayPin, HIGH);   // Pump ON
    digitalWrite(buzzer, HIGH);
    Serial.println("Tank Low - Pump ON");
    if (!pumpIsRunning) {
      pumpIsRunning = true;
      pumpStartTime = millis();
    }
  } else {
    digitalWrite(relayPin, HIGH);   // Pump ON
    digitalWrite(buzzer, LOW);
    Serial.println("Pump ON, Normal Level");
  }

  lcd.setCursor(0, 0);
  lcd.print("Water:");
  lcd.print(levelPercent);
  lcd.print("%   ");

  lcd.setCursor(0, 1);
  lcd.print("Temp:");
  lcd.print(temperature, 1);
  lcd.print(" C   ");

  // RGB LED Indicator
  if (levelPercent >= 80) {
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, HIGH);
    digitalWrite(blueLED, LOW);
  } else if (levelPercent >= 20) {
    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, HIGH);
    digitalWrite(blueLED, LOW);
  } else {
    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, LOW);
    digitalWrite(blueLED, LOW);
  }

  delay(500);
  
 
}


