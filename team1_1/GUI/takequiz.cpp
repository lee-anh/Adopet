#include "takequiz.h"
#include "ui_takequiz.h"


/*!
 * \brief TakeQuiz Constructor
 * \param parent
 */
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


/*!
 * \brief on_No_clicked close dialog, do nothing
 */
void TakeQuiz::on_No_clicked()
{
    this->close();
}


/*!
 * \brief on_Yes_clicked close dialog, bring users to quiz
 */
void TakeQuiz::on_Yes_clicked()
{
    emit takeQuiz();
    this->close();
}
