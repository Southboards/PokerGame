#include "../../Headers/Model/card_game.h"

Card_Game::Card_Game(Player playerInput) : moneyBet(0)
{
    Create_Card();
    player_ingame.name = playerInput.getName();
}

Card_Game::~Card_Game()
{

}

void Card_Game::Create_Card()
{
    cards.clear();
    for (uint i=0; i<13; i++)
    {
        Card::Type type = static_cast<Card::Type>(i);
        for (uint j=0; j<4; j++)
        {
            Card::Material material = static_cast<Card::Material>(j);
            Card card(material, type);
            cards.emplace_back(card);
        }
    }
}

void Card_Game::Run()
{
    Shuffle_Cards();
    Distribute_Cards();
}

void Card_Game::Shuffle_Cards()
{
    for (uint i=0; i<cards.size(); i++)
    {
        int randomValue = QRandomGenerator::global()->bounded(0, cards.size());
        Card temp = cards.at(i);
        cards.at(i) = cards.at(randomValue);
        cards.at(randomValue) = temp;
    }
}

Card Card_Game::Pop_Up_Card()
{
    Card card = cards.back();
    cards.pop_back();
    return card;
}
