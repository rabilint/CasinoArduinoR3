//
// Created by rabilint on 10.06.25.
//
#include <Arduino.h>
#include "instruments.h"
#include "config.h"
#include </home/rabilint/CLionProjects/untitled2/lib/LiquidCrystal_I2C-1.1.2/LiquidCrystal_I2C.h> // Library for LCD



void printInfo(int bank)
{
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Bank: " + String(bank) + "$");
    lcd.setCursor(0, 1);
};

void loseLEDAni(int redLedPin)
{
    digitalWrite(redLedPin, HIGH);
    delay(500);
    digitalWrite(redLedPin, LOW);
}

void winLEDAni(int greenLedPin)
{
    for (int i = 0; i < 5; i++)  // animation for green LED in victory case.
    {
        digitalWrite(greenLedPin, HIGH);
        delay(500);
        digitalWrite(greenLedPin, LOW);
        delay(500);
    }
}

void proccessLEDAni(int yellowLedPin)
{
    digitalWrite(yellowLedPin, HIGH);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Processing...");

    delay(1500);    // Here should be animation of gambling

    digitalWrite(yellowLedPin, LOW);
}
