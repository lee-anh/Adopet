QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
QT += core
QT += sql

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    findmatchforadopters.cpp \
    main.cpp \
    gui.cpp \
    ../DBSearch/dbsearch.cpp \
    ../Pets/pet.cpp \
    ../SavedList/savedlist.cpp \
    ../Matchmaking/matchmaking.cpp \
    ../Adopter/adopter.cpp \
    ../Adopter/preferences.cpp \
    manualsearch.cpp \
    myfavorites.cpp \
    petgallery.cpp \
    preferencesform.cpp \
    userinfo.cpp



HEADERS += \
    findmatchforadopters.h \
    gui.h \
    ../DBSearch/dbsearch.h \
    ../Pets/pet.h \
    ../SavedList/savedlist.h \
    ../Matchmaking/matchmaking.h \
    ../Adopter/adopter.h \
    ../Adopter/preferences.h \
    manualsearch.h \
    myfavorites.h \
    petgallery.h \
    preferencesform.h \
    userinfo.h


FORMS += \
    findmatchforadopters.ui \
    gui.ui \
    manualsearch.ui \
    myfavorites.ui \
    preferencesform.ui \
    userinfo.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
