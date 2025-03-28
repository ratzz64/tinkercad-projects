#define ptr 13
bool ptr_val = 0;
#define led 12  // Changed from "Ted" to "led" to match usage

void setup() {
    Serial.begin(9600);
    pinMode(led, OUTPUT);  // Corrected from "pinkode"
    pinMode(ptr, INPUT);   // Corrected from "pinkode"
}

void loop() {  // Added parentheses
    ptr_val = digitalRead(ptr);
    if (ptr_val == HIGH) {
        Serial.println("Motion Detected");
        digitalWrite(led, HIGH);
    }
    else {
        Serial.println("No Motion Detected");
        digitalWrite(led, LOW);
    }
}