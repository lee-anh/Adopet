#include "myfavoritestwo.h"
#include "ui_myfavoritestwo.h"

MyFavoritesTwo::MyFavoritesTwo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyFavoritesTwo)
{
    ui->setupUi(this);
}

MyFavoritesTwo::~MyFavoritesTwo()
{
    delete ui;
}


void MyFavoritesTwo::setSavedList(SavedList s){
    sl = s;
}

void MyFavoritesTwo::showGal(){

    //pet gall must be initalized here b/c need the right saved list
    petgal = PetGallery(true, 8, ui->previous, ui->next, ui->pageLine,
                        {ui->name1, ui->name2, ui->name3, ui->name4, ui->name5, ui->name6, ui->name7, ui->name8},
                        {ui->info1, ui->info2, ui->info3, ui->info4, ui->info5, ui->info6, ui->info7, ui->info8},
                        {ui->link1, ui->link2, ui->link3, ui->link4, ui->link5, ui->link6, ui->link7, ui->link8},
                        {ui->save1, ui->save2, ui->save3, ui->save4, ui->save5, ui->save6, ui->save7, ui->save8},
                        sl.getPetVec());

    petgal.displayPets(0);

    loadSaveButtons({ui->save1, ui->save2, ui->save3, ui->save4, ui->save5, ui->save6, ui->save7, ui->save8});
    ui->viewMode->setCurrentIndex(2);
}

void MyFavoritesTwo::on_previous_clicked()
{
    petgal.previous();
    loadSaveButtons({ui->save1, ui->save2, ui->save3, ui->save4});
}

void MyFavoritesTwo::on_next_clicked()
{
    petgal.next();
    loadSaveButtons({ui->save1, ui->save2, ui->save3, ui->save4});
}




void MyFavoritesTwo::saveButton(QPushButton* saveButton, int index){
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

void MyFavoritesTwo::loadSaveButtons(vector<QPushButton *> saveButtons){
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



void MyFavoritesTwo::on_link1_clicked()
{
    emit learnMoreClicked(petgal.getPet(0), ui->save1->isChecked());
}

void MyFavoritesTwo::on_link2_clicked()
{
    emit learnMoreClicked(petgal.getPet(1), ui->save2->isChecked());
}

void MyFavoritesTwo::on_link3_clicked()
{
    emit learnMoreClicked(petgal.getPet(2), ui->save3->isChecked());
}

void MyFavoritesTwo::on_link4_clicked()
{
    emit learnMoreClicked(petgal.getPet(3), ui->save4->isChecked());
}
void MyFavoritesTwo::on_link5_clicked()
{
    emit learnMoreClicked(petgal.getPet(4), ui->save5->isChecked());
}

void MyFavoritesTwo::on_link6_clicked()
{
    emit learnMoreClicked(petgal.getPet(5), ui->save6->isChecked());
}

void MyFavoritesTwo::on_link7_clicked()
{
    emit learnMoreClicked(petgal.getPet(6), ui->save7->isChecked());
}

void MyFavoritesTwo::on_link8_clicked()
{
    emit learnMoreClicked(petgal.getPet(7), ui->save8->isChecked());
}

void MyFavoritesTwo::on_save1_clicked()
{
    saveButton(ui->save1, 0);
}

void MyFavoritesTwo::on_save2_clicked()
{
    saveButton(ui->save2, 1);
}

void MyFavoritesTwo::on_save3_clicked()
{
    saveButton(ui->save3, 2);
}

void MyFavoritesTwo::on_save4_clicked()
{
    saveButton(ui->save4, 3);
}

void MyFavoritesTwo::on_save5_clicked()
{
    saveButton(ui->save5, 4);
}

void MyFavoritesTwo::on_save6_clicked()
{
    saveButton(ui->save6, 5);
}

void MyFavoritesTwo::on_save7_clicked()
{
    saveButton(ui->save7, 6);
}

void MyFavoritesTwo::on_save8_clicked()
{
    saveButton(ui->save8, 7);
}

void MyFavoritesTwo::on_viewMode_currentIndexChanged(int index)
{
    //go to gallery mode
    if(index == 1){
        emit goToGallery();
    }
}
