TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle

QT += core
QT += sql
QT += network

SOURCES += \
        dbsearch.cpp \
        main.cpp \
        ../Pets/pet.cpp \
        ../Owner/owner.cpp

HEADERS += \
    dbsearch.h \
    ../Pets/pet.h \
    ../Owner/owner.h
