#ifndef FINDMATCHFORADOPTERS_H
#define FINDMATCHFORADOPTERS_H

#include <QWidget>
#include "../Pets/pet.h"
#include "../Matchmaking/matchmaking.h"
#include "../SavedList/savedlist.h"
#include "petgallery.h"

namespace Ui {
class FindMatchForAdopters;
}

class FindMatchForAdopters : public QWidget
{
    Q_OBJECT

public:
    explicit FindMatchForAdopters(QWidget *parent = nullptr);
    ~FindMatchForAdopters();
    void setSavedList(SavedList s);
    void setUser(string username);


private:
    Ui::FindMatchForAdopters *ui;
    Matchmaking mat;
    PetGallery petgal;
    SavedList sl;
    string user;

    void clearLabels();
    void loadSaveButtons(vector<QPushButton *> saveButtons);
    void saveButton(QPushButton* saveButton, int index);


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

    void on_generateMatchesButton_clicked();

signals:
    void learnMoreClicked(Pet sendPet, bool b);
    void heartClicked(Pet p, bool b);

};

#endif // FINDMATCHFORADOPTERS_H
