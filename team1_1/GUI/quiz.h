#ifndef QUIZ_H
#define QUIZ_H

#include <QWidget>
#include "../Adopter/preferences.h"

namespace Ui {
class Quiz;
}

/*!
 * \brief The Quiz class is the gui for the preferences quzi
 */
class Quiz : public QWidget
{
    Q_OBJECT

public:
    /*!
     * \brief Quiz Constructor
     * \param parent
     */
    explicit Quiz(QWidget *parent = nullptr);
    ~Quiz();

    /*!
     * \brief startQuiz gui setup for quiz elements
     */
    void startQuiz();

    /*!
     * \brief displayQuiz manages the buttons for quiz navigation
     */
    void displayQuiz();

private:
    Ui::Quiz *ui;
    int currentPageNum;
    int lastPage;
    Preferences *pref;

    QWidget *dog;
    QWidget *cat;
    QWidget *rabbit;
    QWidget *rodent;
    QWidget *fish;
    QWidget *bird;

    /*!
     * \brief speciesCheckbox
     * \param s the species name
     * \param arg1 0 = unchecked, 2 = checked
     */
    void speciesCheckbox(string s, int arg1);

    /*!
     * \brief breedsCheckbox
     * \param s the breed name
     * \param arg1 0 = unchecked, 2 = checked
     */
    void breedsCheckbox(string s, int arg1);

    /*!
     * \brief breedRadio
     * \param s breed
     * \param b
     */
    void breedRadio(string s, bool b);
private slots:
    /*!
     * \brief on_nextpage_clicked advance the quiz
     */
    void on_nextpage_clicked();

    /*!
     * \brief on_previouspage_clicked go back on the quiz
     */
    void on_previouspage_clicked();

    void on_finishquiz_clicked();

    void on_activeYes_toggled(bool checked);
    void on_activeNo_toggled(bool checked);

    void on_friendly_toggled(bool checked);
    void on_friendlyORIntroverted_toggled(bool checked);
    void on_introverted_toggled(bool checked);

    void on_happy_toggled(bool checked);
    void on_vigilant_toggled(bool checked);
    void on_happyOrVigilant_toggled(bool checked);

    void on_young_toggled(bool checked);
    void on_adult_toggled(bool checked);
    void on_old_toggled(bool checked);
    void on_noage_toggled(bool checked);

    void on_male_toggled(bool checked);
    void on_female_toggled(bool checked);
    void on_maleOrFemale_toggled(bool checked);

    void on_bestFriends_toggled(bool checked);
    void on_humaneSociety_toggled(bool checked);
    void on_animalWelfareLeague_toggled(bool checked);
    void on_anyShelter_toggled(bool checked);

    void on_animalsYes_toggled(bool checked);
    void on_animalsNo_toggled(bool checked);

    void on_childrenYes_toggled(bool checked);
    void on_childrenNo_toggled(bool checked);

    void on_dogCheckBox_stateChanged(int arg1);
    void on_catCheckBox_stateChanged(int arg1);
    void on_rabbitCheckBox_stateChanged(int arg1);
    void on_rodentCheckBox_stateChanged(int arg1);
    void on_birdCheckBox_stateChanged(int arg1);
    void on_fishCheckBox_stateChanged(int arg1);


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


    void on_toyDog_toggled(bool checked);

    void on_workingDog_toggled(bool checked);

    void on_nonsportingDog_toggled(bool checked);

    void on_terrierDog_toggled(bool checked);

    void on_houndDog_toggled(bool checked);

    void on_sportingDog_toggled(bool checked);

    void on_herdingDogs_toggled(bool checked);

    void on_lionHeadCaliRabbit_toggled(bool checked);

    void on_angoraRabbit_toggled(bool checked);

    void on_silverFoxRabbit_toggled(bool checked);

    void on_mouseRodent_toggled(bool checked);

    void on_ratRodent_toggled(bool checked);

    void on_guineaPigRodent_toggled(bool checked);

    void on_hamsterRodent_toggled(bool checked);

    void on_gerbilRodent_toggled(bool checked);

    void on_parakeetBird_toggled(bool checked);

    void on_lovebirdBird_toggled(bool checked);

    void on_parrotBird_toggled(bool checked);

    void on_saltwaterFish_toggled(bool checked);

    void on_freshwaterFish_toggled(bool checked);

signals:
    void backToPreference(Preferences p);


};

#endif // QUIZ_H
