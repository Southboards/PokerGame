#include "../../Headers/Controller/controller.h"
#include "../../Headers/Model/databases.h"
#include "../../Headers/Model/check_valid.h"
#include "../../Headers/Model/three_cards.h"
#include "../../Headers/Model/poker.h"

Controller::Controller(QObject *parent) : QObject(parent),
    m_visibleWelcomeScreen(true),
    m_visiblePlayerScreen(false),
    m_jackpotNumber(0),
    m_player(nullptr),
    m_linkRank(""),
    m_visibleIngameScreen(false),
    m_visibleButtonTypeGame(true),
    m_visibleGameInPlay(false),
    game_controller(nullptr),
    m_linkFirstCardBot(""),
    m_linkSecondCardBot(""),
    m_linkThirdCardBot(""),
    m_linkFirstCardPlayer(""),
    m_linkSecondCardPlayer(""),
    m_linkThirdCardPlayer(""),
    m_visibleWinLose(false),
    m_linkWinLose(""),
    m_visibleButtonBet(true),
    currentGame(NONE_TYPE),
    m_visibleThreeCardsGame(false),
    m_visiblePokerGame(false),
    m_linkFirstCardTable(""),
    m_linkSecondCardTable(""),
    m_linkThirdCardTable(""),
    m_linkFourthCardTable(""),
    m_linkFifthCardTable(""),
    timesBet(0)
{
    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(Update_Jackpot_Callback()));
    m_timer->start(1000);
    m_jackpotNumber = Databases::Get_Instance().getJackpot();
}

Controller::~Controller()
{
    if (m_timer != nullptr)
    {
        delete m_timer;
    }
    m_timer = nullptr;

    if (m_player != nullptr)
    {
        delete m_player;
    }
    m_player = nullptr;
}

bool Controller::visibleWelcomeScreen()
{
    return m_visibleWelcomeScreen;
}

void Controller::setVisibleWelcomeScreen(bool value)
{
    m_visibleWelcomeScreen = value;
    emit visibleWelcomeScreenChanged();
}

bool Controller::visiblePlayerScreen()
{
    return m_visiblePlayerScreen;
}

void Controller::setVisiblePlayerScreen(bool value)
{
    m_visiblePlayerScreen = value;
    emit visiblePlayerScreenChanged();
}

int Controller::jackpotNumber()
{
    return m_jackpotNumber;
}

void Controller::setJackpotNumber(int value)
{
    m_jackpotNumber = value;
    emit jackpotNumberChanged();
}

void Controller::setMoneyPlayer(int value)
{
    if (m_player != nullptr)
    {
        m_player->setMoney(value);
    }
    emit moneyPlayerChanged();
}
int Controller::moneyPlayer()
{
    int returnValue = 0;
    if (m_player != nullptr)
    {
        returnValue = m_player->getMoney();
    }
    return returnValue;
}

void Controller::setLinkRank(QString value)
{
    m_linkRank = value;
    emit linkRankChanged();
}

QString Controller::linkRank()
{
    return m_linkRank;
}

void Controller::setVisibleIngameScreen(bool value)
{
    m_visibleIngameScreen = value;
    emit visibleIngameScreenChanged();
}
bool Controller::visibleIngameScreen()
{
    return m_visibleIngameScreen;
}

void Controller::setVisibleButtonTypeGame(bool value)
{
    m_visibleButtonTypeGame = value;
    emit visibleButtonTypeGameChanged();
}
bool Controller::visibleButtonTypeGame()
{
    return m_visibleButtonTypeGame;
}

void Controller::setVisibleGameInPlay(bool value)
{
    m_visibleGameInPlay = value;
    emit visibleGameInPlayChanged();
}

bool Controller::visibleGameInPlay()
{
    return m_visibleGameInPlay;
}

void Controller::setLinkFirstCardBot(QString value)
{
    m_linkFirstCardBot = value;
    emit linkFirstCardBotChanged();
}
QString Controller::linkFirstCardBot()
{
    return m_linkFirstCardBot;
}

void Controller::setLinkSecondCardBot(QString value)
{
    m_linkSecondCardBot = value;
    emit linkSecondCardBotChanged();
}
QString Controller::linkSecondCardBot()
{
    return m_linkSecondCardBot;
}

void Controller::setLinkThirdCardBot(QString value)
{
    m_linkThirdCardBot = value;
    emit linkThirdCardBotChanged();
}
QString Controller::linkThirdCardBot()
{
    return m_linkThirdCardBot;
}

void Controller::setLinkFirstCardPlayer(QString value)
{
    m_linkFirstCardPlayer = value;
    emit linkFirstCardPlayerChanged();
}
QString Controller::linkFirstCardPlayer()
{
    return m_linkFirstCardPlayer;
}

void Controller::setLinkSecondCardPlayer(QString value)
{
    m_linkSecondCardPlayer = value;
    emit linkSecondCardPlayerChanged();
}
QString Controller::linkSecondCardPlayer()
{
    return m_linkSecondCardPlayer;
}

void Controller::setLinkThirdCardPlayer(QString value)
{
    m_linkThirdCardPlayer = value;
    emit linkThirdCardPlayerChanged();
}

QString Controller::linkThirdCardPlayer()
{
    return m_linkThirdCardPlayer;
}

void Controller::setVisibleWinLose(bool value)
{
    m_visibleWinLose = value;
    emit visibleWinLoseChanged();
}

bool Controller::visibleWinLose()
{
    return m_visibleWinLose;
}

void Controller::setLinkWinLose(QString value)
{
    m_linkWinLose = value;
    emit linkWinLoseChanged();
}
QString Controller::linkWinLose()
{
    return m_linkWinLose;
}

void Controller::setVisibleButtonBet(bool value)
{
    m_visibleButtonBet = value;
    emit visibleButtonBetChanged();
}
bool Controller::visibleButtonBet()
{
    return m_visibleButtonBet;
}

void Controller::setVisibleThreeCardsGame(bool value)
{
    m_visibleThreeCardsGame = value;
    emit visibleThreeCardsGameChanged();
}

bool Controller::visibleThreeCardsGame()
{
    return m_visibleThreeCardsGame;
}

void Controller::setVisiblePokerGame(bool value)
{
    m_visiblePokerGame = value;
    emit visiblePokerGameChanged();
}

bool Controller::visiblePokerGame()
{
    return m_visiblePokerGame;
}

void Controller::setLinkFirstCardTable(QString value)
{
    m_linkFirstCardTable = value;
    emit linkFirstCardTableChanged();
}
QString Controller::linkFirstCardTable()
{
    return m_linkFirstCardTable;
}

void Controller::setLinkSecondCardTable(QString value)
{
    m_linkSecondCardTable = value;
    emit linkSecondCardTableChanged();
}
QString Controller::linkSecondCardTable()
{
    return m_linkSecondCardTable;
}

void Controller::setLinkThirdCardTable(QString value)
{
    m_linkThirdCardTable = value;
    emit linkThirdCardTableChanged();
}
QString Controller::linkThirdCardTable()
{
    return m_linkThirdCardTable;
}

void Controller::setLinkFourthCardTable(QString value)
{
    m_linkFourthCardTable = value;
    emit linkFourthCardTableChanged();
}
QString Controller::linkFourthCardTable()
{
    return m_linkFourthCardTable;
}

void Controller::setLinkFifthCardTable(QString value)
{
    m_linkFifthCardTable = value;
    emit linkFifthCardTableChanged();
}
QString Controller::linkFifthCardTable()
{
    return m_linkFifthCardTable;
}

void Controller::Process_EI_Button_Login(QString accountInput, QString passWordInput)
{
    std::string account, passWord;
    account = accountInput.toStdString();
    passWord = passWordInput.toStdString();
    if (Databases::Get_Instance().Check_Login(account, passWord))
    {
        this->m_player = new Player(account);
        Update_Rank_Player();
        Turn_On_Screen(PLAYERSCREEN);
    }
    else
    {
        emit loginFail();
    }
}

void Controller::Process_EI_Button_Register(QString accountInput, QString passWordInput)
{
    std::string account, passWord;
    account = accountInput.toStdString();
    passWord = passWordInput.toStdString();

    if (Check_Valid::Check_Valid_Account(account, passWord) != 0)
    {
        if (Databases::Get_Instance().Check_Account_Exist(account) == 0)
        {
            Databases::Get_Instance().Add_Account(account, passWord);
            m_player = new Player(account);
            Update_Rank_Player();
            Turn_On_Screen(PLAYERSCREEN);
        }
        else
        {
            emit registerFail();
        }
    }
    else
    {
        emit registerFail();
    }
}

void Controller::Process_EI_Button_New_Game()
{
    Turn_On_Screen(INGAMESCREEN);
    setVisibleButtonTypeGame(true);
    setVisibleGameInPlay(false);
}

void Controller::Process_EI_Button_LogOut()
{
    if (m_player != nullptr)
    {
        delete m_player;
    }
    m_player = nullptr;
    Turn_On_Screen(WELCOMESCREEN);
}

void Controller::Process_EI_Button_Three_Cards_Game()
{
    setVisibleThreeCardsGame(true);
    currentGame = THREE_CARDS;
    game_controller = new Three_Cards(*this->m_player);
    game_controller->Run();
    Update_Link_Cards();
    setVisibleButtonTypeGame(false);
    setVisibleGameInPlay(true);
}

void Controller::Process_EI_Button_Poker_Game()
{
    setVisiblePokerGame(true);
    currentGame = POKER;
    game_controller = new Poker(*this->m_player);
    game_controller->Run();
    Update_Link_Cards();
    setVisibleButtonTypeGame(false);
    setVisibleGameInPlay(true);
}

void Controller::Process_EI_Button_Bet(int moneyBet)
{
    if (game_controller != nullptr)
    {
        game_controller->moneyBet += moneyBet;
        if (currentGame == THREE_CARDS)
        {
            switch (game_controller->Check_Win())
            {
            case Card_Game::WIN:
                setMoneyPlayer(m_player->getMoney() + game_controller->moneyBet);
                setLinkWinLose("qrc:/image/you_win.jpg");
                break;
            case Card_Game::DRAW:
                setLinkWinLose("qrc:/image/you_draw.jpg");
                break;
            case Card_Game::LOSE:
                setMoneyPlayer(m_player->getMoney() - game_controller->moneyBet);
                setLinkWinLose("qrc:/image/you_lose.jpg");
                break;
            default:
                break;
            }

            setVisibleWinLose(true);
            setVisibleButtonBet(false);
            Show_All_Cards();
        }
        else if (currentGame == POKER)
        {
            timesBet++;
            Poker* poker_game = dynamic_cast<Poker*>(game_controller);
            if (timesBet == 1)
            {
                poker_game->tableOwner.cardOwned.at(0).setStatus(true);
                poker_game->tableOwner.cardOwned.at(1).setStatus(true);
                poker_game->tableOwner.cardOwned.at(2).setStatus(true);
            }
            else if (timesBet == 2)
            {
                poker_game->tableOwner.cardOwned.at(3).setStatus(true);
            }
            else if (timesBet == 3)
            {
                poker_game->tableOwner.cardOwned.at(4).setStatus(true);
            }
            else
            {
                switch (game_controller->Check_Win())
                {
                case Card_Game::WIN:
                    setMoneyPlayer(m_player->getMoney() + game_controller->moneyBet);
                    setLinkWinLose("qrc:/image/you_win.jpg");
                    break;
                case Card_Game::DRAW:
                    setLinkWinLose("qrc:/image/you_draw.jpg");
                    break;
                case Card_Game::LOSE:
                    setMoneyPlayer(m_player->getMoney() - game_controller->moneyBet);
                    setLinkWinLose("qrc:/image/you_lose.jpg");
                    break;
                default:
                    break;
                }
                setVisibleWinLose(true);
                setVisibleButtonBet(false);
                Show_All_Cards();
            }
            Update_Link_Cards();
        }
        else
        {

        }
    }
}

void Controller::Process_EI_Button_Fold()
{
    Poker* poker_game = dynamic_cast<Poker*>(game_controller);
    poker_game->tableOwner.cardOwned.at(0).setStatus(true);
    poker_game->tableOwner.cardOwned.at(1).setStatus(true);
    poker_game->tableOwner.cardOwned.at(2).setStatus(true);
    poker_game->tableOwner.cardOwned.at(3).setStatus(true);
    poker_game->tableOwner.cardOwned.at(4).setStatus(true);
    setMoneyPlayer(m_player->getMoney() - game_controller->moneyBet);
    setLinkWinLose("qrc:/image/you_lose.jpg");
    setVisibleWinLose(true);
    setVisibleButtonBet(false);
    Show_All_Cards();
    Update_Link_Cards();
}

void Controller::Process_EI_Button_Card(int value)
{
    if (game_controller != nullptr)
    {
        game_controller->player_ingame.cardOwned.at(value-1).Upside_Card();
        Update_Link_Cards();
    }
}

void Controller::Process_EI_Button_Play_Again()
{
    if (game_controller != nullptr)
    {
        delete game_controller;
    }
    game_controller = nullptr;

    Reset_Preset_InGame_Screen();
    setVisibleWinLose(false);

    switch (currentGame)
    {
    case THREE_CARDS:
        Process_EI_Button_Three_Cards_Game();
        break;
    case POKER:
        Process_EI_Button_Poker_Game();
        break;
    case NONE_TYPE:
        break;
    default:
        break;
    }
}

void Controller::Process_EI_Button_Out_Table()
{
    if (game_controller != nullptr)
    {
        delete game_controller;
    }
    game_controller = nullptr;
    Reset_Preset_InGame_Screen();
    setVisibleWinLose(false);
    Update_Rank_Player();
    Turn_On_Screen(PLAYERSCREEN);
}

void Controller::Turn_On_Screen(ScreenModel model)
{
    Turn_OFF_All_Screen();
    switch(model)
    {
    case WELCOMESCREEN:
        m_visibleWelcomeScreen = 1;
        break;
    case PLAYERSCREEN:
        m_visiblePlayerScreen = 1;
        break;
    case INGAMESCREEN:
        m_visibleIngameScreen = 1;
        break;
    default:
        m_visibleWelcomeScreen = 1;
        break;
    }
    emit visibleWelcomeScreenChanged();
    emit visiblePlayerScreenChanged();
    emit visibleIngameScreenChanged();
}

void Controller::Turn_OFF_All_Screen()
{
    m_visibleWelcomeScreen = 0;
    m_visiblePlayerScreen = 0;
    m_visibleIngameScreen = 0;
}

void Controller::Update_Rank_Player()
{
    switch (m_player->Get_Rank())
    {
    case Player::BRONZE:
        m_linkRank = "qrc:/image/bronze_rank.png";
        break;
    case Player::SILVER:
        m_linkRank = "qrc:/image/silver_rank.png";
        break;
    case Player::GOLD:
        m_linkRank = "qrc:/image/gold_rank.png";
        break;
    case Player::PLATIUM:
        m_linkRank = "qrc:/image/platium_rank.png";
        break;
    case Player::DIAMOND:
        m_linkRank = "qrc:/image/diamond_rank.png";
        break;
    case Player::MASTER:
        m_linkRank = "qrc:/image/master_rank.png";
        break;
    case Player::GRANDMASTER:
        m_linkRank = "qrc:/image/grandmaster_rank.png";
        break;
    case Player::CHALLENGER:
        m_linkRank = "qrc:/image/challenger_rank.png";
        break;
    default:
        m_linkRank = "";
        break;
    }

    emit moneyPlayerChanged();
    emit linkRankChanged();
}

void Controller::Update_Link_Cards()
{
    if (game_controller != nullptr)
    {
        if (currentGame == THREE_CARDS)
        {
            setLinkFirstCardBot(game_controller->bot.cardOwned.at(0).Get_Link());
            setLinkSecondCardBot(game_controller->bot.cardOwned.at(1).Get_Link());
            setLinkThirdCardBot(game_controller->bot.cardOwned.at(2).Get_Link());
            setLinkFirstCardPlayer(game_controller->player_ingame.cardOwned.at(0).Get_Link());
            setLinkSecondCardPlayer(game_controller->player_ingame.cardOwned.at(1).Get_Link());
            setLinkThirdCardPlayer(game_controller->player_ingame.cardOwned.at(2).Get_Link());
        }
        else if (currentGame == POKER)
        {
            Poker* poker_game = dynamic_cast<Poker*>(game_controller);
            setLinkFirstCardBot(poker_game->bot.cardOwned.at(0).Get_Link());
            setLinkSecondCardBot(poker_game->bot.cardOwned.at(1).Get_Link());
            setLinkFirstCardPlayer(poker_game->player_ingame.cardOwned.at(0).Get_Link());
            setLinkSecondCardPlayer(poker_game->player_ingame.cardOwned.at(1).Get_Link());
            setLinkFirstCardTable(poker_game->tableOwner.cardOwned.at(0).Get_Link());
            setLinkSecondCardTable(poker_game->tableOwner.cardOwned.at(1).Get_Link());
            setLinkThirdCardTable(poker_game->tableOwner.cardOwned.at(2).Get_Link());
            setLinkFourthCardTable(poker_game->tableOwner.cardOwned.at(3).Get_Link());
            setLinkFifthCardTable(poker_game->tableOwner.cardOwned.at(4).Get_Link());
        }
        else
        {

        }
    }
}

void Controller::Show_All_Cards()
{
    for (Card& itr : game_controller->bot.cardOwned)
    {
        itr.setStatus(true);
    }
    for (Card& itr : game_controller->player_ingame.cardOwned)
    {
        itr.setStatus(true);
    }
    Update_Link_Cards();
}

void Controller::Reset_Preset_InGame_Screen()
{
    if (game_controller != nullptr)
    {
        for (Card& itr : game_controller->bot.cardOwned)
        {
            itr.setStatus(false);
        }
        for (Card& itr : game_controller->player_ingame.cardOwned)
        {
            itr.setStatus(false);
        }
        Poker* poker_game = dynamic_cast<Poker*>(game_controller);
        for (Card& itr : poker_game->tableOwner.cardOwned)
        {
            itr.setStatus(false);
        }
    }
    setVisibleThreeCardsGame(false);
    setVisiblePokerGame(false);
    setVisibleButtonBet(true);
    timesBet = 0;
}

void Controller::Update_Jackpot_Callback()
{
    m_jackpotNumber++;
    Databases::Get_Instance().setJackpot(m_jackpotNumber);
    emit jackpotNumberChanged();
}
