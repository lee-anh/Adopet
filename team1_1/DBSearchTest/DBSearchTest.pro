TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle

QT += core
QT += sql

QMAKE_CXXFLAGS += --coverage
QMAKE_LFLAGS += --coverage

SOURCES += main.cpp

LIBS += -pthread
LIBS += -lgcov
SOURCES += ../../gtest/googletest/src/gtest-all.cc

INCLUDEPATH += ../../gtest \
 ../../gtest/googletest \
 ../../gtest/googletest/include \
 ../../gtest/googletest/include/gtest

HEADERS += ../DBSearch/dbsearch.h
SOURCES += ../DBSearch/dbsearch.cpp

HEADERS += ../Pets/pet.h
SOURCES += ../Pets/pet.cpp