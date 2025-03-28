void setup() {
    unsigned char ledPin;
    for(ledPin=1; ledPin<=8; ledPin++) {
        pinMode(ledPin, OUTPUT);
    }
}

void loop() {
    unsigned char ledPin;
    for(ledPin=1; ledPin<=8; ledPin++) {
        digitalWrite(ledPin, HIGH);
        delay(300);
    }
    for(ledPin=1; ledPin<=8; ledPin++) {
        digitalWrite(ledPin, LOW);
        delay(300);
    }
}