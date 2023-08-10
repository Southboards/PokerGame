#include "../../Headers/Model/three_cards.h"

#define NUMBER_PLAYER   2
#define NUMBER_CARD_FOR_PLAYER   3

Three_Cards::Three_Cards(Player playerInput) : Card_Game(playerInput)
{

}

Three_Cards::~Three_Cards()
{

}

Card_Game::EndGame Three_Cards::Check_Win()
{
    int pointBot, pointPlayer;
    pointBot = Calculate_Point(bot);
    pointPlayer = Calculate_Point(player_ingame);

    if (pointPlayer > pointBot)
    {
        return WIN;
    }
    else if (pointPlayer == pointBot)
    {
        return DRAW;
    }
    else
    {
        return LOSE;
    }
}

int Three_Cards::Calculate_Point(Player_In_Game player)
{
    int point = 0;
    bool royal = true;
    for (Card itr : player.cardOwned)
    {
        if ((int)itr.getNumber()<=9)
        {
            point += (int)itr.getNumber()+1;
            royal = false;
        }
        else
        {
            point += 10;
        }
    }

    if (royal)
    {
        point = 10;
    }
    else
    {
       point %= 10;
    }
    return point;
}

void Three_Cards::Distribute_Cards()
{
    for (uint i=0; i<NUMBER_CARD_FOR_PLAYER; i++)
    {
        Card card = Pop_Up_Card();
        bot.cardOwned.emplace_back(card);
        card = Pop_Up_Card();
        player_ingame.cardOwned.emplace_back(card);
    }
}

