#ifndef USERINFO_H
#define USERINFO_H

#include <QWidget>
#include <algorithm>

#include "../Authentication/authentication.h"


namespace Ui {
class UserInfo;
}

/*!
 * \brief The UserInfo class creates a widget where the user
 * inputs and edits their personal information
 */
class UserInfo : public QWidget
{
    Q_OBJECT

public:
    /*!
     * \brief UserInfo constructor
     * \param parent
     */
    explicit UserInfo(QWidget *parent = nullptr);

    /*!
     * \brief UserInfo destructor
     */
    ~UserInfo();


    void setAuth(Authentication *a, bool b);
    /*!
     * \brief setAuth, for adopters
     * \param a
     */
    void setAuth(Authentication *a);

    /*!
     * \brief setAuth, for owners
     * \param a
     * \param uname
     */
    void setAuth(Authentication *a, string uname);

    /*!
     * \brief createAccountClicked, sets up create account objects
     */
    void createAccountClicked();


    /*!
     * \brief adopterMyInfoClicked, sets up additional info objects
     * for adopters
     */
    void adopterMyInfoClicked();

    /*!
     * \brief ownerMyInfoClicked, sets up additional info objects
     * for owners
     */
    void ownerMyInfoClicked();


    /*!
     * \brief setFirstTime, indicate whether it's the first time
     * a user is using the system
     * \param b
     */
    void setFirstTime(bool b);


    /*!
     * \brief helpAdopter navigates to the help page for adopters
     */
    void helpAdopter();

    /*!
     * \brief helpOwner navigates to the help page for owners
     */
    void helpOwner();

private slots:
    /*!
     * \brief on_continueButton_clicked, go to next create account page
     */
    void on_continueButton_clicked();

    /*!
     * \brief on_saveButton_clicked, save changes made to user info
     * for adopters
     */
    void on_saveButton_clicked();

    /*!
     * \brief on_backButton_clicked, back to previous page
     */
    void on_backButton_clicked();

    /*!
     * \brief on_saveOwnerButton_clicked, save changes made to user info
     * for owners
     */
    void on_saveOwnerButton_clicked();

private:
    Ui::UserInfo *ui;
    Authentication *auth;

    string username;
    string password;
    bool firstTime;

    /*!
     * \brief clearAdopterInfo, clears associated gui objects
     */
    void clearAdopterInfo();

    /*!
     * \brief clearOwnerInfo, clears associated gui objects
     */
    void clearOwnerInfo();

    /*!
     * \brief clearCreateAccount, clears associated gui objects
     */
    void clearCreateAccount();

signals:
    /*!
     * \brief backClicked, go back to the login page
     */
    void backClicked();


};

#endif // USERINFO_H
