#include "findmatchforadopters.h"
#include "ui_findmatchforadopters.h"

FindMatchForAdopters::FindMatchForAdopters(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FindMatchForAdopters)
{
    ui->setupUi(this);
}

FindMatchForAdopters::~FindMatchForAdopters()
{
    delete ui;
}

void FindMatchForAdopters::on_pushButton_clicked()
{

}
