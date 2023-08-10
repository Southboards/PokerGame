#include "../../Headers/Model/player.h"
#include "../../Headers/Model/databases.h"

Player::Player(std::string nameInput)
{
    name = nameInput;
    money = Databases::Get_Instance().Get_Amount(name);
}

void Player::setName(std::string value)
{
    name = value;
}
std::string Player::getName()
{
    return name;
}

void Player::setMoney(int value)
{
    money = value;
    Databases::Get_Instance().Update_Money_Player(*this);
}
int Player::getMoney()
{
    return money;
}

Player::Rank Player::Get_Rank()
{
    Player::Rank rank;
    if (money >= CHALLENGER_RANK_LIMIT)
    {
        rank = CHALLENGER;
    }
    else if (money >= GRANDMASTER_RANK_LIMIT)
    {
        rank = GRANDMASTER;
    }
    else if (money >= MASTER_RANK_LIMIT)
    {
        rank = MASTER;
    }
    else if (money >= DIAMOND_RANK_LIMIT)
    {
        rank = DIAMOND;
    }
    else if (money >= PLATIUM_RANK_LIMIT)
    {
        rank = PLATIUM;
    }
    else if (money >= GOLD_RANK_LIMIT)
    {
        rank = GOLD;
    }
    else if (money >= SILVER_RANK_LIMIT)
    {
        rank = SILVER;
    }
    else if (money >= 0)
    {
        rank = BRONZE;
    }
    else
    {
        rank = NONE;
    }
    return rank;
}
