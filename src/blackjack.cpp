//
// Created by rabilint on 02.09.25.
//

#include "Arduino.h"
#include "config.h"
#include </home/rabilint/CLionProjects/untitled2/lib/LiquidCrystal_I2C-1.1.2/LiquidCrystal_I2C.h> // Library for LCD

constexpr int cardValues[13] = {11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10};
constexpr char* cardNames[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
constexpr int MAX_CARDS = 5;

bool buttonAlreadyPressed = false;
bool thirdAlreadyPressed = false;

int firstButtonState = 0;
int secButtonState = 0;
int thirdButtonState = 0;
class Player
{
    public:
    int cards[MAX_CARDS];
    int cardsCount = 0 ;
};

Player dealer;
Player user;

void printPlayersCards(const Player& player, const Player& dealer, bool ShowOrNot)
{
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Dealer cards:");
    if (ShowOrNot)
    {
        for (int i = 0; i < dealer.cardsCount; ++i)
        {
            lcd.setCursor(i+14,0);
            lcd.print(cardNames[dealer.cards[i]]);
        }
    }else
    {
        lcd.setCursor(14,0);
        lcd.print(cardNames[dealer.cards[0]]);
    }
    lcd.setCursor(0, 1);
    lcd.print("Your cards:");
    for (int i = 0; i < player.cardsCount; ++i)
    {
        lcd.setCursor(i+12,1);
        lcd.print(cardNames[player.cards[i]]);
    }
}

int calculateSum(const Player& p){
    int sum = 0;
    for (int i = 0; i < p.cardsCount; ++i)
    {
        sum += cardValues[p.cards[i]];
    }
    return sum;
}
void blackjackGame()
{

    firstButtonState = digitalRead(firstButtonPin);
    secButtonState = digitalRead(secButtonPin);
    thirdButtonState = digitalRead(thirdButtonPin);



                dealer.cardsCount = 0;
                user.cardsCount = 0 ;

                dealer.cards[dealer.cardsCount++] = random(0,12);
                user.cards[user.cardsCount++] = random(0,12);

                dealer.cards[dealer.cardsCount++] = random(0,12);
                user.cards[user.cardsCount++] = random(0,12);

                while (calculateSum(dealer) < 17) {
                    dealer.cards[dealer.cardsCount++] = random(0,12);
                }
                lcd.clear();

                do
                {

                    printPlayersCards(user, dealer, false);
                    int sumOfUserCards = calculateSum(user);
                    lcd.setCursor(0, 3);
                    lcd.print("pick another card?");

                    delay(500);
                    thirdAlreadyPressed = false;

                    if (thirdButtonState == HIGH)
                    {
                        if (!thirdAlreadyPressed){
                            thirdAlreadyPressed = true;
                            if (sumOfUserCards < 22)
                            {
                                if (user.cardsCount < MAX_CARDS)
                                {
                                    user.cards[user.cardsCount++] = random(0,12);
                                }
                                else
                                {
                                    lcd.clear();
                                    lcd.setCursor(0, 3);
                                    lcd.print("Too many cards!");
                                }
                            }
                            else
                            {
                                lcd.clear();
                                lcd.setCursor(0, 3);
                                lcd.print("Too many points!");
                                break;
                            }
                        }
                        else
                        {

                            break;
                        }
                    }

                }while (true);


                int userSum = calculateSum(user);
                int dealerSum = calculateSum(dealer);

                printPlayersCards(user, dealer, true);

                delay(800);

                lcd.clear();
                lcd.setCursor(0, 1);

                if (userSum > 21) {
                    lcd.print("You bust! You lose!");
                } else if (dealerSum > 21) {
                    lcd.print("Dealer busts! You win!");
                } else if (userSum > dealerSum) {
                    lcd.print("You win!");
                } else if (userSum < dealerSum) {
                    lcd.print("You lose!");
                } else {
                    lcd.print("It's a tie!");
                }


}



#include "blackjack.h"