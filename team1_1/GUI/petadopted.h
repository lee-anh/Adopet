#ifndef PETADOPTED_H
#define PETADOPTED_H

#include <QDialog>

namespace Ui {
class PetAdopted;
}

class PetAdopted : public QDialog
{
    Q_OBJECT

public:
    explicit PetAdopted(QWidget *parent = nullptr);
    ~PetAdopted();

private slots:
    void on_yes_clicked();

    void on_no_clicked();

signals:
   // void yesAdopted();

private:
    Ui::PetAdopted *ui;
};

#endif // PETADOPTED_H
