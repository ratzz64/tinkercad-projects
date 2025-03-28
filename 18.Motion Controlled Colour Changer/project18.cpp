int buzzer = 3;
int pir = 7;
int red_light_pin = 9;
int green_light_pin = 11;
int blue_light_pin = 10;

void setup() {
    pinMode(pir, INPUT);
    pinMode(buzzer, OUTPUT);
    pinMode(red_light_pin, OUTPUT);
    pinMode(green_light_pin, OUTPUT);
    pinMode(blue_light_pin, OUTPUT);
    digitalWrite(pir, LOW);
    digitalWrite(buzzer, LOW);
    digitalWrite(red_light_pin, LOW);
    digitalWrite(green_light_pin, LOW);
    digitalWrite(blue_light_pin, LOW);
}

void RGB_color(int red_light_value, int green_light_value, int blue_light_value) {
    analogWrite(red_light_pin, red_light_value);
    analogWrite(green_light_pin, green_light_value);
    analogWrite(blue_light_pin, blue_light_value);
}

void loop() {
    if(digitalRead(pir) == HIGH) {
        digitalWrite(buzzer, HIGH);
        RGB_color(0, 0, 255); // Blue
        while(digitalRead(pir) == HIGH); // Wait while motion detected
    }
    else {
        digitalWrite(buzzer, LOW);
        RGB_color(255, 0, 255); // Magenta
    }
}