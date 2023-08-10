#include "../../Headers/Model/poker.h"

#define NUMBER_PLAYER   2
#define NUMBER_CARD_FOR_PLAYER   2
#define NUMBER_CARD_FOR_TABLE   5

Poker::Poker(Player playerInput) : Card_Game(playerInput)
{

}

Poker::~Poker()
{

}

Card_Game::EndGame Poker::Check_Win()
{
    Card_Game::EndGame result = Card_Game::LOSE;
    std::vector<Card> cardsFirstPlayer;
    std::vector<Card> cardsSecondPlayer;
    std::vector<Card> bestCardsFirstPlayer;
    std::vector<Card> bestCardsSecondPlayer;
    Type_Poker_Cards typeBestCardsFirstPlayer;
    Type_Poker_Cards typeBestCardsSecondPlayer;

    cardsFirstPlayer = tableOwner.cardOwned;
    cardsSecondPlayer = tableOwner.cardOwned;
    for (int i=0; i<2; i++)
    {
        cardsFirstPlayer.emplace_back(bot.cardOwned.at(i));
        cardsSecondPlayer.emplace_back(player_ingame.cardOwned.at(i));
    }

    typeBestCardsFirstPlayer = Get_Best_Cards(cardsFirstPlayer, bestCardsFirstPlayer);
    typeBestCardsSecondPlayer = Get_Best_Cards(cardsSecondPlayer, bestCardsSecondPlayer);

    if (typeBestCardsFirstPlayer < typeBestCardsSecondPlayer)
    {
        result = Card_Game::WIN;
    }
    else if (typeBestCardsFirstPlayer > typeBestCardsSecondPlayer)
    {
        result = Card_Game::LOSE;
    }
    else
    {
        switch (typeBestCardsFirstPlayer)
        {
        case STRAIGHT_FLUSH:
            result = Compare_Straight(bestCardsFirstPlayer, bestCardsSecondPlayer);
            break;
        case FOUR_OF_A_KIND:
            result = Compare_Four(bestCardsFirstPlayer, bestCardsSecondPlayer);
            break;
        case FULL_HOUSE:
            result = Compare_Full_House(bestCardsFirstPlayer, bestCardsSecondPlayer);
            break;
        case FLUSH:
            result = Compare_All_Card(bestCardsFirstPlayer, bestCardsSecondPlayer);
            break;
        case STRAIGHT:
            result = Compare_Straight(bestCardsFirstPlayer, bestCardsSecondPlayer);
            break;
        case THREE_OF_A_KIND:
            result = Compare_Three_Cards(bestCardsFirstPlayer, bestCardsSecondPlayer);
            break;
        case TWO_PAIR:
            result = Compare_Two_Pair(bestCardsFirstPlayer, bestCardsSecondPlayer);
            break;
        case ONE_PAIR:
            result = Compare_One_Pair(bestCardsFirstPlayer, bestCardsSecondPlayer);
            break;
        case HIGH_CARD:
            result = Compare_All_Card(bestCardsFirstPlayer, bestCardsSecondPlayer);
            break;
        default:
            break;
        }
    }
    return result;
}

Card_Game::EndGame Poker::Compare_Straight(std::vector<Card> firstPlayer, std::vector<Card> secondPlayer)
{
    Card_Game::EndGame result = Card_Game::LOSE;
    if (firstPlayer.at(0).getNumber() < secondPlayer.at(0).getNumber())
    {
        result = Card_Game::WIN;
    }
    else if (firstPlayer.at(0).getNumber() > secondPlayer.at(0).getNumber())
    {
        result = Card_Game::LOSE;
    }
    else
    {
        result = Card_Game::DRAW;
    }
    return result;
}

Card_Game::EndGame Poker::Compare_Four(std::vector<Card> firstPlayer, std::vector<Card> secondPlayer)
{
    Card_Game::EndGame result = Card_Game::LOSE;
    if (firstPlayer.at(0).getNumber(true) < secondPlayer.at(0).getNumber(true))
    {
        result = Card_Game::WIN;
    }
    else if (firstPlayer.at(0).getNumber(true) > secondPlayer.at(0).getNumber(true))
    {
        result = Card_Game::LOSE;
    }
    else
    {
        if (firstPlayer.at(4).getNumber(true) < secondPlayer.at(4).getNumber(true))
        {
            result = Card_Game::WIN;
        }
        else if (firstPlayer.at(4).getNumber(true) > secondPlayer.at(4).getNumber(true))
        {
            result = Card_Game::LOSE;
        }
        else
        {
            result = Card_Game::DRAW;
        }
    }
    return result;
}

Card_Game::EndGame Poker::Compare_All_Card(std::vector<Card> firstPlayer, std::vector<Card> secondPlayer)
{
    Card_Game::EndGame result = Card_Game::DRAW;
    for (uint i=0; i<5; i++)
    {
        if (firstPlayer.at(i).getNumber(true) < secondPlayer.at(i).getNumber(true))
        {
            result = Card_Game::WIN;
            break;
        }
        else if (firstPlayer.at(i).getNumber(true) > secondPlayer.at(i).getNumber(true))
        {
            result = Card_Game::LOSE;
            break;
        }
    }
    return result;
}

Card_Game::EndGame Poker::Compare_Full_House(std::vector<Card> firstPlayer, std::vector<Card> secondPlayer)
{
    Card_Game::EndGame result = Card_Game::LOSE;
    if (firstPlayer.at(0).getNumber(true) < secondPlayer.at(0).getNumber(true))
    {
        result = Card_Game::WIN;
    }
    else if (firstPlayer.at(0).getNumber(true) > secondPlayer.at(0).getNumber(true))
    {
        result = Card_Game::LOSE;
    }
    else
    {
        if (firstPlayer.at(3).getNumber(true) < secondPlayer.at(3).getNumber(true))
        {
            result = Card_Game::WIN;
        }
        else if (firstPlayer.at(3).getNumber(true) > secondPlayer.at(3).getNumber(true))
        {
            result = Card_Game::LOSE;
        }
        else
        {
            result = Card_Game::DRAW;
        }
    }
    return result;
}

Card_Game::EndGame Poker::Compare_Three_Cards(std::vector<Card> firstPlayer, std::vector<Card> secondPlayer)
{
    Card_Game::EndGame result = Card_Game::DRAW;
    if (firstPlayer.at(0).getNumber(true) < secondPlayer.at(0).getNumber(true))
    {
        result = Card_Game::WIN;
    }
    else if (firstPlayer.at(0).getNumber(true) > secondPlayer.at(0).getNumber(true))
    {
        result = Card_Game::LOSE;
    }
    else
    {
        if (firstPlayer.at(3).getNumber(true) < secondPlayer.at(3).getNumber(true))
        {
            result = Card_Game::WIN;
        }
        else if (firstPlayer.at(3).getNumber(true) > secondPlayer.at(3).getNumber(true))
        {
            result = Card_Game::LOSE;
        }
        else
        {
            if (firstPlayer.at(4).getNumber(true) < secondPlayer.at(4).getNumber(true))
            {
                result = Card_Game::WIN;
            }
            else if (firstPlayer.at(4).getNumber() > secondPlayer.at(4).getNumber())
            {
                result = Card_Game::LOSE;
            }
            else
            {
                result = Card_Game::DRAW;
            }
        }
    }
    return result;
}

Card_Game::EndGame Poker::Compare_Two_Pair(std::vector<Card> firstPlayer, std::vector<Card> secondPlayer)
{
    Card_Game::EndGame result = Card_Game::DRAW;
    if (firstPlayer.at(0).getNumber(true) < secondPlayer.at(0).getNumber(true))
    {
        result = Card_Game::WIN;
    }
    else if (firstPlayer.at(0).getNumber(true) > secondPlayer.at(0).getNumber(true))
    {
        result = Card_Game::LOSE;
    }
    else
    {
        if (firstPlayer.at(2).getNumber(true) < secondPlayer.at(2).getNumber(true))
        {
            result = Card_Game::WIN;
        }
        else if (firstPlayer.at(2).getNumber(true) > secondPlayer.at(2).getNumber(true))
        {
            result = Card_Game::LOSE;
        }
        else
        {
            if (firstPlayer.at(4).getNumber(true) < secondPlayer.at(4).getNumber(true))
            {
                result = Card_Game::WIN;
            }
            else if (firstPlayer.at(4).getNumber(true) > secondPlayer.at(4).getNumber(true))
            {
                result = Card_Game::LOSE;
            }
            else
            {
                result = Card_Game::DRAW;
            }
        }
    }
    return result;
}

Card_Game::EndGame Poker::Compare_One_Pair(std::vector<Card> firstPlayer, std::vector<Card> secondPlayer)
{
    Card_Game::EndGame result = Card_Game::DRAW;
    if (firstPlayer.at(0).getNumber(true) < secondPlayer.at(0).getNumber(true))
    {
        result = Card_Game::WIN;
    }
    else if (firstPlayer.at(0).getNumber(true) > secondPlayer.at(0).getNumber(true))
    {
        result = Card_Game::LOSE;
    }
    else
    {
        if (firstPlayer.at(2).getNumber(true) < secondPlayer.at(2).getNumber(true))
        {
            result = Card_Game::WIN;
        }
        else if (firstPlayer.at(2).getNumber(true) > secondPlayer.at(2).getNumber(true))
        {
            result = Card_Game::LOSE;
        }
        else
        {
            if (firstPlayer.at(3).getNumber(true) < secondPlayer.at(3).getNumber(true))
            {
                result = Card_Game::WIN;
            }
            else if (firstPlayer.at(3).getNumber(true) > secondPlayer.at(3).getNumber(true))
            {
                result = Card_Game::LOSE;
            }
            else
            {
                if (firstPlayer.at(4).getNumber(true) < secondPlayer.at(4).getNumber(true))
                {
                    result = Card_Game::WIN;
                }
                else if (firstPlayer.at(4).getNumber(true) > secondPlayer.at(4).getNumber(true))
                {
                    result = Card_Game::LOSE;
                }
                else
                {
                    result = Card_Game::DRAW;
                }
            }
        }
    }
    return result;
}

void Poker::Distribute_Cards()
{
    for (uint i=0; i<NUMBER_CARD_FOR_PLAYER; i++)
    {
        Card card = Pop_Up_Card();
        bot.cardOwned.emplace_back(card);
        card = Pop_Up_Card();
        player_ingame.cardOwned.emplace_back(card);
    }

    for (uint i=0; i<NUMBER_CARD_FOR_TABLE; i++)
    {
        Card card = Pop_Up_Card();
        tableOwner.cardOwned.emplace_back(card);
    }
}

bool Poker::Get_Best_Card(std::vector<Card> cardsInput, std::vector<Card>& cardsOutput)
{
    std::sort(cardsInput.begin(), cardsInput.end(),
                    [](Card& a, Card& b)
                    {
                       return a.getNumber(true) > b.getNumber(true);
                    });

    cardsOutput.emplace_back(cardsInput.at(0));
    return true;
}

void Poker::Remove_Vector(std::vector<Card>& cardsBase, std::vector<Card> remove)
{
    for(auto itr_1 = cardsBase.begin(); itr_1 != cardsBase.end(); itr_1++)
    {
        for(auto itr_2 = remove.begin(); itr_2 != remove.end(); itr_2++)
        {
            if ((itr_2->getNumber() == itr_1->getNumber()) && (itr_2->getMaterial() == itr_1->getMaterial()))
            {
                cardsBase.erase(itr_1);
                itr_1--;
                break;
            }
        }
    }
}

bool Poker::Get_Best_One_Pair(std::vector<Card> cardsInput, std::vector<Card>& cardsOutput)
{
    bool result = false;
    std::vector<Card> cardsResult;
    cardsOutput.clear();
    for(auto itr_1 = cardsInput.begin(); itr_1 != cardsInput.end(); itr_1++)
    {
        for(auto itr_2 = itr_1+1; itr_2 != cardsInput.end(); itr_2++)
        {
            if (itr_2->getNumber() == itr_1->getNumber())
            {
                result = true;
                cardsResult.emplace_back(*itr_1);
                cardsResult.emplace_back(*itr_2);
                break;
            }
        }
    }

    if (cardsResult.size()==6)
    {
        if ((cardsResult.at(0).getNumber(true) > cardsResult.at(2).getNumber(true)) &&
            (cardsResult.at(0).getNumber(true) > cardsResult.at(4).getNumber(true)))
        {
            cardsOutput.emplace_back(cardsResult.at(0));
            cardsOutput.emplace_back(cardsResult.at(1));
        }
        else if (cardsResult.at(2).getNumber(true) > cardsResult.at(4).getNumber(true))
        {
            cardsOutput.emplace_back(cardsResult.at(2));
            cardsOutput.emplace_back(cardsResult.at(3));
        }
        else
        {
            cardsOutput.emplace_back(cardsResult.at(4));
            cardsOutput.emplace_back(cardsResult.at(5));
        }
    }
    else if (cardsResult.size()==4)
    {
        if (cardsResult.at(0).getNumber(true) >= cardsResult.at(2).getNumber(true))
        {
            cardsOutput.emplace_back(cardsResult.at(0));
            cardsOutput.emplace_back(cardsResult.at(1));
        }
        else
        {
            cardsOutput.emplace_back(cardsResult.at(2));
            cardsOutput.emplace_back(cardsResult.at(3));
        }
    }
    else if (cardsResult.size()==2)
    {
        cardsOutput = cardsResult;
    }
    else
    {

    }
    return result;
}

bool Poker::Get_Best_Two_Pair(std::vector<Card> cardsInput, std::vector<Card>& cardsOutput)
{
    bool result = false;
    std::vector<Card> cardsResult;
    std::vector<Card> pairFirst;
    std::vector<Card> pairSecond;
    cardsOutput.clear();
    if (Get_Best_One_Pair(cardsInput, pairFirst))
    {
        Remove_Vector(cardsInput, pairFirst);
        if (Get_Best_One_Pair(cardsInput, pairSecond))
        {
            cardsOutput = pairFirst;
            cardsOutput.emplace_back(pairSecond.at(0));
            cardsOutput.emplace_back(pairSecond.at(1));
            result = true;
        }
    }
    return result;
}

bool Poker::Get_Best_Three_Of_A_Kind(std::vector<Card> cardsInput, std::vector<Card>& cardsOutput)
{
    bool result = false;
    bool result_step_1 = false;
    std::vector<Card>::iterator cardSecond;
    std::vector<Card> resultCards;
    for(auto itr_1 = cardsInput.begin(); itr_1 != cardsInput.end(); itr_1++)
    {
        for(auto itr_2 = itr_1+1; itr_2 != cardsInput.end(); itr_2++)
        {
            if (itr_1->getNumber() == itr_2->getNumber())
            {
                if (result_step_1 == false)
                {
                    cardSecond = itr_2;
                    result_step_1 = true;
                }
                else
                {
                    resultCards.emplace_back(*itr_1);
                    resultCards.emplace_back(*cardSecond);
                    resultCards.emplace_back(*itr_2);
                    break;
                }
            }
        }
        result_step_1 = false;
    }

    if (resultCards.size()==6)
    {
        result = true;
        if (resultCards.at(0).getNumber(true) > resultCards.at(3).getNumber(true))
        {
            cardsOutput.emplace_back(resultCards.at(0));
            cardsOutput.emplace_back(resultCards.at(1));
            cardsOutput.emplace_back(resultCards.at(2));
        }
        else
        {
            cardsOutput.emplace_back(resultCards.at(3));
            cardsOutput.emplace_back(resultCards.at(4));
            cardsOutput.emplace_back(resultCards.at(5));
        }
    }
    else if (resultCards.size()==3)
    {
        result = true;
        cardsOutput = resultCards;
    }
    else
    {

    }
    return result;
}

bool Poker::Get_Best_Straight(std::vector<Card> cardsInput, std::vector<Card>& cardsOutput)
{
    bool result = false;
    std::vector<Card> cardsInput_2 = cardsInput;
    for(auto itr_1 = cardsInput_2.begin(); itr_1 != cardsInput_2.end(); itr_1++)
    {
        for(auto itr_2 = cardsInput.begin()+1; itr_2 != cardsInput.end(); itr_2++)
        {
            if ((itr_2->getNumber() == itr_1->getNumber()) && (itr_2->getMaterial() != itr_1->getMaterial()))
            {
                cardsInput.erase(itr_2);
                itr_2--;
            }
        }
    }
    std::sort(cardsInput.begin(), cardsInput.end(),
                    [](Card& a, Card& b)
                    {
                       return a.getNumber() < b.getNumber();
                    });

    if (cardsInput.size()<5)
    {
        result = false;
    }
    else if (cardsInput.size()==5)
    {
        if (cardsInput.at(4).getNumber() == (cardsInput.at(0).getNumber() + 4))
        {
            result = true;
            cardsOutput = cardsInput;
        }
    }
    else if (cardsInput.size()==6)
    {
        if ((cardsInput.at(0).getNumber() == Card::ACE) && (cardsInput.at(2).getNumber() == Card::TEN))
        {
            cardsOutput.emplace_back(cardsInput.at(5));
            cardsOutput.emplace_back(cardsInput.at(4));
            cardsOutput.emplace_back(cardsInput.at(3));
            cardsOutput.emplace_back(cardsInput.at(2));
            cardsOutput.emplace_back(cardsInput.at(1));
            result = true;
        }
        else
        {
            if (cardsInput.at(5).getNumber() == (cardsInput.at(1).getNumber() + 4))
            {
                cardsOutput.emplace_back(cardsInput.at(5));
                cardsOutput.emplace_back(cardsInput.at(4));
                cardsOutput.emplace_back(cardsInput.at(3));
                cardsOutput.emplace_back(cardsInput.at(2));
                cardsOutput.emplace_back(cardsInput.at(1));
                result = true;
            }

            else if (cardsInput.at(4).getNumber() == (cardsInput.at(0).getNumber() + 4) )
            {
                cardsOutput.emplace_back(cardsInput.at(4));
                cardsOutput.emplace_back(cardsInput.at(3));
                cardsOutput.emplace_back(cardsInput.at(2));
                cardsOutput.emplace_back(cardsInput.at(1));
                cardsOutput.emplace_back(cardsInput.at(0));
                result = true;
            }
        }

    }
    else if (cardsInput.size()==7)
    {
        if (cardsInput.at(6).getNumber() == (cardsInput.at(2).getNumber() + 4))
        {
            cardsOutput.emplace_back(cardsInput.at(6));
            cardsOutput.emplace_back(cardsInput.at(5));
            cardsOutput.emplace_back(cardsInput.at(4));
            cardsOutput.emplace_back(cardsInput.at(3));
            cardsOutput.emplace_back(cardsInput.at(2));
            result = true;
        }
        else if (cardsInput.at(5).getNumber() == (cardsInput.at(1).getNumber() + 4) )
        {
            result = true;
            cardsOutput.emplace_back(cardsInput.at(5));
            cardsOutput.emplace_back(cardsInput.at(4));
            cardsOutput.emplace_back(cardsInput.at(3));
            cardsOutput.emplace_back(cardsInput.at(2));
            cardsOutput.emplace_back(cardsInput.at(1));
        }
        else if (cardsInput.at(4).getNumber() == (cardsInput.at(0).getNumber() + 4) )
        {
            cardsOutput.emplace_back(cardsInput.at(4));
            cardsOutput.emplace_back(cardsInput.at(3));
            cardsOutput.emplace_back(cardsInput.at(2));
            cardsOutput.emplace_back(cardsInput.at(1));
            cardsOutput.emplace_back(cardsInput.at(0));
            result = true;
        }
    }

    return result;
}

bool Poker::Get_Best_Flush(std::vector<Card> cardsInput, std::vector<Card>& cardsOutput)
{
    bool result = false;
    std::vector<Card> resultCardsSpade;
    std::vector<Card> resultCardsClube;
    std::vector<Card> resultCardsDiamond;
    std::vector<Card> resultCardsHeart;
    for (auto itr : cardsInput)
    {
        switch (itr.getMaterial()) {
        case Card::SPADE :
            resultCardsSpade.emplace_back(itr);
            break;
        case Card::CLUBE :
            resultCardsClube.emplace_back(itr);
            break;
        case Card::DIAMOND :
            resultCardsDiamond.emplace_back(itr);
            break;
        case Card::HEART :
            resultCardsHeart.emplace_back(itr);
            break;
        default:
            break;
        }
    }
    if (resultCardsSpade.size()>=5)
    {
        std::sort(resultCardsSpade.begin(), resultCardsSpade.end(),
                        [](Card& a, Card& b)
                        {
                           return a.getNumber(true) > b.getNumber(true);
                        });
        for (int i=0;i<5;i++)
        {
            cardsOutput.emplace_back(resultCardsSpade.at(i));
        }
        result = true;
    }
    else if (resultCardsClube.size()>=5)
    {
        std::sort(resultCardsClube.begin(), resultCardsClube.end(),
                        [](Card& a, Card& b)
                        {
                           return a.getNumber(true) > b.getNumber(true);
                        });
        for (int i=0;i<5;i++)
        {
            cardsOutput.emplace_back(resultCardsClube.at(i));
        }
        result = true;
    }
    else if (resultCardsDiamond.size()>=5)
    {
        std::sort(resultCardsDiamond.begin(), resultCardsDiamond.end(),
                        [](Card& a, Card& b)
                        {
                           return a.getNumber(true) > b.getNumber(true);
                        });
        for (int i=0;i<5;i++)
        {
            cardsOutput.emplace_back(resultCardsDiamond.at(i));
        }
        result = true;
    }
    else if (resultCardsHeart.size()>=5)
    {
        std::sort(resultCardsHeart.begin(), resultCardsHeart.end(),
                        [](Card& a, Card& b)
                        {
                           return a.getNumber(true) > b.getNumber(true);
                        });
        for (int i=0;i<5;i++)
        {
            cardsOutput.emplace_back(resultCardsHeart.at(i));
        }
        result = true;
    }

    return result;
}

bool Poker::Get_Best_Full_House(std::vector<Card> cardsInput, std::vector<Card>& cardsOutput)
{
    bool result = false;
    std::vector<Card> threeCards;
    std::vector<Card> pairCards;
    if (Get_Best_Three_Of_A_Kind(cardsInput, threeCards))
    {
        Remove_Vector(cardsInput, threeCards);
        if (Get_Best_Two_Pair(cardsInput, threeCards))
        {
            cardsOutput = threeCards;
            cardsOutput.emplace_back(pairCards.at(1));
            cardsOutput.emplace_back(pairCards.at(0));
            result = true;
        }
    }
    return result;
}

bool Poker::Get_Four_Of_A_Kind(std::vector<Card> cardsInput, std::vector<Card>& cardsOutput)
{
    bool result_step_1 = false;
    bool result_step_2 = false;
    bool result_step_3 = false;
    for(auto itr_1 = cardsInput.begin(); itr_1 != cardsInput.end(); itr_1++)
    {
        for(auto itr_2 = itr_1+1; itr_2 != cardsInput.end(); itr_2++)
        {
            if (itr_1->getNumber() == itr_2->getNumber())
            {
                if (result_step_1 == false)
                {
                    cardsOutput.emplace_back(*itr_1);
                    cardsOutput.emplace_back(*itr_2);
                    result_step_1 = true;
                }
                else if (result_step_2 == false)
                {
                    cardsOutput.emplace_back(*itr_2);
                    result_step_2 = true;
                }
                else
                {
                    cardsOutput.emplace_back(*itr_2);
                    result_step_3 = true;
                    break;
                }
            }
        }
        if (result_step_3)
        {
            break;
        }
        else
        {
            cardsOutput.clear();
            result_step_1 = false;
            result_step_2 = false;
        }
    }
    return result_step_3;
}

bool Poker::Get_Straight_Flush(std::vector<Card> cardsInput, std::vector<Card>& cardsOutput)
{
    bool result = false;
    std::vector<Card> flush;
    std::vector<Card> flush_straight;
    if (Get_Best_Flush(cardsInput, flush))
    {
        if (Get_Best_Straight(flush, flush_straight))
        {
            result = true;
            cardsOutput = flush_straight;
        }
    }
    return result;
}

bool Poker::Get_Royal_Flush(std::vector<Card> cardsInput, std::vector<Card>& cardsOutput)
{
    bool result = false;
    std::vector<Card> royal;
    if (Get_Straight_Flush(cardsInput, royal))
    {
        if (royal.at(0).getNumber() == Card::ACE && royal.at(0).getMaterial() == Card::SPADE)
        {
            cardsOutput = royal;
            result = true;
        }
    }
    return result;
}

Poker::Type_Poker_Cards Poker::Get_Best_Cards(std::vector<Card> cardsInput, std::vector<Card>& cardsOutput)
{
    std::vector<Card> resultCards;
    Poker::Type_Poker_Cards resultType;
    if (Get_Royal_Flush(cardsInput, resultCards))
    {
        resultType = ROYAL_FLUSH;
    }
    else if (Get_Straight_Flush(cardsInput, resultCards))
    {
        resultType = STRAIGHT_FLUSH;
    }
    else if (Get_Four_Of_A_Kind(cardsInput, resultCards))
    {
        resultType = FOUR_OF_A_KIND;
        std::vector<Card> fourCards = resultCards;
        std::vector<Card> cardLastOne;
        Remove_Vector(cardsInput, fourCards);
        Get_Best_Card(cardsInput, cardLastOne);
        resultCards.emplace_back(cardLastOne.at(0));
    }
    else if (Get_Best_Full_House(cardsInput, resultCards))
    {
        resultType = FULL_HOUSE;
    }
    else if (Get_Best_Flush(cardsInput, resultCards))
    {
        resultType = FLUSH;
    }
    else if (Get_Best_Straight(cardsInput, resultCards))
    {
        resultType = STRAIGHT;
    }
    else if (Get_Best_Three_Of_A_Kind(cardsInput, resultCards))
    {
        resultType = THREE_OF_A_KIND;
        std::vector<Card> threeCards = resultCards;
        std::vector<Card> cardLastOne;
        Remove_Vector(cardsInput, threeCards);
        Get_Best_Card(cardsInput, cardLastOne);
        resultCards.emplace_back(cardLastOne.at(0));
        Remove_Vector(cardsInput, cardLastOne);
        cardLastOne.clear();
        Get_Best_Card(cardsInput, cardLastOne);
        resultCards.emplace_back(cardLastOne.at(0));
    }
    else if (Get_Best_Two_Pair(cardsInput, resultCards))
    {
        resultType = TWO_PAIR;
        std::vector<Card> twoPair = resultCards;
        std::vector<Card> cardLastOne;
        Remove_Vector(cardsInput, twoPair);
        Get_Best_Card(cardsInput, cardLastOne);
        resultCards.emplace_back(cardLastOne.at(0));
    }
    else if (Get_Best_One_Pair(cardsInput, resultCards))
    {
        resultType = ONE_PAIR;
        std::vector<Card> pair = resultCards;
        std::vector<Card> cardLastOne;
        Remove_Vector(cardsInput, pair);
        for (int i=0; i<3; i++)
        {
            Get_Best_Card(cardsInput, cardLastOne);
            resultCards.emplace_back(cardLastOne.at(0));
            Remove_Vector(cardsInput, cardLastOne);
            cardLastOne.clear();
        }
    }
    else
    {
        resultType = HIGH_CARD;
        std::vector<Card> cardLastOne;
        for (int i=0; i<5; i++)
        {
            Get_Best_Card(cardsInput, cardLastOne);
            resultCards.emplace_back(cardLastOne.at(0));
            Remove_Vector(cardsInput, cardLastOne);
            cardLastOne.clear();
        }
    }
    cardsOutput = resultCards;
    return resultType;
}
