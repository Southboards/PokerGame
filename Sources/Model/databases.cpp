#include "../../Headers/Model/databases.h"

Databases::Databases() : numAccount(0), jackpot(0)
{
    QFile dataBaseFile(LINK_DATABASE);

    if( dataBaseFile.open(QIODevice::ReadOnly | QIODevice::Text) )
    {
        /* file exist */
        QJsonParseError JsonParseError;
        QJsonDocument JsonDocument = QJsonDocument::fromJson(dataBaseFile.readAll(), &JsonParseError);
        if (JsonParseError.error != QJsonParseError::NoError)
        {
            dataBaseFile.close();
            // throw
            return;
        }
        dataBaseFile.close();

        QJsonObject rootObj = JsonDocument.object();
        this->numAccount = rootObj.value(QString(STRING_NUMBER_OF_ACCOUNT)).toInt();
        this->jackpot = rootObj.value(QString(STRING_JACKPOT)).toInt();

    }

    else
    {
        /* create file*/
        dataBaseFile.open(QIODevice::WriteOnly | QIODevice::Text);

        QJsonObject rootObj;
        rootObj[STRING_NUMBER_OF_ACCOUNT] = this->numAccount;
        rootObj[STRING_JACKPOT] = this->jackpot ;

        QJsonArray list;
        rootObj[STRING_LIST_ACCOUNT] = list;

        auto writeContent = QJsonDocument(rootObj).toJson();
        dataBaseFile.write(writeContent);

        dataBaseFile.close();
    }
}

void Databases::Add_Account(std::string accountNew, std::string passWord)
{
    if (Check_Account_Exist(accountNew))
    {
        return;
    }

    /* file not exist */

    /* update databases */
    QFile dataBaseFile(LINK_DATABASE);
    if( dataBaseFile.open( QIODevice::ReadOnly | QIODevice::Text) == 0 )
    {
        //throw
        return;
    }

    else
    {
        QJsonParseError JsonParseError;
        QJsonDocument JsonDocument = QJsonDocument::fromJson(dataBaseFile.readAll(), &JsonParseError);
        if (JsonParseError.error != QJsonParseError::NoError)
        {
            dataBaseFile.close();
            return;
        }

        QJsonObject rootObj = JsonDocument.object();
        this->numAccount = rootObj.value(STRING_NUMBER_OF_ACCOUNT).toInt() + 1;
        rootObj[STRING_NUMBER_OF_ACCOUNT] = this->numAccount;

        QJsonArray listAccount = rootObj[STRING_LIST_ACCOUNT].toArray();
        listAccount.push_back(accountNew.c_str());
        rootObj[STRING_LIST_ACCOUNT] = listAccount;
        dataBaseFile.close();

        QJsonObject newRootObj = rootObj;

        dataBaseFile.open( QIODevice::ReadWrite | QIODevice::Text | QIODevice::Truncate);
        auto writeContent = QJsonDocument(newRootObj).toJson();
        dataBaseFile.write(writeContent);

        dataBaseFile.close();
    }


    /* create player file */
    QFile playerFile(Get_Link_Database(accountNew));
    if( playerFile.open( QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate) == 0 )
    {
        //throw
        return;
    }
    else
    {
        QJsonObject rootObj;
        rootObj.insert(STRING_NAME_PLAYER, accountNew.c_str() );

        rootObj.insert(STRING_PASSWORD, passWord.c_str() );

        rootObj.insert(STRING_AMOUNT, 1000);

        auto writeContent = QJsonDocument(rootObj).toJson();
        playerFile.write(writeContent);
        playerFile.close();

    }

    playerFile.close();
}

float Databases::Get_Amount(std::string account)
{
    QFile playerFile(Get_Link_Database(account));
    if( playerFile.open( QIODevice::ReadOnly | QIODevice::Text) == 0 )
    {
        //throw
        return -1;
    }
    else
    {
        QJsonParseError JsonParseError;
        QJsonDocument JsonDocument = QJsonDocument::fromJson(playerFile.readAll(), &JsonParseError);
        if (JsonParseError.error != QJsonParseError::NoError)
        {
            playerFile.close();
            // throw
        }
        QJsonObject rootObj = JsonDocument.object();

        playerFile.close();
        return rootObj.value(STRING_AMOUNT).toDouble();

    }
}

bool Databases::Check_Login(std::string account, std::string password)
{

    QFile playerFile(Get_Link_Database(account));
    if( playerFile.open( QIODevice::ReadOnly | QIODevice::Text) == 0 )
    {
        //throw
        return 0;
    }
    else
    {
        QJsonParseError JsonParseError;
        QJsonDocument JsonDocument = QJsonDocument::fromJson(playerFile.readAll(), &JsonParseError);
        if (JsonParseError.error != QJsonParseError::NoError)
        {
            playerFile.close();
            // throw
        }
        QJsonObject rootObj = JsonDocument.object();

        if (rootObj[STRING_PASSWORD].toString().toStdString() == password)
        {
            playerFile.close();
            return 1;
        }
        playerFile.close();
        return 0;
    }
}

bool Databases::Check_Account_Exist(std::string account)
{
    bool returnValue = 1;
    QFile dataBaseFile(Get_Link_Database(account));
    if( dataBaseFile.open( QIODevice::ReadOnly | QIODevice::Text) == 0 )
    {
        returnValue = 0;
    }
    dataBaseFile.close();
    return returnValue;
}

int Databases::getJackpot()
{
    return jackpot;
}

void Databases::setJackpot(int value)
{
    jackpot = value;
    QFile dataBaseFile(LINK_DATABASE);

    if( dataBaseFile.open( QIODevice::ReadOnly | QIODevice::Text) == 0 )
    {
        //throw
    }
    else
    {
        QJsonParseError JsonParseError;
        QJsonDocument JsonDocument = QJsonDocument::fromJson(dataBaseFile.readAll(), &JsonParseError);
        if (JsonParseError.error != QJsonParseError::NoError)
        {
            dataBaseFile.close();
        }
        else
        {
            QJsonObject rootObj = JsonDocument.object();
            rootObj[STRING_JACKPOT] = this->jackpot;

            dataBaseFile.close();

            QJsonObject newRootObj = rootObj;

            dataBaseFile.open( QIODevice::ReadWrite | QIODevice::Text | QIODevice::Truncate);
            auto writeContent = QJsonDocument(newRootObj).toJson();
            dataBaseFile.write(writeContent);

            dataBaseFile.close();
        }
    }
}

void Databases::Update_Money_Player(Player player)
{
    if (Check_Account_Exist(player.getName()) == 0)
    {
        return;
    }

    QFile playerFile(Get_Link_Database(player.getName()));
    if( playerFile.open( QIODevice::ReadOnly | QIODevice::Text) == 0 )
    {
        //throw
        return;
    }
    else
    {
        QJsonParseError JsonParseError;
        QJsonDocument JsonDocument = QJsonDocument::fromJson(playerFile.readAll(), &JsonParseError);
        if (JsonParseError.error != QJsonParseError::NoError)
        {
            playerFile.close();
            return;
        }

        QJsonObject rootObj = JsonDocument.object();
        rootObj[STRING_AMOUNT] = player.getMoney();
        playerFile.close();

        QJsonObject newRootObj = rootObj;
        playerFile.open( QIODevice::ReadWrite | QIODevice::Text | QIODevice::Truncate);
        auto writeContent = QJsonDocument(newRootObj).toJson();
        playerFile.write(writeContent);

        playerFile.close();
    }

    playerFile.close();
}

QString Databases::Get_Link_Database(std::string input)
{
    QString link = ROOT_POKER + input.c_str() + ".json";
    return link;
}
