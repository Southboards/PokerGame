#ifndef Three_Cards_H
#define Three_Cards_H

#include "card_game.h"
#include "player.h"

class Three_Cards : public Card_Game
{
public:
    Three_Cards(Player playerInput);
    ~Three_Cards();
    virtual EndGame Check_Win() override;

protected:
    virtual void Distribute_Cards() override;
    virtual int Calculate_Point(Player_In_Game player);


};

#endif // Three_Cards_H
