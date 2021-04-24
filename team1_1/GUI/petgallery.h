#ifndef PETGALLERY_H
#define PETGALLERY_H


#include <QtSql>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <vector>
#include <algorithm>

#include "../Pets/pet.h"

using namespace std;

class PetGallery
{
public:

    PetGallery();


    //for owner MyPets
    PetGallery(int numPetsToDisplay, QPushButton* prev,
               QPushButton* next, QLabel* pageLine,
               vector<QLabel*> petNameLabels,
               vector<QLabel*> petPhotos, vector<QPushButton*> petLearnMore,
               vector<Pet> petVec);

    //for my favorites and manual search
    PetGallery(int numPetsToDisplay, QPushButton* prev,
               QPushButton* next, QLabel* pageLine,
               vector<QLabel*> petNameLabels,
               vector<QLabel*> petPhotos, vector<QPushButton*> petLearnMore,
               vector<QPushButton*> petSaves, vector<Pet> petVec);



    //for matchmaking
    PetGallery(int numPetsToDisplay, QPushButton* prev,
               QPushButton* next, QLabel* pageLine,
               vector<QLabel*> petNameLabels, vector<QLabel*> petPhotos,
               vector<QLabel*> petScores, vector<QPushButton*> petLearnMore,
               vector<QPushButton*> petSaves, vector<pair<Pet, int>> petVec);

    ~PetGallery();

    void updatePetVec(vector<Pet> p);

    void displayPets(int start);
    void next();
    void previous();


    void setPageNum(int p);
    Pet getPet(int pos);

    vector<Pet> getPetVec();

    void clearLabels();



private:

    int numToDisplay;
    QPushButton* previousButton;
    QPushButton* nextButton;

    QLabel* pageNum;
    vector<QLabel*> nameLabels;
    vector<QLabel*> picLabels;
    vector<QLabel*> scoreLabels;

    vector<QPushButton*> learnMores;
    vector <QPushButton*> saveButtons;

    vector<Pet> pets;
    vector<pair<Pet, int>> matPets;

    vector<Pet> petsToDisplay;


    int nextStartIndex;
    int displayPetsPageNumber;

    //conversion method
    void matchPetsToRegPets();

    void petPictures();

    QSqlDatabase petsDB;
    void openDB();


};



#endif // PETGALLERY_H
