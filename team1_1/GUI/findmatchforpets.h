#ifndef FINDMATCHFORPETS_H
#define FINDMATCHFORPETS_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <vector>

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

    void forOnePet(Owner* owner);


private slots:
    void on_searchOne_clicked();

    void on_previousOne_clicked();

    void on_nextOne_clicked();

private:
    Ui::FindMatchForPets *ui;

    Matchmaking mat;

    void displayPeople(int start);
    void next();
    void previous();

    void setPageNum(int p);


    int numToDisplay;
    int nextStartIndex;
    int displayPageNumber;


    QPushButton* previousButton;
    QPushButton* nextButton;

    QLabel* pageNum;
    vector<QLabel*> nameLabels;
    vector<QLabel*> scoreLabels;
    vector<QLabel*> infoLabels;

    vector<pair<Adopter, int>> matResults;




};

#endif // FINDMATCHFORPETS_H
