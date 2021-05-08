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

    void writeToCSV();                                  //writes in the randomized data into the csv files

    string getImageFileNameBySpecies(string petSpecies);     //gets the image file name of a specific pet based on its species
    string getVideoFileNameBySpecies(string petSpecies);     //gets the video file name of a specific pet based on its species
    string getMediaType(string fileName);               //returns either "image" or "video" depending on file type


private:
    int numOfPets;
    ofstream writePetsCsv;
    ofstream writeMediaCsv;
    ofstream readCsv;

    //Database stuff
    QSqlDatabase db;
    void openDB();          //opens a database connection

    void initializeNameVecs(); //initializes vectors with static information

    //vectors that don't change
    vector<string> names;
    vector<string> age;
    vector<string> gender;
    vector<string> size;
    vector<string> imageFileNames;    
    vector<string> videoFileNames;

    //read from DB
    vector<string> species;
    vector<pair<string, string>> breed;
    vector<string> temperament;
    vector<string> goodWith;
    vector<string> shelter;

    int seed;
};

#endif // PETRANDOMIZER_H
