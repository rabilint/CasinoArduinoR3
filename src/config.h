//
// Created by rabilint on 10.06.25.
//


#ifndef CONFIG_H
#define CONFIG_H

#include </home/rabilint/CLionProjects/untitled2/lib/LiquidCrystal_I2C-1.1.2/LiquidCrystal_I2C.h> // Library for LCD

constexpr int firstButtonPin = 8;  // the number of the pushbutton pin
constexpr int secButtonPin = 4; // pin for sec button
constexpr int thirdButtonPin = 7; // pin for sec button
constexpr int fourButtonPin = 2; // pin for sec button

constexpr int yellowLedPin = 6;
constexpr int redLedPin = 5;
constexpr int greenLedPin = 3;

constexpr uint8_t LCD_ADDRESS = 0x3F;
constexpr uint8_t LCD_COLS = 20;
constexpr uint8_t LCD_ROWS = 4;

extern String arrOfGame[4];

extern LiquidCrystal_I2C lcd;

#endif //CONFIG_H
