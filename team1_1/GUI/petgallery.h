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
    PetGallery(int numPetsToDisplay,QPushButton* prev, QPushButton* next, QLabel* pageLine, vector<QLabel*> petNameLabels,
               vector<QLabel*> petPhotos, vector<QPushButton*> petLearnMore,vector<Pet> petVec);
    PetGallery(int numPetsToDisplay, QPushButton* prev, QPushButton* next, QLabel* pageLine,
               vector<QLabel*> petNameLabels,
               vector<QLabel*> petPhotos, vector<QPushButton*> petLearnMore,
               vector<QPushButton*> petSaves, vector<Pet> petVec);
    // PetGallery(int numPetsToDisplay, vector<QLabel*> petNameLabels); //just for testing
    ~PetGallery();

    void updatePetVec(vector<Pet> p);

    void displayPets(int start);
    void next();
    void previous();

    void setPageNum(int p);
    Pet getPet(int pos);

    vector<Pet> getPetVec();

    void clearLabels();






    //constructor that takes in list of pets, start pos
    //list of relavent gui elements

    //learn more method could be here too
    //learn more just needs the positions and the vector of pets.
    //learn more needs to return a pet

private:

    int numToDisplay;
    QPushButton* previousButton;
    QPushButton* nextButton;

    QLabel* pageNum;
    vector<QLabel*> nameLabels;
    vector<QLabel*> picLabels;
    vector<QPushButton*> learnMores;
    vector <QPushButton*> saveButtons;

    vector<Pet> pets;

    vector<Pet> petsToDisplay;

    int nextStartIndex;
    int displayPetsPageNumber;



};



#endif // PETGALLERY_H
