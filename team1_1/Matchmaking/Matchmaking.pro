TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle

QT += core
QT += sql
QT += network

SOURCES += \
        main.cpp \
        matchmaking.cpp \
        ../Adopter/preferences.cpp \
        ../Adopter/adopter.cpp \
        ../Pets/pet.cpp \
        ../Owner/owner.cpp

HEADERS += \
    matchmaking.h \
    ../Adopter/preferences.h \
    ../Adopter/adopter.h \
    ../Pets/pet.h \
    ../Owner/owner.h

