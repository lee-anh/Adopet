#ifndef SAVEDLIST_H
#define SAVEDLIST_H

#include "../Pets/pet.h"
#include <vector>
#include <QtSql>

using namespace std;


class SavedList
{
public:
    SavedList();
    SavedList(string username);
    ~SavedList();
    void savePet(Pet* p);
    void savePet(int petID);
    void unsavePet(int petID);
    void setUsername(string username);
    //Reload the vector from the SQL every time you
    //call
    void loadList();
    void openDB();


private:
    vector<Pet> savedPets;
    string username;
    QSqlDatabase db;
};

#endif // SAVEDLIST_H
