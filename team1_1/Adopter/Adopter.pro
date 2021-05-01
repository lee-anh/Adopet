TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle

QT+=core
QT+=sql
QT += network

SOURCES += \
        adopter.cpp \
        main.cpp \
        preferences.cpp

HEADERS += \
    adopter.h \
    preferences.h
