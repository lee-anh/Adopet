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


QT_BEGIN_NAMESPACE
namespace Ui { class GUI; }
QT_END_NAMESPACE

class GUI : public QWidget
{
    Q_OBJECT

public:
    GUI(QWidget *parent = nullptr);
    GUI(QSqlDatabase d, QWidget *parent = nullptr);
    ~GUI();

    //Ui::GUI *ui;

private:
    Ui::GUI *ui;
    DBSearch *search;
    SavedList *savedList;

    string currentUser;

    void displayPets(int start);
    void meetPet(Pet p);
    void clearLabels();
    void clearCheckBoxes();
    void checkBoxSearch(string wordToSearch, string category, int arg1);


    Pet displayedPet1;
    Pet displayedPet2;
    Pet displayedPet3;

    Pet petToMeet;

    int nextDisplayPetsStartIndex;
    int displayPetsPageNumber;
    int previousPage;

    vector<QLabel*> nameLabels;



private slots:
    void on_searchButton_clicked();

    //CHECKBOXES
    //species
    void on_dogCheckBox_stateChanged(int arg1);
    void on_catCheckBox_stateChanged(int arg1);
    void on_rabbitCheckBox_stateChanged(int arg1);
    void on_rodentCheckBox_stateChanged(int arg1);
    void on_fishCheckBox_stateChanged(int arg1);
    void on_birdCheckBox_stateChanged(int arg1);

    //age
    void on_youngCheckBox_stateChanged(int arg1);
    void on_adultCheckBox_stateChanged(int arg1);
    void on_seniorCheckBox_stateChanged(int arg1);

    //gender
    void on_maleCheckBox_stateChanged(int arg1);
    void on_femaleCheckBox_stateChanged(int arg1);


    //results
    void on_linkToResult1_clicked();
    void on_linkToResult2_clicked();
    void on_linkToResult3_clicked();
    void on_backButton_clicked();

    void on_loadNext_clicked();
    void on_loadPrevious_clicked();

    void on_saveButton_clicked();
    void on_exit_clicked();
    void on_navMyFavoritesButton_clicked();
    void on_hiButton_clicked();
};
#endif // GUI_H
