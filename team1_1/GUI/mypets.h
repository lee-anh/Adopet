#ifndef MYPETS_H
#define MYPETS_H

#include <QWidget>
#include <petadopted.h>

namespace Ui {
class MyPets;
}

class MyPets : public QWidget
{
    Q_OBJECT

public:
    explicit MyPets(QWidget *parent = nullptr);
    ~MyPets();

    void goToMyPets();

private slots:
    void on_markAsAdopted_clicked();

private:
    Ui::MyPets *ui;
};

#endif // MYPETS_H
