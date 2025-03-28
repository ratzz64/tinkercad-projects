int pot_value = 0;
int ledPin = 0;
int sensorPin = A3;

void setup()
{
    pinMode(ledPin, OUTPUT);
    pinMode(sensorPin, INPUT);
}

void loop()
{
    pot_value = analogRead(sensorPin);
    pot_value = map(pot_value, 0, 1023, 0, 255);
    analogWrite(ledPin, pot_value);
}