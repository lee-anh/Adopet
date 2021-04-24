#ifndef MYPETS_H
#define MYPETS_H

#include <QWidget>
#include <petadopted.h>
#include <algorithm>

#include <../Owner/owner.h>
#include <../Pets/pet.h>
#include <petgallery.h>

namespace Ui {
class MyPets;
}

class MyPets : public QWidget
{
    Q_OBJECT

public:
    explicit MyPets(QWidget *parent = nullptr);
    ~MyPets();

    void setOwner(Owner *o);
    void goToUploadPet();
    void goToMyPets();

private:
    Ui::MyPets *ui;
    Owner *owner;
    PetGallery petgal;

    int previousPage;

private slots:
    void on_markAsAdopted_clicked();


    void on_singleUploadButton_clicked();
    void on_saveChangesButton_clicked();
    void on_previous_clicked();
    void on_next_clicked();
    void on_backButton_clicked();
};

#endif // MYPETS_H
