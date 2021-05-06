#include "preferencesform.h"
#include "ui_preferencesform.h"


/*!
 * \brief PreferencesForm constructor
 * \param parent
 */
PreferencesForm::PreferencesForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PreferencesForm)
{
    ui->setupUi(this);

    fillCheckBoxVec();
    toAdd = vector<pair<string, string>>();
    toRemove = vector<pair<string, string>>();

    connect(&tq, SIGNAL(takeQuiz()), this, SLOT(goToQuiz()));

}

/*!
 * \brief PreferencesForm destructor
 */
PreferencesForm::~PreferencesForm()
{
    delete ui;
}



/*!
  * \brief setAdopter, set adopter object that the preferences
  * will belong to
  * \param a, pointer to adopter object
  */
void PreferencesForm::setAdopter(Adopter *a){
    adopter = a;

}

/*!
 * \brief loadPreferences, checks the right checkboxes
 */
void PreferencesForm::loadPreferences(){


    Preferences p = adopter->getPreferences();
    clearCheckBoxes();


    //species
    for(int i = 0; i < (int) p.getSpecies().size(); i ++){
        findInVec(p.getSpecies()[i]);
    }

    //age
    for(int i = 0; i < (int) p.getAge().size(); i ++){
        findInVec(p.getAge()[i]);
    }
   //gender
    for(int i = 0; i < (int) p.getGender().size(); i ++){
        findInVec(p.getGender()[i]);
    }

    for(int i = 0; i < (int) p.getSize().size(); i ++){
        findInVec(p.getSize()[i]);
    }

    //good with
    for(int i = 0; i < (int) p.getGoodWith().size(); i ++){
        findInVec(p.getGoodWith()[i]);
    }

    //temperament
    for(int i = 0; i < (int) p.getTemperament().size(); i ++){
        findInVec(p.getTemperament()[i]);
    }
    //shelter
    for(int i = 0; i < (int) p.getShelter().size(); i ++){
        findInVec(p.getShelter()[i]);
    }
    //breed
    for(int i = 0; i < (int) p.getBreed().size(); i ++){
        findInVec(p.getBreed()[i]);
    }

    on_saveButton_clicked(); //make sure everything is synced up

    ui->unsavedChangesLabel->clear();
    //cout << "loaded preferences" << endl;

}

/*!
 * \brief clearCheckBoxes, clears all preference checkboxes
 */
void PreferencesForm::clearCheckBoxes(){
    for (int i = 0; i < (int) cb.size(); i++){
        cb[i].second->setChecked(false);
    }
}

/*!
 * \brief fillCheckBoxVec, helper method to class methods
 * fills in a vector with strings and buttons to easily access those
 * checkboxes throughout the class
 */
void PreferencesForm::fillCheckBoxVec(){
    cb = vector<pair<string, QCheckBox*>>();
    cb.push_back(make_pair("dog", ui->dogCheckBox));
    cb.push_back(make_pair("cat", ui->catCheckBox));
    cb.push_back(make_pair("rabbit", ui->rabbitCheckBox));
    cb.push_back(make_pair("rodent", ui->rodentCheckBox));
    cb.push_back(make_pair("fish", ui->fishCheckBox));
    cb.push_back(make_pair("bird", ui->birdCheckBox));
    cb.push_back(make_pair("young", ui->youngCheckBox));
    cb.push_back(make_pair("adult", ui->adultCheckBox));
    cb.push_back(make_pair("senior", ui->seniorCheckBox));
    cb.push_back(make_pair("male", ui->maleCheckBox));
    cb.push_back(make_pair("female", ui->femaleCheckBox));
    cb.push_back(make_pair("small", ui->smallCheckBox));
    cb.push_back(make_pair("medium", ui->mediumCheckBox));
    cb.push_back(make_pair("large", ui->largeCheckBox));
    cb.push_back(make_pair("happy", ui->happyCheckBox));
    cb.push_back(make_pair("friendly", ui->friendlyCheckBox));
    cb.push_back(make_pair("introverted", ui->introvertedCheckBox));
    cb.push_back(make_pair("active", ui->activeCheckBox));
    cb.push_back(make_pair("vigilant", ui->vigilantCheckBox));
    cb.push_back(make_pair("best friends", ui->bestFriendsCheckBox));
    cb.push_back(make_pair("humane society", ui->humaneSocietyCheckBox));
    cb.push_back(make_pair("animal welfare league", ui->animalWelfareLeagueCheckBox));
    cb.push_back(make_pair("sporting", ui->sporting));
    cb.push_back(make_pair("hound", ui->hound));
    cb.push_back(make_pair("working", ui->working));
    cb.push_back(make_pair("terrier", ui->terrier));
    cb.push_back(make_pair("toy", ui->toy));
    cb.push_back(make_pair("non-sporting", ui->nonsporting));
    cb.push_back(make_pair("herding", ui->herding));
    cb.push_back(make_pair("siamese", ui->siamese));
    cb.push_back(make_pair("persian", ui->persian));
    cb.push_back(make_pair("maine coon", ui->maineCoon));
    cb.push_back(make_pair("ragdoll", ui->ragdoll));
    cb.push_back(make_pair("rex", ui->rex));
    cb.push_back(make_pair("lionhead", ui->lionhead));
    cb.push_back(make_pair("californian", ui->californian));
    cb.push_back(make_pair("angora", ui->angora));
    cb.push_back(make_pair("silver fox", ui->silverFox));
    cb.push_back(make_pair("hamster", ui->hamster));
    cb.push_back(make_pair("gerbil", ui->gerbil));
    cb.push_back(make_pair("mouse", ui->mouse));
    cb.push_back(make_pair("rat", ui->rat));
    cb.push_back(make_pair("freshwater", ui->freshwater));
    cb.push_back(make_pair("saltwater", ui->saltwater));
    cb.push_back(make_pair("parakeet", ui->parakeet));
    cb.push_back(make_pair("lovebird", ui->lovebird));
    cb.push_back(make_pair("parrot", ui->lovebird));
    cb.push_back(make_pair("kids", ui->kidsCheckBox));
    cb.push_back(make_pair("animals", ui->animalsCheckBox));

}


/*!
 * \brief findInVec, checks corresponding checkbox given attribute
 * \param attribute, attribute to find and check off
 */
void PreferencesForm::findInVec(string attribute){
    for(int i = 0; i < (int) cb.size(); i++){
        if(attribute == cb[i].first){
            cb[i].second->setChecked(true);
        }
    }

}

/*!
 * \brief checkBoxChange handles any checkbox state changes
 * \param attribute to change
 * \param category, attribute's category
 * \param arg1, 0 = unchecked, 1 = partially checked, 2 = checked
 */
void PreferencesForm::on_saveButton_clicked()
{

    //remove FIRST!!
    for(int i = 0; i < (int) toRemove.size(); i++){

        //then change
        adopter->removePreference(toRemove[i].first, toRemove[i].second);

    }

    //then add
    for(int i = 0; i < (int) toAdd.size(); i++){
        //prevent duplicates
        //CHANGE HERE
        adopter->removePreference(toAdd[i].first, toAdd[i].second);
        //CHANGE HERE
        adopter->addPreference(toAdd[i].first, toAdd[i].second);
    }


    //clear vectors
    toAdd.clear();
    toRemove.clear();

    ui->unsavedChangesLabel->clear();
    ui->savedLabel->setText("Your changes have been saved");

    emit adopterChanged(adopter);
}



/*!
 * \brief checkBoxChange handles any checkbox state changes
 * \param attribute, new attribute
 * \param category, attribute's category
 * \param arg1,  0 = unchecked, 1 = partially checked, 2 = checked
 */
void PreferencesForm::checkBoxChange(string attribute, string category, int arg1){

    // 0 unchecked
    // 1 partially checked
    // 2 checked


    if(arg1 == 2){
        toAdd.push_back(make_pair(attribute, category));
    } else if (arg1 == 0){
        toRemove.push_back(make_pair(attribute, category));
    }
    ui->savedLabel->clear();
    ui->unsavedChangesLabel->setText("You have unsaved changes!");

}


//CHECKBOXES
void PreferencesForm::on_dogCheckBox_stateChanged(int arg1){
    checkBoxChange("dog", "species", arg1);
}
void PreferencesForm::on_catCheckBox_stateChanged(int arg1){
    checkBoxChange("cat", "species", arg1);
}
void PreferencesForm::on_rabbitCheckBox_stateChanged(int arg1){
    checkBoxChange("rabbit","species", arg1);
}
void PreferencesForm::on_rodentCheckBox_stateChanged(int arg1){
    checkBoxChange("rodent", "species", arg1);
}
void PreferencesForm::on_fishCheckBox_stateChanged(int arg1){
    checkBoxChange("fish", "species", arg1);
}
void PreferencesForm::on_birdCheckBox_stateChanged(int arg1){
    checkBoxChange("bird", "species", arg1);
}
void PreferencesForm::on_youngCheckBox_stateChanged(int arg1){
    checkBoxChange("young", "age", arg1);
}
void PreferencesForm::on_adultCheckBox_stateChanged(int arg1){
    checkBoxChange("adult", "age", arg1);
}
void PreferencesForm::on_seniorCheckBox_stateChanged(int arg1){
    checkBoxChange("senior", "age", arg1);
}
void PreferencesForm::on_maleCheckBox_stateChanged(int arg1){
    checkBoxChange("male", "gender", arg1);
}
void PreferencesForm::on_femaleCheckBox_stateChanged(int arg1){
    checkBoxChange("female", "gender", arg1);
}
void PreferencesForm::on_smallCheckBox_stateChanged(int arg1){
    checkBoxChange("small", "size", arg1);
}
void PreferencesForm::on_mediumCheckBox_stateChanged(int arg1){
    checkBoxChange("medium", "size", arg1);
}
void PreferencesForm::on_largeCheckBox_stateChanged(int arg1){
    checkBoxChange("large", "size", arg1);
}
void PreferencesForm::on_kidsCheckBox_stateChanged(int arg1){
    checkBoxChange("kids", "goodWith", arg1);
}
void PreferencesForm::on_animalsCheckBox_stateChanged(int arg1){
    checkBoxChange("animals", "goodWith", arg1);
}
void PreferencesForm::on_happyCheckBox_stateChanged(int arg1){
    checkBoxChange("happy", "temperament", arg1);
}
void PreferencesForm::on_friendlyCheckBox_stateChanged(int arg1){
    checkBoxChange("friendly", "temperament", arg1);
}
void PreferencesForm::on_introvertedCheckBox_stateChanged(int arg1){
    checkBoxChange("introverted", "temperament", arg1);
}
void PreferencesForm::on_activeCheckBox_stateChanged(int arg1){
    checkBoxChange("active", "temperament", arg1);
}
void PreferencesForm::on_vigilantCheckBox_stateChanged(int arg1){
    checkBoxChange("vigilant", "temperament", arg1);
}
void PreferencesForm::on_bestFriendsCheckBox_stateChanged(int arg1){
    checkBoxChange("best friends", "shelter", arg1);
}
void PreferencesForm::on_humaneSocietyCheckBox_stateChanged(int arg1){
    checkBoxChange("humane society", "shelter", arg1);
}
void PreferencesForm::on_animalWelfareLeagueCheckBox_stateChanged(int arg1){
    checkBoxChange("animal welfare league", "shelter", arg1);
}
void PreferencesForm::on_sporting_stateChanged(int arg1){
    checkBoxChange("sporting", "breed", arg1);
}
void PreferencesForm::on_hound_stateChanged(int arg1){
    checkBoxChange("hound", "breed", arg1);
}
void PreferencesForm::on_working_stateChanged(int arg1){
    checkBoxChange("working", "breed", arg1);
}
void PreferencesForm::on_terrier_stateChanged(int arg1){
    checkBoxChange("terrier", "breed", arg1);
}
void PreferencesForm::on_toy_stateChanged(int arg1){
    checkBoxChange("toy", "breed", arg1);
}
void PreferencesForm::on_nonsporting_stateChanged(int arg1){
    checkBoxChange("non-sporting", "breed", arg1);
}
void PreferencesForm::on_herding_stateChanged(int arg1){
    checkBoxChange("herding", "breed", arg1);
}
void PreferencesForm::on_siamese_stateChanged(int arg1){
    checkBoxChange("siamese", "breed", arg1);
}
void PreferencesForm::on_persian_stateChanged(int arg1){
    checkBoxChange("persian", "breed", arg1);
}
void PreferencesForm::on_maineCoon_stateChanged(int arg1){
    checkBoxChange("maine coon", "breed", arg1);
}
void PreferencesForm::on_ragdoll_stateChanged(int arg1){
    checkBoxChange("ragdoll", "breed", arg1);
}
void PreferencesForm::on_rex_stateChanged(int arg1){
    checkBoxChange("rex", "breed", arg1);
}
void PreferencesForm::on_lionhead_stateChanged(int arg1){
    checkBoxChange("lionhead", "breed", arg1);
}
void PreferencesForm::on_californian_stateChanged(int arg1){
    checkBoxChange("californian", "breed", arg1);
}
void PreferencesForm::on_angora_stateChanged(int arg1){
    checkBoxChange("angora", "breed", arg1);
}
void PreferencesForm::on_silverFox_stateChanged(int arg1){
    checkBoxChange("silverFox", "breed", arg1);
}
void PreferencesForm::on_hamster_stateChanged(int arg1){
    checkBoxChange("hamster", "breed", arg1);
}
void PreferencesForm::on_guineaPig_stateChanged(int arg1){
    checkBoxChange("guinea pig", "breed", arg1);
}
void PreferencesForm::on_gerbil_stateChanged(int arg1){
    checkBoxChange("gerbil", "breed", arg1);
}
void PreferencesForm::on_mouse_stateChanged(int arg1){
    checkBoxChange("mouse", "breed", arg1);
}
void PreferencesForm::on_rat_stateChanged(int arg1){
    checkBoxChange("rat", "breed", arg1);
}
void PreferencesForm::on_freshwater_stateChanged(int arg1){
    checkBoxChange("freshwater", "breed", arg1);
}
void PreferencesForm::on_saltwater_stateChanged(int arg1){
    checkBoxChange("saltwater", "breed", arg1);
}
void PreferencesForm::on_parakeet_stateChanged(int arg1){
    checkBoxChange("parakeet", "breed", arg1);
}
void PreferencesForm::on_lovebird_stateChanged(int arg1){
    checkBoxChange("lovebird", "breed", arg1);
}
void PreferencesForm::on_parrot_stateChanged(int arg1){
    checkBoxChange("parrot", "breed", arg1);
}



void PreferencesForm::on_goToQuiz_clicked()
{

    tq.setModal(true);
    tq.exec();

}

void PreferencesForm::on_clearAll_clicked()
{
    clearCheckBoxes();
}
void PreferencesForm::goToQuiz(){
    emit toQuiz();
}
