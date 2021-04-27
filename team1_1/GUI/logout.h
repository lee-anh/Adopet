#ifndef LOGOUT_H
#define LOGOUT_H

#include <QDialog>

namespace Ui {
class Logout;
}

class Logout : public QDialog
{
    Q_OBJECT

public:
    explicit Logout(QWidget *parent = nullptr);
    ~Logout();

private:
    Ui::Logout *ui;

signals:
    void timeToLogout();
private slots:
    void on_yes_clicked();
    void on_no_clicked();
};

#endif // LOGOUT_H
