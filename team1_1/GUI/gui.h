#ifndef GUI_H
#define GUI_H

#include <QWidget>

#include <QtSql>

#include "../DBSearch/dbsearch.h"
#include "../Pets/pet.h"

QT_BEGIN_NAMESPACE
namespace Ui { class GUI; }
QT_END_NAMESPACE

class GUI : public QWidget
{
    Q_OBJECT

public:
    GUI(QWidget *parent = nullptr);
    ~GUI();



private:
    Ui::GUI *ui;
    DBSearch *search;
    void displayPets(int start);
    void meetPet(Pet p);
    void clearLabels();
    void checkBoxSearch(string wordToSearch, int arg1);


    //static or dynamic?
    Pet displayedPet1;
    Pet displayedPet2;
    Pet displayedPet3;

    int previousPage;


private slots:
    void on_searchButton_clicked();

    //checkboxes
    void on_dogCheckBox_stateChanged(int arg1);
    void on_catCheckBox_stateChanged(int arg1);
    void on_rabbitCheckBox_stateChanged(int arg1);
    void on_rodentCheckBox_stateChanged(int arg1);
    void on_fishCheckBox_stateChanged(int arg1);
    void on_birdCheckBox_stateChanged(int arg1);


    void on_linkToResult1_clicked();
    void on_linkToResult2_clicked();
    void on_linkToResult3_clicked();
    void on_backButton_clicked();
};
#endif // GUI_H
