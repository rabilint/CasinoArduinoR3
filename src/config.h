//
// Created by rabilint on 10.06.25.
//


#ifndef CONFIG_H
#define CONFIG_H

#include </home/rabilint/CLionProjects/untitled2/lib/LiquidCrystal_I2C-1.1.2/LiquidCrystal_I2C.h> // Library for LCD

const int buttonPin = 8;  // the number of the pushbutton pin
const int yellowLedPin = 12;    // the number of the LED pin
const int redLedPin = 17;    // the number of the LED pin
const int greenLedPin = 14;    // the number of the LED pin
const int secButtonPin = 4;

const uint8_t LCD_ADDRESS = 0x3F;
const uint8_t LCD_COLS = 20;
const uint8_t LCD_ROWS = 4;

extern String arrOfGame[4];

extern LiquidCrystal_I2C lcd;

#endif //CONFIG_H
