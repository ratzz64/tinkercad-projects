// Define the analog pin for the LM35 temperature sensor
const int tempPin = A0;

void setup() {
  Serial.begin(9600); // Start the serial monitor
}

void loop() {
  int analogValue = analogRead(tempPin); // Read the analog value
  float voltage = analogValue * (5.0 / 1023.0); // Convert to voltage
  float temperatureC = (voltage - 0.5) * 100; // Corrected formula for LM35
  float temperatureF = (temperatureC * 9.0 / 5.0) + 32.0; // Convert to Fahrenheit

  // Print the temperature values
  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.print(" °C / ");
  Serial.print(temperatureF);
  Serial.println(" °F");

  delay(1000); // Wait for 1 second before reading again
}