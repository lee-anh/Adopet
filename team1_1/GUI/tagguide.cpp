#include "tagguide.h"
#include "ui_tagguide.h"

TagGuide::TagGuide(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TagGuide)
{
    ui->setupUi(this);
}

TagGuide::~TagGuide()
{
    delete ui;
}
