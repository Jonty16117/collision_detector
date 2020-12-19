////Collision Warning System////
//// Year 2020 ////
//// palvish sachdeva////

#include <hcsr04.h>



const int trigPin = 12;
const int echoPin = 13;
int buzz = 10;
long duration;
long long distance;
int counter;

HCSR04 us_sensor(trigPin, echoPin, 20, 4000);

// the setup function runs once when you press reset or power the board
void setup() {
    // initialize digital pin 13 as an output.
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(1, OUTPUT);
    pinMode(2, OUTPUT);
    Serial.begin(9600);

    counter = 0;
}

// the loop function runs over and over again forever
void loop()
{
//print the current distance
    Serial.println(us_sensor.ToString());

    Serial.println("function ok");
    Serial.println(counter);
// Clears the trigPin
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

// Reads the the distance in millimeters
    distance = us_sensor.distanceInMillimeters();

// Prints the distance on the Serial Monitor
    if (distance <= 150 && distance >= 10)
    {
        digitalWrite(1, HIGH);

// digitalWrite(13, LOW);
        // turn the LED on (HIGH is the voltage level)

    } else 
    {
        

        digitalWrite(1, LOW);    
        // turn the LED off by making the voltage LOW
        // wait for a second

    }

    if (distance <= 50 && counter < 4)
    {
        counter++;
    }
    else{
        counter = 0;
    }


    if (distance <= 50 && counter >= 4)
    {
        digitalWrite(2, HIGH);

        tone(buzz, 2000);
        delay(100);
        noTone(buzz);
        delay(100);

        tone(buzz, 2000);
        delay(100);
        noTone(buzz);
        delay(100);

        tone(buzz, 2000);
        delay(100);
        noTone(buzz);

        tone(buzz, 2000);
        delay(100);
        noTone(buzz);
        delay(100);
    }

    else
    {
        digitalWrite(2, LOW);    
        // turn the LED off by making the voltage LOW
        // wait for a second
    }
}