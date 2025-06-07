#include <Arduino.h>
#include </home/rabilint/CLionProjects/untitled2/lib/LiquidCrystal_I2C-1.1.2/LiquidCrystal_I2C.h> // Library for LCD

/*
 sudo chmod 777 /dev/ttyACM0   <--- this command give access to port.

0x3F <--- this is address of my I2C.

I left lib "Arduino-I2CScannner-master in case if you want to scan address of your I2C not quiting project.

Also I want to continue developing this project.

Plans:

Add BlackJack
Add roulette

*/

const int buttonPin = 8;  // the number of the pushbutton pin
const int yellowLedPin = 2;    // the number of the LED pin
const int redLedPin = 7;    // the number of the LED pin
const int greenLedPin = 4;    // the number of the LED pin
LiquidCrystal_I2C lcd(0x3F, 20, 4); // I2C address 0x27, 20 column and 4 rows

int bank = 10000;

bool buttonAlreadyPressed = false;
// variables will change:
int buttonState = 0;  // variable for reading the pushbutton status
// int randNum;
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
        // turn LED on:
        switch (buttonAlreadyPressed)
        {



            case false:

                Serial.println("Chance to win: " + String(chanceToWin));
                chanceToLose = random(100);
                Serial.println("----------------------------");
                Serial.println("Chance to lose: " + String(chanceToLose));
                Serial.println("----------------------------");

                // Here should be animation of gambling {

                int TypeOfWin = 0;
                digitalWrite(yellowLedPin, HIGH);

                lcd.clear();
                lcd.setCursor(0, 0);
                lcd.print("Processing...");

                delay(1500);    // Here should be animation of gambling

                digitalWrite(yellowLedPin, LOW);

                //}

                // Serial.println("random = " + String(randNum));

                //shitty algorithm for victory.

                if (random(1,4) == random(1,4) == random(1,4) && chanceToLose < chanceToWin && bank > 102 )
                {
                    TypeOfWin = 1; // Client win 100$
                    if (random(1,4) == random(1,4) == random(1,4) && bank > 502)
                    {
                        TypeOfWin = 2; // Client win 500$
                        if (random(1,4) == random(1,4))
                        {
                            TypeOfWin = 3; // Jackpot
                        }
                    }
                    if (chanceToWin > 400) TypeOfWin = 1;
                    lcd.clear();

                    switch (TypeOfWin) // Displaying different version of victory on LCD .
                    {


                        case 1:
                        bank -=100;
                        lcd.setCursor(0, 0);
                        lcd.print("Bank: " + String(bank));
                        lcd.setCursor(0,1);
                        lcd.print("You have won: 100$!");
                        break;


                        case 2:
                        bank -=500;
                        lcd.setCursor(0, 0);
                        lcd.print("Bank: " + String(bank));
                        lcd.setCursor(0,1);
                        lcd.print("You have won: 500$!");
                        break;


                        case 3:
                        bank = 0;
                        lcd.setCursor(0, 0);
                        lcd.print("Bank: " + String(bank));
                        lcd.setCursor(0,1);
                        lcd.print("You have won: " + String(bank) + "$ !");
                        break;

                        case 0:
                        break;

                    }

                    for (int i = 0; i < 5; i++)  // animation for green LED in victory case.
                    {
                        digitalWrite(greenLedPin, HIGH);
                        delay(500);
                        digitalWrite(greenLedPin, LOW);
                        delay(500);
                    }


                    chanceToWin -=30;
                }else
                {
                    //Turning on and turning off Red LED {

                    digitalWrite(redLedPin, HIGH);
                    delay(500);
                    digitalWrite(redLedPin, LOW);

                    //}

                    // Calculation for bank and chance to win {

                    chanceToWin += 10;
                    bank += 50;

                    //}

                    //Display on LCD info{

                    lcd.clear();

                    lcd.setCursor(0, 0);
                    lcd.print("Bank: " + String(bank) + "$");
                    lcd.setCursor(0, 1);
                    lcd.print("Lose...");

                    //}
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
