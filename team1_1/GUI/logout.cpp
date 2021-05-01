#include "logout.h"
#include "ui_logout.h"

/*!
 * \brief Logout constructor
 * \param parent
 */
Logout::Logout(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Logout)
{
    ui->setupUi(this);
}

/*!
 * \brief Logout destructor
 */
Logout::~Logout()
{
    delete ui;
}

/*!
 * \brief on_yes_clicked, logout
 */
void Logout::on_yes_clicked()
{
    emit timeToLogout();
    this->close();
}

/*!
 * \brief on_no_clicked, don't logout
 */
void Logout::on_no_clicked()
{
    this->close();
}
