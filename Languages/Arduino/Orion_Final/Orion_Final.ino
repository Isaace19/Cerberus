// Author: Isaac Abella, Roger Smith, Daniel Phan, Grey Ellington
// Description: EF 152 Project 2: Code implementation

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

bool loadCheck = false; // used to prevent flashing in loop

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
    // Check the state of buttonPin2 (button 1)
    int buttonState2 = digitalRead(buttonPin2);

    // If button 1 is pressed, turn on the LEDs sequentially
    if (buttonState2 == HIGH) {
        digitalWrite(ledPin1, HIGH);
        delay(100); 
        digitalWrite(ledPin2, HIGH);
        delay(100);
        digitalWrite(ledPin3, HIGH);
        delay(100);
        digitalWrite(ledPin4, HIGH);
        delay(100);
        digitalWrite(ledPin5, HIGH);
        delay(100);
    }
 
  // TODO create the arrow function still after testing wiring
  int buttonState3 = digitalRead(buttonPin3);

   if (buttonState3 == HIGH) {
        // Button 2 (buttonPin3) is pressed
        digitalWrite(ledPin6, HIGH);
        delay(300);
        digitalWrite(ledPin6, LOW);
        digitalWrite(ledPin7, HIGH);
        delay(300);
        digitalWrite(ledPin7, LOW);
        digitalWrite(ledPin8, HIGH);
        delay(300);
        digitalWrite(ledPin8, LOW);
    }
}
