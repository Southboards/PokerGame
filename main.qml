import QtQuick 2.0
import QtQuick.Window 2.0
import QtQuick.Controls 2.0
import game.Backend 1.0

Window {
    id: root
    width: 1280
    height: 960
    visible: true
    title: qsTr("Game Poker")

    Text {
        id: statusText
        visible: false
        text: ""
    }

    Backend {
        id: myBackend

        onLoginFail: {
            statusText.text = "Login Fail. Username or password is wrong !!!"
        }

        onRegisterFail: {
            statusText.text = "Register Fail. Username is existed or Username or Password is invalid!!!"
        }
    }

    Welcome {
        id: welcomeMenuScreen
        visible: myBackend.visibleWelcomeScreen
        anchors.fill: parent
    }

    PlayerScreen {
        id: playerMenuScreen
        visible: myBackend.visiblePlayerScreen
        anchors.fill: parent
    }

    InGameScreen {
        id: inGameScreen
        visible: myBackend.visibleIngameScreen
        anchors.fill: parent
    }
}



