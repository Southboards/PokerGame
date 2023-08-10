#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string.h>

#define BRONZE_RANK_LIMIT       5000
#define SILVER_RANK_LIMIT       10000
#define GOLD_RANK_LIMIT         50000
#define PLATIUM_RANK_LIMIT      200000
#define DIAMOND_RANK_LIMIT      500000
#define MASTER_RANK_LIMIT       2000000
#define GRANDMASTER_RANK_LIMIT  5000000
#define CHALLENGER_RANK_LIMIT   10000000


class Player
{

private:
    std::string name;
    int money;


public:
    Player(std::string nameInput);

    enum Rank
    {
        BRONZE,
        SILVER,
        GOLD,
        PLATIUM,
        DIAMOND,
        MASTER,
        GRANDMASTER,
        CHALLENGER,
        NONE
    };

    void setName(std::string value);
    std::string getName();

    void setMoney(int value);
    int getMoney();

    Rank Get_Rank();
};

#endif // PLAYER_H
