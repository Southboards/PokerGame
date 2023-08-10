QT += quick

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        Sources/Controller/controller.cpp \
        Sources/Model/databases.cpp \
        Sources/Model/check_valid.cpp \
        Sources/Model/player.cpp \
        Sources/Model/card.cpp \
        Sources/Model/three_cards.cpp \
        Sources/Model/card_game.cpp \
        Sources/Model/poker.cpp \
        Sources/main.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    Headers/Controller/controller.h \
    Headers/Model/three_cards.h \
    Headers/Model/card.h \
    Headers/Model/card_game.h \
    Headers/Model/databases.h \
    Headers/Model/check_valid.h \
    Headers/Model/poker.h \
    Headers/Model/player.h



