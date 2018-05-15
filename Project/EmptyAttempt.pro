#-------------------------------------------------
#
# Project created by QtCreator 2018-04-22T21:42:57
#
#-------------------------------------------------

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EmptyAttempt
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        menu.cpp \
    gameplay.cpp \
    ball.cpp \
    balldown.cpp \
    board.cpp \
    ia.cpp \
    move.cpp \
    secondmenu.cpp \
    thirdmenu.cpp \
    infos.cpp

HEADERS += \
        menu.h \
    gameplay.h \
    ball.h \
    balldown.h \
    board.h \
    ia.h \
    move.h \
    ball.h \
    ball.h \
    secondmenu.h \
    thirdmenu.h \
    infos.h

FORMS += \
        menu.ui \
    gameplay.ui \
    secondmenu.ui \
    secondmenu.ui \
    thirdmenu.ui \
    infos.ui

RESOURCES += \
    ressource.qrc
