#ifndef SAVEDLIST_H
#define SAVEDLIST_H
#include "../Pets/pet.h"


class SavedList
{
public:
    SavedList();
    ~SavedList();
    void savePet(Pet* p);
    Pet* searchPet(string n);
    void unsavePet(string n);

private:
    vector<Pet> savedPets;
};

#endif // SAVEDLIST_H
