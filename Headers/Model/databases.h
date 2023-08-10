#ifndef DATABASES_H
#define DATABASES_H

#include <vector>
#include <string>
#include <fstream>
#include <QtCore>
#include <QIODevice>
#include "player.h"

#define STRING_ROOT_POKER               "../Poker/Databases/"
#define STRING_ACCOUNTS_LIST            "AccountList.json"
#define STRING_NUMBER_OF_ACCOUNT        "Number of Account"
#define STRING_JACKPOT                  "Jackpot"
#define STRING_LIST_ACCOUNT             "List Account"
#define STRING_NAME_PLAYER              "Name Player"
#define STRING_PASSWORD                 "Password"
#define STRING_AMOUNT                   "Amount"

class Databases
{

private:
    int numAccount;
    int jackpot;

    const QString ROOT_POKER = STRING_ROOT_POKER;
    const QString LINK_DATABASE = ROOT_POKER + STRING_ACCOUNTS_LIST;
    QString Get_Link_Database(std::string);

public:
    Databases();
    static Databases &Get_Instance()
    {
        static Databases instance;
        return instance;
    }

    void Add_Account(std::string account, std::string passWord);

    bool Check_Login(std::string account, std::string password);

    bool Check_Account_Exist(std::string account);

    float Get_Amount(std::string amount);

    int getJackpot();
    void setJackpot(int value);

    void Update_Money_Player(Player player);

    Databases(Databases const &) = delete;
    void operator=(Databases const &) = delete;
};

#endif // DATABASES_H
