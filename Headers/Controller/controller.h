#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QTimer>
#include <QDateTime>
#include <QDebug>
#include "../../Headers/Model/player.h"
#include "../Model/card_game.h"


class Controller : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool visibleWelcomeScreen READ visibleWelcomeScreen WRITE setVisibleWelcomeScreen NOTIFY visibleWelcomeScreenChanged)
    Q_PROPERTY(bool visiblePlayerScreen READ visiblePlayerScreen WRITE setVisiblePlayerScreen NOTIFY visiblePlayerScreenChanged)
    Q_PROPERTY(int jackpotNumber READ jackpotNumber WRITE setJackpotNumber NOTIFY jackpotNumberChanged)
    Q_PROPERTY(int moneyPlayer READ moneyPlayer WRITE setMoneyPlayer NOTIFY moneyPlayerChanged)
    Q_PROPERTY(QString linkRank READ linkRank WRITE setLinkRank NOTIFY linkRankChanged)
    Q_PROPERTY(bool visibleIngameScreen READ visibleIngameScreen WRITE setVisibleIngameScreen NOTIFY visibleIngameScreenChanged)
    Q_PROPERTY(bool visibleButtonTypeGame READ visibleButtonTypeGame WRITE setVisibleButtonTypeGame NOTIFY visibleButtonTypeGameChanged)
    Q_PROPERTY(bool visibleGameInPlay READ visibleGameInPlay WRITE setVisibleGameInPlay NOTIFY visibleGameInPlayChanged)
    Q_PROPERTY(QString linkFirstCardBot READ linkFirstCardBot WRITE setLinkFirstCardBot NOTIFY linkFirstCardBotChanged)
    Q_PROPERTY(QString linkSecondCardBot READ linkSecondCardBot WRITE setLinkSecondCardBot NOTIFY linkSecondCardBotChanged)
    Q_PROPERTY(QString linkThirdCardBot READ linkThirdCardBot WRITE setLinkThirdCardBot NOTIFY linkThirdCardBotChanged)
    Q_PROPERTY(QString linkFirstCardPlayer READ linkFirstCardPlayer WRITE setLinkFirstCardPlayer NOTIFY linkFirstCardPlayerChanged)
    Q_PROPERTY(QString linkSecondCardPlayer READ linkSecondCardPlayer WRITE setLinkSecondCardPlayer NOTIFY linkSecondCardPlayerChanged)
    Q_PROPERTY(QString linkThirdCardPlayer READ linkThirdCardPlayer WRITE setLinkThirdCardPlayer NOTIFY linkThirdCardPlayerChanged)
    Q_PROPERTY(bool visibleWinLose READ visibleWinLose WRITE setVisibleWinLose NOTIFY visibleWinLoseChanged)
    Q_PROPERTY(QString linkWinLose READ linkWinLose WRITE setLinkWinLose NOTIFY linkWinLoseChanged)
    Q_PROPERTY(bool visibleButtonBet READ visibleButtonBet WRITE setVisibleButtonBet NOTIFY visibleButtonBetChanged)
    Q_PROPERTY(bool visibleThreeCardsGame READ visibleThreeCardsGame WRITE setVisibleThreeCardsGame NOTIFY visibleThreeCardsGameChanged)
    Q_PROPERTY(bool visiblePokerGame READ visiblePokerGame WRITE setVisiblePokerGame NOTIFY visiblePokerGameChanged)
    Q_PROPERTY(QString linkFirstCardTable READ linkFirstCardTable WRITE setLinkFirstCardTable NOTIFY linkFirstCardTableChanged)
    Q_PROPERTY(QString linkSecondCardTable READ linkSecondCardTable WRITE setLinkSecondCardTable NOTIFY linkSecondCardTableChanged)
    Q_PROPERTY(QString linkThirdCardTable READ linkThirdCardTable WRITE setLinkThirdCardTable NOTIFY linkThirdCardTableChanged)
    Q_PROPERTY(QString linkFourthCardTable READ linkFourthCardTable WRITE setLinkFourthCardTable NOTIFY linkFourthCardTableChanged)
    Q_PROPERTY(QString linkFifthCardTable READ linkFifthCardTable WRITE setLinkFifthCardTable NOTIFY linkFifthCardTableChanged)

private:
    QTimer* m_timer;
    bool m_visibleWelcomeScreen;
    bool m_visiblePlayerScreen;
    int m_jackpotNumber;
    Player* m_player;
    QString m_linkRank;
    bool m_visibleIngameScreen;
    bool m_visibleButtonTypeGame;
    bool m_visibleGameInPlay;

    Card_Game* game_controller;

    QString m_linkFirstCardBot;
    QString m_linkSecondCardBot;
    QString m_linkThirdCardBot;
    QString m_linkFirstCardPlayer;
    QString m_linkSecondCardPlayer;
    QString m_linkThirdCardPlayer;

    bool m_visibleWinLose;
    QString m_linkWinLose;
    bool m_visibleButtonBet;

    enum Type_Game
    {
        THREE_CARDS,
        POKER,
        NONE_TYPE
    };
    Type_Game currentGame;

    bool m_visibleThreeCardsGame;
    bool m_visiblePokerGame;

    QString m_linkFirstCardTable;
    QString m_linkSecondCardTable;
    QString m_linkThirdCardTable;
    QString m_linkFourthCardTable;
    QString m_linkFifthCardTable;

    int timesBet;

public:
    explicit Controller(QObject *parent = nullptr);
    ~Controller();

    void setVisibleWelcomeScreen(bool value);
    bool visibleWelcomeScreen();

    void setVisiblePlayerScreen(bool value);
    bool visiblePlayerScreen();

    void setJackpotNumber(int value);
    int jackpotNumber();

    void setMoneyPlayer(int value);
    int moneyPlayer();

    void setLinkRank(QString value);
    QString linkRank();

    void setVisibleIngameScreen(bool value);
    bool visibleIngameScreen();

    void setVisibleButtonTypeGame(bool value);
    bool visibleButtonTypeGame();

    void setVisibleGameInPlay(bool value);
    bool visibleGameInPlay();

    void setLinkFirstCardBot(QString value);
    QString linkFirstCardBot();

    void setLinkSecondCardBot(QString value);
    QString linkSecondCardBot();

    void setLinkThirdCardBot(QString value);
    QString linkThirdCardBot();

    void setLinkFirstCardPlayer(QString value);
    QString linkFirstCardPlayer();

    void setLinkSecondCardPlayer(QString value);
    QString linkSecondCardPlayer();

    void setLinkThirdCardPlayer(QString value);
    QString linkThirdCardPlayer();

    void setVisibleWinLose(bool value);
    bool visibleWinLose();

    void setLinkWinLose(QString value);
    QString linkWinLose();

    void setVisibleButtonBet(bool value);
    bool visibleButtonBet();

    void setVisibleThreeCardsGame(bool value);
    bool visibleThreeCardsGame();

    void setVisiblePokerGame(bool value);
    bool visiblePokerGame();

    void setLinkFirstCardTable(QString value);
    QString linkFirstCardTable();

    void setLinkSecondCardTable(QString value);
    QString linkSecondCardTable();

    void setLinkThirdCardTable(QString value);
    QString linkThirdCardTable();

    void setLinkFourthCardTable(QString value);
    QString linkFourthCardTable();

    void setLinkFifthCardTable(QString value);
    QString linkFifthCardTable();

    Q_INVOKABLE void Process_EI_Button_Login(QString accountInput, QString passWordInput);
    Q_INVOKABLE void Process_EI_Button_Register(QString accountInput, QString passWordInput);
    Q_INVOKABLE void Process_EI_Button_New_Game();
    Q_INVOKABLE void Process_EI_Button_LogOut();
    Q_INVOKABLE void Process_EI_Button_Three_Cards_Game();
    Q_INVOKABLE void Process_EI_Button_Poker_Game();
    Q_INVOKABLE void Process_EI_Button_Bet(int moneyBet);
    Q_INVOKABLE void Process_EI_Button_Card(int value);
    Q_INVOKABLE void Process_EI_Button_Play_Again();
    Q_INVOKABLE void Process_EI_Button_Out_Table();
    Q_INVOKABLE void Process_EI_Button_Fold();

signals:
    void visibleWelcomeScreenChanged();
    void loginFail();
    void registerFail();

    void visiblePlayerScreenChanged();
    void jackpotNumberChanged();
    void moneyPlayerChanged();
    void linkRankChanged();

    void visibleIngameScreenChanged();
    void visibleButtonTypeGameChanged();
    void visibleGameInPlayChanged();

    void linkFirstCardBotChanged();
    void linkSecondCardBotChanged();
    void linkThirdCardBotChanged();
    void linkFirstCardPlayerChanged();
    void linkSecondCardPlayerChanged();
    void linkThirdCardPlayerChanged();

    void visibleWinLoseChanged();
    void linkWinLoseChanged();

    void visibleButtonBetChanged();

    void visibleThreeCardsGameChanged();
    void visiblePokerGameChanged();

    void linkFirstCardTableChanged();
    void linkSecondCardTableChanged();
    void linkThirdCardTableChanged();
    void linkFourthCardTableChanged();
    void linkFifthCardTableChanged();

private:
    enum ScreenModel {
        WELCOMESCREEN,
        PLAYERSCREEN,
        INGAMESCREEN
    };
    void Turn_On_Screen(ScreenModel model);
    void Turn_OFF_All_Screen();
    void Update_Rank_Player();
    void Update_Link_Cards();
    void Show_All_Cards();
    void Reset_Preset_InGame_Screen();

private slots:
    void Update_Jackpot_Callback();

};

#endif // CONTROLLER_H
