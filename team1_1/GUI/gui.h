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
#include "videoplayer.h"
#include "zip.h"

//QDialogs
#include "logout.h"
#include "unsavepet.h"



QT_BEGIN_NAMESPACE
namespace Ui { class GUI; }
QT_END_NAMESPACE

/*!
 * \brief The GUI class is the main class for Adopet's front end system
 */
class GUI : public QWidget
{
    Q_OBJECT

public:
    /*!
     * \brief GUI constructor
     * \param parent
     */
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

    /*!
     * \brief meetPet displays more info about a pet, bio info
     * \param p
     */
    void meetPet(Pet p);

    /*!
     * \brief displayPicture, displays the pictures for a pet
     * \param i
     */
    void displayPicture(int i);
    int mediaCarosel;

    Pet petToMeet;
    int previousPage;

    /*!
     * \brief hideNavAdopter hide adopter's navigation bar
     */
    void hideNavAdopter();

    /*!
     * \brief showNavAdopter show adopter's navigation bar
     */
    void showNavAdopter();

    /*!
     * \brief hideNavOwner hide the owner's navigation bar
     */
    void hideNavOwner();

    /*!
     * \brief showNavOwner shows the owner's navigation bar
     */
    void showNavOwner();


private slots:



    //for the media carosel
    /*!
     * \brief on_right_clicked advance media carousel
     */
    void on_right_clicked();

    /*!
     * \brief on_left_clicked go back on media carousel
     */
    void on_left_clicked();

    //slots to receive signals

    /*!
     * \brief on_exit_clicked logout of system
     */
    void on_exit_clicked();
    /*!
     * \brief moveToMeetMe send user to meet me page
     * \param sendPet pet to display
     * \param b if the pet is saved or not
     */
    void moveToMeetMe(Pet sendPet, bool b);

    /*!
     * \brief heartPet heart info for a pet to meet
     * \param p pet
     * \param b if the pet is saved or not
     */
    void heartPet(Pet p, bool b);

    /*!
     * \brief backToLogin bring user back to login
     */
    void backToLogin();

    /*!
     * \brief updateAdopter object
     * \param a
     */
    void updateAdopter(Adopter *a);

    /*!
     * \brief toListMyFavorites to my favorites, list mode
     */
    void toListMyFavorites();

    /*!
     * \brief toGalleryMyFavorites to my favorites, gallery mode
     */
    void toGalleryMyFavorites();

    /*!
     * \brief logOut of system
     */
    void logOut();

    /*!
     * \brief goToQuiz (preference quiz)
     */
    void goToQuiz();

    /*!
     * \brief unheartPet unsave a pet
     */
    void unheartPet();

    /*!
     * \brief goToMeetMe for owners
     * \param p
     */
    void goToMeetMe(Pet p);

    /*!
     * \brief quizToPreference back to preference from quiz
     * \param pf
     */
    void quizToPreference(Preferences pf);



    //save Button

    /*!
     * \brief on_saveButton_clicked save a pet
     */
    void on_saveButton_clicked();

    //navigation slots
    //adopter navigation

        //nav bar
    /*!
     * \brief on_navHomeButton_clicked back to home page
     * for Adopters
     */
    void on_navHomeButton_clicked();

    /*!
     * \brief on_navFindMatchButton_clicked to Find Match page
     * for Adopters
     */
    void on_navFindMatchButton_clicked();

    /*!
     * \brief on_navMyFavoritesButton_clicked to My Favorites page
     * for Adopters
     */
    void on_navMyFavoritesButton_clicked();

    /*!
     * \brief on_navManualSearchButton_clicked to Manual Search page
     * for Adopters
     */
    void on_navManualSearchButton_clicked();

    /*!
     * \brief on_navMyInfoButton_clicked to My Info page
     * for Adopters
     */
    void on_navMyInfoButton_clicked();

    /*!
     * \brief on_navMyPreferences_clicked to My Preferences page
     * for Adopters
     */
    void on_navMyPreferences_clicked();

    /*!
     * \brief on_preferenceFromHome_clicked to my preferences page
     * for Adopters
     */
    void on_preferenceFromHome_clicked();

    /*!
     * \brief on_navHelpButton_clicked to help page
     * for Adopters
     */
    void on_navHelpButton_clicked();

        //from home
    /*!
     * \brief on_findMatchFromHome_clicked to find Match page
     * for Adopters
     */
    void on_findMatchFromHome_clicked();

    /*!
     * \brief on_manualSearchFromHome_clicked to manual search page
     * for Adopters
     */
    void on_manualSearchFromHome_clicked();

    /*!
     * \brief on_myFavoritesFromHome_clicked to my favorites page
     * for Adopters
     */
    void on_myFavoritesFromHome_clicked();


    //common navigation elements
    /*!
     * \brief on_backButton_clicked go back to previous page
     */
    void on_backButton_clicked();

    /*!
     * \brief on_loginButton_clicked login to system
     */
    void on_loginButton_clicked();

    /*!
     * \brief on_password_returnPressed login to system
     */
    void on_password_returnPressed();

    /*!
     * \brief on_createAccountButton_clicked to create account page
     */
    void on_createAccountButton_clicked();


    //owner navigation
        //nav bar

    /*!
     * \brief on_ownerMyPets_clicked to My Pets page
     * for Owners
     */
    void on_ownerMyPets_clicked();

    /*!
     * \brief on_ownerLogout_clicked logout of system
     * for Owners
     */
    void on_ownerLogout_clicked();

    /*!
     * \brief on_ownerUploadPet_clicked to upload pet page
     * for Owners
     */
    void on_ownerUploadPet_clicked();

    /*!
     * \brief on_ownerMyInfo_clicked to my info page
     * for Owners
     */
    void on_ownerMyInfo_clicked();

    /*!
     * \brief on_ownerFindMatch_clicked to find match page
     * for Owners
     */
    void on_ownerFindMatch_clicked();
    /*!
     * \brief on_ownerHome_clicked to home page
     * for Owners
     */
    void on_ownerHome_clicked();
    /*!
     * \brief on_ownerHelp_clicked to help page
     * for Owners
     */
    void on_ownerHelp_clicked();












};
#endif // GUI_H
