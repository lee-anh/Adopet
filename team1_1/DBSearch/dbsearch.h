#ifndef DBSEARCH_H
#define DBSEARCH_H

#include <iostream>
#include <vector>
#include <QtSql>
#include "../Pets/pet.h"


using namespace std;

class DBSearch
{
public:
    DBSearch();
    DBSearch(string dbFilepath);
    ~DBSearch();

    //two options: search bar or check/uncheck the boxes

    //cout all the animals that match
    void search(string s);

    int queryDB(string s, string attribute);
    vector<Pet> getPetVec();
    int getPetVecSize();
    void printMatchingVec();


private:
    //database stuff
    string filepath;
    void openDB();
    QSqlDatabase db;
    void fillVecsFromDB();
    void fillStaticVecs();



    //vectors of keywords
    vector<string> mainSpecies; //from DB
    vector<string> mainBreeds; //from DB
    vector<string> mainAges; //static
    vector<string> mainSizes; //static
    vector<string> mainTemperaments; //from DB
    vector<string> mainGenders; //static
    vector<string> mainGoodWith; //from DB
    vector<string> mainShelters; //from DB

    vector<Pet> matchingPets;




    //optimization for later: find likes

    //how do we refine searches?
    //store what you write to a datastructure
    //or you could query the database again (preferred)

    //specific order



};

#endif // DBSEARCH_H
