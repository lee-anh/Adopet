QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
QT += core
QT += sql


#QT += multimedia
#QT += multimediawidgets


QT += network


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    findmatchforadopters.cpp \
    findmatchforpets.cpp \
    logout.cpp \
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
    myfavoritestwo.cpp \
    mypets.cpp \
    petadopted.cpp \
    petgallery.cpp \
    preferencesform.cpp \
    quiz.cpp \
    tagguide.cpp \
    takequiz.cpp \
    unsavepet.cpp \
    userinfo.cpp \
    ../Authentication/authentication.cpp \
    ../Owner/owner.cpp \
    videoplayer.cpp \
    zip.cpp


HEADERS += \
    findmatchforadopters.h \
    findmatchforpets.h \
    gui.h \
    ../DBSearch/dbsearch.h \
    ../Pets/pet.h \
    ../SavedList/savedlist.h \
    ../Matchmaking/matchmaking.h \
    ../Adopter/adopter.h \
    ../Adopter/preferences.h \
    logout.h \
    manualsearch.h \
    myfavorites.h \
    myfavoritestwo.h \
    mypets.h \
    petadopted.h \
    petgallery.h \
    preferencesform.h \
    quiz.h \
    tagguide.h \
    takequiz.h \
    unsavepet.h \
    userinfo.h \
    ../Authentication/authentication.h \
    ../Owner/owner.h \
    videoplayer.h \
    zip.h



FORMS += \
    findmatchforadopters.ui \
    findmatchforpets.ui \
    gui.ui \
    logout.ui \
    manualsearch.ui \
    myfavorites.ui \
    myfavoritestwo.ui \
    mypets.ui \
    petadopted.ui \
    preferencesform.ui \
    quiz.ui \
    tagguide.ui \
    takequiz.ui \
    unsavepet.ui \
    userinfo.ui \
    videoplayer.ui \
    zip.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
