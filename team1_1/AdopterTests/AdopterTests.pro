TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle

QT += core
QT += sql
QT += network

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



HEADERS += ../Adopter/adopter.h \
           ../Adopter/preferences.h

SOURCES += ../Adopter/adopter.cpp \
           ../Adopter/preferences.cpp
