int sensorPin = A0;      // Analog input pin for the sensor
int sensorValue = 0;     // Variable to store the sensor reading

void setup() {
    Serial.begin(9600);  // Initialize serial communication
    pinMode(sensorPin, INPUT);  // Set the sensor pin as input
}

void loop() {
    sensorValue = analogRead(sensorPin);  // Read the analog value
    Serial.println(sensorValue);          // Print the value to Serial Monitor
}