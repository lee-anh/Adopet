#include "manualsearch.h"
#include "ui_manualsearch.h"


/*!
 * \brief ManualSearch constructor
 * \param parent
 */
ManualSearch::ManualSearch(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ManualSearch)
{
    ui->setupUi(this);

    connect(&zp, SIGNAL(finishedCall()), this, SLOT(finishedAPICall()));
      
    QString os = QSysInfo::productVersion();
    cout << os.toStdString() << endl;
      
    if(os == "10.16"){
        search = new DBSearch("../../../../../projectDB.sqlite");
    } else {
        search = new DBSearch("../../projectDB.sqlite");
    }

    galleryMode();


    //manual search doesn't display any results when the user starts

    petgal.updatePetVec(search->getPetVec());
    ui->pageLine->setText("Search for pets using search bar and checkboxes!");
    ui->searchingFor->clear();

}

ManualSearch::~ManualSearch()
{
    delete search;
    delete ui;
}


/*!
 * \brief setSavedList sets up instance variables like saved list, zipcode
 * sets up save buttons and location combo box
 * basically needs to be called when a constructor is called
 * \param s
 * \param zipcode
 */
void ManualSearch::setSavedList(SavedList s, string zipcode){
    clearCheckBoxes();
    ui->location->setCurrentIndex(0);
    sl = s;
    zip = zipcode;
    if(mode == "gallery"){
        loadSaveButtons({ui->save1, ui->save2, ui->save3});
    } else {
        loadSaveButtons({ui->save1a, ui->save2a, ui->save3a, ui->save4a, ui->save5a, ui->save6a});
    }

}

/*!
 * \brief galleryMode set up for gallery mode, sets up pet gallery,
 * navigates to correct page
 */
void ManualSearch::galleryMode(){
    ui->viewModeComboBox->setCurrentIndex(1);
    //able to initalize petgal here b/c username doesn't matter
    petgal = PetGallery(3,ui->previous, ui->next, ui->pageLine, {ui->name1, ui->name2, ui->name3},
                        {ui->pic1, ui->pic2, ui->pic3},
                        {ui->link1, ui->link2, ui->link3},
                        {ui->save1, ui->save2, ui->save3},
                        search->getPetVec(), true);
    ui->stackedWidget_2->setCurrentIndex(0);
    ui->pageLine->setText("Search for pets using search bar and checkboxes!");
    mode = "gallery";
    clearCheckBoxes();

}

/*!
 * \brief listMode set up for list mode, sets up pet gallery,
 * navigates to correct page
 */
void ManualSearch::listMode(){
    ui->viewModeComboBox->setCurrentIndex(2);
    petgal = PetGallery(true, 6, ui->previousa, ui->nexta, ui->pageLinea,
                        {ui->name1a, ui->name2a, ui->name3a, ui->name4a, ui->name5a, ui->name6a},
                        {ui->info1a, ui->info2a, ui->info3a, ui->info4a, ui->info5a, ui->info6a},
                        {ui->link1a, ui->link2a, ui->link3a, ui->link4a, ui->link5a, ui->link6a},
                        {ui->save1a, ui->save2a, ui->save3a, ui->save4a, ui->save5a, ui->save6a},
                        search->getPetVec());
    ui->stackedWidget_2->setCurrentIndex(1);
    ui->pageLinea->setText("Search for pets using search bar and checkboxes!");
    mode = "list";
    clearCheckBoxes();

}


/*!
 * \brief checkBoxSearch search used by all the checkboxes,
 * adds and removes attributes
 * \param wordToSearch attribute
 * \param category of wordToSearch
 * \param arg1 0 = remove, 2 = add
 */
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
    //search->runNewQuery();

    //update the gallery and display
    if(ui->location->currentIndex() == 0){
        search->runNewQuery(false);
    } else {
        search->runNewQuery(true);
    }
    petgal.updatePetVec(search->getPetVec());
    petgal.setPageNum(1);
    petgal.displayPets(0);

    //reload save buttons
    if(mode == "gallery"){
        loadSaveButtons({ui->save1, ui->save2, ui->save3});
    } else {
        loadSaveButtons({ui->save1a, ui->save2a, ui->save3a, ui->save4a, ui->save5a, ui->save6a});
    }

}

/*!
 * \brief clearCheckBoxes clear all the checkboxes
 */
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

/*!
 * \brief loadSaveButtons load the save buttons, determines what kind of heart
 * to display
 * \param saveButtons list of saveButtons
 */
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

/*!
 * \brief saveButton handles different saveButton changes
 * \param saveButton the button object
 * \param index which pet
 */
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

/*!
 * \brief APICall call the zipcode api
 * \param distance in miles
 */
void ManualSearch::APICall(string distance){
    if(zip.size() == 4){
        zip = "0" + zip;
    }

    zp.zip(zip, distance);
}

/*!
 * \brief finishedAPICall process the api's output
 * update screen info to reflect changes
 */
void ManualSearch::finishedAPICall(){

    search->runNewQuery(true);
    petgal.updatePetVec(search->getPetVec());
    petgal.displayPets(0);
    petgal.setPageNum(1);
    if(mode == "gallery"){
        //galleryMode();
        loadSaveButtons({ui->save1, ui->save2, ui->save3});
    } else {
        //listMode();
        loadSaveButtons({ui->save1a, ui->save2a, ui->save3a, ui->save4a, ui->save5a, ui->save6a});
    }


}


/*!
 * \brief on_searchButton_clicked query the database with a custom string,
 * processes query and displays results
 */

void ManualSearch::on_searchButton_clicked()
{
    clearCheckBoxes();
    //ui->searchingForLabel->clear();

    //take string from search bar and run query on it
    QString searchInput = ui->searchBar->text();
    string searchString = searchInput.toStdString();
    search->search(searchString);

    if(ui->location->currentIndex() == 0){
        search->runNewQuery(false);
    } else {
        search->runNewQuery(true);
    }

    cout << search->getConstraints() << endl;

    ui->searchingFor->setText("Searching for: " + QString::fromStdString(search->getConstraints()));


    //update the pet gallery
    petgal.updatePetVec(search->getPetVec());

    petgal.displayPets(0);
    petgal.setPageNum(1);
    if(mode == "gallery"){
        loadSaveButtons({ui->save1, ui->save2, ui->save3});
    } else {
        loadSaveButtons({ui->save1a, ui->save2a, ui->save3a, ui->save4a, ui->save5a, ui->save6a});
    }
}

/*!
 * \brief on_searchBar_returnPressed acts the same as search button clicked,
 * just uses the return/enter key and not the button
 */
void ManualSearch::on_searchBar_returnPressed()
{
    on_searchButton_clicked();
}

/*!
 * \brief on_surpriseMe_clicked randomizes the results,
 * no constraints taken into account
 */
void ManualSearch::on_surpriseMe_clicked()
{
    clearCheckBoxes();

    if(ui->location->currentIndex() == 0){
        search->randomShuffle(false);
    } else {
        search->randomShuffle(true);
    }

    petgal.updatePetVec(search->getPetVec());
    petgal.displayPets(0);
    petgal.setPageNum(1);
    if(mode == "gallery"){
        loadSaveButtons({ui->save1, ui->save2, ui->save3});
    } else {
        loadSaveButtons({ui->save1a, ui->save2a, ui->save3a, ui->save4a, ui->save5a, ui->save6a});
    }
}


/*!
 * \brief on_viewModeComboBox_currentIndexChanged
 * change the view mode
 * \param index 1 = gallery, 2 = list
 */
void ManualSearch::on_viewModeComboBox_currentIndexChanged(int index)
{
    //stateChanged(index, ui->location->currentIndex());

    ui->searchingFor->clear();
    if(index == 1){ //gallery mode
        mode = "gallery";
        galleryMode();
    } else if (index == 2) {
        mode = "list";
        listMode();
    }
}

/*!
 * \brief on_location_currentIndexChanged
 * change the location mode
 * \param index 1 = 20 miles,  2= 50 miles
 */
void ManualSearch::on_location_currentIndexChanged(int index){
    //stateChanged(ui->viewModeComboBox->currentIndex(), index);

    if (index == 1){
        // 20
        APICall("20");
    } else if (index == 2){
        //50
        APICall("50");
    } else {
        search->runNewQuery(false);
        petgal.updatePetVec(search->getPetVec());
        petgal.displayPets(0);
        petgal.setPageNum(1);

        if(ui->viewModeComboBox->currentIndex() == 1){
            loadSaveButtons({ui->save1, ui->save2, ui->save3});
        } else if (ui->viewModeComboBox->currentIndex() == 2){
            loadSaveButtons({ui->save1a, ui->save2a, ui->save3a, ui->save4a, ui->save5a, ui->save6a});
        }
    }
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





void ManualSearch::on_nexta_clicked()
{
    petgal.next();
    loadSaveButtons({ui->save1a, ui->save2a, ui->save3a, ui->save4a, ui->save5a, ui->save6a});
}

void ManualSearch::on_previousa_clicked()
{
    petgal.previous();
    loadSaveButtons({ui->save1a, ui->save2a, ui->save3a, ui->save4a, ui->save5a, ui->save6a});
}

void ManualSearch::on_link1a_clicked()
{

    emit learnMoreClicked(petgal.getPet(0), ui->save1a->isChecked());
}

void ManualSearch::on_link2a_clicked(){

    emit learnMoreClicked(petgal.getPet(1), ui->save2a->isChecked());
}

void ManualSearch::on_link3a_clicked()
{

    emit learnMoreClicked(petgal.getPet(2), ui->save3a->isChecked());
}
void ManualSearch::on_link4a_clicked()
{

    emit learnMoreClicked(petgal.getPet(3), ui->save4a->isChecked());
}

void ManualSearch::on_link5a_clicked(){

    emit learnMoreClicked(petgal.getPet(4), ui->save5a->isChecked());
}

void ManualSearch::on_link6a_clicked()
{

    emit learnMoreClicked(petgal.getPet(5), ui->save6a->isChecked());
}


void ManualSearch::on_save1a_clicked()
{
    saveButton(ui->save1a, 0);

}

void ManualSearch::on_save2a_clicked()
{
    saveButton(ui->save2a, 1);
}

void ManualSearch::on_save3a_clicked()
{
    saveButton(ui->save3a, 2);
}

void ManualSearch::on_save4a_clicked()
{
    saveButton(ui->save4a, 3);

}

void ManualSearch::on_save5a_clicked()
{
    saveButton(ui->save5a, 4);
}

void ManualSearch::on_save6a_clicked()
{
    saveButton(ui->save6a, 5);
}



