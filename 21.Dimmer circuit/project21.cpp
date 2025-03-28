int potPin = A0;      // Declare potPin to be analog pin A0
int LEDPin = 9;        // Declare LEDPin to be Arduino pin 9
int readValue;         // Use this variable to read Potentiometer
int writeValue;        // Use this variable for writing to LED

void setup() {
    pinMode(potPin, INPUT);     // Set potPin to be an input
    pinMode(LEDPin, OUTPUT);    // Set LEDPin to be an OUTPUT
    Serial.begin(9600);         // Turn on Serial Port
}

void loop() {
    readValue = analogRead(potPin);                     // Read the voltage on the Potentiometer
    writeValue = (255. / 1023.) * readValue;           // Convert 0-1023 range to 0-255
    analogWrite(LEDPin, writeValue);                   // Write PWM value to the LED
    Serial.print("You are writing a value of ");
    Serial.println(writeValue);
}