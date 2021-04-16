#include "preferencesform.h"
#include "ui_preferencesform.h"

PreferencesForm::PreferencesForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PreferencesForm)
{
    ui->setupUi(this);
}

PreferencesForm::~PreferencesForm()
{
    delete ui;
}
