#include "findmatchforadopters.h"
#include "ui_findmatchforadopters.h"


/*!
 * \brief FindMatchForAdopters constructor
 */
FindMatchForAdopters::FindMatchForAdopters(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FindMatchForAdopters)
{
    ui->setupUi(this);
    ui->pageLine->setText("Press on the generate matches button!");



}


/*!
 * \brief FindMatchForAdopters destructor
 */
FindMatchForAdopters::~FindMatchForAdopters()
{
    delete ui;

}


/*!
 * \brief setSavedList, must be set when class is used
 * \param s
 */
void FindMatchForAdopters::setSavedList(SavedList s){
    sl = s;
}


/*!
 * \brief setUser, must be set when class is used
 * \param username
 */
void FindMatchForAdopters::setUser(string username){
    user = username;

    //causes database cxn error b/c this matchmaking is called again
    //but should be fine because it's just reopened right after


    QString os = QSysInfo::productVersion();
    string dbName;
    if(os == "10.16"){
        dbName = "../../../../../projectDB.sqlite";
    } else {
        dbName = "../../projectDB.sqlite";
    }
     mat = Matchmaking(dbName, user);

    galleryMode();

}

/*!
 * \brief galleryMode for pet display, initalize the pet gallery
 */
void FindMatchForAdopters::galleryMode(){

    petgal = PetGallery(4, ui->previous, ui->next, ui->pageLine,
                        {ui->name1, ui->name2, ui->name3, ui->name4},
                        {ui->pic1, ui->pic2, ui->pic3, ui->pic4},
                        {ui->score1, ui->score2, ui->score3, ui->score4},
                        {ui->link1, ui->link2, ui->link3, ui->link4},
                        {ui->save1, ui->save2, ui->save3, ui->save4},
                        mat.findMatchesForAdopter(user));

    ui->stackedWidget->setCurrentIndex(0); //gallery mode
}


/*!
 * \brief listMode for pet display, intialize the pet gallery
 */
void FindMatchForAdopters::listMode(){
    petgal = PetGallery(true, 6, ui->previousa, ui->nexta, ui->pageLinea,
                        {ui->name1a, ui->name2a, ui->name3a, ui->name4a, ui->name5a, ui->name6a},
                        {ui->info1a, ui->info2a, ui->info3a, ui->info4a, ui->info5a, ui->info6a},
                        {ui->match1, ui->match2, ui->match3, ui->match4, ui->match5, ui->match6},
                        {ui->link1a, ui->link2a, ui->link3a, ui->link4a, ui->link5a, ui->link6a},
                        {ui->save1a, ui->save2a, ui->save3a, ui->save4a, ui->save5a, ui->save6a},
                        mat.findMatchesForAdopter(user));

    ui->stackedWidget->setCurrentIndex(1); //list mode
}



/*!
 * \brief saveButton, changes the saveButton
 * \param saveButton
 * \param index
 */
void FindMatchForAdopters::saveButton(QPushButton* saveButton, int index){

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
 * \brief loadSaveButtons, load the saved buttons from the saved list
 * \param saveButtons
 */
void FindMatchForAdopters::loadSaveButtons(vector<QPushButton *> saveButtons){
    //for each save button
    for(int i = 0; i < (int) saveButtons.size(); i++){
        //if there is a pet to display
        if((int) petgal.getPetVec().size() > i){
            //if the pet is saved, show red heart
            if(sl.isSavedPet(petgal.getPet(i)) == true){
                saveButtons[i]->setChecked(true);
                saveButtons[i]->setText("♥");
                saveButtons[i]->setStyleSheet("color: red; border: none");
            } else{ //pet is not saved, show empty heart
                saveButtons[i]->setChecked(false);
                saveButtons[i]->setText("♡");
                saveButtons[i]->setStyleSheet("color: black");
            }
        }
    }
}


/*!
 * \brief on_previous_clicked, advances the 
 */
void FindMatchForAdopters::on_previous_clicked()
{
    petgal.previous();
    loadSaveButtons({ui->save1, ui->save2, ui->save3, ui->save4});
}


/*!
 * \brief on_next_clicked
 */
void FindMatchForAdopters::on_next_clicked()
{
    petgal.next();
    loadSaveButtons({ui->save1, ui->save2, ui->save3, ui->save4});
}

/*!
 * \brief on_link1_clicked
 */
void FindMatchForAdopters::on_link1_clicked()
{

    emit learnMoreClicked(petgal.getPet(0), ui->save1->isChecked());
}


/*!
 * \brief on_link2_clicked
 */
void FindMatchForAdopters::on_link2_clicked(){

    emit learnMoreClicked(petgal.getPet(1), ui->save2->isChecked());
}


/*!
 * \brief on_link3_clicked
 */
void FindMatchForAdopters::on_link3_clicked()
{

    emit learnMoreClicked(petgal.getPet(2), ui->save3->isChecked());
}

/*!
 * \brief on_link4_clicked
 */
void FindMatchForAdopters::on_link4_clicked()
{

    emit learnMoreClicked(petgal.getPet(3), ui->save4->isChecked());
}


/*!
 * \brief on_save1_clicked
 */
void FindMatchForAdopters::on_save1_clicked()
{
    saveButton(ui->save1, 0);

}

/*!
 * \brief on_save2_clicked
 */
void FindMatchForAdopters::on_save2_clicked()
{
    saveButton(ui->save2, 1);
}

/*!
 * \brief on_save3_clicked
 */
void FindMatchForAdopters::on_save3_clicked()
{
    saveButton(ui->save3, 2);
}


/*!
 * \brief on_save4_clicked
 */
void FindMatchForAdopters::on_save4_clicked()
{
    saveButton(ui->save4, 3);
}


/*!
 * \brief on_previousa_clicked
 */
void FindMatchForAdopters::on_previousa_clicked()
{
    petgal.previous();
    loadSaveButtons({ui->save1a, ui->save2a, ui->save3a, ui->save4a, ui->save5a, ui->save6a});
}


/*!
 * \brief on_nexta_clicked
 */
void FindMatchForAdopters::on_nexta_clicked()
{
    petgal.next();
    loadSaveButtons({ui->save1a, ui->save2a, ui->save3a, ui->save4a, ui->save5a, ui->save6a});
}


/*!
 * \brief on_link1a_clicked
 */
void FindMatchForAdopters::on_link1a_clicked()
{

    emit learnMoreClicked(petgal.getPet(0), ui->save1a->isChecked());
}

/*!
 * \brief on_link2a_clicked
 */
void FindMatchForAdopters::on_link2a_clicked(){

    emit learnMoreClicked(petgal.getPet(1), ui->save2a->isChecked());
}


/*!
 * \brief on_link3a_clicked
 */
void FindMatchForAdopters::on_link3a_clicked()
{

    emit learnMoreClicked(petgal.getPet(2), ui->save3a->isChecked());
}


/*!
 * \brief on_link4a_clicked
 */
void FindMatchForAdopters::on_link4a_clicked()
{

    emit learnMoreClicked(petgal.getPet(3), ui->save4a->isChecked());
}

/*!
 * \brief on_link5a_clicked
 */
void FindMatchForAdopters::on_link5a_clicked()
{

    emit learnMoreClicked(petgal.getPet(4), ui->save5a->isChecked());
}


/*!
 * \brief on_link6a_clicked
 */
void FindMatchForAdopters::on_link6a_clicked()
{

    emit learnMoreClicked(petgal.getPet(5), ui->save6a->isChecked());
}

/*!
 * \brief on_save1a_clicked
 */
void FindMatchForAdopters::on_save1a_clicked()
{
    saveButton(ui->save1a, 0);

}

/*!
 * \brief on_save2a_clicked
 */
void FindMatchForAdopters::on_save2a_clicked()
{
    saveButton(ui->save2a, 1);
}

/*!
 * \brief on_save3a_clicked
 */
void FindMatchForAdopters::on_save3a_clicked()
{
    saveButton(ui->save3a, 2);
}


/*!
 * \brief on_save4a_clicked
 */
void FindMatchForAdopters::on_save4a_clicked()
{
    saveButton(ui->save4a, 3);
}


/*!
 * \brief on_save5a_clicked
 */
void FindMatchForAdopters::on_save5a_clicked()
{
    saveButton(ui->save5a, 4);
}


/*!
 * \brief on_save6a_clicked
 */
void FindMatchForAdopters::on_save6a_clicked()
{
    saveButton(ui->save6a, 5);
}




/*!
 * \brief on_generateMatchesButtona_clicked
 */
void FindMatchForAdopters::on_generateMatchesButton_clicked()
{
    //order is important here - set page num then display pets
    petgal.setPageNum(1);
    petgal.displayPets(0);

    loadSaveButtons({ui->save1, ui->save2, ui->save3, ui->save4});
}


/*!
 * \brief on_generateMatchesButtona_clicked
 */
void FindMatchForAdopters::on_generateMatchesButtona_clicked()
{
    //order is important here - set page num then display pets
    petgal.setPageNum(1);
    petgal.displayPets(0);

    loadSaveButtons({ui->save1a, ui->save2a, ui->save3a, ui->save4a, ui->save5a, ui->save6a});
}


/*!
 * \brief on_viewMode_currentIndexChanged
 * \param index
 */
void FindMatchForAdopters::on_viewMode_currentIndexChanged(int index)
{
    //go to list mode
    if(index == 2){
        ui->stackedWidget->setCurrentIndex(1);
        listMode();
    }
}

/*!
 * \brief on_viewModea_currentIndexChanged
 * \param index
 */
void FindMatchForAdopters::on_viewModea_currentIndexChanged(int index)
{
    //go to gallery mode
    if(index == 1){
        ui->stackedWidget->setCurrentIndex(0);
        galleryMode();
    }
}

