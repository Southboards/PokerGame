import QtQuick 2.15
import QtQuick.Controls 2.15
import game.Backend 1.0

Item {
    Image {
        id: imagePlayerBackgound
        visible: true
        source: "qrc:/image/table_background.jpg"
        height: root.height
        width: root.width
        opacity: 0.5
        anchors.centerIn: parent
    }

    Row {
        id: jackpotTextRow
        anchors.right: parent.right
        spacing: 10
        Text {
            id: jackpotText
            text: "Jackpot: "
            color: "red"
            font.pixelSize: 30
            x: 0
            y: 0
        }

        Text {
            id: jackpotNumber
            text: myBackend.jackpotNumber
            color: "red"
            font.pixelSize: jackpotText.font.pixelSize
            x: 0
            y: 0
        }

        Text {
            id: currencyJacpotUnit
            text: "$"
            color: "red"
            font.pixelSize: jackpotText.font.pixelSize
        }
    }

    Column {
        id: infomationPlayer
        anchors.horizontalCenter: parent.horizontalCenter
        y: 40
        spacing: 50

        Image {
            id: imageRank
            source: myBackend.linkRank
        }

        Row {
            spacing: 20
            Text {
                id: moneyText
                text: "Treasury: "
                color: "blue"
                font.pixelSize: 25
            }

            Text {
                id: numberMoney
                text: myBackend.moneyPlayer
                color: "red"
                font.pixelSize: moneyText.font.pixelSize
            }

            Text {
                id: currencyUnit
                text: "$"
                color: "blue"
                font.pixelSize: moneyText.font.pixelSize
            }
        }
    }



    Column {
        id: playerMenuText
        visible: true
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 20
        y: infomationPlayer.y + infomationPlayer.height + 180
        Button {
            id: newGameButton
            text: "New Game"
            font.pixelSize: 20
            width: 200
            height: 80
            onClicked: myBackend.Process_EI_Button_New_Game()
        }

        Button {
            id: logOutButton
            text: "Log Out"
            font.pixelSize: newGameButton.font.pixelSize
            width: newGameButton.width
            height: newGameButton.height
            onClicked: myBackend.Process_EI_Button_LogOut()
        }
    }
}
