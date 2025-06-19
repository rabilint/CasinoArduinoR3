//
// Created by rabilint on 08.06.25.
//

#include "automat.h"
#include "instruments.h"
#include "Arduino.h"
#include "config.h"
#include </home/rabilint/CLionProjects/untitled2/lib/LiquidCrystal_I2C-1.1.2/LiquidCrystal_I2C.h> // Library for LCD


int printLose(int bank)
{
    printInfo(bank);
    lcd.print("Lose...");
    loseLEDAni(redLedPin);
    return 0;
}
int printWin(int bank, int TypeOfWin)
{
    switch (TypeOfWin) // Displaying different version of victory on LCD .
    {
    case 1:
        bank -=100;
        printInfo(bank);
        lcd.print("You have won: 100$!");
        break;
    case 2:
        bank -=500;
        printInfo(bank);
        lcd.print("You have won: 500$!");
        break;
    case 3:
        printInfo(0);
        lcd.print("You have won: " + String(bank) + "$ !");
        bank = 0;
        break;
    case 0:
        break;
    }

    return bank;
}


int kindOfWin(int bank)
{
    int TypeOfWin = 0;
        if (random(1,25) == random(1,40) && bank > 102 ) TypeOfWin = 1; // Client win 100$

        if (( random(1,50) == random(1,75) ) == random(1,25) && bank > 502) TypeOfWin = 2; // Client win 500$

        if ( ( random(1,100) == random(1,100) ) == random(1,100)) TypeOfWin = 3; // Jackpot

        bank = printWin(bank, TypeOfWin);
    if (TypeOfWin == 0)
    {

        bank += 50;
        printLose(bank);

    }else winLEDAni(greenLedPin);
    return bank;
}


