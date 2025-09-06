#include <Arduino.h>
#include </home/rabilint/CLionProjects/untitled2/lib/LiquidCrystal_I2C-1.1.2/LiquidCrystal_I2C.h> // Library for LCD
#include "instruments.h"
#include "automat.h"
#include "config.h"
#include "blackjack.h"
#include "menu.h"
/*
 sudo chmod 777 /dev/ttyACM0   <--- this command give access to port.

0x3F <--- this is address of my I2C.

I left lib "Arduino-I2CScannner-master in case if you want to scan address of your I2C not quiting project.

Also I want to continue developing this project.

Plans:

Add BlackJack
Add roulette
Add clients profiles with saving their "progress" in a file.

create Menu.

*/
//


int bank = 10000;

LiquidCrystal_I2C lcd(LCD_ADDRESS, LCD_COLS, LCD_ROWS);
String arrOfGame[4] = {"Create User", "Automat", "Blackjack","Poker"};

bool buttonAlreadyPressed = false;
bool secButAlreadyPressed = false;
// variables will change:
int buttonState = 0;  // variable for reading the pushbutton status
int secButtonState = 0;  // variable for reading the pushbutton status
int fourButtonState = 0;  // variable for reading the pushbutton status
// int randNum;
int userSelectPos = 0;

void setup() {
    randomSeed(analogRead(0));


    Serial.begin(9600);
    // initialize the LED pin as an output:
    pinMode(yellowLedPin, OUTPUT);
    pinMode(redLedPin, OUTPUT);
    pinMode(greenLedPin, OUTPUT);
    // initialize the pushbutton pin as an input:
    pinMode(firstButtonPin, INPUT);

    // Serial.println(randNum);

    lcd.init(); //initialize the lcd
    lcd.backlight(); //open the backlight

    lcd.setCursor(0, 0);
    lcd.print("Welcome to Casino");

    delay(800);
    renderMenu(userSelectPos);

}

void loop() {


    // read the state of the pushbutton value:
    buttonState = digitalRead(firstButtonPin);
    secButtonState = digitalRead(secButtonPin);

    if (secButtonState == HIGH)
    {
        if (!secButAlreadyPressed)
        {
            delay(100);

            Serial.println("-----------------------------------------");
            Serial.println( "Amount of games in arrOfGame arr: " + String( sizeof(arrOfGame) / sizeof(arrOfGame[0])) ) ; // some Debug code
            Serial.println("----------------------------------------");


            if (userSelectPos ==  (sizeof(arrOfGame)  / sizeof(arrOfGame[0]) ) - 1 )
            {
                userSelectPos = 0;
            } else
            {
                userSelectPos++;
            }
            renderMenu(userSelectPos);

            Serial.print(userSelectPos);
            buttonAlreadyPressed = true;
        }else
        {
            Serial.println("Button already pressed.");
        }

    }
    else
    {
        secButAlreadyPressed = false;
    }

    // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
    if (buttonState == HIGH) {
        if (!buttonAlreadyPressed)
        {
            if (userSelectPos == 1)
            {
                switch (userSelectPos)
                {
                case 0:
                    proccessLEDAni(yellowLedPin);  // Here should be animation of gambling
                    bank = kindOfWin(bank);
                    // temporary there's only automat in any case.

                    break;
                case 1:


                    proccessLEDAni(yellowLedPin);  // Here should be animation of gambling
                    bank = kindOfWin(bank);
                    // temporary there's only automat in any case.
                    break;
                case 2:
                    proccessLEDAni(yellowLedPin);  // Here should be animation of gambling
                    bank = kindOfWin(bank);
                    // temporary there's only automat in any case.

                    break;
                case 3:
                    proccessLEDAni(yellowLedPin);  // Here should be animation of gambling
                    bank = kindOfWin(bank);
                    // temporary there's only automat in any case.

                    break;
                case 4:
                    proccessLEDAni(yellowLedPin);  // Here should be animation of gambling
                    bank = kindOfWin(bank);
                    // temporary there's only automat in any case.

                    break;
                }


                buttonAlreadyPressed = true;
            }else if (userSelectPos == 2)
            {
                do
                {
                    fourButtonState = digitalRead(fourButtonPin);
                    lcd.setCursor(0, 0);
                    lcd.print("Blackjack");
                    lcd.setCursor(0, 1);
                    lcd.print("Still wanna play?");
                    if (secButtonState == HIGH)
                    {
                        if (!secButAlreadyPressed)
                        {
                            blackjackGame();
                        }
                    }

                }while (fourButtonState == HIGH);
            }
        }else{
            Serial.println("Button already pressed.");
        }

    } else {
        // turn LED off:
        buttonAlreadyPressed = false;
    }
}
