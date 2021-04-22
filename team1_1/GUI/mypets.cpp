#include "mypets.h"
#include "ui_mypets.h"

MyPets::MyPets(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyPets)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
}

MyPets::~MyPets()
{
    delete ui;
}

void MyPets::goToMyPets(){
    //go to myPets page
    ui->stackedWidget->setCurrentIndex(0);
}
void MyPets::on_markAsAdopted_clicked()
{
    //QDialog Experiment
    PetAdopted petAdopted;
    petAdopted.setModal(true);
    petAdopted.exec();
}
