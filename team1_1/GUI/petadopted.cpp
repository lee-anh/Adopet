#include "petadopted.h"
#include "ui_petadopted.h"

PetAdopted::PetAdopted(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PetAdopted)
{
    ui->setupUi(this);
}

PetAdopted::~PetAdopted()
{
    delete ui;
}

void PetAdopted::on_yes_clicked()
{
    //TODO Remove the pet
    this->close();
    emit yesAdopted();

}

void PetAdopted::on_no_clicked()
{
    this->close();
}
