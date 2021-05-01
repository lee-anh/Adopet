#include "unsavepet.h"
#include "ui_unsavepet.h"

/*!
 * \brief UnsavePet constructor
 * \param parent
 */
UnsavePet::UnsavePet(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UnsavePet)
{
    ui->setupUi(this);
}


/*!
 * \brief UnsavePet destructor
 */
UnsavePet::~UnsavePet()
{
    delete ui;
}

/*!
 * \brief on_no_clicked, don't unsave
 */
void UnsavePet::on_no_clicked()
{
    this->close();
}

/*!
 * \brief on_yes_clicked, unsave the pet
 */
void UnsavePet::on_yes_clicked()
{
    emit unsavePet();
    this->close();
}
