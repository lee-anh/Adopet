#ifndef MYFAVORITESTWO_H
#define MYFAVORITESTWO_H

#include <QWidget>
#include <QtSql>

#include "../Pets/pet.h"
#include "../SavedList/savedlist.h"

#include "petgallery.h"

namespace Ui {
class MyFavoritesTwo;
}

class MyFavoritesTwo : public QWidget
{
    Q_OBJECT

public:
    explicit MyFavoritesTwo(QWidget *parent = nullptr);
    ~MyFavoritesTwo();
    void setSavedList(SavedList s);
    void showGal();

private:
    Ui::MyFavoritesTwo *ui;

    SavedList sl;
    PetGallery petgal;
    void saveButton(QPushButton *saveButton, int index);
    void loadSaveButtons(vector<QPushButton*> saveButtons);
private slots:
    void on_previous_clicked();
    void on_next_clicked();

    void on_link1_clicked();
    void on_link2_clicked();
    void on_link3_clicked();
    void on_link4_clicked();
    void on_link5_clicked();
    void on_link6_clicked();
    void on_link7_clicked();
    void on_link8_clicked();

    void on_save1_clicked();
    void on_save2_clicked();
    void on_save3_clicked();
    void on_save4_clicked();
    void on_save5_clicked();
    void on_save6_clicked();
    void on_save7_clicked();
    void on_save8_clicked();


    void on_viewMode_currentIndexChanged(int index);

signals:

    void learnMoreClicked(Pet sendPet, bool b);
    void heartClicked(Pet p, bool b);
    void goToGallery();
};

#endif // MYFAVORITESTWO_H
