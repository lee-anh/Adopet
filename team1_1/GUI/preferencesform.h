#ifndef PREFERENCESFORM_H
#define PREFERENCESFORM_H

#include <QWidget>
#include <QCheckBox>


#include "../Adopter/adopter.h"
#include "takequiz.h"

namespace Ui {
class PreferencesForm;
}

/*!
 * \brief The PreferencesForm class creates a widget where adopters
 * can set their preferences
 */
class PreferencesForm : public QWidget
{
    Q_OBJECT

public:

    /*!
     * \brief PreferencesForm constructor
     * \param parent
     */
    explicit PreferencesForm(QWidget *parent = nullptr);
    /*!
     * \brief PreferencesForm destructor
     */
    ~PreferencesForm();


    /*!
      * \brief setAdopter, set adopter object that the preferences
      * will belong to
      * \param a
      */
     void setAdopter(Adopter *a);

     /*!
      * \brief loadPreferences, checks the right checkboxes
      */
     void loadPreferences();

     /*!
      * \brief clearCheckBoxes, clears all preference checkboxes
      */
     void clearCheckBoxes();

private:
    Ui::PreferencesForm *ui;
    Adopter *adopter;
    TakeQuiz tq;

    vector<pair<string, string>> toAdd;
    vector<pair<string, string>> toRemove;
    vector<pair<string, QCheckBox*>> cb;

    /*!
     * \brief fillCheckBoxVec, helper method to class methods
     */
    void fillCheckBoxVec();

    /*!
     * \brief findInVec, checks corresponding checkbox given attribute
     * \param attribute
     */
    void findInVec(string attribute);

    /*!
     * \brief checkBoxChange handles any checkbox state changes
     * \param attribute
     * \param category
     * \param arg1
     */
    void checkBoxChange(string attribute, string category, int arg1);



private slots:

    void on_saveButton_clicked();

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


    //breeds
        //dogs
    void on_sporting_stateChanged(int arg1);
    void on_hound_stateChanged(int arg1);
    void on_working_stateChanged(int arg1);
    void on_terrier_stateChanged(int arg1);
    void on_toy_stateChanged(int arg1);
    void on_nonsporting_stateChanged(int arg1);
    void on_herding_stateChanged(int arg1);
        //cats
    void on_siamese_stateChanged(int arg1);
    void on_persian_stateChanged(int arg1);
    void on_maineCoon_stateChanged(int arg1);
    void on_ragdoll_stateChanged(int arg1);
        //rabbits
    void on_rex_stateChanged(int arg1);
    void on_lionhead_stateChanged(int arg1);
    void on_californian_stateChanged(int arg1);
    void on_angora_stateChanged(int arg1);
    void on_silverFox_stateChanged(int arg1);
        //rodents
    void on_hamster_stateChanged(int arg1);
    void on_guineaPig_stateChanged(int arg1);
    void on_gerbil_stateChanged(int arg1);
    void on_mouse_stateChanged(int arg1);
    void on_rat_stateChanged(int arg1);
        //fish
    void on_freshwater_stateChanged(int arg1);
    void on_saltwater_stateChanged(int arg1);

        //birds
    void on_parakeet_stateChanged(int arg1);
    void on_lovebird_stateChanged(int arg1);
    void on_parrot_stateChanged(int arg1);


    void on_goToQuiz_clicked();

    void on_clearAll_clicked();

    void goToQuiz();

signals:
    void adopterChanged(Adopter *a);
    void toQuiz();

};


#endif // PREFERENCESFORM_H
