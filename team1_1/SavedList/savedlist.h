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
    SavedList(string databaseFilepath, string username);
    SavedList(QSqlDatabase d);
    ~SavedList();
    void savePet(Pet p);
    void unsavePet(Pet p);

    void savePet(int petID); //just helper rn, doesn't push to vec
    void unsavePet(int petID); //just helper rn, doesn't push to vec

    void setUsername(string username);

    vector<Pet> getPetVec();
    void printVec();

    bool isSavedPet(Pet p);



private:
    vector<Pet> savedPets;
    string username;

    //DB Stuff
    string dbName;
    QSqlDatabase dbSL;
    void loadList();
    void openDB();
    void closeDB();


    //another method that retrieves from the DB?

};

#endif // SAVEDLIST_H
