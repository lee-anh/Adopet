#include "findmatchforpets.h"
#include "ui_findmatchforpets.h"

FindMatchForPets::FindMatchForPets(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FindMatchForPets)
{
    ui->setupUi(this);
}

FindMatchForPets::~FindMatchForPets()
{
    delete ui;
}
