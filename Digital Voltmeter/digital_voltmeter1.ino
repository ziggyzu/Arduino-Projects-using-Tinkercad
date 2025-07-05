#include <LiquidCrystal.h>

// Define LCD pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Variable declaration
float r1 = 90900.0; // 90.9 kOhm
float r2 = 10000.0; // 10 kOhm
int analogValue = 0;
float voltage = 0.0;
float temp = 0.0;

void setup() {
  // Initialize serial monitor
  Serial.begin(9600);

  // Initialize LCD display
  lcd.begin(16, 2); // 16 columns, 2 rows

  // Print initial message to LCD
  lcd.print("Digital Voltmeter");
}

void loop() {
  // Read analog value from A0 pin
  analogValue = analogRead(A0);

  // Voltage calculation
  temp = (analogValue * 5.0) / 1024.0; // Convert analog reading to voltage at A0
  voltage = temp * ((r1 + r2) / r2);   // Scale voltage using voltage divider formula

  // Display voltage on serial monitor
  Serial.print("Voltage: ");
  Serial.print(voltage);
  Serial.println(" V");

  // Display voltage on LCD
  lcd.setCursor(0, 1); // Set cursor to the second line
  lcd.print("Voltage: ");
  lcd.print(voltage);
  lcd.print("V   "); // Add spaces to clear previous digits if any

  // Delay for readability
  delay(300);
}