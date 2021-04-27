TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle

QT += core
QT += sql


QMAKE_CXXFLAGS += --coverage
QMAKE_LFLAGS += --coverage


SOURCES += main.cpp

LIBS += -pthread
SOURCES += ../../gtest/googletest/src/gtest-all.cc

INCLUDEPATH += ../../gtest \
 ../../gtest/googletest \
 ../../gtest/googletest/include \
 ../../gtest/googletest/include/gtest

HEADERS += ../Authentication/authentication.h \
        authentication.h \
        ../Adopter/adopter.h \
        ../Adopter/preferences.h \
        ../Owner/owner.h \
        ../Pets/pet.h

SOURCES += ../Authentication/authentication.cpp \
        ../Adopter/adopter.cpp \
        ../Adopter/preferences.cpp \
        ../Owner/owner.cpp \
        ../Pets/pet.cpp
