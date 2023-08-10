#ifndef CARD_GAME_H
#define CARD_GAME_H

#include "../Model/card.h"
#include <iostream>
#include <QRandomGenerator>
#include "player.h"

#define     NUMBER_CARD     52


class Card_Game
{
public:
    Card_Game(Player playerInput);
    virtual ~Card_Game();
    void Run();
    void Shuffle_Cards();

    enum EndGame{
        WIN,
        DRAW,
        LOSE
    };
    virtual EndGame Check_Win() = 0;

    int moneyBet;

protected:
    std::vector<Card> cards;
    virtual void Distribute_Cards() = 0;
    void Create_Card();
    Card Pop_Up_Card();

    struct Player_In_Game
    {
        std::string name = "Bot";
        std::vector<Card> cardOwned;
    };


public:
    Player_In_Game bot;
    Player_In_Game player_ingame;

};

#endif // CARD_GAME_H
