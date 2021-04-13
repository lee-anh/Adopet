#ifndef PETGALLERY_H
#define PETGALLERY_H


#include <QtSql>
#include <QWidget>
#include <QLabel>
#include <vector>

#include "gui.h"
#include "../Pets/pet.h"

using namespace std;

class PetGallery
{
public:

    PetGallery();
    PetGallery(int numToDisplay, vector<QLabel*> petNameLabels, vector<Pet> petVec);
     PetGallery(int numToDisplay, vector<QLabel*> petNameLabels); //just for testing
    ~PetGallery();
    void displayNames(int start);

    //constructor that takes in list of pets, start/stop pos
    //list of relavent gui elements
    //learn more method could be here too
    //learn more just needs the positions and the vector of pets.
    //learn more needs to return a pet

private:
    //Ui::GUI *ui;
    int numPets;
    vector<QLabel*> nameLabels;
    vector<Pet> pets;

};



#endif // PETGALLERY_H
