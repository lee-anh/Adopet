#include "manualsearch.h"
#include "ui_manualsearch.h"

ManualSearch::ManualSearch(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ManualSearch)
{
    ui->setupUi(this);
    search = new DBSearch("../../../../../projectDB.sqlite");
    //able to initalize petgal here b/c username doesn't matter
    petgal = PetGallery(3,ui->previous, ui->next, ui->pageLine, {ui->name1, ui->name2, ui->name3},
                        {ui->pic1, ui->pic2, ui->pic3},
                        {ui->link1, ui->link2, ui->link3},
                        {ui->save1, ui->save2, ui->save3},
                        search->getPetVec());

    //manual search doesn't display any results when the user starts
    //search->runNewQuery();
    petgal.updatePetVec(search->getPetVec());
    ui->pageLine->setText("Search for pets using search bar and checkboxes!");
    //petgal.displayPets(0);





}

ManualSearch::~ManualSearch()
{
    delete search;
    delete ui;
}

void ManualSearch::setSavedList(SavedList s){
    sl = s;
    loadSaveButtons({ui->save1, ui->save2, ui->save3});

}


void ManualSearch::checkBoxSearch(string wordToSearch, string category, int arg1){
    // 0 unchecked
    // 1 partially checked
    // 2 checked
    if(arg1 == 2){
        search->addToAttributes(wordToSearch, category);


    } else if (arg1 == 0){
        search->removeFromAttributes(wordToSearch, category);
    }


    //rerun the query
    search->runNewQuery();

    //update the gallery and display
    petgal.updatePetVec(search->getPetVec());
    petgal.setPageNum(1);
    petgal.displayPets(0);

    //reload save buttons
    loadSaveButtons({ui->save1, ui->save2, ui->save3});

}

//CHECKBOXES
void ManualSearch::on_dogCheckBox_stateChanged(int arg1){
    checkBoxSearch("dog", "species", arg1);
}

void ManualSearch::on_catCheckBox_stateChanged(int arg1){
    checkBoxSearch("cat", "species", arg1);
}

void ManualSearch::on_rabbitCheckBox_stateChanged(int arg1){
    checkBoxSearch("rabbit","species", arg1);
}

void ManualSearch::on_rodentCheckBox_stateChanged(int arg1){
    checkBoxSearch("rodent", "species", arg1);
}


void ManualSearch::on_fishCheckBox_stateChanged(int arg1){
    checkBoxSearch("fish", "species", arg1);
}

void ManualSearch::on_birdCheckBox_stateChanged(int arg1){
    checkBoxSearch("bird", "species", arg1);
}

void ManualSearch::on_youngCheckBox_stateChanged(int arg1){
    checkBoxSearch("young", "age", arg1);
}

void ManualSearch::on_adultCheckBox_stateChanged(int arg1){
    checkBoxSearch("adult", "age", arg1);
}

void ManualSearch::on_seniorCheckBox_stateChanged(int arg1){
    checkBoxSearch("senior", "age", arg1);
}

void ManualSearch::on_maleCheckBox_stateChanged(int arg1){
    checkBoxSearch("male", "gender", arg1);
}

void ManualSearch::on_femaleCheckBox_stateChanged(int arg1){
    checkBoxSearch("female", "gender", arg1);
}

void ManualSearch::on_smallCheckBox_stateChanged(int arg1){
    checkBoxSearch("small", "size", arg1);
}
void ManualSearch::on_mediumCheckBox_stateChanged(int arg1){
    checkBoxSearch("medium", "size", arg1);
}
void ManualSearch::on_largeCheckBox_stateChanged(int arg1){
    checkBoxSearch("large", "size", arg1);
}

void ManualSearch::on_kidsCheckBox_stateChanged(int arg1){
    checkBoxSearch("kids", "goodWith", arg1);
}
void ManualSearch::on_animalsCheckBox_stateChanged(int arg1){
    checkBoxSearch("animals", "goodWith", arg1);
}
void ManualSearch::on_happyCheckBox_stateChanged(int arg1){
    checkBoxSearch("happy", "temperament", arg1);
}
void ManualSearch::on_friendlyCheckBox_stateChanged(int arg1){
    checkBoxSearch("friendly", "temperament", arg1);
}
void ManualSearch::on_introvertedCheckBox_stateChanged(int arg1){
    checkBoxSearch("introverted", "temperament", arg1);
}
void ManualSearch::on_activeCheckBox_stateChanged(int arg1){
    checkBoxSearch("active", "temperament", arg1);
}
void ManualSearch::on_vigilantCheckBox_stateChanged(int arg1){
    checkBoxSearch("vigilant", "temperament", arg1);
}
void ManualSearch::on_bestFriendsCheckBox_stateChanged(int arg1){
    checkBoxSearch("best friends", "shelter", arg1);
}
void ManualSearch::on_humaneSocietyCheckBox_stateChanged(int arg1){
    checkBoxSearch("humane society", "shelter", arg1);
}
void ManualSearch::on_animalWelfareLeagueCheckBox_stateChanged(int arg1){
    checkBoxSearch("animal welfare league", "shelter", arg1);
}

void ManualSearch::ManualSearch::on_previous_clicked()
{
    petgal.previous();
    loadSaveButtons({ui->save1, ui->save2, ui->save3});
}

void ManualSearch::on_next_clicked()
{
    petgal.next();
    loadSaveButtons({ui->save1, ui->save2, ui->save3});
}

void ManualSearch::on_searchButton_clicked()
{
    clearCheckBoxes();

    //take string from search bar and run query on it
    QString searchInput = ui->searchBar->text();
    string searchString = searchInput.toStdString();
    search->search(searchString);
    search->runNewQuery();

    //update the pet gallery
    petgal.updatePetVec(search->getPetVec());
    petgal.displayPets(0);
    petgal.setPageNum(1);
    loadSaveButtons({ui->save1, ui->save2, ui->save3});
}

void ManualSearch::clearCheckBoxes(){
    //clear all the checkboxes!
    //could potentially iterate over everything to optimize


    ui->dogCheckBox->setChecked(false);
    ui->catCheckBox->setChecked(false);
    ui->rabbitCheckBox->setChecked(false);
    ui->rodentCheckBox->setChecked(false);
    ui->fishCheckBox->setChecked(false);
    ui->birdCheckBox->setChecked(false);
    ui->youngCheckBox->setChecked(false);
    ui->adultCheckBox->setChecked(false);
    ui->seniorCheckBox->setChecked(false);
    ui->maleCheckBox->setChecked(false);
    ui->femaleCheckBox->setChecked(false);
    ui->smallCheckBox->setChecked(false);
    ui->mediumCheckBox->setChecked(false);
    ui->largeCheckBox->setChecked(false);
    ui->kidsCheckBox->setChecked(false);
    ui->happyCheckBox->setChecked(false);
    ui->friendlyCheckBox->setChecked(false);
    ui->introvertedCheckBox->setChecked(false);
    ui->activeCheckBox->setChecked(false);
    ui->vigilantCheckBox->setChecked(false);
    ui->bestFriendsCheckBox->setChecked(false);
    ui->humaneSocietyCheckBox->setChecked(false);
    ui->animalWelfareLeagueCheckBox->setChecked(false);

}

void ManualSearch::on_link1_clicked()
{

    emit learnMoreClicked(petgal.getPet(0), ui->save1->isChecked());
}

void ManualSearch::on_link2_clicked(){

    emit learnMoreClicked(petgal.getPet(1), ui->save2->isChecked());
}

void ManualSearch::on_link3_clicked()
{

    emit learnMoreClicked(petgal.getPet(2), ui->save3->isChecked());
}

void ManualSearch::on_save1_clicked()
{
    saveButton(ui->save1, 0);

}

void ManualSearch::on_save2_clicked()
{
    saveButton(ui->save2, 1);
}

void ManualSearch::on_save3_clicked()
{
    saveButton(ui->save3, 2);
}

void ManualSearch::saveButton(QPushButton* saveButton, int index){
    if(saveButton->isChecked() == false){
        sl.unsavePet(petgal.getPet(index));
        saveButton->setText("♡");
        saveButton->setStyleSheet("color: black");
        emit heartClicked(petgal.getPet(index), false);

    } else if (saveButton->isChecked() == true){
        sl.savePet(petgal.getPet(index));
        saveButton->setText("♥");
        saveButton->setStyleSheet("color: red; border: none");
        emit heartClicked(petgal.getPet(index), true);
    }
}

void ManualSearch::loadSaveButtons(vector<QPushButton *> saveButtons){
    for(int i = 0; i < (int) saveButtons.size(); i++){
        if((int) petgal.getPetVec().size() > i){
        if(sl.isSavedPet(petgal.getPet(i)) == true){
            saveButtons[i]->setChecked(true);
            saveButtons[i]->setText("♥");
            saveButtons[i]->setStyleSheet("color: red; border: none");
        } else{
            saveButtons[i]->setChecked(false);
            saveButtons[i]->setText("♡");
            saveButtons[i]->setStyleSheet("color: black");
        }
    }
    }
}
