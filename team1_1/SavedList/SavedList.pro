TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle

QT += sql
QT += core

SOURCES += \
        main.cpp \
        savedlist.cpp

HEADERS += \
    savedlist.h

HEADERS += ../Pets/pet.h
SOURCES += ../Pets/pet.cpp
