#include "petadopted.h"
#include "ui_petadopted.h"

/*!
 * \brief PetAdopted constructor
 * \param parent
 */
PetAdopted::PetAdopted(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PetAdopted)
{
    ui->setupUi(this);
}


/*!
 * \brief PetAdopted destructor
 */
PetAdopted::~PetAdopted()
{
    delete ui;
}

/*!
 * \brief on_yes_clicked, yes remove the pet
 * After, close this dialog
 */
void PetAdopted::on_yes_clicked()
{
    //TODO Remove the pet
    this->close();
    emit yesAdopted();

}
\
/*!
 * \brief on_no_clicked, don't remove the pet
 * Just close the dialog
 */
void PetAdopted::on_no_clicked()
{
    this->close();
}
