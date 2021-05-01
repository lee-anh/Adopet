TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle

QT += core
QT += sql
QT += network

SOURCES += \
        main.cpp \
        savedlist.cpp

HEADERS += \
    savedlist.h

HEADERS += ../Pets/pet.h
SOURCES += ../Pets/pet.cpp

HEADERS += ../Owner/owner.h
SOURCES += ../Owner/owner.cpp
