#ifndef MYFAVORITES_H
#define MYFAVORITES_H

#include <QWidget>
#include <QtSql>

#include "../Pets/pet.h"
#include "../SavedList/savedlist.h"

#include "petgallery.h"

namespace Ui {
class MyFavorites;
}

class MyFavorites : public QWidget
{
    Q_OBJECT

public:
    explicit MyFavorites(QWidget *parent = nullptr);
    ~MyFavorites();

    void setSavedList(SavedList s);
    void showGal();

private:
    Ui::MyFavorites *ui;
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

    void on_save1_clicked();
    void on_save2_clicked();
    void on_save3_clicked();
    void on_save4_clicked();

    void on_viewModeComboBox_currentIndexChanged(int index);

signals:

    void learnMoreClicked(Pet sendPet, bool b);
    void heartClicked(Pet p, bool b);
    void toListMode();



};

#endif // MYFAVORITES_H
