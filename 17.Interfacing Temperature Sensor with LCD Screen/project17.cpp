#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int degree;
double realdegree;
String lcdBuffer;

void setup() {
    lcd.begin(16, 2);  // Corrected from "l6" to "16" (16x2 LCD)
    degree = 0;        // Corrected variable name from "degrees"
    realdegree = 0.0;
    lcd.print("Today's Temp:");
}

void loop() {
    degree = analogRead(0);  // Corrected variable name from "degrees"
    
    realdegree = (double)degree / 1024;  // Fixed syntax
    realdegree = realdegree * 5;         // Corrected calculation
    realdegree = realdegree - 0.5;       // Corrected calculation
    realdegree = realdegree * 100;       // Corrected calculation
    
    lcd.setCursor(0, 1);
    realdegree = (realdegree * 9.0/5.0) + 32;  // Celsius to Fahrenheit conversion
    String output = String(realdegree) + String((char)178) + "F";  // Fixed variable name and syntax
    lcd.print(output);  // Fixed variable name
    delay(1000);  // Added delay for stability
}