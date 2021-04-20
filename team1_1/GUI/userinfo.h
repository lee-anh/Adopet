#ifndef USERINFO_H
#define USERINFO_H

#include <QWidget>
#include <algorithm>

#include "../Authentication/authentication.h"


namespace Ui {
class UserInfo;
}

class UserInfo : public QWidget
{
    Q_OBJECT

public:
    explicit UserInfo(QWidget *parent = nullptr);
    ~UserInfo();

    void setAuth(Authentication a);
    void adopterMyInfoClicked();

private slots:
    void on_continueButton_clicked();

    void on_saveButton_clicked();

    void on_backButton_clicked();

private:
    Ui::UserInfo *ui;
    Authentication auth;
    string username;
    string password;
    bool firstTime;

signals:
    void backClicked();
    void updatedAdopter(Adopter);


};

#endif // USERINFO_H
