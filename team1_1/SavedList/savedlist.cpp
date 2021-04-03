#include "savedlist.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

SavedList::SavedList()
{

}

SavedList::~SavedList(){
    savedPets.clear();
}

void SavedList::savePet(Pet* p){
    Pet newPet = Pet(p->getName(), p->getSpecies(), p->getBreed(),p->getAge(),p->getGender(), p->getSize(),
                     p->getTemperament(), p->getGoodWith(), p->getShelter(), p->getBio());
    savedPets.push_back(newPet);
}

void SavedList::unsavePet(string n){
    for (vector<Pet>::iterator it = savedPets.begin() ; it != savedPets.end(); ++it){
        if(it->getName().compare(n)==0){
            savedPets.erase(it);
        }
    }
}

Pet* SavedList::searchPet(string n){
    for (vector<Pet>::iterator it = savedPets.begin() ; it != savedPets.end(); ++it){
        if(it->getName().compare(n)==0){
            return &*it;
        }
    }
    return nullptr;
}
