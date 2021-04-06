#ifndef PETRANDOMIZER_H
#define PETRANDOMIZER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <QtSql>
#include <algorithm>
#include <time.h>
using namespace std;

class PetRandomizer
{
public:
    PetRandomizer();
    PetRandomizer(int num);
    ~PetRandomizer();

    void writeToCSV();
    void speciesTest();

private:
    int numOfPets;
    ofstream writeCsv;
    ofstream readCsv;

    //Database stuff
    QSqlDatabase db;
    void openDB();

    void initalizeNameVecs();
    void loadDBVecs();

    //vectors that don't change
    vector<string> names;
    vector<string> age;
    vector<string> gender;
    vector<string> size;



    //read from DB
    vector<string> species;
    vector<string> breed;
    vector<string> temperament;
    vector<string> goodWith;
    vector<string> shelter;

    int seed;
};

#endif // PETRANDOMIZER_H
