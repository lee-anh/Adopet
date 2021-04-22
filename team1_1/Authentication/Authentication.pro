TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle

QT += core
QT += sql

SOURCES += \
        authentication.cpp \
        main.cpp \
        ../Adopter/adopter.cpp \
        ../Adopter/preferences.cpp \
        ../Owner/owner.cpp \
        ../Pets/pet.cpp


HEADERS += \
    authentication.h \
    ../Adopter/adopter.h \
    ../Adopter/preferences.h \
    ../Owner/owner.h \
    ../Pets/pet.h
