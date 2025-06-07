#include <Arduino.h>
/*
 sudo chmod 777 /dev/ttyACM0
*/

const int buttonPin = 8;  // the number of the pushbutton pin
const int yellowLedPin = 2;    // the number of the LED pin
const int redLedPin = 7;    // the number of the LED pin
const int greenLedPin = 4;    // the number of the LED pin

bool buttonAlreadyPressed = false;
// variables will change:
int buttonState = 0;  // variable for reading the pushbutton status
int randNum;
float chanceToLose;
float chanceToWin = 50;
void setup() {
    randomSeed(analogRead(0));
    Serial.begin(9600);
    // initialize the LED pin as an output:
    pinMode(yellowLedPin, OUTPUT);
    pinMode(redLedPin, OUTPUT);
    pinMode(greenLedPin, OUTPUT);
    // initialize the pushbutton pin as an input:
    pinMode(buttonPin, INPUT);
    Serial.println(randNum);

}

void loop() {
    // read the state of the pushbutton value:
    buttonState = digitalRead(buttonPin);


    // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
    if (buttonState == HIGH) {


        Serial.println("----------------------------");
        // turn LED on:
        switch (buttonAlreadyPressed)
        {
            case false:

                Serial.println("Chance to win: " + String(chanceToWin));
                chanceToLose = random(100);
                Serial.println("----------------------------");
                Serial.println("Chance to lose: " + String(chanceToLose));
                Serial.println("----------------------------");


                digitalWrite(yellowLedPin, HIGH);
                delay(1500);    // Here should be animation of gambling
                digitalWrite(yellowLedPin, LOW);

                // Serial.println("random = " + String(randNum));
                if (random(1,4) == random(1,4) && chanceToLose < chanceToWin )
                {
                    for (int i = 0; i < 5; i++)
                    {
                        digitalWrite(greenLedPin, HIGH);
                        delay(500);
                        digitalWrite(greenLedPin, LOW);
                        delay(500);
                    }
                    chanceToWin = chanceToWin - 30;
                }else
                {
                    for (int i = 0; i < 5; i++)
                    {
                        digitalWrite(redLedPin, HIGH);
                        delay(100);
                        digitalWrite(redLedPin, LOW);
                    }
                    chanceToWin = chanceToWin + 10;
                }

                buttonAlreadyPressed = true;
            break;
            case true:
                Serial.println("Button already pressed. No random needed.");
        }

    } else {
        // turn LED off:

        buttonAlreadyPressed = false;
    }
}
