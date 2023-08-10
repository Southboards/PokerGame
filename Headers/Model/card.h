#ifndef CARD_H
#define CARD_H

#include <QtCore>
#include <QIODevice>

class Card
{

public:
    enum Material {
        SPADE,
        CLUBE,
        DIAMOND,
        HEART,
        NONE_MATERIAL
    };

    enum Type {
        ACE,
        TWO,
        THREE,
        FOUR,
        FIVE,
        SIX,
        SEVEN,
        EIGHT,
        NINE,
        TEN,
        JACK,
        QUEEN,
        KING,
        NONE_TYPE
    };

    Card();
    Card(Material materialInput, Type numberInput);

    Material getMaterial();
    Type getNumber();
    Type getNumber(bool usingAce);

    bool getStatus();
    void setStatus(bool value);

    void Upside_Card();

    QString Get_Link();


private:

    Material material;
    Type number;
    bool status;
    QString link;

    QString Get_Link_None_Card();
    void Update_Link();
};

#endif // CARD_H
