QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = "Sword Battle"
TEMPLATE = app

QMAKE_TARGET_COMPANY = CoolONE Inc.
QMAKE_TARGET_PRODUCT = Sword Battle
QMAKE_TARGET_DESCRIPTION = Sword Battle Game
QMAKE_TARGET_COPYRIGHT = Nickolay Trukhin

SOURCES += main.cpp\
        widget.cpp \
    drawmain.cpp \
    drawgame.cpp \
    clickbuttons.cpp \
    button.cpp \
    keypress.cpp \
    buttonprogress.cpp \
    animation.cpp \
    animationcoords.cpp \
    setAnimations.cpp \
    sword.cpp \
    icon.cpp

HEADERS  += widget.h \
    button.h \
    buttonprogress.h \
    animation.h \
    animationcoords.h \
    sword.h \
    icon.h

FORMS    += widget.ui

QT += multimedia

RC_ICONS = icon.ico

RESOURCES +=
