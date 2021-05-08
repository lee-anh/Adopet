TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle

QT += core
QT += sql
QT += network


SOURCES += \
        main.cpp \
        pet.cpp \
        ../Owner/owner.cpp

HEADERS += \
    pet.h \
    ../Owner/owner.h

