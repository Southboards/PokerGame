import QtQuick 2.0
import QtQuick.Controls 2.0
import game.Backend 1.0

Item {
    Image {
        id: tablePoker
        visible: true
        source: "qrc:/image/table_poker.jpg"
        height: root.height
        width: root.width
        opacity: 1
        anchors.centerIn: parent
    }

    Row {
        id: jackpotTextRow
        anchors.right: parent.right
        spacing: 10
        Text {
            id: jackpotText
            text: "Jackpot: "
            color: "yellow"
            font.pixelSize: 20
            x: 0
            y: 0
        }

        Text {
            id: jackpotNumber
            text: myBackend.jackpotNumber
            color: jackpotText.color
            font.pixelSize: jackpotText.font.pixelSize
            x: 0
            y: 0
        }

        Text {
            id: currencyJacpotUnit
            text: "$"
            color: jackpotText.color
            font.pixelSize: jackpotText.font.pixelSize
        }
    }
    Row {
        id: typeGame
        spacing: 40
        anchors.centerIn: parent
        visible: myBackend.visibleButtonTypeGame
        Button {
            id: threeCardsType
            text: "Three Cards"
            font.pixelSize: 30
            width: 200
            height: 120
            onClicked: myBackend.Process_EI_Button_Three_Cards_Game()
        }
        Button {
            id: pokerType
            text: "Poker"
            font.pixelSize: threeCardsType.font.pixelSize
            width: threeCardsType.width
            height: threeCardsType.height
            onClicked: myBackend.Process_EI_Button_Poker_Game()
        }
    }

    Three_Cards {
        id: threeCardsGame
        visible: myBackend.visibleThreeCardsGame
        anchors.fill: parent
    }

    Poker {
        id: pokerGame
        visible: myBackend.visiblePokerGame
        anchors.fill: parent
    }


}
