#ifndef Poker_H
#define Poker_H

#include "card_game.h"
#include "player.h"

class Poker : public Card_Game
{
public:
    Poker(Player playerInput);
    ~Poker();
    virtual EndGame Check_Win() override;
    Player_In_Game tableOwner;

protected:
    virtual void Distribute_Cards() override;

    enum Type_Poker_Cards
    {
        HIGH_CARD,
        ONE_PAIR,
        TWO_PAIR,
        THREE_OF_A_KIND,
        STRAIGHT,
        FLUSH,
        FULL_HOUSE,
        FOUR_OF_A_KIND,
        STRAIGHT_FLUSH,
        ROYAL_FLUSH
    };

    void Remove_Vector(std::vector<Card>& cardsBase, std::vector<Card> remove);

    bool Get_Best_Card(std::vector<Card> cardsInput, std::vector<Card>& cardsOutput);
    bool Get_Best_One_Pair(std::vector<Card> cardsInput, std::vector<Card>& cardsOutput);
    bool Get_Best_Two_Pair(std::vector<Card> cardsInput, std::vector<Card>& cardsOutput);
    bool Get_Best_Three_Of_A_Kind(std::vector<Card> cardsInput, std::vector<Card>& cardsOutput);
    bool Get_Best_Straight(std::vector<Card> cardsInput, std::vector<Card>& cardsOutput);
    bool Get_Best_Flush(std::vector<Card> cardsInput, std::vector<Card>& cardsOutput);
    bool Get_Best_Full_House(std::vector<Card> cardsInput, std::vector<Card>& cardsOutput);
    bool Get_Four_Of_A_Kind(std::vector<Card> cardsInput, std::vector<Card>& cardsOutput);
    bool Get_Straight_Flush(std::vector<Card> cardsInput, std::vector<Card>& cardsOutput);
    bool Get_Royal_Flush(std::vector<Card> cardsInput, std::vector<Card>& cardsOutput);

    EndGame Compare_Straight(std::vector<Card> firstPlayer, std::vector<Card> secondPlayer);
    EndGame Compare_Four(std::vector<Card> firstPlayer, std::vector<Card> secondPlayer);
    EndGame Compare_Full_House(std::vector<Card> firstPlayer, std::vector<Card> secondPlayer);
    EndGame Compare_All_Card(std::vector<Card> firstPlayer, std::vector<Card> secondPlayer);
    EndGame Compare_Three_Cards(std::vector<Card> firstPlayer, std::vector<Card> secondPlayer);
    EndGame Compare_Two_Pair(std::vector<Card> firstPlayer, std::vector<Card> secondPlayer);
    EndGame Compare_One_Pair(std::vector<Card> firstPlayer, std::vector<Card> secondPlayer);

    Type_Poker_Cards Get_Best_Cards(std::vector<Card> cardsInput, std::vector<Card>& cardsOutput);

};

#endif // Poker_H
