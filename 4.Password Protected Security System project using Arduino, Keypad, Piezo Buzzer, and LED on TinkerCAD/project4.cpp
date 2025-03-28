#include <Keypad.h>

const int buzzer = 9;
const int redLed = 7;
const int greenLed = 6;

const String password = "1234";  // Change this to your desired password
String inputPassword = "";

const byte ROWS = 4; 
const byte COLS = 4; 
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {A0, A1, A2, A3};
byte colPins[COLS] = {4, 5, 2, 3};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  char key = keypad.getKey();
  
  if (key) {
    Serial.print(key);
    
    if (key == '#') {  // '#' is used to confirm the password
      if (inputPassword == password) {
        unlockSystem();
      } else {
        denyAccess();
      }
      inputPassword = "";  // Reset input
    } else if (key == '*') {  // '*' is used to clear input
      inputPassword = "";
      Serial.println(" - Input Cleared");
    } else {
      inputPassword += key;  // Append entered key to password
    }
  }
}

void unlockSystem() {
  Serial.println(" - ACCESS GRANTED");
  digitalWrite(greenLed, HIGH);
  delay(2000);
  digitalWrite(greenLed, LOW);
}

void denyAccess() {
  Serial.println(" - ACCESS DENIED");
  digitalWrite(redLed, HIGH);
  tone(buzzer, 1000);
  delay(2000);
  digitalWrite(redLed, LOW);
  noTone(buzzer);
}
