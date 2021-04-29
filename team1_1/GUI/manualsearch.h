#ifndef MANUALSEARCH_H
#define MANUALSEARCH_H

#include <QWidget>
#include <QtSql>
#include <vector>

#include "../DBSearch/dbsearch.h"
#include "../Pets/pet.h"
#include "../SavedList/savedlist.h"

#include "petgallery.h"


namespace Ui {
class ManualSearch;
}

class ManualSearch : public QWidget
{
    Q_OBJECT

public:
    explicit ManualSearch(QWidget *parent = nullptr);
    ~ManualSearch();

    void setSavedList(SavedList s);

private:
    Ui::ManualSearch *ui;
    DBSearch *search;
    PetGallery petgal;
    SavedList sl;
    void galleryMode();
    void listMode();

    string mode;

    void checkBoxSearch(string wordToSearch, string category, int arg1);
    void clearCheckBoxes();
    void loadSaveButtons(vector<QPushButton *> saveButtons);
    void saveButton(QPushButton* saveButton, int index);

private slots:
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


    //size
    void on_smallCheckBox_stateChanged(int arg1);
    void on_mediumCheckBox_stateChanged(int arg1);
    void on_largeCheckBox_stateChanged(int arg1);

    //goodWith
    void on_kidsCheckBox_stateChanged(int arg1);
    void on_animalsCheckBox_stateChanged(int arg1);

    //temperament
    void on_happyCheckBox_stateChanged(int arg1);
    void on_friendlyCheckBox_stateChanged(int arg1);
    void on_introvertedCheckBox_stateChanged(int arg1);
    void on_activeCheckBox_stateChanged(int arg1);
    void on_vigilantCheckBox_stateChanged(int arg1);

    //shelter
    void on_bestFriendsCheckBox_stateChanged(int arg1);
    void on_humaneSocietyCheckBox_stateChanged(int arg1);
    void on_animalWelfareLeagueCheckBox_stateChanged(int arg1);


    //previous/next
    void on_previous_clicked();
    void on_next_clicked();

    //search
    void on_searchButton_clicked();

    //links
    void on_link1_clicked();
    void on_link2_clicked();
    void on_link3_clicked();

    void on_save1_clicked();
    void on_save2_clicked();
    void on_save3_clicked();




    void on_surpriseMe_clicked();

    void on_viewModeComboBox_currentIndexChanged(int index);

    void on_nexta_clicked();

    void on_previousa_clicked();

    //list mode
    void on_link1a_clicked();
    void on_link2a_clicked();
    void on_link3a_clicked();
    void on_link4a_clicked();
    void on_link5a_clicked();
    void on_link6a_clicked();

    void on_save1a_clicked();
    void on_save2a_clicked();
    void on_save3a_clicked();
    void on_save4a_clicked();
    void on_save5a_clicked();
    void on_save6a_clicked();


signals:
    void learnMoreClicked(Pet sendPet);
    void learnMoreClicked(Pet sendPet, bool b);
    void heartClicked(Pet p, bool b);




};

#endif // MANUALSEARCH_H
