TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle

QT += core
QT += sql


QMAKE_CXXFLAGS += --coverage
QMAKE_LFLAGS += --coverage


SOURCES += main.cpp

LIBS += -pthread
!macx{
    LIBS += -lgcov
}

SOURCES += ../../gtest/googletest/src/gtest-all.cc

INCLUDEPATH += ../../gtest \
 ../../gtest/googletest \
 ../../gtest/googletest/include \
 ../../gtest/googletest/include/gtest

HEADERS += \
    ../Matchmaking/matchmaking.h \
    ../Adopter/preferences.h \
    ../Adopter/adopter.h \
    ../Pets/pet.h

SOURCES += \
        ../Matchmaking/matchmaking.cpp \
        ../Adopter/preferences.cpp \
        ../Adopter/adopter.cpp \
        ../Pets/pet.cpp
