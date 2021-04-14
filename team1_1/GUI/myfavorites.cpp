#include "myfavorites.h"
#include "ui_myfavorites.h"

MyFavorites::MyFavorites(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyFavorites)
{
    ui->setupUi(this);




}

MyFavorites::~MyFavorites()
{
    delete ui;
}


void MyFavorites::setSavedList(SavedList s){
    sl = s;
}

void MyFavorites::showGal(){
    petgal = PetGallery(4, ui->previous, ui->next, ui->pageLine, {ui->name1, ui->name2, ui->name3, ui->name4},
                        {ui->pic1, ui->pic2, ui->pic3, ui->pic4},
                        {ui->link1, ui->link2, ui->link3, ui->link4},
                        {ui->save1, ui->save2, ui->save3, ui->save4},
                        sl.getPetVec());
    petgal.displayPets(0);
    loadSaveButtons({ui->save1, ui->save2, ui->save3, ui->save4});
}


void MyFavorites::on_previous_clicked()
{
    petgal.previous();
    loadSaveButtons({ui->save1, ui->save2, ui->save3, ui->save4});
}

void MyFavorites::on_next_clicked()
{
    petgal.next();
    loadSaveButtons({ui->save1, ui->save2, ui->save3, ui->save4});
}


void MyFavorites::on_link1_clicked()
{

    emit learnMoreClicked(petgal.getPet(0), ui->save1->isChecked());
}

void MyFavorites::on_link2_clicked(){

    emit learnMoreClicked(petgal.getPet(1), ui->save2->isChecked());
}

void MyFavorites::on_link3_clicked()
{

    emit learnMoreClicked(petgal.getPet(2), ui->save3->isChecked());
}

void MyFavorites::on_link4_clicked()
{

    emit learnMoreClicked(petgal.getPet(3), ui->save4->isChecked());
}



void MyFavorites::on_save1_clicked()
{
    saveButton(ui->save1, 0);
}

void MyFavorites::on_save2_clicked()
{
    saveButton(ui->save2, 1);
}

void MyFavorites::on_save3_clicked()
{
    saveButton(ui->save3, 2);
}

void MyFavorites::on_save4_clicked()
{
    saveButton(ui->save4, 3);
}


void MyFavorites::saveButton(QPushButton* saveButton, int index){
    if(saveButton->isChecked() == false){
        sl.unsavePet(petgal.getPet(index));
        saveButton->setText("♡");
        saveButton->setStyleSheet("color: black");

    } else if (saveButton->isChecked() == true){
        sl.savePet(petgal.getPet(index));
        saveButton->setText("♥");
        saveButton->setStyleSheet("color: red; border: none");
    }
}

void MyFavorites::loadSaveButtons(vector<QPushButton *> saveButtons){
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
