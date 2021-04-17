#ifndef GUI_H
#define GUI_H

#include <QWidget>
#include <QLabel>
#include <QtSql>
#include <vector>

//classes that we need
#include "../DBSearch/dbsearch.h"
#include "../Pets/pet.h"
#include "../SavedList/savedlist.h"
#include "../Matchmaking/matchmaking.h"
#include "petgallery.h"

//other UI pages
#include "manualsearch.h"
#include "myfavorites.h"
#include "findmatchforadopters.h"


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
    SavedList savedList;

    //other UI pages
    ManualSearch manSearch;
    MyFavorites myFavs;
    FindMatchForAdopters fmForAdopters;

    string currentUser;

    void meetPet(Pet p);
    Pet petToMeet;
    int previousPage;


private slots:

    //slots to receive signals
    void moveToMeetMe(Pet sendPet, bool b);
    void heartPet(Pet p, bool b);

    //save Button
    void on_saveButton_clicked();

    //navigation slots
    void on_exit_clicked();
    void on_backButton_clicked();
    void on_navHomeButton_clicked();
    void on_navFindMatchButton_clicked();
    void on_navMyFavoritesButton_clicked();
    void on_navManualSearchButton_clicked();
    void on_findMatchFromHome_clicked();
    void on_manualSearchFromHome_clicked();
    void on_myFavoritesFromHome_clicked();

};
#endif // GUI_H
