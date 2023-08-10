import QtQuick 2.0
import QtQuick.Controls 2.0
import game.Backend 1.0

Item {
    anchors.fill: parent
    Column {
        id: winloseText
        spacing: 20
        visible: myBackend.visibleWinLose
        anchors.horizontalCenter: parent.horizontalCenter
        y: botCardLine.height + 60
        Image {
            id: winlose
            width: 300
            height: 160
            source: myBackend.linkWinLose
        }

        Button {
            id: startGameAgain
            text: "Play Again"
            anchors.horizontalCenter: winlose.horizontalCenter
            font.pixelSize: 25
            width: 200
            height: 60
            onClicked: myBackend.Process_EI_Button_Play_Again()
        }

        Button {
            id: outTable
            text: "Out Table"
            anchors.horizontalCenter: winlose.horizontalCenter
            font.pixelSize: startGameAgain.font.pixelSize
            width: startGameAgain.width
            height: startGameAgain.height
            onClicked: myBackend.Process_EI_Button_Out_Table()
        }
    }

    Item {
        id: ingameAfterStart
        visible: myBackend.visibleGameInPlay
        anchors.fill: parent

        Row {
            id: botCardLine
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: 20
            y: 30
            Image {
                id: botCardFirst
                width: 120
                height: 200
                source: myBackend.linkFirstCardBot
            }

            Image {
                id: botCardSecond
                width: botCardFirst.width
                height: botCardFirst.height
                source: myBackend.linkSecondCardBot
            }

            Image {
                id: botCardThird
                width: botCardFirst.width
                height: botCardFirst.height
                source: myBackend.linkThirdCardBot
            }
        }

        Row {
            id: buttonPlayerIngame
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: 40
            visible: myBackend.visibleButtonBet
            y: playerCardLine.y - buttonPlayerIngame.height - 30

            Button {
                id: bet1
                text: "Bet 100"
                font.pixelSize: 20
                width: 160
                height: 60
                onClicked: myBackend.Process_EI_Button_Bet(100)
            }

            Button {
                id: bet2
                text: "Bet 200"
                font.pixelSize: bet1.font.pixelSize
                width: bet1.width
                height: bet1.height
                onClicked: myBackend.Process_EI_Button_Bet(200)
            }

            Button {
                id: bet3
                text: "Bet 500"
                font.pixelSize: bet1.font.pixelSize
                width: bet1.width
                height: bet1.height
                onClicked: myBackend.Process_EI_Button_Bet(500)
            }
        }

        Row {
            id: playerCardLine
            anchors.horizontalCenter: parent.horizontalCenter
            spacing: 20
            y: parent.height - playerCardFirst.height - 30

            Image {
                id: playerCardFirst
                width: botCardFirst.width
                height: botCardFirst.height
                source: myBackend.linkFirstCardPlayer

                MouseArea {
                    anchors.fill: parent
                    onClicked: myBackend.Process_EI_Button_Card(1)
                }
            }

            Image {
                id: playerCardSecond
                width: botCardFirst.width
                height: botCardFirst.height
                source: myBackend.linkSecondCardPlayer

                MouseArea {
                    anchors.fill: parent
                    onClicked: myBackend.Process_EI_Button_Card(2)
                }
            }

            Image {
                id: playerCardThird
                width: botCardFirst.width
                height: botCardFirst.height
                source: myBackend.linkThirdCardPlayer

                MouseArea {
                    anchors.fill: parent
                    onClicked: myBackend.Process_EI_Button_Card(3)
                }
            }
        }

        Row {
            id: infomationPlayerInGame
            anchors.right: parent.right
            anchors.bottom: parent.bottom
            spacing: 10
            Text {
                id: moneyPlayerInGame
                text: "Money: "
                color: "yellow"
                font.pixelSize: 25
            }

            Text {
                id: numberMoneyPlayerInGame
                text: myBackend.moneyPlayer
                color: "red"
                font.pixelSize: moneyPlayerInGame.font.pixelSize
            }

            Text {
                id: currencyUnitPlayerInGame
                text: "$"
                color: "yellow"
                font.pixelSize: moneyPlayerInGame.font.pixelSize
            }
        }
    }
}






