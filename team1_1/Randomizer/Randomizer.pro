TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle


QT += core
QT += sql
QT += network

SOURCES += \
        main.cpp \
        peoplerandomizer.cpp \
        petrandomizer.cpp

HEADERS += \
    peoplerandomizer.h \
    petrandomizer.h
