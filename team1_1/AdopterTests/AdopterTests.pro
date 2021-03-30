TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle

SOURCES += \
        main.cpp

LIBS += -pthread
SOURCES += ../../gtest/googletest/src/gtest-all.cc

INCLUDEPATH += ../../gtest \
 ../../gtest/googletest \
 ../../gtest/googletest/include \
 ../../gtest/googletest/include/gtest



HEADERS += ../Adopter/adopter.h \
           ../Adopter/preferences.h

SOURCES += ../Adopter/adopter.cpp \
           ../Adopter/preferences.cpp
