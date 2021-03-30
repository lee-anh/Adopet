TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle

QT += core
QT += sql

SOURCES += \
        main.cpp \
        matchmaking.cpp \
        ../Adopter/preferences.cpp

HEADERS += \
    matchmaking.h \
    ../Adopter/preferences.h
