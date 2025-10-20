// Author: Isaac Abella
// Description: EF 152 Project 2: Code implementation

#include <Arduino.h>

const int buttonPin2 = 2; // Button 1 rightmost button
const int buttonPin3 = 3; // Button 2 lefftmost button

const int ledPin1 = 4;
const int ledPin2 = 5;
const int ledPin3 = 6;
const int ledPin4 = 7;
const int ledPin5 = 8;
const int ledPin6 = 9;
const int ledPin7 = 10;
const int ledPin8 = 11;

/*
General Instruction: The led pins 1 - 5 will light up sequentially

Than when you press button 2, the led pins 6 - 8. will light up in order as a pulse.
*/

void setup()
{ // set the inputs and outputs.
    pinMode(buttonPin2, INPUT);
    pinMode(buttonPin3, INPUT);

    pinMode(ledPin1, OUTPUT);
    pinMode(ledPin2, OUTPUT);
    pinMode(ledPin3, OUTPUT);
    pinMode(ledPin4, OUTPUT);
    pinMode(ledPin5, OUTPUT);
    pinMode(ledPin6, OUTPUT);
    pinMode(ledPin7, OUTPUT);
    pinMode(ledPin8, OUTPUT);
}

void loop()
{
    int button2state = digitalRead(buttonPin2); // read state of the rightmost button
    int button3state = digitalRead(buttonPin3); // read state of the leftmost button

    if (button2State == LOW)
    { // Button 2 is active, start the pulse effect
        button2PulseEffect();
    }
    if (buttson3State == HIGH)
    { // Button 3 is pressed, run the sequential LED pattern
        sequentialLEDs();
    }
}

void sequentialLEDs()
{
    for (int i = 1; i <= 5; i++)
    {
        digitalWrite(i + 3, HIGH); // Turn on LEDs 1 to 5
        delay(500);                // Delay for 500 milliseconds (0.5 seconds)
        digitalWrite(i + 3, LOW);  // Turn off the current LED
    }
}

void button2PulseEffect()
{
    for (int i = 6; i <= 8; i++)
    {
        for (int brightness = 0; brightness < 256; brightness++)
        {
            analogWrite(i, brightness); // Increase LED brightness
            delay(10);                  // Delay to control the pulse speed
        }
        for (int brightness = 255; brightness >= 0; brightness--)
        {
            analogWrite(i, brightness); // Decrease LED brightness
            delay(10);                  // Delay to control the pulse speed
        }
    }
}
