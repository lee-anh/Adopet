#ifndef PEOPLELIST_H
#define PEOPLELIST_H

#include <QLabel>
#include <QPushButton>

#include <algorithm>

#include "../Pets/pet.h"
#include "../Owner/owner.h"
using namespace std;

class PeopleList
{
public:
    PeopleList();

private:
    int numToDisplay;
    QPushButton* previousButton;
    QPushButton* nextButton;

    QLabel* pageNum;
    vector<QLabel*> adopterNameLabels;
    vector<QLabel*> adopterEmailLabels;
    vector<QLabel*> matchLabels;
    vector<QLabel*> petNameLabels;


    vector<Pet> pets;


};

#endif // PEOPLELIST_H
