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

private:
    Ui::PetAdopted *ui;
};

#endif // PETADOPTED_H
