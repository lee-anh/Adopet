#include "petdisplay.h"
#include "ui_petdisplay.h"

PetDisplay::PetDisplay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PetDisplay)
{
    ui->setupUi(this);
}

PetDisplay::~PetDisplay()
{
    delete ui;
}

void PetDisplay::on_more1_clicked()
{
    ui->name1->setText("Changed!");
}
