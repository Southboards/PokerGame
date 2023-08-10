import QtQuick 2.0
import QtQuick.Controls 2.0
import game.Backend 1.0

Item {
    Image {
        id: imageBackgound
        source: "qrc:/image/background.jpg"
        height: root.height
        width: root.width
        opacity: 0.5
        anchors.centerIn: parent
    }

    Text {
        id: welcomeText
        x: parent.width/2 - welcomeText.width/2
        y: 60
        color: "blue"
        text: "Welcome to Poker Champion League"
        font.pixelSize: 30
    }

    Column {
        id: loginText
        anchors.horizontalCenter: parent.horizontalCenter
        y: welcomeText.y + 100
        spacing: 15

        Row {
            spacing: 10

            Text {
                id: userNameText
                anchors.verticalCenter: parent.verticalCenter
                color: "black"
                text: "Username: "
                font.pixelSize: 20
            }

            TextField {
                id: userNameInput
                anchors.verticalCenter: parent.verticalCenter
                placeholderText: "username"
                font.pixelSize: 15
            }
        }

        Row {
            spacing: 10

            Text {
                id: passwordText
                color: "black"
                text: " Password: "
                font.pixelSize: 20
                anchors.verticalCenter: parent.verticalCenter
            }

            TextField {
                id: passwordInput
                placeholderText: "password"
                font.pixelSize: 15
                anchors.verticalCenter: parent.verticalCenter
                echoMode: TextInput.Password
            }
        }

        Text {
            id: statusLogin
            text: statusText.text
            color: "red"
            font.pixelSize: 13
            x: parent.width/2 - width/2
            y: parent.height/2
        }

        Button {
            id: signInButton
            text: "Sign In"
            x: parent.width/2 - width/2
            y: parent.height/2 + 60
            width: 120
            height: 40
            onClicked: myBackend.Process_EI_Button_Login(userNameInput.text, passwordInput.text)
        }

        Button {
            id: signUpButton
            text: "Sign Up"
            x: parent.width/2 - width/2
            y: parent.height/2 + 120
            width: 120
            height: 40
            onClicked: myBackend.Process_EI_Button_Register(userNameInput.text, passwordInput.text)
        }
    }
}
