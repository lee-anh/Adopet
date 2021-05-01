#ifndef LOGOUT_H
#define LOGOUT_H

#include <QDialog>

namespace Ui {
class Logout;
}

/*!
 * \brief The Logout class creates a QDialog for users to confirm
 * that they want to logout of the system
 */
class Logout : public QDialog
{
    Q_OBJECT

public:
    /*!
     * \brief Logout constructor
     * \param parent
     */
    explicit Logout(QWidget *parent = nullptr);

    /*!
     * \brief Logout destructor
     */
    ~Logout();

private:
    Ui::Logout *ui;


private slots:
    /*!
     * \brief on_yes_clicked, logout
     */
    void on_yes_clicked();

    /*!
     * \brief on_no_clicked, don't logout
     */
    void on_no_clicked();


signals:
    /*!
     * \brief timeToLogout, emits that the user want to logout
     */
    void timeToLogout();
};

#endif // LOGOUT_H
