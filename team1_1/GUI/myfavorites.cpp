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
    petgal = PetGallery(4, ui->pageLine, {ui->name1, ui->name2, ui->name3, ui->name4},
                        {ui->pic1, ui->pic2, ui->pic3, ui->pic4},
                        {ui->link1, ui->link2, ui->link3, ui->link4},
                        sl.getPetVec());
    petgal.displayPets(0);
}


void MyFavorites::on_previous_clicked()
{
    petgal.previous();
}

void MyFavorites::on_next_clicked()
{
    petgal.next();
}


void MyFavorites::on_link1_clicked()
{
    emit learnMoreClicked(petgal.getPet(0));
}

void MyFavorites::on_link2_clicked()
{
    emit learnMoreClicked(petgal.getPet(1));
}

void MyFavorites::on_link3_clicked()
{
    emit learnMoreClicked(petgal.getPet(2));
}

void MyFavorites::on_link4_clicked()
{
    emit learnMoreClicked(petgal.getPet(3));
}


