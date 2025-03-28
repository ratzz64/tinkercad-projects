/* This program controls three LEDs based on a button press */
int buttonState = 0;          // Fixed: Renamed from 'buttonsState' for consistency
const int buttonPin = 2;      // Button connected to pin 2
int ledOne = 13;              // LED 1 (built-in LED)
int ledTwo = 12;              // LED 2
int ledThree = 8;             // Fixed: Renamed from 'ledThrée' to 'ledThree'

void setup() {
  pinMode(ledOne, OUTPUT);
  pinMode(ledTwo, OUTPUT);
  pinMode(ledThree, OUTPUT);
  pinMode(buttonPin, INPUT);  // Button as input
  Serial.begin(9600);         // Start serial communication
}

void loop() {
  buttonState = digitalRead(buttonPin);  // Read button state

  if (buttonState == 1) {               // If button is pressed
    digitalWrite(ledOne, 1);            // Turn on LED 1
    Serial.print("STOP\n");             // Print message
    delay(2000);                        // Wait 2 seconds
    digitalWrite(ledOne, 0);            // Turn off LED 1
    delay(500);                         // Short pause

    digitalWrite(ledTwo, 1);            // Turn on LED 2
    Serial.print("GET READY\n");        // Print message
    delay(2000);                        // Wait 2 seconds
    digitalWrite(ledTwo, 0);            // Turn off LED 2
    delay(500);                         // Short pause

    digitalWrite(ledThree, 1);          // Turn on LED 3
    Serial.print("BYE\n");              // Print message
    delay(2000);                        // Wait 2 seconds
    digitalWrite(ledThree, 0);          // Turn off LED 3
  }
}