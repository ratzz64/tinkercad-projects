int ledPin = 11;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Fade in (0 to 255)
  for(int a = 0; a <= 255; a++) {
    analogWrite(ledPin, a);
    delay(20);
  }
  
  // Fade out (255 to 0) - Fixed: changed a++ to a--
  for(int a = 255; a >= 0; a--) {
    analogWrite(ledPin, a);
    delay(20);
  }
  
  delay(200);
}