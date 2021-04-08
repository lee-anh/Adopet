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
    void savePet(Pet p);
    void unsavePet(Pet p);

    void savePet(int petID); //just helper rn, doesn't push to vec
    void unsavePet(int petID); //just helper rn, doesn't push to vec

    void setUsername(string username);
    //Reload the vector from the SQL every time you
    //call
    void printVec();



private:
    vector<Pet> savedPets;
    string username;

    //DB Stuff
    QSqlDatabase dbSL;
    void loadList();
    void openDB();
    void closeDB();


    //another method that retrieves from the DB?

};

#endif // SAVEDLIST_H
