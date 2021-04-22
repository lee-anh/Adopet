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
