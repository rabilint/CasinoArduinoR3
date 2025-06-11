#include <Arduino.h>
#include </home/rabilint/CLionProjects/untitled2/lib/LiquidCrystal_I2C-1.1.2/LiquidCrystal_I2C.h> // Library for LCD
#include "instruments.h"
#include "automat.h"
#include "config.h"
/*
 sudo chmod 777 /dev/ttyACM0   <--- this command give access to port.

0x3F <--- this is address of my I2C.

I left lib "Arduino-I2CScannner-master in case if you want to scan address of your I2C not quiting project.

Also I want to continue developing this project.

Plans:

Add BlackJack
Add roulette
Add clients profiles with saving their "progress" in a file.

*/



int bank = 10000;

LiquidCrystal_I2C lcd(LCD_ADDRESS, LCD_COLS, LCD_ROWS);

bool buttonAlreadyPressed = false;
// variables will change:
int buttonState = 0;  // variable for reading the pushbutton status
// int randNum;

void setup() {
    randomSeed(analogRead(0));
    Serial.begin(9600);
    // initialize the LED pin as an output:
    pinMode(yellowLedPin, OUTPUT);
    pinMode(redLedPin, OUTPUT);
    pinMode(greenLedPin, OUTPUT);
    // initialize the pushbutton pin as an input:
    pinMode(buttonPin, INPUT);

    // Serial.println(randNum);

    lcd.init(); //initialize the lcd
    lcd.backlight(); //open the backlight

    lcd.setCursor(0, 0);
    lcd.print("Welcome to Casino");

}

void loop() {
    // read the state of the pushbutton value:
    buttonState = digitalRead(buttonPin);

    // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
    if (buttonState == HIGH) {


        Serial.println("----------------------------");

        switch (buttonAlreadyPressed)
        {
            case false:
                Serial.println("----------------------------");
                Serial.println("bank: " + String(bank));
                Serial.println("----------------------------");



                proccessLEDAni(yellowLedPin);  // Here should be animation of gambling

                bank = kindOfWin(bank);

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
