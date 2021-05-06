#ifndef QUIZ_H
#define QUIZ_H

#include <QWidget>
#include "../Adopter/preferences.h"

namespace Ui {
class Quiz;
}

class Quiz : public QWidget
{
    Q_OBJECT

public:
    explicit Quiz(QWidget *parent = nullptr);
    ~Quiz();
    void displayQuiz();
    void startQuiz();

private slots:
    void on_nextpage_clicked();
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


signals:
    void backToPreference(Preferences p);

private:
    Ui::Quiz *ui;
    int currentPageNum;
    Preferences *pref;

    void speciesCheckbox(string s, int arg1);
    void breedsCheckbox(string s, int arg1);
};

#endif // QUIZ_H
