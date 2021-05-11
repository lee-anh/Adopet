#ifndef GUI_H
#define GUI_H

#include <QWidget>
#include <QLabel>
#include <QtSql>
#include <vector>

//#include <QMediaPlayer>
//#include <QVideoWidget>

//classes that we need
#include "../DBSearch/dbsearch.h"
#include "../Pets/pet.h"
#include "../SavedList/savedlist.h"
#include "../Matchmaking/matchmaking.h"
#include "../Authentication/authentication.h"
#include "petgallery.h"

//other UI pages
#include "manualsearch.h"
#include "myfavorites.h"
#include "myfavoritestwo.h"
#include "findmatchforadopters.h"
#include "userinfo.h"
#include "preferencesform.h"
#include "mypets.h"
#include "quiz.h"
#include "findmatchforpets.h"
//#include "videoplayer.h"
#include "zip.h"

//QDialogs
#include "logout.h"
#include "unsavepet.h"



QT_BEGIN_NAMESPACE
namespace Ui { class GUI; }
QT_END_NAMESPACE

class GUI : public QWidget
{
    Q_OBJECT

public:
    GUI(QWidget *parent = nullptr);
    ~GUI();


private:
    Ui::GUI *ui;
    QSqlDatabase db;



    SavedList savedList;
    Authentication auth;
    Adopter *adopter;
    Owner *owner;

    //other UI pages
    ManualSearch manSearch;
    MyFavorites myFavs;
    FindMatchForAdopters fmForAdopters;
    UserInfo uinfo;
    PreferencesForm pform;
    MyPets myPets;
    MyFavoritesTwo myFavsList;
    Quiz qz;
    FindMatchForPets fmForPets;
    Zip zp;
    //VideoPlayer *vp;

    //QDialogs
    Logout lg;
    UnsavePet unsave;


    string userType;
    string username;
    string dbName;

    void meetPet(Pet p);
    void displayPicture(int i);
    int mediaCarosel;

    Pet petToMeet;
    int previousPage;

    void hideNavAdopter();
    void showNavAdopter();

    void hideNavOwner();
    void showNavOwner();

    void showHomeOwner();







private slots:

    //slots to receive signals
    void moveToMeetMe(Pet sendPet, bool b);
    void heartPet(Pet p, bool b);
    void backToLogin();
    void updateAdopter(Adopter *a);
    void toListMyFavorites();
    void toGalleryMyFavorites();
    void logOut();
    void goToQuiz();
    void unheartPet();
    void goToMeetMe(Pet p);
    void quizToPreference(Preferences pf);



    //save Button
    void on_saveButton_clicked();

    //navigation slots


    //adopter navigation

        //nav bar
    void on_navHomeButton_clicked();
    void on_navFindMatchButton_clicked();
    void on_navMyFavoritesButton_clicked();
    void on_navManualSearchButton_clicked();
    void on_navMyInfoButton_clicked();
    void on_navMyPreferences_clicked();
    void on_exit_clicked();

        //from home
    void on_findMatchFromHome_clicked();
    void on_manualSearchFromHome_clicked();
    void on_myFavoritesFromHome_clicked();
    void on_preferenceFromHome_clicked();

    //owner navigation
        //nav bar


        //from home

    //common navigation elements
    void on_backButton_clicked();
    void on_loginButton_clicked();
    void on_createAccountButton_clicked();

    void on_ownerMyPets_clicked();
    void on_ownerLogout_clicked();
    void on_ownerUploadPet_clicked();
    void on_ownerMyInfo_clicked();
    void on_ownerFindMatch_clicked();
    void on_ownerHome_clicked();
    void on_right_clicked();
    void on_left_clicked();
    void on_navHelpButton_clicked();
    void on_ownerHelp_clicked();
    void on_password_returnPressed();
    void on_pushButton_clicked();
};
#endif // GUI_H
