#ifndef GUI_H
#define GUI_H

#include <QWidget>
#include <QLabel>
#include <QtSql>
#include <vector>

#include "../DBSearch/dbsearch.h"
#include "../Pets/pet.h"
#include "../SavedList/savedlist.h"
#include "petgallery.h"

//other UI pages
#include "manualsearch.h"
#include "myfavorites.h"


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

    string currentUser;

    void meetPet(Pet p);


    Pet petToMeet;
    int previousPage;





private slots:

    void moveToMeetMe(Pet sendPet);

    void on_saveButton_clicked();
    void on_exit_clicked();


    void on_backButton_clicked();
    void on_navMyFavoritesButton_clicked();
    void on_navManualSearchButton_clicked();
};
#endif // GUI_H
