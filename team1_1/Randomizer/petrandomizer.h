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

    string getFileNameBySpecies(string petSpecies);     //gets the media file name of a specific pet based on its species
    string getMediaType(string fileName);               //returns either "image" or "video" depending on file type


private:
    int numOfPets;
    ofstream writePetsCsv;
    ofstream writeMediaCsv;
    ofstream readCsv;

    //Database stuff
    QSqlDatabase db;
    void openDB();

    void initializeNameVecs();
    void loadDBVecs();

    //vectors that don't change
    vector<string> names;
    vector<string> age;
    vector<string> gender;
    vector<string> size;
    vector<string> imageFileNames;


    //read from DB
    vector<string> species;
    vector<pair<string, string>> breed;
    vector<string> temperament;
    vector<string> goodWith;
    vector<string> shelter;

    int seed;
};

#endif // PETRANDOMIZER_H
