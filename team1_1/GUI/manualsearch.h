#ifndef MANUALSEARCH_H
#define MANUALSEARCH_H

#include <QWidget>
#include <QtSql>
#include <vector>

#include "../DBSearch/dbsearch.h"
#include "../Pets/pet.h"
#include "../SavedList/savedlist.h"

#include "petgallery.h"
#include "zip.h"


namespace Ui {
class ManualSearch;
}

/*!
 * \brief The ManualSearch class allows adopters to search for pets
 * using user specified parameters
 */
class ManualSearch : public QWidget
{
    Q_OBJECT

public:
    /*!
     * \brief ManualSearch constructor
     * \param parent
     */
    explicit ManualSearch(QWidget *parent = nullptr);
    ~ManualSearch();

    /*!
     * \brief setSavedList sets up instance variables
     * basically needs to be called when a constructor is called
     * \param s
     * \param zipcode
     */
    void setSavedList(SavedList s, string zipcode);

private:
    Ui::ManualSearch *ui;
    DBSearch *search;
    PetGallery petgal;
    SavedList sl;
    Zip zp;

    /*!
     * \brief galleryMode set up for gallery mode
     */
    void galleryMode();

    /*!
     * \brief listMode set up for list mode
     */
    void listMode();

    string mode;
    string zip;

    /*!
     * \brief checkBoxSearch search used by all the checkboxes
     * \param wordToSearch attribute
     * \param category of wordToSearch
     * \param arg1 0 = remove, 2 = add
     */
    void checkBoxSearch(string wordToSearch, string category, int arg1);

    /*!
     * \brief clearCheckBoxes clear all the checkboxes
     */
    void clearCheckBoxes();

    /*!
     * \brief loadSaveButtons load the save buttons
     * \param saveButtons list of saveButtons
     */
    void loadSaveButtons(vector<QPushButton *> saveButtons);

    /*!
     * \brief saveButton handles different saveButton changes
     * \param saveButton the button object
     * \param index which pet
     */
    void saveButton(QPushButton* saveButton, int index);

    /*!
     * \brief APICall call the api
     * \param distance in miles
     */
    void APICall(string distance);

private slots:

    /*!
     * \brief finishedAPICall process the api's output
     */
    void finishedAPICall();

    //search
    /*!
     * \brief on_searchButton_clicked query the database with a custom string
     */
    void on_searchButton_clicked();

    /*!
     * \brief on_searchBar_returnPressed acts the same as search button clicked
     */
    void on_searchBar_returnPressed();

    /*!
     * \brief on_surpriseMe_clicked randomizes the results
     */
    void on_surpriseMe_clicked();

    /*!
     * \brief on_viewModeComboBox_currentIndexChanged
     * change the view mode
     * \param index 1 = gallery, 2 = list
     */
    void on_viewModeComboBox_currentIndexChanged(int index);

    /*!
     * \brief on_location_currentIndexChanged
     * change the location mode
     * \param index 1 = 20 miles,  2= 50 miles
     */
    void on_location_currentIndexChanged(int index);

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

    //links
    void on_link1_clicked();
    void on_link2_clicked();
    void on_link3_clicked();

    void on_save1_clicked();
    void on_save2_clicked();
    void on_save3_clicked();



    //list mode


    void on_nexta_clicked();
    void on_previousa_clicked();

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
