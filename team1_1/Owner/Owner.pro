TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle

QT += core
QT += sql

SOURCES += main.cpp \
    owner.cpp \
    ../Pets/pet.cpp

HEADERS += \
    owner.h \
    ../Pets/pet.h

