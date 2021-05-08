#ifndef FINDMATCHFORPETS_H
#define FINDMATCHFORPETS_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <vector>
#include <QCompleter>

#include "../Matchmaking/matchmaking.h"
#include "../Owner/owner.h"
#include "../Pets/pet.h"





namespace Ui {
class FindMatchForPets;
}

class FindMatchForPets : public QWidget
{
    Q_OBJECT

public:
    explicit FindMatchForPets(QWidget *parent = nullptr);
    ~FindMatchForPets();
    void toMainPage(Owner* owner);



private slots:
    void on_searchOne_clicked();

    void on_previousOne_clicked();

    void on_nextOne_clicked();

    void on_previousAll_clicked();

    void on_nextAll_clicked();

    void on_toAllPets_clicked();

    void on_toOnePet_clicked();

    void on_petName_returnPressed();

private:
    Ui::FindMatchForPets *ui;

    Owner* currentOwner;

    void forOnePet(Owner* owner);
    void forMultiPets(Owner* owner);

    Matchmaking mat;

    void setup();
    void displayPeople(int start);

    void displayPeopleMulti(int start);
    void next();
    void previous();

    void setPageNum(int p);
    void clearAll();


    int numToDisplay;
    int nextStartIndex;
    int displayPageNumber;

    string mode;


    QPushButton* previousButton;
    QPushButton* nextButton;

    QLabel* pageNum;
    vector<QLabel*> nameLabels;
    vector<QLabel*> scoreLabels;
    vector<QLabel*> infoLabels;
    vector<QLabel*> petNameLabels;

    vector<pair<Adopter, int>> matResults;

    vector<pair<Pet, pair<Adopter, int>>> multiMat;




};

#endif // FINDMATCHFORPETS_H
