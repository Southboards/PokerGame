#include "../../Headers/Model/card.h"

Card::Card() :  material(NONE_MATERIAL),
                number(NONE_TYPE),
                status(false)
{

}

Card::Card(Material materialInput, Type numberInput) :  material(materialInput),
                                                        number(numberInput),
                                                        status(false)
{
    Update_Link();
}

Card::Material Card::getMaterial()
{
    return material;
}

Card::Type Card::getNumber()
{
    return number;
}

Card::Type Card::getNumber(bool usingAce)
{
    if (usingAce && (number == Card::ACE))
    {
        return NONE_TYPE;
    }
    return number;
}

bool Card::getStatus()
{
    return status;
}
void Card::setStatus(bool value)
{
    status = value;
}

QString Card::Get_Link()
{
    QString cardLink = Get_Link_None_Card();
    if (status)
    {
        cardLink = link;
    }
    return cardLink;
}

void Card::Update_Link()
{
    QString num, mater;
    switch (number)
    {
    case ACE:
        num = "ace";
        break;
    case TWO:
        num = "two";
        break;
    case THREE:
        num = "three";
        break;
    case FOUR:
        num = "four";
        break;
    case FIVE:
        num = "five";
        break;
    case SIX:
        num = "six";
        break;
    case SEVEN:
        num = "seven";
        break;
    case EIGHT:
        num = "eight";
        break;
    case NINE:
        num = "nine";
        break;
    case TEN:
        num = "ten";
        break;
    case JACK:
        num = "jack";
        break;
    case QUEEN:
        num = "queen";
        break;
    case KING:
        num = "king";
        break;
    default:
        num = "";
        break;
    }

    switch (material)
    {
    case SPADE:
        mater = "1";
        break;
    case CLUBE:
        mater = "2";
        break;
    case DIAMOND:
        mater = "3";
        break;
    case HEART:
        mater = "4";
        break;
    default:
        mater = "";
        break;
    }

    link = "qrc:/image/" + num + "_" + mater + ".png";
}

QString Card::Get_Link_None_Card()
{
    QString card_link = "qrc:/image/none_card.png";
    return card_link;
}

void Card::Upside_Card()
{
    status = !status;
}
