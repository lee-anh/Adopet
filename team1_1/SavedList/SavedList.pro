TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle

QT += core
QT += sql

SOURCES += \
        main.cpp \
        savedlist.cpp

HEADERS += \
    savedlist.h

HEADERS += ../Pets/pet.h
SOURCES += ../Pets/pet.cpp
