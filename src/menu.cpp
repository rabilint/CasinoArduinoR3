//
// Created by rabilint on 11.06.25.
//

#include "menu.h"
#include "config.h"

#include <HardwareSerial.h>

void renderMenu(int cursorPos)
{

    String select = "> ";
    Serial.println(" - " + String(cursorPos));
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Menu");
    int pos = cursorPos;
    if (cursorPos > 2)
    {
        for (int i = 0; i < 3; i++)
        {
            lcd.setCursor(0, 3-i);
            if (pos == cursorPos)
            {
                select += arrOfGame[pos];
                lcd.print(select);
            }else
            {
                Serial.println(arrOfGame[pos]);
                lcd.print(arrOfGame[pos]);
            }
            pos--;
        }
    }else
    {
        for (int i = 0; i < 3; i++)
        {
            lcd.setCursor(0, i+1);
            if (i == cursorPos)
            {
                select += arrOfGame[i];
                lcd.print(select);
            }
            else
            {
                lcd.print(arrOfGame[i]);
            }
        }
    }
}