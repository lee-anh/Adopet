
#include "petgallery.h"

PetGallery::PetGallery()
{

}

PetGallery::PetGallery(int numToDisplay, vector<QLabel*> petNameLabels,
                       vector<Pet> petVec){
    numPets = numToDisplay;
    nameLabels = petNameLabels;
    pets = petVec;
}

PetGallery::PetGallery(int numToDisplay, vector<QLabel*> petNameLabels){
    numPets = numToDisplay;
    nameLabels = petNameLabels;
}


PetGallery::~PetGallery(){

}

void PetGallery::displayNames(int start){
    for(int i = start; i < (int) nameLabels.size(); i++){
        nameLabels[i]->setText("hi, it works!");
    }
}

