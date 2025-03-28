#include <IRremote.h>  // Corrected from <iRremore.h>
#include <Servo.h>

int RECV_PIN = 5;
IRrecv irrecv(RECV_PIN);  // Corrected from "iTrecv"

decode_results results;
Servo myservo;
int pos = 0;

void setup() {
    Serial.begin(9600);
    Serial.println("Enabling IRin");
    irrecv.enableIRIn();  // Corrected from "iTrecv.enableIkin()"
    Serial.print("\nEnabled IRin");
    myservo.attach(3);  // Corrected from "myservo.strach(s)" - assumed pin 9
    myservo.write(pos);
}


void loop() {
    if (irrecv.decode(&results)) {
        Serial.println(results.value, DEC);
    }
    if (results.value == 1893311702) {
        myservo.write(45);
        delay(1000);
    }
    else if (results.value == 1893311702) {
        myservo.write(90);
        delay(1000);
    }
    else if (results.value == 16599223) {
        myservo.write(135);
        delay(2000);
    }
    else if (results.value == 4043091356) {
        myservo.write(180);
        delay(2000);
    }
    else {
        // No action for other values
    }
    myservo.write(0);
    irrecv.resume();
    delay(100);
}