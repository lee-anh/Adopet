TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle

QT += core
QT += sql



SOURCES += main.cpp

LIBS += -pthread
SOURCES += ../../gtest/googletest/src/gtest-all.cc

INCLUDEPATH += ../../gtest \
 ../../gtest/googletest \
 ../../gtest/googletest/include \
 ../../gtest/googletest/include/gtest

HEADERS += ../SavedList/savedlist.h
SOURCES += ../SavedList/savedlist.cpp

HEADERS += ../Pets/pet.h
SOURCES += ../Pets/pet.cpp
