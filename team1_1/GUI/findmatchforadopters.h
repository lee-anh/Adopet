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

    void galleryMode();
    void listMode();

    void clearLabels();
    void loadSaveButtons(vector<QPushButton *> saveButtons);
    void saveButton(QPushButton* saveButton, int index);


private slots:

    //GALLERY VIEW
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


    //LIST VIEW
    void on_previousa_clicked();
    void on_nexta_clicked();

    void on_link1a_clicked();
    void on_link2a_clicked();
    void on_link3a_clicked();
    void on_link4a_clicked();
    void on_link5a_clicked();
    void on_link6a_clicked();

    void on_save1a_clicked();
    void on_save2a_clicked();
    void on_save3a_clicked();
    void on_save4a_clicked();
    void on_save5a_clicked();
    void on_save6a_clicked();

    void on_generateMatchesButtona_clicked();

    void on_viewMode_currentIndexChanged(int index);
    void on_viewModea_currentIndexChanged(int index);


signals:
    void learnMoreClicked(Pet sendPet, bool b);
    void heartClicked(Pet p, bool b);

};

#endif // FINDMATCHFORADOPTERS_H
