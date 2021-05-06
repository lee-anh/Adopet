#include "takequiz.h"
#include "ui_takequiz.h"

TakeQuiz::TakeQuiz(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TakeQuiz)
{
    ui->setupUi(this);
}

TakeQuiz::~TakeQuiz()
{
    delete ui;
}

void TakeQuiz::on_No_clicked()
{
    this->close();
}

void TakeQuiz::on_Yes_clicked()
{
    emit takeQuiz();
    this->close();
}
