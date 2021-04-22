#include "findmatchforadopters.h"
#include "ui_findmatchforadopters.h"

FindMatchForAdopters::FindMatchForAdopters(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FindMatchForAdopters)
{
    ui->setupUi(this);
    ui->pageLine->setText("Press on the generate matches button!");



}

FindMatchForAdopters::~FindMatchForAdopters()
{
    delete ui;

}

void FindMatchForAdopters::setSavedList(SavedList s){
    sl = s;
}

void FindMatchForAdopters::setUser(string username){
    user = username;

    //causes database cxn error b/c this matchmaking is called again
    //but should be fine because it's just reopened right after
    mat = Matchmaking("../../../../../projectDB.sqlite", username);
    petgal = PetGallery(4, ui->previous, ui->next, ui->pageLine,
                        {ui->name1, ui->name2, ui->name3, ui->name4},
                        {ui->pic1, ui->pic2, ui->pic3, ui->pic4},
                        {ui->score1, ui->score2, ui->score3, ui->score4},
                        {ui->link1, ui->link2, ui->link3, ui->link4},
                        {ui->save1, ui->save2, ui->save3, ui->save4},
                        mat.findMatchesForAdopter(user));
}


void FindMatchForAdopters::on_previous_clicked()
{
    petgal.previous();
    loadSaveButtons({ui->save1, ui->save2, ui->save3, ui->save4});
}

void FindMatchForAdopters::on_next_clicked()
{
    petgal.next();
    loadSaveButtons({ui->save1, ui->save2, ui->save3, ui->save4});
}


void FindMatchForAdopters::on_link1_clicked()
{

    emit learnMoreClicked(petgal.getPet(0), ui->save1->isChecked());
}

void FindMatchForAdopters::on_link2_clicked(){

    emit learnMoreClicked(petgal.getPet(1), ui->save2->isChecked());
}

void FindMatchForAdopters::on_link3_clicked()
{

    emit learnMoreClicked(petgal.getPet(2), ui->save3->isChecked());
}

void FindMatchForAdopters::on_link4_clicked()
{

    emit learnMoreClicked(petgal.getPet(3), ui->save4->isChecked());
}

void FindMatchForAdopters::on_save1_clicked()
{
    saveButton(ui->save1, 0);

}

void FindMatchForAdopters::on_save2_clicked()
{
    saveButton(ui->save2, 1);
}

void FindMatchForAdopters::on_save3_clicked()
{
    saveButton(ui->save3, 2);
}

void FindMatchForAdopters::on_save4_clicked()
{
    saveButton(ui->save4, 3);
}



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

void FindMatchForAdopters::on_generateMatchesButton_clicked()
{
    //order is important here - set page num then display pets
    petgal.setPageNum(1);
    petgal.displayPets(0);

    loadSaveButtons({ui->save1, ui->save2, ui->save3, ui->save4});
}
